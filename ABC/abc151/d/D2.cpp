#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
//const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct DFS{
    int h,w;
    vector<string> S;
    DFS(int h_, int w_, vector<string> S_){
        h = h_;
        w = w_;
        S = S_;
    }

    vector<vector<ll>>> solve(int sx, int sy){
        
    }
}

void solve() {

    int h,w; cin>>h>>w;
    vector<string> S(h);
    for(int i=0;i<h;i++) cin>>S[i];

    vector<vector<ll>> dist(h,vector<ll>(w,LINF));
    auto dfs = [&](auto dfs, int px, int py)->void{
        for(int i=0;i<4;i++){
            int nx = px+dx[i];
            int ny = py+dy[i];
            if(0<=nx&&nx<h&&0<=ny&&ny<w&&S[nx][ny]!='#'){
                if(dist[px][py]+1<dist[nx][ny]){
                    dist[nx][ny] = dist[px][py]+1;
                    dfs(dfs, nx,ny);
                }
            }
        }
    };

    ll ans = 0;
    rep(i,h) rep(j,w) if(S[i][j]=='.'){
        dist = V<V<ll>>(h,V<ll>(w,LINF));
        dist[i][j]=0;
        dfs(dfs, i,j);
        rep(x,h) rep(y,w) if(dist[x][y]!=LINF) chmax(ans, dist[x][y]);
    }
    PL(ans)

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
