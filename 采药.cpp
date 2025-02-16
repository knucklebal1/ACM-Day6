#include<bits/stdc++.h>
using namespace std;
int T,M; 
int t[105],m[105],dp[105][1005];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	T=read(),M=read();
	memset(dp,0,sizeof(dp));//将所有单元格初始化为0
	for(int i=1;i<=M;++i){
		t[i]=read(),m[i]=read();
	}
	for(int i=1;i<=M;++i){
		for(int j=1;j<=T;++j){
			if(t[i]>j){//时间超出，不采
				dp[i][j]=dp[i-1][j];//dp[i][j]：只能装前i株草药，时间为j时包中草药的最大价值
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+m[i]);
			}
		}
	}
	cout<<dp[M][T];
	
	return 0;
}
