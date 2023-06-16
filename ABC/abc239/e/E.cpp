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
const ll MOD = 998244353;
//const ll MOD = 1000000007;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

V<V<int>> que;
V<V<int>> AB;
V<bool> done;
V<int> X;
void dfs(int num){
    bool end = true;
    rep(i,AB[num].size()){
        int next = AB[num][i];
        if(!done[next]) {
            done[next] = true;
            dfs(next);
            end = false;
            rep(j,que[next].size()){
                que[num].push_back(que[next][j]);
            }
        }
    }


    que[num].push_back(X[num]);


    sort(RALL(que[num]));

    if(que[num].size()>20) que[num].erase(que[num].begin()+20, que[num].end());
}

void solve() {
	
	int n,q; cin>>n>>q;
    X.resize(n);
    cin>>X;
    AB.resize(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--; b--;
        AB[a].push_back(b);
        AB[b].push_back(a);
    }

    que.resize(n);
    done.resize(n);
    rep(i,n) done[i]=false;
    done[0]=true;
    EL("dfs start")
    dfs(0);
    EL("dfs end")
    rep(_,q){
        int v,k; cin>>v>>k;
        v--; k--;
        //EL(que[v])
        PL(que[v][k])
    }

    //rep(i,n){ES(i) EL(que[i])}

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
