#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <map>
#include <vector>
using namespace std;


// BFS
// ToDo: Double-BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord==endWord) return 2;
        if (beginWord.empty() || endWord.empty()) return 0;
        int level = 1;
        queue<string> que;
        que.push(beginWord);
        wordDict.erase(beginWord);
        int count = 1;

        while(!que.empty() && wordDict.size() > 0)
        {
            string cur = que.front();
            que.pop();
            --count;
            //next word
            for (int i = cur.length()-1; i>=0; i--)
            {
                for (int j = 'a'; j <= 'z'; j++)
                {
                    if (j==cur[i]) continue;
                    string tmp = cur;
                    tmp[i]=j;
                    if (tmp == endWord) // get result
                        return level+1;
                    if (wordDict.find(tmp)!=wordDict.end())
                    {
                        que.push(tmp);
                        wordDict.erase(tmp);
                    }
                }
            }

            if (count==0)
            {
                ++level;
                count=que.size();
            }
        }
        return 0;
    }

    int ladderLength2(string beginWord, string endWord, unordered_set<string>& wordDict) { //分层广搜,两个队列分别表示相邻的两层
        if (beginWord==endWord) return 2;
        if (beginWord.empty() || endWord.empty()) return 0;
        int level = 1;
        queue<string> que[2];
        que[0].push(beginWord);
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        int ti = 0;
        bool hit = false;
        unordered_set<string> st;
        while(!que[ti].empty())
        {
            while(!que[ti].empty())
            {
                string cur = que[ti].front();
                que[ti].pop();
                
                //next word
                for (int i = cur.length()-1; i>=0; i--)
                {
                    for (int j = 'a'; j <= 'z'; j++)
                    {
                        if (j==cur[i]) continue;
                        string tmp = cur;
                        tmp[i]=j;
                        if (tmp == endWord) // get result
                        {
                            hit = true;
                            return level+1;
                        }
                        else if (wordDict.find(tmp)!=wordDict.end())
                        {
                            que[1-ti].push(tmp);
                            wordDict.erase(tmp);
                        }
                    }
                }
            }
            ++level;
            ti = 1-ti;
        }

        return 0;
    }

    int ladderLength3(string beginWord, string endWord, unordered_set<string>& wordDict) { //slower
        if (beginWord==endWord) return 2;
        if (beginWord.empty() || endWord.empty()) return 0;
        int level = 1;
        queue<string> que[2];
        que[0].push(beginWord);
        que[1].push(endWord);
        map<string,int> steps[2];
        steps[0][beginWord] = 1;
        steps[1][endWord] = 1;
        int ti = 0;
        int mmin = 0, hit = 0;
        while(!que[ti].empty())
        {
            string cur = que[ti].front();
            que[ti].pop();
            
            //next word
            for (int i = cur.length()-1; i>=0; i--)
            {
                for (int j = 'a'; j <= 'z'; j++)
                {
                    if (j==cur[i]) continue;
                    string tmp = cur;
                    tmp[i]=j;
                    if (ti==0 && tmp==endWord) return steps[ti][cur]+1;
                    else if (ti==1 && tmp==beginWord) return steps[ti][cur]+1;

                    if (steps[ti].find(tmp)==steps[ti].end()&&wordDict.find(tmp)!=wordDict.end()) // get result
                    {
                        if (steps[1-ti].find(tmp)!=steps[1-ti].end()&&(mmin==0||mmin>steps[ti][cur]+steps[1-ti][tmp]))
                        {
                            mmin=steps[ti][cur]+steps[1-ti][tmp];
                            hit |= (1<<ti);
                            if (hit==3) return mmin;
                        }
                        que[ti].push(tmp);
                        steps[ti][tmp] = steps[ti][cur]+1;
                        
                    }
                }
            }

            if (!(hit&(1<<(1-ti)))) // if one direction queue already hit the shortest, no need to expand it more
                ti=1-ti;
        }
        return 0;
    }

    static void test()
    {
        int n;
        string beginWord, endWord;
        unordered_set<string> wordDict;
        cin>>beginWord>>endWord>>n;
        for(int i = 0; i < n; i++)
        {
            string x;
            cin>>x;
            wordDict.insert(x);
        }

        Solution sol;
        cout<<"result="<<sol.ladderLength2(beginWord, endWord, wordDict)<<endl;
    }
};