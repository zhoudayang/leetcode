//key idea: TrieTree and dfs 
class TrieNode
{
public:
	const static int NUM = 26;

	TrieNode() :end_(false), nodes_(NUM, nullptr), keys_() {}

	bool containsKey(char ch) const
	{
		return nodes_[ch - 'a'] != nullptr;
	}

	void put(char ch, TrieNode * node)
	{
		nodes_[ch - 'a'] = node;
		keys_.insert(ch);
	}

	TrieNode * get(char ch)
	{
		return nodes_[ch - 'a'];
	}

	void setEnd()
	{
		end_ = true;
	}

	bool isEnd() const
	{
		return end_;
	}

	set<char> keys() const
	{
		return keys_;
	}

private:
	bool end_;
	vector<TrieNode *> nodes_;
	set<char> keys_;

};



class WordDictionary {
public:
	WordDictionary() :
		root(new TrieNode) {}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode * cur = root;
		for (auto ch : word)
		{
			if (!cur->containsKey(ch))
			{
				cur->put(ch, new TrieNode);
			}
			cur = cur->get(ch);
		}
		cur->setEnd();
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return helper(word, root);
	}

private:
	//an helper function use dfs algorithm 
	bool helper(string word, TrieNode * cur)
	{
		if (word.empty())
			return cur->isEnd();
		char ch = word.front();
		if (ch != '.')
		{
			if (!cur->containsKey(ch))
				return false;
			return helper(word.substr(1), cur->get(ch));
		}
		else
		{
			set<char> keys = cur->keys();
			if (keys.empty())
				return false;
			for (auto ch : keys)
			{
				if (helper(word.substr(1), cur->get(ch)))
					return true;
			}
			return false;
		}
	}
	TrieNode * root;
};