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

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int n; cin>>n;
	vector<ll> a(n), b(n);
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];

	vector<vector<ll> > dp(3001, vector<ll>(3001));
	/*
	repi(i,a[0], b[0]+1){
		dp[0][i] = 1;
	}
	*/
	

	dp[0][a[0]]=1;

	repill(i,0,n+1){
		ll A = a[i];
		ll B = b[i];
		repll(j,300){
			//cout<<i<<" "<<j<<endl;
			if(j==A){
				ll sum = 0;
				//cout<<j<<"  a"<<endl;
				cout<<A<<endl;
				repll(k,A) sum = (sum+dp[i][k])%MOD;
				//cout<<"b"<<endl;
				dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1] + sum)%MOD;
			}
			else if(A<j && j<=B){
				dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1])%MOD;
			}
		}
		rep(k,10) cout<<dp[i][k];
		cout<<endl;
	}

	ll ans = 0;
	rep(i,3001) ans = (ans + dp[n+1][i])%MOD;
	cout<<ans<<endl;



	return;
}

int main() {
	solve();
	return 0;
}
