#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10, mod = 998244353;

typedef pair<int, int> PII;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0, dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		if(a[i] == a[i - 1]) {
			dp[i][1] = dp[i - 1][1];
		}
		if(a[i] == a[i - 2] + 1) {
			(dp[i][1] += dp[i - 1][0]) %= mod;
		}
	}
	cout << (dp[n][0] + dp[n][1]) % mod <<'\n';
}

signed main(){
	int t = 1;
	cin >> t;
	while (t --) solve();
	return 0;
}
