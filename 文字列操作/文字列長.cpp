#include "•¶š—ñ’·.h"
#include <iostream>

RESULT •¶š—ñ’·::‹Œ(const char* word, size_t &len)
{
	len = strlen(word);
	return RESULT::SUCCESS;
}
RESULT •¶š—ñ’·::V(const std::string& word, size_t& len)
{
	len = word.size();
	len = word.length();	// ƒoƒbƒtƒ@ƒTƒCƒY‚È‚Ì‚Å•¶š—ñ’·‚Æ‚ÍˆÙ‚È‚é
	return RESULT::SUCCESS;
}

void •¶š—ñ’·::exec() 
{
	const char word1[] = "1234567890‚P‚Q‚R‚S‚T‚U‚V‚W‚X‚O";
	size_t len = 0;
	RESULT result = ‹Œ(word1, len);
	printf("%d\r\n", len);

	const std::string word2 = "1234567890‚P‚Q‚R‚S‚T‚U‚V‚W‚X‚O";
	len = 0;
	result = V(word2, len);
	std::cout << len << std::endl;
}
