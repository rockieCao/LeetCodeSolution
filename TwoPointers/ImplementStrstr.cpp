#include<iostream>
using namespace std;

class Solution {
public:
    int strStr2(char *haystack, char *needle) { //normal method: BF
        if (haystack==NULL || needle==NULL) return -1;
        char *start = haystack, *cur = haystack, *ptr = needle;
        while ( (*cur)!='\0' && (*ptr)!='\0')
        {
            if ((*cur)==(*ptr))
            {
                ++cur;
                ++ptr;
            }
            else
            {
                ptr = needle;
                cur = start+1;
                start = cur;
            }

        }
        if ((*ptr) == '\0')
        {
            return start-haystack;
        }
        else
            return -1;
    }

    int strStr(char *haystack, char *needle) { // KMP
        if (haystack==NULL || needle==NULL) return -1;

        int len_Hay = strlen(haystack), len_Nee = strlen(needle);
        int i = 0, j = 0;
        
        int *next = new int[len_Nee];
        getNext(needle, next);

        while (i < len_Hay && j < len_Nee)
        {
            if (j == -1 || haystack[i]==needle[j])
            {
                ++i;
                ++j;
            }
            else
                j = next[j];
        }

        if (j >= len_Nee)
            return i - len_Nee;
        else
            return -1;
    }

    void getNext(char *p, int *next) {
        int j = 0, k = -1, n = strlen(p);
        next[0] = -1;

        while (j < n-1)
        {
            if (k==-1 || p[j]==p[k])
            {
                ++k;
                ++j;
                next[j]=k;
            }
            else
            {
                k = next[k];
            }
        }
    }

    static void test() {
        char haystack[100], needle[100];
        cin>>haystack>>needle;
        Solution sol;
        cout<<"result="<<sol.strStr(haystack, needle)<<endl;
    }
};