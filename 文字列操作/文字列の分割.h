#pragma once
#include <vector>
#include <string>
#include "constdefine.h"

class 文字列の分割
{
private:
	RESULT 旧(const char* src, size_t srcSize, const char* delim);
	RESULT 新(const std::string& src, const std::string& delims);
	std::vector<std::string> split(const std::string& src, const std::string& delim);

public:
	void exec();
};