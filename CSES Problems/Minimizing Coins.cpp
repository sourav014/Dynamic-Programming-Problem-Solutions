#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

//top down approach
int dp[1000001];
int find_min_coins(int sum, vector<int>& coins, int n){
	if(sum==0){
		return 0;
	}
	int res = INT_MAX;

	if(dp[sum] != -1){
		return dp[sum];
	}

	for(int i=0;i<n;i++){
		if(sum >= coins[i]){
			int take = find_min_coins(sum-coins[i], coins, n);
			if(take != INT_MAX){
				res = min(1 + take, res);
			}
		}
	}
	return dp[sum] = res;
}


int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n>>x;
	vector<int> coins;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		coins.push_back(k);
	}
	memset(dp, -1, sizeof(dp));
	int ans = find_min_coins(x, coins, n);
	if(ans == INT_MAX){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}