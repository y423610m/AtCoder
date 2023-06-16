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
//constants
#define INF 1001001001;
#define LINF 1001001001001001001LL;


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

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};


void solve() {
	
    int n; cin>>n;
    V<int> X(n), Y(n);
    rep(i,n) cin>>X[i]>>Y[i];

    ll sumx = 0, sumy = 0;
    rep(i,n) sumx += X[i];
    rep(i,n) sumy += Y[i];

    ll px, py;
    px = sumx/n;
    py = sumy/n;

    ll ansx = LINF;
    ll ansy = LINF;

    ll tmpx;
    ll tmpy;

    tmpx = 0;
    tmpy = 0;
    rep(i,n){
        tmpx += abs(X[i]-px);
        tmpy += abs(Y[i]-py);
    }
    chmin(ansx,tmpx);
    chmin(ansy,tmpy);

    tmpx = 0;
    tmpy = 0;
    rep(i,n){
        tmpx += abs(X[i]-px+1);
        tmpy += abs(Y[i]-py+1);
    }
    chmin(ansx,tmpx);
    chmin(ansy,tmpy);

    tmpx = 0;
    tmpy = 0;
    rep(i,n){
        tmpx += abs(X[i]-px-1);
        tmpy += abs(Y[i]-py-1);
    }
    chmin(ansx,tmpx);
    chmin(ansy,tmpy);

    PL(ansx+ansy)
	return;
}

void solve2(){
    int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	nth_element(X.begin(), X.begin() + N / 2, X.end());
	nth_element(Y.begin(), Y.begin() + N / 2, Y.end());
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += abs(X[i] - X[N / 2]);
		ans += abs(Y[i] - Y[N / 2]);
	}
	cout << ans << endl;
}

void solve3(){
    int n; cin>>n;
    V<int> X(n), Y(n);
    rep(i,n) cin>>X[i]>>Y[i];

    sort(ALL(X));
    sort(ALL(Y));

    ll ansx=0, ansy=0;
    rep(i,n){
        ansx += abs(X[i]-X[n/2]);
        ansy += abs(Y[i]-Y[n/2]);
    }
    PL(ansx+ansy)
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve3();

	return 0;
}
