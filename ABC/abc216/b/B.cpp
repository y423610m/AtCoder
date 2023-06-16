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

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

void solve() {

	int n; cin>>n;

	set<pair<string,string>> sp;
	rep(i,n){
		string s,t;
		cin>>s>>t;
		sp.insert(mp(s,t));
	}

	if(sp.size()==n) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
