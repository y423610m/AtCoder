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

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int n,l;
	cin>>n>>l;

	vector<string> vs(3*n);

	ll tmp = 3*n;
	repll(i,3*n){
		tmp  %= 3;
		rep(j,l){
			string s;
			if(i<tmp) s = "0";
			else if(i<2*tmp) s = "1";
			else s = "2";
			vs[i] += s;
		}
	} 

	rep(i,3*n){
		cout<<vs[i]<<endl;
	}

	return;
}

int main() {
	solve();
	return 0;
}
