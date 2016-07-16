#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;
//Well, this problem has a nice BFS structure.
//
//Let's see the example in the problem statement.
//
//start = "hit"
//
//end = "cog"
//
//dict = ["hot", "dot", "dog", "lot", "log"]
//
//Since only one letter can be changed at a time, if we start from "hit", we can only change to those words which have only one different letter from it, like "hot". Putting in graph-theoretic terms, we can say that "hot" is a neighbor of "hit".
//
//The idea is simpy to begin from start, then visit its neighbors, then the non-visited neighbors of its neighbors... Well, this is just the typical BFS structure.
//
//To simplify the problem, we insert end into dict. Once we meet end during the BFS, we know we have found the answer. We maintain a variable dist for the current distance of the transformation and update it by dist++ after we finish a round of BFS search (note that it should fit the definition of the distance in the problem statement). Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.
//
//The code is as follows.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<string> q;
        //将endWord加入wordList
        wordList.insert(endWord);
        //从wordList中删除beginWord,避免重复使用词beginWord
        wordList.erase(beginWord);
        //BFS
        helper(beginWord, wordList, q);
        int ret = 2;
        while (!q.empty()) {
            int size = q.size();
            //处理这一层的所有节点
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                //get end word
                if (word == endWord)
                    return ret;
                //BFS
                helper(word, wordList, q);
            }
            //节点全部处理完毕,层数加1
            ret++;
        }
        //没有找到结果,返回0
        return 0;
    }

private:
    void helper(string word, unordered_set<string> &wordList, queue<string> &q) {
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            for (int j = 0; j < 26; j++) {
                //可能的下一个单词
                word[i] = 'a' + j;
                //满足条件的下一个单词
                if (wordList.find(word) != wordList.end()) {
                    //加入这一层结果队列中
                    q.push(word);
                    //从字典中删除这个单词,避免重复
                    wordList.erase(word);
                }
            }
            //恢复word
            word[i] = ch;
        }
    }
};

int main() {
    Solution *s = new Solution();
    
}
