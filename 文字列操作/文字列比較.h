#pragma once
#include "constdefine.h"
#include <string>

enum STRING_COMP {
	UNDEFINE,
	L_BIGGER_THAN_R,
	L_SMALLER_THAN_R,
	EQUAL
};
class �������r
{
private:
	RESULT ��(const char* word1, const char* word2, int& cmpResult);
	RESULT �V1(const std::string& word1, const std::string& word2, int& cmpResult);
	STRING_COMP �V2(const std::string& word1, const std::string& word2);

public:
	void exec();
};

