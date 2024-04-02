#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

//top down approach
int dp[1000001];
int find_no_of_ways(int sum, vector<int>& coins, int n){
	if(sum==0){
		return 1;
	}
	if(sum < 0){
		return 0;
	}
	if(dp[sum] != -1){
		return dp[sum];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		if(sum >= coins[i]){
			int take = find_no_of_ways(sum-coins[i], coins, n);
			ans += take;
			ans %= MOD;
		}
	}
	return dp[sum] = ans;	
}


int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> coins;
    for(int i=0;i<n;i++){
    	int k;cin>>k;
    	coins.push_back(k);
    }
    memset(dp, -1, sizeof(dp));
    cout << find_no_of_ways(x, coins, n)<<endl;
 
    return 0;
}