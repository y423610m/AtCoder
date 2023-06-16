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

	int n; cin>>n;

	vector<int> A(n), B(n);
	rep(i,n)  cin>>A[i]>>B[i];

	double rlen = 0;
	double flen = 0;
	rep(i,n) rlen += 1.0*A[i];
	rep(i,n) flen += 1.0*A[i]/B[i];

	double rdis = 0.0;
	double fdis = 0.0;
	int i = 0;
	while(fdis<flen*0.5){
		fdis += 1.0*A[i]/B[i];
		rdis += 1.0*A[i];
		i++;
	}

	//putl(rdis)

	rdis += (flen*0.5-fdis)*B[i-1];
	putl(rdis)

	return;
}

int main() {
	solve();
	return 0;
}
