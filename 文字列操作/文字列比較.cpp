#include "�������r.h"
#include <iostream>


RESULT �������r::��(const char* word1, const char* word2, int& cmpResult)
{
	cmpResult = strcmp(word1, word2);

	return RESULT::SUCCESS;
}

RESULT �������r::�V1(const std::string& word1, const std::string& word2, int& cmpResult)
{
	cmpResult = word1.compare(word2);

	return RESULT::SUCCESS;
}

STRING_COMP �������r::�V2(const std::string& word1, const std::string& word2)
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

void �������r::exec()
{
	int cmpResult1 = 0;
	const char word11[] = "�e�X�g";
	const char word12[] = "�e�X�g";
	RESULT result = ��(word11, word12, cmpResult1);
	printf("%d\r\n", cmpResult1);

	int cmpResult2 = 0;
	const std::string word21 = "�e�X�g";
	const std::string word22 = "�e�X�g";
		result = �V1(word21, word22, cmpResult2);
	printf("%d\r\n", cmpResult2);
	
	STRING_COMP cmpResult = �V2(word21, word22);
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
