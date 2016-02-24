#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*Problem: Self Crossing
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise. 

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not. 
Example 1:

Given x = [2, 1, 1, 2],
┌───┐
│      │
└───┼──>
        │

Return true (self crossing)



Example 2:

Given x = [1, 2, 3, 4],
┌──────┐
│            │
│
│
└────────────>

Return false (not self crossing)



Example 3:

Given x = [1, 1, 1, 1],
┌───┐
│      │
└───┼>

Return true (self crossing)

Solution:
   Use two set to store horizontal lines and vertial lines. Then simulate the process and check whether self cross after each step.
   Optimization: To reduce the time used to check cross line, use a map to store horizontal/vertical lines and take y or x as key
                 use two sets to store above keys (one for x and the other for y)
*/

class Solution {
public:
    struct HLine{
        int s,e,y;
        HLine(int _s=0,int _e=0,int _y=0):s(_s),e(_e),y(_y){}
    };
    
    struct VLine{
        int s,e,x;
        VLine(int _s=0,int _e=0,int _x=0):s(_s),e(_e),x(_x){}
    };
    
    bool isSelfCrossing(vector<int>& num) {
        int n=num.size();
        if(n<4) return false;
        vector<HLine> hlines;
        vector<VLine> vlines;
        int x=0,y=0,xx,yy;
        for(int i=0; i<n; ++i) {
            int dir=i%4;
            xx=x, yy=y;
            if(dir==0) { //north
                yy+=num[i];
                if(hasHCross(hlines,vlines,y,yy,x)) return true;
                vlines.push_back(VLine(y,yy,x));
            }
            else if(dir==1) { //west
                xx-=num[i];
                if(hasVCross(vlines,hlines,xx,x,y)) return true;
                hlines.push_back(HLine(xx,x,y));
            }
            else if(dir==2) { //south
                yy-=num[i];
                if(hasHCross(hlines,vlines,yy,y,x)) return true;
                vlines.push_back(VLine(yy,y,x));
            }
            else if(dir==3) { //east
                xx+=num[i];
                if(hasVCross(vlines,hlines,x,xx,y)) return true;
                hlines.push_back(HLine(x,xx,y));
            }
            x=xx,y=yy;
        }
        return false;
    }
    
    bool hasHCross(vector<HLine>& hlines, vector<VLine>& vlines, int s, int e, int x) { // check whether current vertical line cross with other lines
        int n=hlines.size();
        for(int i=0;i<n-1;++i) { // n-1 here because no need to check previous line
            HLine line=hlines[i];
            if(x>=line.s&&x<=line.e&&line.y>=s&&line.y<=e) return true;
        }
        for(VLine& line:vlines) {
            if(line.x==x&&((line.s>=s&&line.s<=e)||(line.e>=s&&line.e<=e))) return true;
        }
        return false;
    }
    
    bool hasVCross(vector<VLine>& vlines, vector<HLine>& hlines, int s, int e, int y) { // check whether current horizontal line cross with other lines
        int n=vlines.size();
        for(int i=0;i<n-1;++i) { // no need to check previous line
            VLine line=vlines[i];
            if(y>=line.s&&y<=line.e&&line.x>=s&&line.x<=e) return true;
        }
        for(HLine& line:hlines) {
            if(line.y==y&&((line.s>=s&&line.s<=e)||(line.e>=s&&line.e<=e))) return true;
        }
        return false;
    }
};
