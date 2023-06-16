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
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

//DRUL  SENW
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

auto inGrid = [&](int nx, int ny){
    if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
    return false;
};

void solve() {



    int H,W; cin>>H>>W;
    int sx,sy; cin>>sx>>sy; sx--,sy--;
    int gx,gy; cin>>gx>>gy; gx--,gy--;
    V<string> S(H); cin>>S;

    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    queue<Pii> que;
    V<V<V<int>>> dist(H, V<V<int>>(W, V<int>(4, INF)));
    rep(i,4) dist[sx][sy][i] = 0;
    rep(i,4){
        int nx = sx+dx[i];
        int ny = sy+dy[i];
        if(!inGrid(nx, ny)) continue;
        if(S[nx][ny]!='.') continue;
        dist[nx][ny][i] = 0;
        que.push({nx,ny});
        rep(j,4) chmin(dist[nx][ny][j], dist[nx][ny][i]+1);
    }

    int ans = INF;
    rep(i,4) chmin(ans, dist[gx][gy][i]);

    while(!que.empty()){
        int x = que.front().fi;
        int y = que.front().se;
        que.pop();

        int minDist = INF;
        rep(i,4) chmin(minDist, dist[x][y][i]);
        ES(x) ES(y) EL(minDist)

        if(minDist>ans) continue;

        rep(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(inGrid(nx,ny)&&S[nx][ny]=='.'){
                if(dist[nx][ny][i]>min(dist[x][y][i], minDist+1)){
                    dist[nx][ny][i] = min(dist[x][y][i], minDist+1);
                    que.push({nx,ny});
                    rep(j,4) chmin(dist[nx][ny][j], dist[nx][ny][i]+1);

                    if(nx==gx&&ny==gy){
                        rep(j,4) chmin(ans, dist[nx][ny][j]);
                    }
                }
            }
        }
    }

    rep(i,4) chmin(ans, dist[gx][gy][i]);
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



//struct state {
//int x, y, dir;
//};
//
//int n; cin>>n;
//int H, W, sx, sy, gx, gy;
//H=n, W=n;
//cin >> sx >> sy >> gx >> gy;
//--sx, --sy, --gx, --gy;
//vector<string> S(n, string(' ',W));
//for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>S[i][j];
//
//vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));
//
//deque<state> deq;
//for (int i = 0; i < 4; ++i) {
//dist[sx][sy][i] = 0;
//deq.push_back({ sx, sy, i });
//}
//
//int shortest = INF;
//while (!deq.empty()) {
//state p = deq.front(); deq.pop_front();
//if(shortest<dist[p.x][p.y][p.dir]) break;
//for (int i = 0; i < 4; ++i) {
//int nx = p.x + dx[i];
//int ny = p.y + dy[i];
//int cost = dist[p.x][p.y][p.dir];
//if(p.dir != i) cost++;
//
//if (0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.' && dist[nx][ny][i] > cost) {
//dist[nx][ny][i] = cost;
//if (p.dir != i) deq.push_back({ nx, ny, i });
//else deq.push_front({ nx, ny, i });
//if(nx==gx&&ny==gy) shortest = min(shortest, cost);
//}
//}
//}
//int answer = INF;
//for (int i = 0; i < 4; ++i) {
//answer = min(answer, dist[gx][gy][i]);
//}
//if(answer==INF){
//cout<<-1<<endl;
//return 0;
//}
////曲がった回数をカウントしているので，移動回数は+1
//cout << answer+1 << endl;
//return 0;