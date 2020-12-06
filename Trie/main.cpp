#include "Trie.h"
#include "BMmatch.h"

// BMMatch
//int main()
//{
//	//             0....+....1....+....
//	string text = "abacaabadcabacabaabb";
//	string pattern = "abacab";
//
//	int ret = BMmatch(text, pattern);
//
//	cout << ret << endl;
//
//	return 1;
//}

// Trie
int main(void)
{
	Trie* trie = new Trie();

	trie->insert("HELLO");
	trie->insert("HELL");
	trie->insert("HALL");
	trie->insert("HALO");
	trie->insert("TRAVEL");

	delete trie;

	return 0;
}
