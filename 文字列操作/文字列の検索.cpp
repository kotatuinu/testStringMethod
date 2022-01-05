#include "������̌���.h"
#include <iostream>
#include <vector>

RESULT ������̌���::��(const char* src, const char* searchword)
{
	if (src == NULL || searchword == NULL) {
		// invalid arguments
		return RESULT::ERR;
	}

	const char* tmp1 = src;
	do {
		/*
		* char *strstr(const char *haystack, const char *needle);
		* strstr() �֐��́A���������� needle �������� haystack �� �ōŏ��Ɍ����ʒu��������B ��������I�[�k���o�C�g ('\0') �͔�r����Ȃ�
		* �Ԃ�l
		*	�����̊֐��́A������������������̊J�n���w���|�C���^�[��Ԃ��A �������������񂪌�����Ȃ��ꍇ�� NULL ��Ԃ��B
		*/
		const char* tmp2 = strstr(tmp1, searchword);
		if (tmp2 != NULL) {
			printf("���FThere is word[%s] in %d character of searchword[%s].\r\n", tmp1, (tmp2 - tmp1), searchword);
			tmp1 = tmp2 + strlen(searchword);
		}
		else {
			printf("���Fword[%s] is not in searchword[%s].\r\n", tmp1, searchword);
			tmp1 = NULL;
		}
	} while (tmp1 != NULL);

	return RESULT::SUCCESS;
}

RESULT ������̌���::�V(const std::string &src, const std::string &searchword)
{
	size_t pos1 = 0;

	do {
		size_t pos2 = src.find(searchword, pos1);
		if (pos2 != std::string::npos) {
			std::cout << "�V�FWord[" << src << "] Search for searchword[" << searchword << "]. There is in posision " << pos2 << " character." << std::endl;
			pos1 = pos2 + searchword.length();
		}
		else {
			std::cout << "�V�Fword[" << src << "] is not in searchword[" << searchword << "]." << std::endl;
			pos1 = pos2;
		}
	} while (pos1 != std::string::npos);

	return RESULT::SUCCESS;
}


void ������̌���::exec()
{
	std::cout << "������̌���" << std::endl;

	const char src1[] = "�����������̂����A�����������̂���";
	const char delim1[] = "��";

	RESULT result = ��(src1, delim1);

	const std::string src2 = "�����������̂����A�����������̂���";
	const std::string delim2 = "��";

	result = �V(src2, delim2);

}
