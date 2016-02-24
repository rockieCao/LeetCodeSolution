#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area=(D-B)*(C-A)+(H-F)*(G-E);
        int lx=max(A,E), ly=max(B,F), rx=min(C,G),ry=min(D,H);
        if(ry<=ly||rx<=lx) return area;
        else return area-(rx-lx)*(ry-ly);
    }
};
