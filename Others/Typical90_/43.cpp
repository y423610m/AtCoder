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

    struct POS{
        int cost,x,y;
        //bool operator <(POS a){return(this->cost<a.cost);}
        //bool operator >(POS a){return(this->cost>a.cost);}
    };

    struct comp{
        bool operator()(POS const& p1, POS const& p2){
            return(p1.cost<p2.cost);
        }
    };
	
    int h,w; cin>>h>>w;
    int sx,sy; cin>>sx>>sy; sx--; sy--;
    int gx,gy; cin>>gx>>gy; gx--; gy--;

    V<string> vs(h); cin>>vs;

    priority_queue<POS,V<POS>,comp > que;
    que.push({-1,sx,sy});

    V<V<int> > dist(h, V<int>(w,INF));
    dist[sx][sy] = 0;
    bool flag = true;
    while(!que.empty() && flag){
        POS pos = que.top(); que.pop();
        int d = pos.cost;
        if(d==0){ES(pos.x) ES(pos.y) EL(pos.cost)}
        rep(i,4){
            int nx = pos.x + DX[i];
            int ny = pos.y + DY[i];
            while(0<=nx&&nx<h&&0<=ny&&ny<w&&vs[nx][ny]=='.'){
                if(nx==gx&&ny==gy){
                    PL(d+1);
                    flag = false;
                }
                if(d+1<dist[nx][ny]){
                    que.push({d+1, nx, ny});
                    dist[nx][ny] = d+1;
                }
                nx += DX[i];
                ny += DY[i];
            }
        }
    }

    PL(dist[gx][gy])


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
