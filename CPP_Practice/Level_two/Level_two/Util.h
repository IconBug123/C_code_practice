#ifndef UTIL_HEAD
#define UTIL_HEAD

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

namespace util {
	inline double pi() { return std::acos(-1.0); }
	constexpr double EPS = 1e-9;
	inline bool eq(double a, double b) { return std::fabs(a - b) < EPS; }


	inline std::string trim(std::string s) {
		auto issp = [](int c) { return std::isspace(c); };
		s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), issp));
		s.erase(std::find_if_not(s.rbegin(), s.rend(), issp).base(), s.end());
		return s;
	}


	inline std::vector<std::string> splitCSV(const std::string& line) {
		// 简单 CSV：仅按逗号分割，不处理引号转义
		std::vector<std::string> out;
		std::string cur;
		for (char c : line) {
			if (c == ',') { out.push_back(trim(cur)); cur.clear(); }
			else { cur.push_back(c); }
		}
		out.push_back(trim(cur));
		return out;
	}


	inline double readDouble(const std::string& prompt) {
		std::cout << prompt;
		double x;
		while (!(std::cin >> x)) {
			std::cout << "输入无效，请重新输入：";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return x;
	}


	inline int readInt(const std::string& prompt, int lo, int hi) {
		std::cout << prompt;
		int x;
		while (!(std::cin >> x) || x < lo || x > hi) {
			std::cout << "输入无效，请输入 " << lo << "-" << hi << "：";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return x;
	}
}



#endif
