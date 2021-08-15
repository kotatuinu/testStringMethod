#include "文字_数値変換.h"
#include <stdlib.h>
#include <iostream>

RESULT 文字_数値変換::旧(const char* word, int& dec)
{
	dec = atoi(word);

	return RESULT::SUCCESS;
}

RESULT 文字_数値変換::新(const std::string& word, int& dec)
{
	dec = std::stoi(word);

	return RESULT::SUCCESS;
}

void 文字_数値変換::exec()
{
	const char* word1 = "1000";
	int dec;
	RESULT result = 旧(word1, dec);
	printf("%d\r\n", dec);

	std::string word2 = "1001";
	result = 新(word2, dec);
	std::cout << dec;
}