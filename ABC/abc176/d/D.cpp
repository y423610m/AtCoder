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
//#define ONLINE_JUDGE 1
#ifdef ONLINE_JUDGE
    #define ES(a) while(0){}
    #define EL(a) while(0){}
#else
    #define NAME(a) #a
    #define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
    #define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#endif
#define END(a) {PL(a) return;}
#define RES(a) cerr<<"\r"<<NAME(a)<<": "<<(a)<<"   ";
#define fi first
#define se second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

//DRUL  SENW
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



void solve() {

    int H,W; cin>>H>>W;
    int sx, sy; cin>>sx>>sy; sx--, sy--;
    int gx, gy; cin>>gx>>gy; gx--, gy--;

    V<string> S(H); cin>>S;

    V<V<int>> dist(H, V<int>(W, INF));

    //warp, x,y
    using P = pair<int, Pii>;
    priority_queue<P, V<P>, greater<P>> que;
    que.push({0,make_pair(sx,sy)});
    dist[sx][sy] = 0;

    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    while(!que.empty()){
        int d = que.top().fi;
        auto [x,y] = que.top().se;
        que.pop();
        if(d>dist[x][y]) continue;
        rep(i,4){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!inGrid(nx,ny)) continue;
            if(S[nx][ny]=='#') continue;
            if(dist[nx][ny]>d){
                dist[nx][ny] = d;
                que.push({d,make_pair(nx,ny)});
            }
        }
        for(int dX = -2;dX<=2;dX++) for(int dY = -2;dY<=2;dY++){
            int nx = x+dX;
            int ny = y+dY;
            if(!inGrid(nx,ny)) continue;
            if(S[nx][ny]=='#') continue;
            if(dist[nx][ny]>d+1){
                dist[nx][ny] = d+1;
                que.push({d+1,make_pair(nx,ny)});
            }
        } 
    }

    if(dist[gx][gy]==INF) PL(-1)
    else PL(dist[gx][gy])

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
