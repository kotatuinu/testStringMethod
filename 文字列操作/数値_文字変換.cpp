#include "���l_�����ϊ�.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

RESULT ���l_�����ϊ�::��(int dec, char* word, size_t bufSize)
{
	_itoa_s(dec, word, bufSize, 10);
	return RESULT::SUCCESS;
}

RESULT ���l_�����ϊ�::�V(int dec, std::string &word)
{
	word = std::to_string(dec);
	return RESULT::SUCCESS;
}

RESULT ���l_�����ϊ�::�V2(int dec, std::string& word)
{
	// stringstream���g���ƁA<<�ŕ�������\�z�ł���B�ł��A�x���B
	// �����ݒ���s�����Ƃ�0���߂ɂȂ�
	std::stringstream ss;
	ss << std::setw(20) << std::setfill('0') << dec << std::endl;
	word = ss.str();
	return RESULT::SUCCESS;
}

void ���l_�����ϊ�::exec()
{
	int dec = 2147483647;
	char word1[11] = {};
	RESULT result = ��(dec, word1, sizeof(word1));

	std::string word2;
	result = �V(dec, word2);
	std::cout << word2 << std::endl;

	word2.clear();
	result = �V2(dec, word2);
	std::cout << word2 << std::endl;
}
