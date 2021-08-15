#include "������̒u��.h"
#include <iostream>

RESULT ������̒u��::��(const char* src, const char* replacesrc, const char* replacedest, char** result)
{
	// �������u������C����֐��͑��݂��Ȃ��̂ŁA�������u������������ǉ�����
	// �ėp�I�ɍ��ƁA�ŏI�I�ȕ����񒷂�������Ȃ��̂ŁA���I�ɗ̈�m�ۂ���K�v�����遁�g���I���������

	if (src == NULL || replacesrc == NULL || replacedest == NULL) {
		// invalid arguments
		return RESULT::ERR;
	}

	if (result == NULL) {
		// invalid arguments
		return RESULT::ERR;
	}

	const char* currentPos = src;

	// ����A�̈�m�ۂ���ƒx���Ȃ�̂ŁA�傫�߂Ɏ擾���ăT�C�Y�𒴂���Ƃ��ɉ��߂Ď擾������
	size_t totalSize = 0;
	size_t allocSize = strlen(src) + ALLOC_SIZE;
	char* buff = (char*)malloc(allocSize);
	buff[0] = '\0';

	size_t rsrcSize = strlen(replacesrc);
	size_t rdestSize = strlen(replacedest);

	// �u���������̕����������u��������̕�������i�[
	do {
		const char* nextPos = strstr(currentPos, replacesrc);
		if (nextPos != NULL) {
			if (totalSize + rdestSize + (nextPos - currentPos) + 1 > allocSize) {
				if (rdestSize > ALLOC_SIZE) {
					// �V���Ɏ擾����o�b�t�@�T�C�Y��蕶���񒷂������ꍇ�A�����񒷕��{���擾
					allocSize += (rdestSize + (nextPos - currentPos) + 1);
				}
				allocSize += ALLOC_SIZE;

				char* nextBuff = (char*)malloc(allocSize);
				if (nextBuff == NULL) {
					return RESULT::ERR;
				}

				strcpy_s(nextBuff, allocSize, buff);
				free(buff);
				buff = nextBuff;
			}
			strncat_s(buff, allocSize, currentPos, (nextPos - currentPos));
			strcat_s(buff, allocSize, replacedest);

			totalSize += (nextPos - currentPos) + rdestSize;
			currentPos = nextPos + rsrcSize;
		}
		else {
			size_t len = strlen(currentPos) + 1;
			if (totalSize + len > allocSize) {
				if (len > ALLOC_SIZE) {
					// �V���Ɏ擾����o�b�t�@�T�C�Y��蕶���񒷂������ꍇ�A�����񒷕��擾
					allocSize += len;
				}

				char* nextBuff = (char*)malloc(allocSize);
				if (nextBuff == NULL) {
					return RESULT::ERR;
				}

				strcpy_s(nextBuff, allocSize, buff);
				free(buff);
				buff = nextBuff;
			}

			strcat_s(buff, allocSize, currentPos);
			totalSize += len;
			currentPos = NULL;
		}
	} while (currentPos != NULL);

	*result = buff;

	return RESULT::SUCCESS;
}

RESULT ������̒u��::�V(const std::string& src, const std::string& replacesrc, const std::string& replacedest, std::string& result)
{
	size_t pos1 = 0;
	do {
		size_t pos2 = src.find(replacesrc, pos1);
		if (pos2 == std::string::npos) {
			result += src.substr(pos1);
			break;
		}
		result += src.substr(pos1, pos2 - pos1);
		result += replacedest;
		pos1 = pos2 + replacesrc.size();
	} while (true);

	return RESULT::SUCCESS;
}

void ������̒u��::exec()
{
	const char src1[] = "�����������̂����A�����������̂���";
	const char replacesrc1[] = "��";
	const char replacedest1[] = "���낤��";
	char* result1 = NULL;
	RESULT result = ��(src1, replacesrc1, replacedest1, &result1);
	printf("%s\n", result1);
	free(result1);


	const std::string src2 = "�����������̂����A�����������̂���";
	const std::string replacesrc2 = "��";
	const std::string replacedest2 = "���낤��";
	std::string result2;
	result = �V(src2, replacesrc2, replacedest2, result2);

	std::cout << result2 << std::endl;
}