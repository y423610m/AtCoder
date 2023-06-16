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
	int h,w;
	cin>>h>>w;

	vector<vector<int> > A(h);
	rep(i,h) rep(j,w) {
		int tmp;
		cin>>tmp;
		A[i].push_back(tmp);
	}

	bool ok = true;
	rep(i,A.size()-1){
		rep(j, A[i].size()-1){
			if(A[i][j]+A[i+1][j+1]>A[i][j+1]+A[i+1][j]) ok = false;
		}
	}

	if(ok) putl("Yes")
	else putl("No")



	return;
}

int main() {
	solve();
	return 0;
}
