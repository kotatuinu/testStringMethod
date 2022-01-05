#pragma once
#include "constdefine.h"
#include <string>

class 数値_文字変換
{
private:
	RESULT 旧(int dec, char* word, size_t bufSize);
	RESULT 新1(int dec, std::string& word);
	RESULT 新2(int dec, std::string& word);

public:
	void exec();
};
