#include "文字列長.h"
#include <iostream>

RESULT 文字列長::旧(const char* word, size_t &len)
{
	/*
	* strlen() 関数は、 s が指す文字列の長さを計算する。 このとき、終端ヌルバイト ('\0') は計算に含まれない。
	* 返り値
	*	strlen() 関数は s が指す文字列のバイト数を返す。
	*/
	len = strlen(word);
	return RESULT::SUCCESS;
}
RESULT 文字列長::新(const std::string& word, size_t& len)
{
	len = word.size();
	len = word.length();	// バッファサイズなので文字列長とは異なる
	return RESULT::SUCCESS;
}

void 文字列長::exec() 
{
	const char word1[] = "1234567890１２３４５６７８９０";
	size_t len = 0;
	RESULT result = 旧(word1, len);
	printf("%d\r\n", len);

	const std::string word2 = "1234567890１２３４５６７８９０";
	len = 0;
	result = 新(word2, len);
	std::cout << len << std::endl;
}
