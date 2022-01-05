#include "������̍\�z.h"
#include <iostream>

RESULT ������̍\�z::���i�o�͌Œ�T�C�Y�j(const char* src, size_t wordSize, size_t count, char* result, size_t resultSize)
{
	for (size_t i = 0; i < count; i++) {
		// ������̌���
		/*
		* errno_t strcat_s( char *strDestination, size_t numberOfElements, const char *strSource );
		* strSource �� strDestination �ɒǉ����A���ʂ̕�����̏I�[�� null ������t���܂��B strSource �̐擪�̕����́AstrDestination �̏I�[�� null �������㏑�����܂��B �R�s�[���ƃR�s�[��̕����񂪏d�Ȃ荇���Ă���ꍇ�� strcat_s �֐��̓���͖���`�ł��B
		* �߂�l
		*	����I�������ꍇ�� 0 ��Ԃ��܂��B���s�����ꍇ�̓G���[ �R�[�h��Ԃ��܂��B
		*/
		errno_t  err = strcat_s(result, resultSize, src);
		if (err != 0) {
			// �G���[
			return RESULT::ERR;
		}
		src += wordSize;
	}

	return RESULT::SUCCESS;
}


RESULT ������̍\�z::���i�o�͉ϒ��j(const char* src, size_t wordSize, size_t count, char** result)
{
	if (result == NULL) {
		return RESULT::ERR;
	}

	// ����A�̈�m�ۂ���ƒx���Ȃ�̂ŁA�傫�߂Ɏ擾���ăT�C�Y�𒴂���Ƃ��ɉ��߂Ď擾������
	size_t totalSize = 0;
	size_t allocSize = ALLOC_SIZE;
	char* tmp = (char*)malloc(allocSize);
	if (tmp == NULL) {
		return RESULT::ERR;
	}
	tmp[0] = '\0';

	for (size_t i = 0; i < count; i++) {

		size_t wordLen = strlen(src);
		totalSize += wordLen;
		if (allocSize < totalSize) {
			if (wordLen > ALLOC_SIZE) {
				// �V���Ɏ擾����o�b�t�@�T�C�Y��蕶���񒷂������ꍇ�A�����񒷕��{���擾
				allocSize += wordLen;
			}
			allocSize += ALLOC_SIZE;

			char* tmp2 = (char*)malloc(allocSize);
			if (tmp2 == NULL) {
				return RESULT::ERR;
			}
			tmp2[0] = '\0';
			// �������V�����̈�ɃR�s�[����
			strcpy_s(tmp2, allocSize, tmp);
			free(tmp);
			tmp = tmp2;
		}

		// ������̌���
		errno_t err = strcat_s(tmp, allocSize, src);
		if (err != 0) {
			// �G���[
			return RESULT::ERR;
		}
		src += wordSize;
	}

	*result = tmp;

	return RESULT::SUCCESS;
}

RESULT ������̍\�z::�V(const std::vector<std::string>& src, std::string& result)
{
	for (const auto& word : src) {
		// std::string�́A"+="���Z�q�Œǉ��o����
		result += word;
	}

	return RESULT::SUCCESS;
}

void ������̍\�z::exec()
{
	std::cout << "������̍\�z" << std::endl;

	const char src1[][9] = {
		"�Ă��ƂP",
		"�Ă��ƂQ",
		"�Ă��ƂR",
	};
	char result1[25] = {};
	RESULT rslt = ���i�o�͌Œ�T�C�Y�j((const char*)(&src1[0]), sizeof(src1[0]), (sizeof(src1) / sizeof(src1[0])), (char*)result1, sizeof(result1));
	if (rslt != RESULT::SUCCESS) {
		fprintf(stderr, "�G���[�F������̍\�z::���i�o�͌Œ�T�C�Y�j\r\n");
	}
	else {
		printf("%s\r\n", result1);
	}

	char* result2 = NULL;
	rslt = ���i�o�͉ϒ��j((const char*)(&src1[0]), sizeof(src1[0]), (sizeof(src1) / sizeof(src1[0])), &result2);
	if (rslt != RESULT::SUCCESS) {
		fprintf(stderr, "�G���[�F������̍\�z::���i�o�͉ϒ��j\r\n");
	}
	else {
		printf("%s\r\n", result2);
	}
	free(result2);

	const std::vector<std::string> src2 = {
		"�Ă��ƂP",
		"�Ă��ƂQ",
		"�Ă��ƂR",
	};
	std::string result3 = {};
	rslt = �V(src2, result3);
	if (rslt != RESULT::SUCCESS) {
		fprintf(stderr, "�G���[�F������̍\�z::�V\r\n");
	}
	else {
		std::cout << result3 << std::endl;
		//printf("%s\r\n", result3.c_str());
	}
}

