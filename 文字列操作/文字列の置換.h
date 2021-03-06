#pragma once
#include "constdefine.h"
#include <string>

class 文字列の置換
{
private:
	static const size_t ALLOC_SIZE = 5;

private:
	RESULT 旧(const char* src, const char* replacesrc, const char* replacedest, char** result);
	RESULT 新(const std::string& src, const std::string& replacesrc, const std::string& replacedest, std::string& result);

public:
	void exec();
};