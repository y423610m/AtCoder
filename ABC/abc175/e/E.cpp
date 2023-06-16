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
int dx[2] = {1, 0};
int dy[2] = {0, 1};



void solve() {

    int H, W; cin>>H>>W;
    int K; cin>>K;
    V<V<ll>> v(H,V<ll>(W));
    rep(k,K){
        int r,c;
        cin>>r>>c;
        r--, c--;
        int a; cin>>a;
        v[r][c] = a;
    }

    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    V<V<V<ll>>> dp(H, V<V<ll>>(W, V<ll>(4, -LINF)));
    dp[0][0][0] = 0;
    dp[0][0][1] = v[0][0];
    rep(h,H) rep(w,W){
        rep(d,2){
            int nx = h+dx[d];
            int ny = w+dy[d];
            if(inGrid(nx, ny)){
                if(d==0){//下
                    rep(i,4) chmax(dp[nx][ny][0], dp[h][w][i]);
                    rep(i,4) chmax(dp[nx][ny][1], dp[h][w][i]+v[nx][ny]);                    
                }
                else{
                    rep(i,4) chmax(dp[nx][ny][i], dp[h][w][i]);
                    rep(i,3) chmax(dp[nx][ny][i+1], dp[h][w][i]+v[nx][ny]);                    
                }
            }
        }
    }
    rep(i,4){
        rep(h,H){
            rep(w,W){
                ES(dp[h][w][i])
            }
            EL("")
        }
    }

    ll ans = 0;
    rep(i,4){
        chmax(ans, dp[H-1][W-1][i]);
    }
    PL(ans)

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
