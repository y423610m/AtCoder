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



void solve() {

    int N,M; cin>>N>>M;
    V<Pii> Pos(N+M); cin>>Pos;
    Pos.push_back({0,0});

    V<int> velocity = {1,2,4,8,16,32};

    V<V<double>> dist(N+M+1, V<double>(N+M+1));
    rep(i,N+M+1) rep(j,N+M+1){
        double d = sqrt(1.0*(Pos[i].fi-Pos[j].fi)*(Pos[i].fi-Pos[j].fi)+1.0*(Pos[i].se-Pos[j].se)*(Pos[i].se-Pos[j].se));
        dist[i][j] = d;
    }

    //dp[visited][last][vel] = 5*20*1<<17
    double inf = 1e18;
    V<V<V<double>>> dp(1<<(N+M), V<V<double>>(N+M+1, V<double>(6, inf)));
    dp[0][N+M][0] = 0.;

    int LoopMax = 1<<(N+M);
    rep(i,LoopMax){
        rep(last, N+M+1){
            rep(to,N+M) if((i&(1<<(to)))==0){
                rep(vel,6){
                    if(dp[i][last][vel]==inf) continue;
                    double dt = dist[last][to]/velocity[vel];
                    if(to<N||to==N+M) chmin(dp[i|(1<<to)][to][vel], dp[i][last][vel]+dt);
                    else chmin(dp[i|(1<<to)][to][vel+1], dp[i][last][vel]+dt);
                }
            }
        }
    }

    EL("aa")
    double ans = 1e18;
    int mask = 0;
    rep(i,N) mask |= (1<<i);
    rep(i,LoopMax) rep(last,N+M) rep(vel, 6){
        if((i&mask)==mask){
            chmin(ans, dp[i][last][vel]+dist[last][N+M]/velocity[vel]);
        }
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
