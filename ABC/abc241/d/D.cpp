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
#define INF 1001001001
#define LINF 1001001001001001001LL


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
	
    int Q; cin>>Q;

    multiset<ll> st;

    rep(_,Q){
        int q;
        ll x;
        int k;
        cin>>q>>x;
        if(q==1){
            st.insert(x);
        }
        if(q==2){
            cin>>k;
            k--;
            bool ng = false;
            auto it = st.upper_bound(x);
            if(it!=st.begin()) it--;
            else{
                PL(-1)
                ng = true;
            }
            rep(i,k){
                if(it!=st.begin()) it--;
                else{
                    ng = true;
                    break;
                }
            }
            if(ng) PL(-1)
            else PL(*it)
        }
        if(q==3){
            cin>>k;
            k--;
            auto it = st.lower_bound(x);
            bool ng = false;
            rep(i,k){
                it++;
                if(it==st.end()){
                    ng = true;
                    break;
                }
            }
            if(ng) PL(-1)
            else PL(*it)
        }


    }

	return;
}

void solve2() {
	
    int Q; cin>>Q;

    multiset<ll> st;

    rep(_,Q){
        int q;
        cin>>q;
     //   ll x;
      //  int k;
       // cin>>q>>x;
        if(q==1){
            ll x; cin>>x;
            st.insert(x);
        }
        if(q==2){
            ll x; cin>>x;
            int k; cin>>k;
            //k--;
            bool ng = false;
            bool ok = true;
            auto it = st.upper_bound(x);
            // if(it!=st.begin()) it--;
            // else{
            //     ng = true;
            // }
            rep(i,k){
                if(it==st.begin()){
                    ng = true;
                    ok = false;
                    break;
                }
                it--;
                // if(it!=st.begin()) it--;
                // else{
                //     ng = true;
                //     break;
                // }
            }
           // if(ng) PL(-1)
            if(!ok) PL(-1)
            else PL(*it)
        }
        if(q==3){
            ll x; cin>>x;
            int k; cin>>k;
            k--;
            auto it = st.lower_bound(x);
            bool ng = false;
            bool ok = true;
            rep(i,k){
                if(it==st.end()){
                    ng = true;
                    ok = false;
                    break;
                }
                it++;
            }
            if(it==st.end()){
                ng = true;
                ok = false;
            }
            //if(ng) PL(-1)
            if(!ok) PL(-1)
            else PL(*it)
        }


    }

	return;
}

void solve3(){
    int Q; cin>>Q;
    multiset<ll> st;
    rep(_,Q){
        int q; cin>>q;
        if(q==1){
            ll x; cin>>x;
            st.insert(x);
        }
        if(q==2){
            ll x; cin>>x;
            int k; cin>>k;
            auto it = st.upper_bound(x);
            bool ok = true;
            rep(i,k){
                if(it==st.begin()){
                    ok = false;
                    break;
                }
                it--;
            }
            if(ok) PL(*it)
            else PL(-1)
        }
        if(q==3){
            ll x; cin>>x;
            int k; cin>>k;
            auto it = st.lower_bound(x);
            bool ok = true;
            rep(i,k-1){
                if(it==st.end()){
                    ok = false;
                    break;
                }
                it++;
            }
            if(it==st.end()){
                ok = false;
            }
            if(ok) PL(*it)
            else PL(-1)
        }
    }
}

int main() {

	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve2();

	return 0;
}
