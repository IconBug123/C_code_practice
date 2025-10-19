#pragma once
#include <iostream>
#include <stdexcept>
#include <utility>
#include <initializer_list>
#include <cassert>
#include <cstddef>
#include <new>          // placement new
#include <numeric>      // std::gcd

// ===================== 模板类定义 =====================
template<typename T>
class MyVector {
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;

private:
    T* data_ = nullptr;
    size_type size_ = 0;
    size_type capacity_ = 0;

public:
    // ---------- 构造 / 析构 ----------
    MyVector() = default;

    explicit MyVector(size_type n, const T& value = T()) {
        allocate_(n);
        for (size_type i = 0; i < n; ++i) new (data_ + i) T(value);
        size_ = n;
    }

    MyVector(std::initializer_list<T> il) {
        allocate_(il.size());
        size_ = 0;
        for (const auto& v : il) push_back(v);
    }

    MyVector(const MyVector& other) {
        allocate_(other.size_);
        for (size_type i = 0; i < other.size_; ++i)
            new (data_ + i) T(other.data_[i]);
        size_ = other.size_;
    }

    MyVector(MyVector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr; other.size_ = 0; other.capacity_ = 0;
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;
        clear();
        if (other.size_ > capacity_) {
            deallocate_();
            allocate_(other.size_);
        }
        for (size_type i = 0; i < other.size_; ++i)
            new (data_ + i) T(other.data_[i]);
        size_ = other.size_;
        return *this;
    }

    MyVector& operator=(MyVector&& other) noexcept {
        if (this == &other) return *this;
        destroy_range_(0, size_);
        deallocate_();
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr; other.size_ = 0; other.capacity_ = 0;
        return *this;
    }

    ~MyVector() {
        destroy_range_(0, size_);
        deallocate_();
    }

    // ---------- 基本访问 ----------
    size_type size() const noexcept { return size_; }
    size_type capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }

    reference operator[](size_type i) { return data_[i]; }
    const_reference operator[](size_type i) const { return data_[i]; }

    reference at(size_type i) {
        if (i >= size_) throw std::out_of_range("MyVector::at index out of range");
        return data_[i];
    }
    const_reference at(size_type i) const {
        if (i >= size_) throw std::out_of_range("MyVector::at index out of range");
        return data_[i];
    }

    reference front() { assert(size_ > 0); return data_[0]; }
    const_reference front() const { assert(size_ > 0); return data_[0]; }
    reference back() { assert(size_ > 0); return data_[size_ - 1]; }
    const_reference back() const { assert(size_ > 0); return data_[size_ - 1]; }

    iterator begin() noexcept { return data_; }
    iterator end()   noexcept { return data_ + size_; }
    const_iterator begin() const noexcept { return data_; }
    const_iterator end()   const noexcept { return data_ + size_; }

    // ---------- 修改器 ----------
    void clear() noexcept {
        destroy_range_(0, size_);
        size_ = 0;
    }

    void push_back(const T& value) {
        ensure_capacity_for_push_();
        new (data_ + size_) T(value);
        ++size_;
    }

    void push_back(T&& value) {
        ensure_capacity_for_push_();
        new (data_ + size_) T(std::move(value));
        ++size_;
    }

    void pop_back() {
        assert(size_ > 0);
        data_[size_ - 1].~T();
        --size_;
    }

    void reserve(size_type new_cap) {
        if (new_cap <= capacity_) return;
        reallocate_(new_cap);
    }

    void resize(size_type n, const T& value = T()) {
        if (n < size_) {
            destroy_range_(n, size_);
            size_ = n;
        }
        else if (n > size_) {
            if (n > capacity_) reallocate_(best_grow_(n));
            for (; size_ < n; ++size_) new (data_ + size_) T(value);
        }
    }

private:
    // ---------- 内部工具 ----------
    void allocate_(size_type cap) {
        if (cap == 0) { data_ = nullptr; capacity_ = 0; return; }
        data_ = static_cast<T*>(::operator new[](cap * sizeof(T)));
        capacity_ = cap;
    }

    void deallocate_() {
        ::operator delete[](data_);
        data_ = nullptr; capacity_ = 0;
    }

    void destroy_range_(size_type from, size_type to) noexcept {
        for (size_type i = from; i < to; ++i)
            data_[i].~T();
    }

    void reallocate_(size_type new_cap) {
        T* new_data = static_cast<T*>(::operator new[](new_cap * sizeof(T)));
        for (size_type i = 0; i < size_; ++i)
            new (new_data + i) T(std::move_if_noexcept(data_[i]));
        destroy_range_(0, size_);
        ::operator delete[](data_);
        data_ = new_data;
        capacity_ = new_cap;
    }

    void ensure_capacity_for_push_() {
        if (size_ == capacity_) {
            const size_type new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate_(new_cap);
        }
    }

    static size_type best_grow_(size_type required) {
        size_type cap = 1;
        while (cap < required) cap <<= 1;
        return cap;
    }
};
