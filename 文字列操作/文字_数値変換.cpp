#include "����_���l�ϊ�.h"
#include <stdlib.h>
#include <iostream>

RESULT ����_���l�ϊ�::��(const char* word, int& dec)
{
	dec = atoi(word);

	return RESULT::SUCCESS;
}

RESULT ����_���l�ϊ�::�V(const std::string& word, int& dec)
{
	dec = std::stoi(word);

	return RESULT::SUCCESS;
}

void ����_���l�ϊ�::exec()
{
	const char* word1 = "1000";
	int dec;
	RESULT result = ��(word1, dec);
	printf("%d\r\n", dec);

	std::string word2 = "1001";
	result = �V(word2, dec);
	std::cout << dec;
}