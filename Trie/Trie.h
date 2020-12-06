#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie
{
	bool finish;
	Trie* nextNode[26];	// 26°³ ¾ËÆÄºª
public:
	Trie()
	{
		finish = false;
		memset(nextNode, 0, sizeof(nextNode));
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (nextNode[i])
				delete nextNode[i];
		}
	}
	void insert(const char* key)
	{
		if (*key == '\0')
			finish = true;
		else
		{
			int next = *key - 'A';
			if (nextNode[next] == NULL)
				nextNode[next] = new Trie;
			nextNode[next]->insert(key + 1);
		}
		return;
	}
	Trie* find(const char* key)
	{
		if (*key == 0)
			return this;

		int next = *key - 'A';
		if (nextNode[next] == NULL)
			return NULL;
		return nextNode[next]->find(key + 1);
	}

};