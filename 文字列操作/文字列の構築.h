#pragma once
#include <vector>
#include <string>
#include "constdefine.h"

class 文字列の構築
{
private:
	const size_t ALLOC_SIZE = 5;

private:
	RESULT 旧（出力固定サイズ）(const char* src, size_t wordSize, size_t count, char* result, size_t resultSize);
	RESULT 旧（出力可変長）(const char* src, size_t wordSize, size_t count, char** result);
	RESULT 新(const std::vector<std::string>& src, std::string& result);

public:
	void exec();
};