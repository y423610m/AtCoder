#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).begin(),(a).end()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 1e9+7;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int n; cin>>n;
	string s; cin>>s;

	string t = " atcoder";
	vector<int> dp(t.size());
	dp[0]=1;

	rep(i,n){
		rep(j,t.size()){
			if(s[i]==t[j]){
				dp[j]+=dp[j-1];
				dp[j]%=MOD;
			}
		}
	}

	PL(dp.back())

	return;
}

int main() {
	solve();
	return 0;
}
