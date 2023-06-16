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

	int n; cin>>n;
	vector<pair<int,int> > vp(n);
	vector<int> s(n);
	rep(i,n) cin>>vp[i].first>>vp[i].second>>s[i];

	sort(ALL(vp), [](pair<int,int> a, pair<int,int> b){
		return a.second<=b.second;
	});

	int ans = 0;
	int last = 0;
	rep(i,n){
		if()
	}


	return;
}

int main() {
	solve();
	return 0;
}
