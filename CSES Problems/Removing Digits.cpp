#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;
set<int> find_digits(int no){
	set<int> st;
	while(no){
    	int digit = no%10;
    	if(digit != 0){
			st.insert(digit);
		}
    	no /= 10;
    }
    return st;
}

int main()
{
    int n;
    cin>>n;
    if(n<=9){
    	cout<<1<<endl;
    	return 0;
    }
    int no = n;
    int dp[n+1] = {0};
    for(int i=1;i<=9;i++){
    	dp[i] = 1;
    }
    for(int i=10;i<=n;i++){
    	set<int> st = find_digits(i);
    	if(st.size()==1){
    		dp[i] = 1 + dp[i-*st.begin()];
    	}
    	else{
    		int ans = INT_MAX;
    		for(auto k: st){
    			ans = min(ans, dp[i-k]);
    		}
    		dp[i] = 1 + ans;
    	}
    }
    cout<<dp[n]<<endl;
    return 0;
}