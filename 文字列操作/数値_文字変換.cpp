#include "数値_文字変換.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

RESULT 数値_文字変換::旧(int dec, char* word, size_t bufSize)
{
	_itoa_s(dec, word, bufSize, 10);
	return RESULT::SUCCESS;
}

RESULT 数値_文字変換::新(int dec, std::string &word)
{
	word = std::to_string(dec);
	return RESULT::SUCCESS;
}

RESULT 数値_文字変換::新2(int dec, std::string& word)
{
	// stringstreamを使うと、<<で文字列を構築できる。でも、遅い。
	// 書式設定を行うことで0埋めになる
	std::stringstream ss;
	ss << std::setw(20) << std::setfill('0') << dec << std::endl;
	word = ss.str();
	return RESULT::SUCCESS;
}

void 数値_文字変換::exec()
{
	int dec = 2147483647;
	char word1[11] = {};
	RESULT result = 旧(dec, word1, sizeof(word1));

	std::string word2;
	result = 新(dec, word2);
	std::cout << word2 << std::endl;

	word2.clear();
	result = 新2(dec, word2);
	std::cout << word2 << std::endl;
}
