#include "文字列の分割.h"
#include <iostream>

RESULT 文字列の分割::旧(const char* src, size_t srcSize, const char* delim, CLList& result)
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
	* str から delimiters（区切り文字のセット）の１文字を検索して、その文字が見つかった位置のポインタを返す。
	* ２つめの以降のdelimitersを検索するとき、引数strをNULL、一回目で設定された引数contextを渡す。（contextは呼び出し間に位置情報を格納するために使用）
	* 戻り値
	*	str で見つかった次のトークンへのポインターを返します。 トークンが見つからない場合はNULLを返します。 各呼び出しは、返されたトークンの後に発生する最初の区切り記号にnull文字を置き換える方法で変更されます。
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

std::vector<std::string> 文字列の分割::split(const std::string& src, const std::string& delim)
{
	std::vector<std::string> result;
	if (delim.size() == 0) {
		// 区切り文字が無いときは、分割対象の文字列をそのまま返す
		result.push_back(src);
	}
	else {
		size_t offset = 0;
		while (true) {
			auto pos = src.find(delim, offset);
			if (pos == std::string::npos) {
				// 区切り文字が見つからない最後の項目
				result.push_back(src.substr(offset));
				break;
			}
			result.push_back(src.substr(offset, pos - offset));
			offset = pos + delim.length();
		}
	}

	return result;
}

RESULT 文字列の分割::新(const std::string& src, const std::string& delims, std::vector<std::string>& result)
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

void 文字列の分割::exec()
{
	std::cout << "文字列の分割" << std::endl;

	const char word1[] = "abc efg\rhij\nklm\tnopq \r\n\trst";
	const char delim1[] = " \r\n\t";
	CLList result1;
	旧(word1, sizeof(word1), delim1, result1);
	ULONG cntMax = result1.getsize();
	for (ULONG i = 0; i < cntMax; i++) {
		CLList::Item* item = result1.getitem(i);
		printf("旧：%s\r\n", (char*)item->val);
	}

	const std::string word2 = "abc efg\rhij\nklm\tnopq \r\n\trst";
	const std::string delim2 = " \r\n\t";
	std::vector<std::string> result2;

	新(word2, delim2, result2);
	for (const auto& item : result2) {
		std::cout << "新：" << item <<  std::endl;
	}
}
