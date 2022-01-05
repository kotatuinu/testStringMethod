#include "数値_文字変換.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

RESULT 数値_文字変換::旧(int dec, char* word, size_t bufSize)
{
	/*
	* errno_t _itoa_s( int value, char * buffer, size_t size, int radix );
	* 引数valueの数値を、引数radixを基数（2～36）として、引数bufferに文字列として変換の結果を保持する（bufferの文字数は引数sizeで指定）。
	* 戻り値
	*	正常終了した場合は 0 を返します。失敗した場合はエラー コードを返します。
	*/
	_itoa_s(dec, word, bufSize, 10);
	return RESULT::SUCCESS;
}

RESULT 数値_文字変換::新1(int dec, std::string &word)
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

	std::cout << "数値→文字変換" << std::endl;

	char word1[11] = {};
	RESULT result = 旧(dec, word1, sizeof(word1));
	printf("旧：数値[%d] -> 文字列[%s]\r\n", dec, word1);

	std::string word2;
	result = 新1(dec, word2);
	std::cout << "新1：数値[" << dec << "] -> 文字列[" << word1 << "]" << std::endl;

	word2.clear();
	result = 新2(dec, word2);
	std::cout << "新2：数値[" << dec << "] -> 文字列[" << word2 << "]" << std::endl;
}
