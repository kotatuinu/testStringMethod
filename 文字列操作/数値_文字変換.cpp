#include "���l_�����ϊ�.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

RESULT ���l_�����ϊ�::��(int dec, char* word, size_t bufSize)
{
	/*
	* errno_t _itoa_s( int value, char * buffer, size_t size, int radix );
	* ����value�̐��l���A����radix����i2�`36�j�Ƃ��āA����buffer�ɕ�����Ƃ��ĕϊ��̌��ʂ�ێ�����ibuffer�̕������͈���size�Ŏw��j�B
	* �߂�l
	*	����I�������ꍇ�� 0 ��Ԃ��܂��B���s�����ꍇ�̓G���[ �R�[�h��Ԃ��܂��B
	*/
	_itoa_s(dec, word, bufSize, 10);
	return RESULT::SUCCESS;
}

RESULT ���l_�����ϊ�::�V1(int dec, std::string &word)
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

	std::cout << "���l�������ϊ�" << std::endl;

	char word1[11] = {};
	RESULT result = ��(dec, word1, sizeof(word1));
	printf("���F���l[%d] -> ������[%s]\r\n", dec, word1);

	std::string word2;
	result = �V1(dec, word2);
	std::cout << "�V1�F���l[" << dec << "] -> ������[" << word1 << "]" << std::endl;

	word2.clear();
	result = �V2(dec, word2);
	std::cout << "�V2�F���l[" << dec << "] -> ������[" << word2 << "]" << std::endl;
}
