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
	vector<int> A(n);
	rep(i,n) cin>>A[i];
	sort(ALL(A));

	int q; cin>>q;

	rep(i,q){
		int b; cin>>b;
		if(b<=A[0]) PL(abs(A[0]-b))
		else if(A[n-1]<=b) PL(abs(b-A[n-1]))
		else{
			auto it = lower_bound(ALL(A), b);
			//PS("it")PL(*it)
			PL(min(abs(*it-b),abs(*(it-1)-b)))
		}
	}

	return;
}

int main() {
	solve();
	return 0;
}
