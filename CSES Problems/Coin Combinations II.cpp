#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

//top down approach
// int dp[101][1000001];
// int find_no_of_ways(int sum, int idx, vector<int>& coins, int n){
// 	if(sum==0){
// 		return 1;
// 	}
// 	if(sum < 0){
// 		return 0;
// 	}
// 	if(idx >= n){
// 		return 0;
// 	}
// 	if(dp[idx][sum] != -1){
// 		return dp[idx][sum];
// 	}
// 	int ans = 0;
// 	if(sum >= coins[idx]){
// 		ans += find_no_of_ways(sum - coins[idx], idx, coins, n);
// 		ans %= MOD;
// 	}
// 	ans += find_no_of_ways(sum, idx+1, coins, n);
// 	ans %= MOD;
// 	return dp[idx][sum] = ans;
// }

//bottom up approach
int find_no_of_ways(int x, vector<int>& coins, int n){
	int dp[n+1][x+1];
	// memset(dp, 0, sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int sum=0;sum<=x;sum++){
			if(sum==0){
				dp[i][sum] = 1;
			}
			else{
				int op1 = (sum >= coins[i]) ? dp[i][sum-coins[i]] : 0;
				int op2 = (i==1) ? 0 : dp[i-1][sum];
				dp[i][sum] = (op1 + op2) % MOD;
			}
		}
	}
    return dp[n][x];
}


int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> coins(n+1);
    for(int i=1;i<=n;i++){
    	int k;cin>>k;
    	coins[i] = k;
    }
    // memset(dp, -1, sizeof(dp));
    cout<<find_no_of_ways(x, coins, n)<<endl;
}