#include "文字列比較.h"
#include <iostream>


RESULT 文字列比較::旧(const char* word1, const char* word2, int& cmpResult)
{
	cmpResult = strcmp(word1, word2);

	return RESULT::SUCCESS;
}

RESULT 文字列比較::新1(const std::string& word1, const std::string& word2, int& cmpResult)
{
	cmpResult = word1.compare(word2);

	return RESULT::SUCCESS;
}

STRING_COMP 文字列比較::新2(const std::string& word1, const std::string& word2)
{
	STRING_COMP result = STRING_COMP::UNDEFINE;

	if (word1 > word2) {
		result = STRING_COMP::L_BIGGER_THAN_R;
	}
	else if (word1 < word2) {
		result = STRING_COMP::L_SMALLER_THAN_R;
	}
	else {
		result = STRING_COMP::EQUAL;
	}
	return result;
}

void 文字列比較::exec()
{
	int cmpResult1 = 0;
	const char word11[] = "テスト";
	const char word12[] = "テスト";
	RESULT result = 旧(word11, word12, cmpResult1);
	printf("%d\r\n", cmpResult1);

	int cmpResult2 = 0;
	const std::string word21 = "テスト";
	const std::string word22 = "テスト";
		result = 新1(word21, word22, cmpResult2);
	printf("%d\r\n", cmpResult2);
	
	STRING_COMP cmpResult = 新2(word21, word22);
	switch (cmpResult)
	{
	case STRING_COMP::EQUAL:
		std::cout << "EQUAL" << std::endl;
		break;
	case STRING_COMP::L_BIGGER_THAN_R:
		std::cout << "left Bigger than Reft" << std::endl;
		break;
	case STRING_COMP::L_SMALLER_THAN_R:
		std::cout << "left Smaller than Reft" << std::endl;
		break;
	default:
		break;
	}

}
