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

	string ns;
	cin>>ns;

	string l,r;

	sort(ALL(ns));

	l += ns[ns.size()-1];
	r += ns[ns.size()-2];
	ns.erase(ns.size()-2);

	reverse(ALL(ns));

	ll ret = 1;
	rep(i,ns.size()){
		if(ns[i]=='0') ret *= 10;
		else{
			if(stoi(l)>stoi(r)) r += ns[i];
			else l += ns[i];
		}
	}

	ret *= stoi(l);
	ret *= stoi(r);

	cout<<ret<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
