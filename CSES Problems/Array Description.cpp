#include<bits/stdc++.h>
#define MOD 1000000007;
#define pb push_back
#define ll long long
using namespace std;

int main()
{
	ll n, m;
	cin>>n>>m;
	vector<ll> x(n);
	for(int i=0;i<n;i++) cin>>x[i];
	ll dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	ll ans = 0;
	if(x[0]==0){
		for(int j=1;j<=m;j++){
			dp[1][j] = 1;
			ans +=1;
		}
	}
	else{
		dp[1][x[0]] = 1;
		ans += 1;
	}
	if(n>1) ans = 0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			ll prev_sum = 0;
			prev_sum += dp[i-1][j];
			prev_sum %= MOD;
			if(j-1>=0){
				prev_sum += dp[i-1][j-1];
				prev_sum %= MOD;
			}
			if(j+1<=m){
				prev_sum += dp[i-1][j+1];
				prev_sum %= MOD;
			}
			if(x[i-1]==0){
				dp[i][j] = prev_sum;
			}
			else if(x[i-1] != 0 and j == x[i-1]){
				dp[i][j] = prev_sum;
			}
			if(i==n){
				ans += dp[i][j];
				ans %= MOD;
			}
		}
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=m;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<ans<<endl;
}
