#include "����_���l�ϊ�.h"
#include <stdlib.h>
#include <iostream>

RESULT ����_���l�ϊ�::��(const char* word, int& dec)
{
	/*
	* int atoi(const char *nptr);
	* atoi() �֐��́Anptr �ɂ���Ďw������镶����̂͂��߂̕����� int �^�����ɕϊ�����B ���̐U�镑���́A atoi() �֐����G���[�������Ȃ��_�ȊO�́A
	* strtol(nptr, NULL, 10);�Ɠ����ł���B
	* �Ԃ�l
	*	The converted value or 0 on error. 
	*/
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

	std::cout << "���������l�ϊ�" << std::endl;

	RESULT result = ��(word1, dec);
	printf("���F������[%s] -> ���l[%d]\r\n", word1, dec);

	std::string word2 = "1001";
	result = �V(word2, dec);
	std::cout << "�V1�F������[" << word2 << "] -> ���l[" << dec << "]" << std::endl;
}