#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1),cnt(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cnt[a[i]]++;
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1,1e15));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n/2;++j){
			if(!cnt[i]){
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
				continue;
			}
			if(j+cnt[i]<=n/2&&j+cnt[i]<=dp[i-1][j]){
				dp[i][j+cnt[i]]=min(dp[i][j+cnt[i]],dp[i-1][j]);
			}
			dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
		}
	}
	int ans=1e15;
	for(int i=0;i<=n/2;++i){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
