#include "文字列の検索.h"
#include <iostream>
#include <vector>

RESULT 文字列の検索::旧(const char* src, const char* searchword)
{
	if (src == NULL || searchword == NULL) {
		// invalid arguments
		return RESULT::ERR;
	}

	const char* tmp1 = src;
	do {
		const char* tmp2 = strstr(tmp1, searchword);
		if (tmp2 != NULL) {
			printf("There is word[%s] in %d character of searchword[%s].\r\n", tmp1, (tmp2 - tmp1), searchword);
			tmp1 = tmp2 + strlen(searchword);
		}
		else {
			printf("word[%s] is not in searchword[%s].\r\n", tmp1, searchword);
			tmp1 = NULL;
		}
	} while (tmp1 != NULL);

	return RESULT::SUCCESS;
}

RESULT 文字列の検索::新(const std::string &src, const std::string &searchword)
{
	size_t pos1 = 0;

	do {
		size_t pos2 = src.find(searchword, pos1);
		if (pos2 != std::string::npos) {
			std::cout << "Word[" << src << "] Search for searchword[" << searchword << "]. There is in posision " << pos2 << " character." << std::endl;
			pos1 = pos2 + searchword.length();
		}
		else {
			std::cout << "word[" << src << "] is not in searchword[" << searchword << "]." << std::endl;
			pos1 = pos2;
		}
	} while (pos1 != std::string::npos);

	return RESULT::SUCCESS;
}


void 文字列の検索::exec()
{
	const char src1[] = "李も桃も桃のうち、桃も李も桃のうち";
	const char delim1[] = "も";

	RESULT result = 旧(src1, delim1);

	const std::string src2 = "李も桃も桃のうち、桃も李も桃のうち";
	const std::string delim2 = "も";

	result = 新(src2, delim2);

}
