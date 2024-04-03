#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

int main()
{
    int n;
    cin>>n;
    char sqr[n][n];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		char ch;
    		cin>>ch;
    		sqr[i][j] = ch;
    	}
    }
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    if(sqr[0][0]=='.'){
    	dp[0][0] = 1;
    }
    for(int j=1;j<n;j++){
    	if(sqr[0][j] == '.' and sqr[0][j-1]=='.'){
    		dp[0][j] = dp[0][j-1];
    	}
    }
    for(int i=1;i<n;i++){
    	if(sqr[i][0] == '.' and sqr[i-1][0]=='.'){
    		dp[i][0] = dp[i-1][0];
    	}
    }
    for(int i=1;i<n;i++){
    	for(int j=1;j<n;j++){
    		if(sqr[i][j] == '.'){
    			if(sqr[i][j-1]=='.'){
    				dp[i][j] += dp[i][j-1];
    				dp[i][j] %= MOD;
    			}
    			if(sqr[i-1][j]=='.'){
    				dp[i][j] += dp[i-1][j];
    				dp[i][j] %= MOD;
    			}
    		}
    	}
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}