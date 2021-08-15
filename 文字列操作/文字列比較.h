#pragma once
#include "constdefine.h"
#include <string>

enum STRING_COMP {
	UNDEFINE,
	L_BIGGER_THAN_R,
	L_SMALLER_THAN_R,
	EQUAL
};
class ï∂éöóÒî‰är
{
private:
	RESULT ãå(const char* word1, const char* word2, int& cmpResult);
	RESULT êV1(const std::string& word1, const std::string& word2, int& cmpResult);
	STRING_COMP êV2(const std::string& word1, const std::string& word2);

public:
	void exec();
};

