#include <iostream>
#include<vector>
#include<cstring>
#include<climits>
#define MOD 1000000007;
using namespace std;

// Top-down approach

// int dp[1000001];
// int no_of_ways(int n){
// 	if(n<1) return 0;
// 	if(n==1){
// 		return 1;
// 	}
// 	if(dp[n] != -1){
// 		return dp[n];
// 	}
// 	int ans = 0;
// 	int psbl1 = no_of_ways(n-1);
// 	ans += psbl1;
// 	ans %= MOD;
// 	int psbl2 = no_of_ways(n-2);
// 	ans += psbl2;
// 	ans %= MOD;
// 	int psbl3 = no_of_ways(n-3);
// 	ans += psbl3;
// 	ans %= MOD;
// 	int psbl4 = no_of_ways(n-4);
// 	ans += psbl4;
// 	ans %= MOD;
// 	int psbl5 = no_of_ways(n-5);
// 	ans += psbl5;
// 	ans %= MOD;
// 	int psbl6 = no_of_ways(n-6);
// 	ans += psbl6;
// 	ans %= MOD;
// 	if(n<=6){
// 		ans += 1;
// 	}
// 	ans %= MOD;
// 	return dp[n] = ans;

// }

// Bottom up approach

int no_of_ways(int n){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] += dp[i-1 > 0 ? i-1 : 0];
        dp[i] %= MOD;
        dp[i] += dp[i-2 > 0 ? i-2 : 0];
        dp[i] %= MOD; 
        dp[i] += dp[i-3 > 0 ? i-3 : 0];
        dp[i] %= MOD;
        dp[i] += dp[i-4 > 0 ? i-4 : 0];
        dp[i] %= MOD;
        dp[i] += dp[i-5 > 0 ? i-5 : 0];
        dp[i] %= MOD;
        dp[i] += dp[i-6 > 0 ? i-6 : 0];
        dp[i] %= MOD;
        if(i<=6){
            dp[i] += 1;
        }
        dp[i] %= MOD;
    }
    return dp[n];
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	// memset(dp, -1, sizeof(dp));
	int ans = no_of_ways(n);
	cout<<ans<<endl;
	return 0;
}