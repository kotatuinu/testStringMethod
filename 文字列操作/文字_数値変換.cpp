#include "文字_数値変換.h"
#include <stdlib.h>
#include <iostream>

RESULT 文字_数値変換::旧(const char* word, int& dec)
{
	/*
	* int atoi(const char *nptr);
	* atoi() 関数は、nptr によって指示される文字列のはじめの部分を int 型整数に変換する。 この振る舞いは、 atoi() 関数がエラーを見つけない点以外は、
	* strtol(nptr, NULL, 10);と同じである。
	* 返り値
	*	The converted value or 0 on error. 
	*/
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

	std::cout << "文字→数値変換" << std::endl;

	RESULT result = 旧(word1, dec);
	printf("旧：文字列[%s] -> 数値[%d]\r\n", word1, dec);

	std::string word2 = "1001";
	result = 新(word2, dec);
	std::cout << "新1：文字列[" << word2 << "] -> 数値[" << dec << "]" << std::endl;
}