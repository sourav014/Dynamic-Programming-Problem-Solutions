#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define ll long long
using namespace std;

int main()
{
	ll t;
	cin>>t;
	vector<vector<ll>> dp(1e6+1, vector<ll>(2));
	while(t--){
		ll n;
		cin>>n;
		dp[n][0] = 1;
		dp[n][1] = 1;

		for(int i=n-1;i>=1;i--){
			dp[i][0] = (2ll * dp[i+1][0] + dp[i+1][1])%MOD;
			dp[i][1] = (4ll *dp[i+1][1] + dp[i+1][0])%MOD;
		}
		ll ans = dp[1][0] + dp[1][1];
		ans %= MOD;
		cout<<ans<<endl;
	}
}
