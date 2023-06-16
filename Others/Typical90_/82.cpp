#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

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
#define END(a) if(1){PL(a) return;}

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

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}


template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using P = pair<int, int>;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 1000000007;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

ull pow10(int a){
	ull ret = 1;
	rep(i,a) ret *= 10;
	return ret;
}



void solve() {
	
	ull L,R; cin>>L>>R;

	modint1000000007 ans = 0;
	rep(i,19){
		if( max(pow10(i),L) > min(pow10(i+1)-1ULL,R) ) continue;

		ull l = max(pow10(i),L);
		ull r = min(pow10(i+1)-1,R);
		ull len = r-l+1;
        r %= MOD;
        l %= MOD;
		len %= MOD;

		modint1000000007 tmp = ((modint1000000007)l+r)*len/2;
		tmp *= i+1;

		ans += tmp;

		ES(l) ES(r) ES(tmp.val()) EL(ans.val())

	}

	PL(ans.val())

	return;
}

// void solve2(){
// 	ll L,R; cin>>L>>R;
// 	L--;
// 	ll lans = 0;
// 	rep(i,19){
// 		if(L<pow10(i)) break;

// 		ll l = pow10(i);
// 		ll r = min(pow10(i+1)-1, L);
// 		ll len = r-l+1;
// 		l %= MOD;
// 		r %= MOD;
// 		len %= MOD;

// 		ll tmp = (l+r)*len/2;
// 		tmp *= i+1;
// 		lans += tmp;
// 	}

// 	ll rans = 0;
// 	L = R;
// 	rep(i,19){
// 		if(L<pow10(i)) break;

// 		ll l = pow10(i);
// 		ll r = min(pow10(i+1)-1, L);
// 		ll len = r-l+1;
// 		l %= MOD;
// 		r %= MOD;
// 		len %= MOD;

// 		ll tmp = (l+r)*len/2;
// 		tmp %= MOD;
// 		tmp *= i+1;
// 		tmp %= MOD;

// 		rans += tmp;
// 		rans %= MOD;
// 	}

// 	PL((rans+MOD-lans)%MOD)
// }


int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}

