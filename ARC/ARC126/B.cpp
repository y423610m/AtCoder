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

	int n,m;
	cin>>n>>m;

	vector<pair<int,int> > vpi(m);
	rep(i,m) cin>>vpi[i].first>>vpi[i].second;

	sort(ALL(vpi));


	vector<int> dp(m+1, INF);
	int last_first = -1;
	int last_second = -1;
	rep(i,m){
		if(vp[i].first != last_first){
			*lower_bound(ALL(dp), vpi[i].second) = vpi[i].second;
			last_first = vpi[i].first;
			last_second = vpi[i].second;
		}
		else if(last){

		}
	}
	int ret = int(lower_bound(ALL(dp), INF)-dp.begin());



	cout<<ret<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
