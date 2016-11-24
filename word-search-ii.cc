//dfs 使用TrieNode进行剪枝，通过标记#注明当前已经访问过的字符，通过设置TrieNode中的end标记来避免返回重复字符串。
class TrieNode {
 public:
  const static int NUM = 26;
  TrieNode() :
      links(NUM, nullptr),
      end_(false) {}
  bool containsKey(char ch) const {
    return links[ch - 'a'] != nullptr;
  }

  TrieNode *get(char ch) {
    return links[ch - 'a'];
  }

  void put(char ch, TrieNode *node) {
    links[ch - 'a'] = node;
  }

  void setEnd(bool isEnd) {
    end_ = isEnd;
  }

  bool isEnd() const {
    return end_;
  }

 private:
  vector<TrieNode *> links;
  bool end_;
};

class Trie {
 public:
  Trie() : root(new TrieNode) {}

  void insert(const string &word) {
    TrieNode *cur = root;
    for (auto ch:word) {
      if (!cur->containsKey(ch)) {
        cur->put(ch, new TrieNode);
      }
      cur = cur->get(ch);
    }
    cur->setEnd(true);
  }

  TrieNode *searchPrifix(const string &prefix) {
    TrieNode *cur = root;
    for (auto ch:prefix) {
      if (cur->containsKey(ch)) {
        cur = cur->get(ch);
      } else
        return nullptr;
    }
    return cur;
  }

  bool contains(const string &word) {
    TrieNode *cur = searchPrifix(word);
    return cur != nullptr and cur->isEnd();
  }

  bool startsWith(const string &prefix) {
    return searchPrifix(prefix) != nullptr;
  }

 private:
  TrieNode *root;

};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    Trie trie;
    for (auto word:words)
      trie.insert(word);
    vector<string> result;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        dfs(board, i, j, "", trie, result);
      }
    }

    return result;

  }

  void dfs(vector<vector<char>> &board, int x, int y, string prev, Trie &trie, vector<string> &result) {
    if (x < 0 or x >= board.size() or y < 0 or y >= board[0].size())
      return;
    char ch;
    if ((ch = board[x][y]) == '#')
      return;
    prev.push_back(board[x][y]);
    TrieNode *cur = trie.searchPrifix(prev);
    if (cur == nullptr)
      return;
    if (cur->isEnd()) {
      result.push_back(prev);
      cur->setEnd(false);
    }
    //使用'#'标明之前是否已经访问过这个字符
    board[x][y] = '#';
    dfs(board, x - 1, y, prev, trie, result);
    dfs(board, x + 1, y, prev, trie, result);
    dfs(board, x, y + 1, prev, trie, result);
    dfs(board, x, y - 1, prev, trie, result);
    board[x][y] = ch;
  }

};
