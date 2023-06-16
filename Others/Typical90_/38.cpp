#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;
const ll POW18 = 1000000000000000000;

void solve() {
	ll a,b;
	cin>>a>>b;

	ll ans = lcm(a,b);

	
	//if(b/gcd(a,b)<=1e18/a && max(a,b)<=ans&&ans<=1e18) PL(ans)
	//else PL("Large")

	ll r = b/gcd(a,b);
	if(r>POW18/a) PL("Large")
	else PL(r*a)

	EL(ans)

	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}
