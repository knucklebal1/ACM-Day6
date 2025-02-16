#include<bits/stdc++.h>
using namespace std;
const int x=1e5+5;
int W,n,v[x],w[x],m[x],cnt=0;
int dp[x];
int value[x],weight[x];

int main(){
	cin>>n>>W;
	for(int i=1;i<=n;++i){
		cin>>v[i]>>w[i]>>m[i];
		for(int j=1;j<=m[i];j<<=1){//j*2：二进制优化，把每种物体的数量m[i]拆分为若干个二进制组合，并将每个组合视为一个新物品（如，m[i]=10=1+2+4+3）
			value[++cnt]=j*v[i];//拆分后的每个新物体（包）价值，由于cnt初值为0，所以记录第一个包，++cnt
			weight[cnt]=j*w[i];////拆分后的每个新物体（包）重量，此时cnt已经更新
			m[i]-=j;
		}
		if(m[i]){//剩下的包（用上例，设有10件物体，此时m[i]=3）
			value[++cnt]=m[i]*v[i];
			weight[cnt]=m[i]*w[i];
		}
	}
	for(int i=1;i<=cnt;++i){//遍历所有的小包
		for(int j=W;j>=weight[i];--j){//为了保证不超重，用倒序，还原装包情况（空间逐渐减少）
			dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);//dp[j]：背包重量为j时的最大价值
		}
	}
	cout<<dp[W];
	return 0;
}
