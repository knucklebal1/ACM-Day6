#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a,dp[N],ans=INT_MIN;//遇到需要考虑负数的求最值情况，（求最大值赋INT_MIN;求最小值赋INT_MAX），这样有操作空间；如果不考虑负数，初值赋0

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a;
		if(dp[i-1]>0){
			dp[i]=dp[i-1]+a;
		}else{
			dp[i]=a;
		}
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
