#include <iostream>
using namespace std;

// #unique paths from (1,1) to (m,n) is C(m+n-2, n-1)
class Solution {
public:
    long long uniquePaths(int m, int n) {
        if (n==1||m==1) return 1;

		long long C[201][101] = {0};
		C[0][0] = 1LL;
		for (int i = 1; i <= m+n-2; i++)
			C[i][0] = C[i][i] = 1LL;
		for (int i = 1; i <= m+n-2; i++)
			for (int j = 1; j <= n-1 && j < i; j++)
			{
				C[i][j] = (C[i-1][j]+C[i-1][j-1]);
			}
		
		return C[m+n-2][n-1];
    }

	static void test() {
		int m, n;
		while (cin>>m>>n)
		{
			Solution sol;
			cout<<"result="<<sol.uniquePaths(m,n)<<endl;
		}
	}
};