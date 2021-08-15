#include "•¶š—ñ‚Ì•ªŠ„.h"
#include <iostream>

RESULT •¶š—ñ‚Ì•ªŠ„::‹Œ(const char* src, size_t srcSize, const char* delim)
{
	size_t len = strlen(src) + 1;
	char* tmp = (char*)malloc(len);
	if (tmp == NULL) {
		return RESULT::ERR;
	}
	strcpy_s(tmp, len, src);

	char* context = NULL;
	char* token = strtok_s(tmp, delim, &context);
	while (token != NULL) {
		if (token != NULL) {
			printf("%s\r\n", token);
		}
		token = strtok_s(NULL, delim, &context);
	}
	free(tmp);

	return RESULT::SUCCESS;
}

std::vector<std::string> •¶š—ñ‚Ì•ªŠ„::split(const std::string& src, const std::string& delim)
{
	std::vector<std::string> result;
	if (delim.size() == 0) {
		// ‹æØ‚è•¶š‚ª–³‚¢‚Æ‚«‚ÍA•ªŠ„‘ÎÛ‚Ì•¶š—ñ‚ğ‚»‚Ì‚Ü‚Ü•Ô‚·
		result.push_back(src);
	}
	else {
		size_t offset = 0;
		while (true) {
			auto pos = src.find(delim, offset);
			if (pos == std::string::npos) {
				// ‹æØ‚è•¶š‚ªŒ©‚Â‚©‚ç‚È‚¢ÅŒã‚Ì€–Ú
				result.push_back(src.substr(offset));
				break;
			}
			result.push_back(src.substr(offset, pos - offset));
			offset = pos + delim.length();
		}
	}

	return result;
}

RESULT •¶š—ñ‚Ì•ªŠ„::V(const std::string& src, const std::string& delims)
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
	for (const auto& word : wordlist) {
		std::cout << word << std::endl;
	}

	return RESULT::SUCCESS;
}

void •¶š—ñ‚Ì•ªŠ„::exec()
{
	const char word1[] = "abc efg\rhij\nklm\tnopq \r\n\trst";
	const char delim1[] = " \r\n\t";

	‹Œ(word1, sizeof(word1), delim1);

	const std::string word2 = "abc efg\rhij\nklm\tnopq \r\n\trst";
	const std::string delim2 = " \r\n\t";

	V(word2, delim2);
}
