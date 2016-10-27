#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    //26个字母，对应26个小写字母
    const static int NUM = 26;

    TrieNode() :
            end_(false),
            links(NUM, nullptr) {

    }

    ~TrieNode() {
        for (auto ptr:links) {
            if (ptr != nullptr) {
                delete ptr;
            }
        }
    }

    bool containsKey(char ch) const{
        return links[ch - 'a'] != nullptr;
    }

    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node) {
       
        links[ch - 'a'] = node;
    }

    //是终端结点，但是不一定是前缀树的叶子结点
    void setEnd() {
        end_ = true;
    }

    bool isEnd() const{
        return end_;
    }

private:
    vector<TrieNode *> links;
    bool end_;

};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode * cur = root;
        for (auto ch:word) {
            if(!cur->containsKey(ch)){
                cur->put(ch,new TrieNode());
            }
            cur = cur->get(ch);
        }
        cur->setEnd();
    }

    TrieNode * searchPrefix(string prefix){
        TrieNode * cur = root;
        for(auto ch:prefix){
            if(cur->containsKey(ch)){
                cur = cur->get(ch);
            }
            else{
                return nullptr;
            }
        }
        return cur;
    }

    bool startsWith(string prefix){
       return searchPrefix(prefix) != nullptr;
    }


    bool search(string word){
        TrieNode * end = searchPrefix(word);
        return end!=nullptr && end->isEnd();
    }

    ~Trie(){
        delete root;
    }
private:
    TrieNode *root;
};


int main() {
    
    return 0;
}

