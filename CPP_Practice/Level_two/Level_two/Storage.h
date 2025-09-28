#pragma once
#include <string>
#include <vector>
class Shape;


namespace storage {
	bool saveToFile(const std::string& path, const std::vector<Shape*>& vec);
	bool loadFromFile(const std::string& path, std::vector<Shape*>& vec); // ×·¼Ó
}