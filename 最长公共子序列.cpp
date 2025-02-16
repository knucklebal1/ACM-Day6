#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N];
int dp[N],num[N];//dp[]存储该序列中，长度为i的上升子序列的最小末尾值
int ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]=i;//离散化，重新编译。如4 3 5 1 2→1 2 3 4 5，则4-1；3-2；5-3；1-4；2-5
	}//num[]为离散化标记数组，num[i]就是i离散化的结果
	for(int i=1;i<=n;++i){
		cin>>b[i];
		b[i]=num[b[i]];//a[]中第i项的值离散化后为num[b[i]]，如2 3 5 1 4→5 2 3 4 1，现在只要看第二个数组中最长不下降序列长度
	}
	for(int i=1;i<=n;++i){
		if(b[i]>dp[ans]){
			dp[++ans]=b[i];
		}else{
			int x=lower_bound(dp+1,dp+ans+1,b[i])-dp;
			dp[x]=b[i];
		}
	}
	cout<<ans;
	return 0;
}
