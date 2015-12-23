#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[26];
    bool isEnd;
    int maxSuffixLen; // for optimization, didn's show big improvement
    int minSuffixLen;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = false;
        maxSuffixLen = 0;
        minSuffixLen = 0x7fff;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = NULL;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        if (root == NULL)
            root = new TrieNode();
        TrieNode* cur = root;
        cur->maxSuffixLen = 0x7fff;
        cur->minSuffixLen = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (cur->child[word[i]-'a']==NULL)
            {
                cur->child[word[i]-'a'] = new TrieNode();
            }
            cur = cur->child[word[i]-'a'];
            cur->maxSuffixLen = max(cur->maxSuffixLen, (int)(word.length()-i));
            cur->minSuffixLen = min(cur->minSuffixLen, (int)(word.length()-i));
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }

    bool search(string word, int ith, TrieNode* cur) {
        if (cur != NULL && word.length()-ith+1 > cur->maxSuffixLen) return false;
        if (ith >= word.length()) return cur->isEnd;
        else if (cur == NULL) return false;
        else if (word.length()-ith+1 < cur->minSuffixLen) return false;
        else if (word[ith]=='.') {
            for (int i = 0; i < 26; i++)
            {
                if (cur->child[i]==NULL) continue;
                if (search(word, ith+1, cur->child[i])) return true;
            }
            return false;
        }
        else {
            if (cur->child[word[ith]-'a']==NULL) return false;
            return search(word, ith+1, cur->child[word[ith]-'a']);
        }
    }

    static void test()
    {
        string s, p;
        cin>>s;
        cin>>p;
        WordDictionary wd;
        wd.addWord(s);
        cout<<"result = "<<wd.search(p)<<endl;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");