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

	int n; cin>>n;
	vector<int> vi(n);
	rep(i,n) cin>>vi[i];
	ll x;
	cin>>x;

	ll sum = 0;
	rep(i,n) sum += vi[i];

	ll ret = n * (x/sum);
	x -= sum * (x/sum);

	int i = 0;
	while(x>=0){
		x -= vi[i];
		ret++;
		i++;
	}

	cout<<ret<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
