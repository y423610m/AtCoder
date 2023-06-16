#pragma comment(linker, "/stack:25600000")


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
    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    const int MAX = 2000;

    V<string> A(H); cin>>A;

    // V<V<int>> dist(H, V<int>(W, INF));
    array<array<int,MAX>,MAX> dist;
    rep(h,H) dist[h].fill(INF);

    int sx, sy;
    int gx, gy;
    rep(h,H) rep(w,W){
        if(A[h][w]=='S') sx = h, sy = w;
        if(A[h][w]=='G') gx = h, gy = w;
    }

    array<V<Pii>, 26> TEL;
    array<bool, 26> TLE_used;
    TLE_used.fill(false);
    rep(h,H) rep(w,W){
        if(A[h][w]<'a'||'z'<A[h][w]) continue;
        TEL[A[h][w]-'a'].push_back({h,w});
        TLE_used[A[h][w]-'a'] = false;
    }


    using P = pair<int, Pii>;
    queue<P> que;
    dist[sx][sy] = 0;
    que.push({0, Pii(sx,sy)});

    

    while(!que.empty()){
        int d = que.front().fi;
        auto [x,y] = que.front().se;
        que.pop();

        if(d>dist[gx][gy]) break;
        if(d>dist[x][y]) continue;

        rep(dir,4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(inGrid(nx,ny)&&A[nx][ny]!='#'){
                if(dist[nx][ny]>d+1){
                    dist[nx][ny] = d+1;
                    que.push({d+1, Pii(nx,ny)});
                }
            }
        }

        if(A[x][y]<'a'||'z'<A[x][y]) continue;
        if(TLE_used[A[x][y]-'a']) continue;
        TLE_used[A[x][y]-'a'] = true;
        auto& tel = TEL[A[x][y]-'a'];
        for(const auto& p:tel){
            auto [nx, ny] = p;
            if(dist[nx][ny]>d+1){
                dist[nx][ny] = d+1;
                que.push({d+1, Pii(nx,ny)});
            }
        }
    }

    if(dist[gx][gy]==INF) END(-1)
    else END(dist[gx][gy])

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
