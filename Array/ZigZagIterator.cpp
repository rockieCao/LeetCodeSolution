#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ZigzagIterator{
public:
    ZigzagItertor(vector<int> &v1, vector<int> &v2) {
        itlist.push_back(v1.begin());
        itlist.push_back(v2.begin());
        endlist.push_back(v1.end());
        endlist.push_back(v2.end());
        cur=0;
    }
    
    int next() {
        if (!hasNext()) return 0;
        int ret=*(itlist[cur]);
        if(itlist[cur]==endlist[cur]) {
            itlist.erase(itlist.begin()+cur);
            endlist.erase(endlist.begin()+cur);
            --cur;
        }
        cur=(cur+1)%itlist.size();
        return ret;
    }
    
    bool hasNext() {
        return itlist.size()>0;
    }
private:
    int cur;
    vector<vector<int>::iterator> itlist;
    vector<vector<int>::iterator> endlist;
};

