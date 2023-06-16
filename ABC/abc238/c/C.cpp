#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    	os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;

ll pow10(int n){
	ll ret = 1; 
	rep(i,n) ret *= 10;
	return ret;
}

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

void solve() {
	
	string s; cin>>s;
	ll n = stoll(s);

	if(n<10){
		END((1+n)*n/2)
	}

	ll ans = 0;
	rep(i,s.size()){

		ll left = 1;
		if(i==0) left=0;

		ll right = min(n,pow10(i+1)-1);
		right = right - pow10(i) + 1;
		//if(i==0) right += 1;
		right %= MOD;

		ll len = 1+right-left;
		//if(i==0) len--;
		len %= MOD;

		ans += (left+right)*len/2;
		ans %= MOD;
		//ES(left) ES(right) ES(len) EL(ans)
	}

	PL(ans)


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
