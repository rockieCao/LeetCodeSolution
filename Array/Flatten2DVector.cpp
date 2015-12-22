#include<iostream>
#include<vector>
using namespace std;

/* Problem: Flatten 2D vector
Implement an iterator to flatten a 2d vector.

For example, Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
] 
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
*/

class Vector2D {
private:
    vector<vector<int>::iterator> itstart;
    vector<vector<int>::iterator> itend;
    int cur;
    
public:
    Vector2D(vector<vector<int>> vec2d) {
        for(int i=0;i<vec2d.size();++i) {
            itstart.push_back(vec2d[i].begin());
            itend.push_back(vec2d[i].end());   
        }
        cur = 0;
    }

    int next() {
        int ret=*(itstart[cur]);
        if(itstart[cur]==itend[cur]) ++cur;
        return ret;
    }
    
    bool hasNext() {
        return cur<itstart.size()&&itstart[cur]!=itend[cur];
    }
};
