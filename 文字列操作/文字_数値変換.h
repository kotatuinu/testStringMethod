#pragma once
#include "constdefine.h"
#include <string>

class 文字_数値変換
{
private:
	RESULT 旧(const char* word, int& dec);
	RESULT 新(const std::string& word, int& dec);

public:
	void exec();
};

