#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

//mod
const int MOD = 998244353;
//const int MOD = 1000000007;
//constants
#define INF 1001001001
#define LINF 1001001001001001001LL
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


void solve() {
	
    int n; cin>>n;
    V<int> A(n); cin>>A;
    V<int> B(n); cin>>B;

    map<int,int> CNT;
    rep(i,n) CNT[A[i]]++;
    rep(i,n){
        CNT[B[i]]--;
        if(CNT[B[i]]==0) CNT.erase(B[i]);
    }
    if(CNT.size()!=0) END("No")

    rep(i,n) CNT[A[i]]++;
    int cnt = 0;
    while(B.size()>=4){
        int tmp = B.back();
        int id = A.size()-1;
        bool again = false;
        rep(i,CNT[tmp]){
            while(B.back() != A[id]) id--;
            if(abs(id-((int)A.size()-1))%2==0){
                break;
            }
            again = true;
        }
        if(abs(id-((int)A.size()-1))%2==0){
            A.erase(A.begin()+id);
            B.pop_back();
            if(again) cnt++;
        }
        else{
            A.erase(A.begin()+id);
            B.pop_back();
            swap(A[A.size()-1],A[A.size()-2]);
        }
        CNT[tmp]--;
    }

    rep(i,3){
        swap(A[1],A[2]);
        swap(A[0],A[1]);
        if(A==B) END("Yes")
    }

    if(cnt>=2) END("Yes")

    PL("No")


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
