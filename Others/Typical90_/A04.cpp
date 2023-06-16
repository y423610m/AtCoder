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
const ll MOD = 998244353;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int h,w; cin>>h>>w;
	vector<vector<int> > HW(h,vector<int>(w));
	rep(i,h) rep(j,w) cin>>HW[i][j];

	vector<int> H(h), W(w);
	rep(i,h) rep(j,w) H[i] += HW[i][j];
	rep(j,w) rep(i,h) W[j] += HW[i][j];

	rep(i,h){
		rep(j,w) PS(H[i]+W[j]-HW[i][j])
		PL("")
	}

	return;
}

int main() {
	solve();
	return 0;
}
