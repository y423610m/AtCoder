#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

//mod
const int MOD = 998244353;
//const int MOD = 1000000007;


//iteration
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
//output
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}

//pair
#define FI first
#define SE second



using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using P = pair<int, int>;
using mint = atcoder::static_modint<MOD>;


template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    	os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}


ostream &operator<<(ostream &os, const mint x) {
    os<<x.val();
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

/*
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
*/

template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

//constants
const int INF = 1<<30-1;
const ll LINF = 1LL<<62-1;

void solve() {
	
    int n; cin>>n;
    V<int> A(n); cin>>A;
    rep(i,n) if(A[i]==0) A[i]=-1;

    // int ini = 0;
    // rep(i,n) if(A[i]==1) ini++;

    fenwick_tree<int> fw1(n);
    rep(i,n) fw1.add(i,A[i]);
    int ans1 = 0;
    for(int l=0;l<n-1;l++){
        for(int r=l+1;r<n;r++){
            chmax(ans1, fw1.sum(l,r));
        }
    }

    fenwick_tree<int> fw0(n);
    rep(i,n) fw0.add(i,-A[i]);
    int ans0 = 0;
    for(int l=0;l<n-1;l++){
        for(int r=l+1;r<n;r++){
            chmax(ans0, fw0.sum(l,r));
        }
    }

    // ans1 = ans1-ini;
    // ans0 = (n-)
    PL(1+ans0+ans1)

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
