#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

	ll n,x;
	cin>>n>>x;
	vector<ll> vll(n);
	rep(i,n) cin>>vll[i];

	sort(ALL(vll));
	reverse(ALL(vll));

	ll ans = 0;

	//queue<int, int> que;

	rep(i,n){
		if(x<=0) continue;
		if(x>vll[i]){
			ans += x/vll[i];
			x -= vll[i]*(x/vll[i]);
		}
		if(i!=n-1&&abs(vll[i]-x)<(vll[i+1]-x)){
			ans++;
			x -= vll[i];
		}
	}

	x = abs(x);

	rep(i,n){
		ans += x/vll[i];
		x -= vll[i]*(x/vll[i]);
		PS(vll[i])PS(x)PL(ans)
	}

	PL(ans)

	return;
}

int main() {
	solve();
	return 0;
}
