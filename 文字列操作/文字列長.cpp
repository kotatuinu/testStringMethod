#include "������.h"
#include <iostream>

RESULT ������::��(const char* word, size_t &len)
{
	/*
	* strlen() �֐��́A s ���w��������̒������v�Z����B ���̂Ƃ��A�I�[�k���o�C�g ('\0') �͌v�Z�Ɋ܂܂�Ȃ��B
	* �Ԃ�l
	*	strlen() �֐��� s ���w��������̃o�C�g����Ԃ��B
	*/
	len = strlen(word);
	return RESULT::SUCCESS;
}
RESULT ������::�V(const std::string& word, size_t& len)
{
	len = word.size();
	len = word.length();	// �o�b�t�@�T�C�Y�Ȃ̂ŕ����񒷂Ƃ͈قȂ�
	return RESULT::SUCCESS;
}

void ������::exec() 
{
	const char word1[] = "1234567890�P�Q�R�S�T�U�V�W�X�O";
	size_t len = 0;
	RESULT result = ��(word1, len);
	printf("%d\r\n", len);

	const std::string word2 = "1234567890�P�Q�R�S�T�U�V�W�X�O";
	len = 0;
	result = �V(word2, len);
	std::cout << len << std::endl;
}
