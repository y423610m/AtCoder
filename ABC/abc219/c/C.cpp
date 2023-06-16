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
	string x; cin>>x;
	map<char, int> mp;
	rep(i,26) mp[x[i]] = i;
	
	int n; cin>>n;
	vector<pair<string, string>> names(n);
	rep(i,n){
		string tmp;
		cin>>tmp;
		names[i].first = tmp;
		names[i].second = tmp;
	}


	rep(i,n){
		rep(j,names[i].first.size()){
			names[i].first[j] = 'a'+mp[names[i].first[j]];
		}
	}

	sort(ALL(names));


	rep(i,n) cout<<names[i].second<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
