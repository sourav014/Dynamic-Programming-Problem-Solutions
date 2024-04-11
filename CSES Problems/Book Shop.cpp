#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;
int price[1001];
int pages[1001];
// int dp[1001][100001];

// top down approach
// int find_max_no_pages(int x, int idx, int n){
// 	if(idx>=n){
// 		return 0;
// 	}
// 	if(dp[idx][x] != -1){
// 		return dp[idx][x];
// 	}
// 	int take = 0;
// 	if(x >= price[idx]){
// 		take = pages[idx] + find_max_no_pages(x-price[idx], idx+1, n);
// 	}
// 	int skip = find_max_no_pages(x, idx+1, n);
// 	return dp[idx][x] = max(take, skip);
// }

// bottom-up approach
int find_max_no_pages(int x, int n){
	int dp[n+1][x+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j >= price[i-1]){
				dp[i][j] = max(pages[i-1] + dp[i-1][j-price[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][x];
}

int main()
{
    int n, x;
    cin>>n>>x;
    memset(price, 0, sizeof(price));
    memset(pages, 0, sizeof(pages));
    // memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
    	cin>>price[i];
    }
    for(int i=0;i<n;i++){
    	cin>>pages[i];
    }
    int ans = find_max_no_pages(x, n);
    cout<<ans<<endl;
}