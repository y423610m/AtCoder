#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define rrep(i, a, n) for (int i = (int)(a); i > (int)(n); i--)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define rrepll(i, a, n) for (ll i = (ll)(a); i > (ll)(n); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

void solve() {

	int n; cin>>n;
	vector<int> vi(n);
	rep(i,n) cin>>vi[i];

	vector<vector<ll>> dp(n, vector<ll>(10));
	dp[0][vi[0]] = 1;
	rep(i,n-1){
		ll tmp = vi[i+1];
		//+
		repll(j,10){
			dp[i+1][(j+tmp)%10] += dp[i][j];
		}
		//*
		repll(j,10){
			dp[i+1][(j*tmp)%10] += dp[i][j];
		}
		rep(j,10) dp[i+1][j] %= MOD;
	}

	rep(i,10){
		cout<<dp[n-1][i]<<endl;
	}

	return;
}

int main() {
	solve();
	return 0;
}
