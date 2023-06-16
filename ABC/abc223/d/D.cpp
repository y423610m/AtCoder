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
#define puts(a) cout<<(a)<<" ";
#define putl(a) cout<<(a)<<endl;

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

	int n,m;
	cin>>n>>m;

	vector<pair<int, int> > vp(m);
	rep(i,m){ 
		int a,b;
		cin>>a>>b;
		a--; b--;
		vp[i].first = a;
		vp[i].second = b;
	}

	sort(ALL(vp));


	vector<pair<int, int> > ans(n); //num, dist
	rep(i,n){
		ans[i].first = i;
		ans[i].second = i;
	}


	rep(i,m){
		int a = vp[i].first;
		int b = vp[i].second;

		if(ans[a].second>ans[b].second){
			ans[b].second = ans[a].second + 1;
			cnt++;
		}
	}

	rep(i,n) swap(ans[i].first, ans[i].second);
	sort(ALL(ans));

	rep(i,n) puts(ans[i].second+1)
	putl("")
	return;

}

int main() {
	solve();
	return 0;
}
