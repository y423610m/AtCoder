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
#define endl "\n"
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

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

void solve() {

    int H,W; cin>>H>>W;
    V<string> C(H); cin>>C;

    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    int sx,sy;
    rep(h,H) rep(w,W) if(C[h][w]=='S'){
        sx = h;
        sy = w;
        break;
    }
    ES(sx) EL(sy)

    V<V<int>> deg(H, V<int>(W));

    //入次数が１のマスを消していけば，求まるはず
    queue<Pii> que;
    rep(h,H) rep(w,W) if(C[h][w]=='.'){
        int degree = 0;
        rep(d,4){
            int nx = h+dx[d];
            int ny = w+dy[d];
            if(inGrid(nx, ny)&&C[nx][ny]!='#') degree++;
        }
        deg[h][w] = degree;
        if(deg[h][w]<=1){
            deg[h][w] = 0;
            que.push({h,w});
        }
    }
    rep(h,H) EL(deg[h])

    while(!que.empty()){
        auto [h,w] = que.front(); que.pop();
        C[h][w] = '#';
        rep(d,4){
            int nx = h+dx[d];
            int ny = w+dy[d];
            if(inGrid(nx, ny)&&C[nx][ny]!='#'){
                deg[nx][ny]--;
                if(deg[nx][ny]==1){
                    deg[nx][ny] = 0;
                    que.push({nx, ny});
                }
            }
        }
    }

    rep(h,H) EL(C[h])
    rep(h,H) EL(deg[h])

    // int degree = 0;
    // rep(d,4){
    //     int nx = sx+dx[d];
    //     int ny = sy+dy[d];
    //     if(inGrid(nx,ny)&&deg[nx][ny]>0){
    //         degree++;
    //     }
    // }

    //各方向から出発して，多方向に到着できるか
    rep(d,4){
        int sx1 = sx+dx[d];
        int sy1 = sy+dy[d];
        if(inGrid(sx1, sy1)&&C[sx1][sy1]=='.'){
            V<V<bool>> visited(H, V<bool>(W));
            que.push({sx1, sy1});
            while(!que.empty()){
                auto [x,y] = que.front(); que.pop();
                rep(d2,4){
                    int nx = x+dx[d2];
                    int ny = y+dy[d2];
                    if(inGrid(nx, ny)){
                        if(nx==sx&&ny==sy){
                            if(!(x==sx1&&y==sy1)) END("Yes")
                        }
                        else{
                            if(!visited[nx][ny]){
                                visited[nx][ny] = true;
                                que.push({nx, ny});
                            }
                        }
                    }
                }
            }

        }
    }

    PL("No")

    // if(degree>=2) PL("Yes")
    // else PL("No")



    return;
}

void solve2(){
    int H,W; cin>>H>>W;
    V<string> C(H); cin>>C;

    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    int sx,sy;
    rep(h,H) rep(w,W) if(C[h][w]=='S'){
        sx = h;
        sy = w;
        break;
    }
    ES(sx) EL(sy)

    dsu tree(H*W);

    queue<Pii> que;
    rep(d,4){
        int nx = sx+dx[d];
        int ny = sy+dy[d];
        if(inGrid(nx, ny)&&C[nx][ny]=='.') que.push({nx, ny});
    }

    while(!que.empty()){
        auto [x,y] = que.front(); que.pop();
        ES(x) EL(y)
        rep(d,4){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(inGrid(nx, ny)&&C[nx][ny]=='.'){
                if(!tree.same(W*x+y, W*nx+ny)){
                    tree.merge(W*x+y, W*nx+ny);
                    que.push({nx, ny});
                }
            }
        }
    }

    // rep(h,H){
    //     rep(w,W){
    //         PS(tree.leader(W*h+w))
    //     }
    //     PL("")
    // }

    EL(tree.size(W*sx+sy))

    rep(d1,4){
        int x1 = sx+dx[d1];
        int y1 = sy+dy[d1];
        if(inGrid(x1, y1)){
            rep(d2,4) if(d1!=d2){
                int x2 = sx+dx[d2];
                int y2 = sy+dy[d2];
                if(inGrid(x2, y2)){
                    if(tree.same(W*x1+y1, W*x2+y2)){
                        ES(x1) ES(y1) EL(tree.leader(W*x1+y1))
                        ES(x2) ES(y2) EL(tree.leader(W*x2+y2))
                        END("Yes")
                    }
                }
            }
        }
    }



    PL("No")
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
