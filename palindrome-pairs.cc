/*
	1. Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

	2. Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] concatenate("a", ""), so as to cover the other situation concatenate("", "a"), I need to traverse the words array again, find the palindrome word candidate except "" itself, and add pair("", palindrome word) to the final answer.

	3. Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. 2) same for checking the right side of current word: candidate | left | right.
*/
class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    unordered_map<string, int> dict;
    vector<vector<int>> result;
    for (int i = 0; i < words.size(); ++i) {
      string word = words[i];
      reverse(word.begin(), word.end());
      dict[word] = i;
    }
    if (dict.find("") != dict.end()) {
      for (int i = 0; i < words.size(); ++i) {
        if (words[i] != "") {
          if (is_palindrome(words[i]))
            result.push_back({dict[""], i});
        }
      }
    }
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].size(); ++j) {
        string left = words[i].substr(0, j);
        string right = words[i].substr(j);
        if (dict.find(left) != dict.end() and is_palindrome(right) and dict[left] != i) {
          result.push_back({i, dict[left]}); // left right reverse_left
        }
        if (dict.find(right) != dict.end() and is_palindrome(left) and dict[right] != i) {
          result.push_back({dict[right], i}); //reverse_right left right 
        }
      }
    }
    return result;
  }
 private:
  bool is_palindrome(const string &input) const {
    return string(input.rbegin(), input.rend()) == input;
  }
};
