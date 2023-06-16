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

ll power(ll a, ll b){
	ll ret = 1;
	rep(i,b) ret *= a;
	return ret;
}

void solve() {

	int k;
	string sa,sb;
	cin>>k>>sa>>sb;

	ll a=0, b=0;

	repll(i,sa.size()){
		a += power(k,i) * int(sa[sa.size()-i-1]-'0');
	}
	repll(i,sb.size()){
		b += power(k,i) * int(sb[sb.size()-i-1]-'0');
	}

	cout<<a*b<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
