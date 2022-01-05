#include "������̕���.h"
#include <iostream>

RESULT ������̕���::��(const char* src, size_t srcSize, const char* delim, CLList& result)
{
	size_t len = strlen(src) + 1;
	char* tmp = (char*)malloc(len);
	if (tmp == NULL) {
		return RESULT::ERR;
	}
	strcpy_s(tmp, len, src);

	char* context = NULL;
	/*
	* char* strtok_s(char* str, const char* delimiters, char** context);
	* str ���� delimiters�i��؂蕶���̃Z�b�g�j�̂P�������������āA���̕��������������ʒu�̃|�C���^��Ԃ��B
	* �Q�߂̈ȍ~��delimiters����������Ƃ��A����str��NULL�A���ڂŐݒ肳�ꂽ����context��n���B�icontext�͌Ăяo���ԂɈʒu�����i�[���邽�߂Ɏg�p�j
	* �߂�l
	*	str �Ō����������̃g�[�N���ւ̃|�C���^�[��Ԃ��܂��B �g�[�N����������Ȃ��ꍇ��NULL��Ԃ��܂��B �e�Ăяo���́A�Ԃ��ꂽ�g�[�N���̌�ɔ�������ŏ��̋�؂�L����null������u����������@�ŕύX����܂��B
	*/
	char* token = strtok_s(tmp, delim, &context);
	while (token != NULL) {
		if (token != NULL) {
			result.additem(token, strlen(token) + 1);
			//printf("%s\r\n", token);
		}
		token = strtok_s(NULL, delim, &context);
	}
	free(tmp);

	return RESULT::SUCCESS;
}

std::vector<std::string> ������̕���::split(const std::string& src, const std::string& delim)
{
	std::vector<std::string> result;
	if (delim.size() == 0) {
		// ��؂蕶���������Ƃ��́A�����Ώۂ̕���������̂܂ܕԂ�
		result.push_back(src);
	}
	else {
		size_t offset = 0;
		while (true) {
			auto pos = src.find(delim, offset);
			if (pos == std::string::npos) {
				// ��؂蕶����������Ȃ��Ō�̍���
				result.push_back(src.substr(offset));
				break;
			}
			result.push_back(src.substr(offset, pos - offset));
			offset = pos + delim.length();
		}
	}

	return result;
}

RESULT ������̕���::�V(const std::string& src, const std::string& delims, std::vector<std::string>& result)
{
	std::vector<std::string> wordlist;
	wordlist.push_back(src);
	for (const auto& delim : delims) {
		std::vector<std::string> tmplist;
		for (const auto& word : wordlist) {
			auto tmp = split(word, std::string(1, delim));
			if (tmp.size() > 0) {
				tmplist.insert(tmplist.end(), tmp.begin(), tmp.end());
			}
		}
		wordlist = tmplist;
	}
	result = wordlist;
	//for (const auto& word : wordlist) {
	//	std::cout << word << std::endl;
	//}

	return RESULT::SUCCESS;
}

void ������̕���::exec()
{
	std::cout << "������̕���" << std::endl;

	const char word1[] = "abc efg\rhij\nklm\tnopq \r\n\trst";
	const char delim1[] = " \r\n\t";
	CLList result1;
	��(word1, sizeof(word1), delim1, result1);
	ULONG cntMax = result1.getsize();
	for (ULONG i = 0; i < cntMax; i++) {
		CLList::Item* item = result1.getitem(i);
		printf("���F%s\r\n", (char*)item->val);
	}

	const std::string word2 = "abc efg\rhij\nklm\tnopq \r\n\trst";
	const std::string delim2 = " \r\n\t";
	std::vector<std::string> result2;

	�V(word2, delim2, result2);
	for (const auto& item : result2) {
		std::cout << "�V�F" << item <<  std::endl;
	}
}
