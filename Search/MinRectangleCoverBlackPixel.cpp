#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

/*Problem:
Smallest Rectangle Enclosing Black Pixels (Medium)

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:
[
  "0010",
  "0110",
  "0100"
]

and x = 0, y = 2, 
Return 6.

Solution: 1)bloodfill OR BFS; 2)binary search
*/

class Solution { 
public:
    int n,m;
    int minx,maxx,miny,maxy;
    
    // bloodfill O(n*m)
    int minArea2(vector<vector<char>> image, int x, int y) {
        minx=maxx=x;
        miny=maxy=y;
        n=image.size();
        if(n==0) return 0;
        m=image[0].size();
        if(m==0) return 0;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        search(image,visited,x,y);
        return (maxy-miny+1)*(maxx-minx+1);
    }
    
    void search(vector<vector<char>> &image, vector<vector<bool>> &visited, int x, int y) {
        if(x<0||x>=n||y<0||y>=m||visited[x][y]||image[x][y]!='1') return;
        visited[x][y]=true;
        minx=min(minx,x);
        maxx=max(maxx,x);
        miny=min(miny,y);
        maxy=max(maxy,y);
        
        search(image, visited, x-1, y);
        search(image, visited, x, y+1);
        search(image, visited, x+1, y);
        search(image, visited, x, y-1);    
    }
    
    //binary search O(logn+logm)
    int minArea(vector<vector<char>> image, int x, int y) {
        n=image.size();
        if(n==0) return 0;
        m=image[0].size();
        if(m==0) return 0;
        
        int left=bisearchCol(image,0,y,true); //left most 1
        int right=bisearchCol(image,y+1,m,false); //first 0 at right
        int top=bisearchCol(image,0,x,true); //top most 1
        int bottom=bisearchCol(image,x+1,n,false); //first 0 at bottom
        return (right-left)*(bottom-top);
    }
    
    int bisearchCol(vector<vector<char>> image, int start, int end, bool left) {
        int row=n;
        while (start<end) {
            int mid=start+(end-start)/2;
            int k=0;
            while(k<row&&image[k][mid]=='0') ++k;
            if((k<row)==left)
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
    
    int bisearchRow(vector<vector<char>> image, int start, int end, bool top) {
        int col=m;
        while (start<end) {
            int mid=start+(end-start)/2;
            int k=0;
            while(k<col&&image[mid][k]=='0') ++k;
            if((k<col)==top)
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
    
    static void test() {
        int r,c,x,y;
        string str;
        vector<vector<char>> image;
        Solution sol;
        while(cin>>r>>c) {
            cin.get();
            for(int i=0;i<r;++i) {
                getline(cin,str);
                vector<char> tmp;
                for(int j=0;j<c;++j) {
                    tmp.push_back(str[j]);
                }
                image.push_back(tmp);
            }
            cin>>x>>y;
            cout<<"ans="<<sol.minArea(image,x,y)<<endl;
        }
    }
};
