#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
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
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

#include "graph/shortest_path/dijkstra.hpp"
/*
    int N; cin>>N;
    int M; cin>>M;

    Edges<int> E = readE<int>(M, -1, false);//辺数，index, weight
    Graph<int> G(N, E, false);//頂点数，Edges, 有向

    Dijkstra<int> di(N, INF);//頂点数，初期距離
    di.solve(G, 0, 0, false);//G, start, goal, 通り数える

    EL(di.dist)
    EL(di.find_path(N-1))
    EL(di.find_edges(N-1))
    EL(di.cnt)
*/

void solve() {

    ll N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//辺数，index, weight
    Graph<int> G(N, E, false);//頂点数，Edges, 有向
    ll K; cin>>K;
    V<ll> C(K); cin>>C;
    rep(i,K) C[i]--;

    V<Dijkstra<int>> di(K,Dijkstra<int>(N, INF));//頂点数，初期距離
    // di.solve(G, 0, 0, false);//G, start, goal, 通り数える

    rep(i,K) di[i].solve(G,C[i]);

    EL(1)

    //iにいて，jを訪れた時の最小距離
    V<V<ll>> dp(K, V<ll>(1<<K,INF));
    rep(i,K) dp[i][1<<i] = 0;
    rep(i,1<<K){
        rep(k,K) if(i&(1<<k)){
            if(dp[k][i]==INF) continue;
            rep(j,K){
                ll to = (i)|(1<<j);
                chmin(dp[j][to], dp[k][i]+di[k].dist[C[j]]);
            }
        }
    }
    EL(dp)

    ll ans = INF;
    rep(i,K) chmin(ans, dp[i][(1<<K)-1]);
    if(ans==INF) PL(-1)
    else PL(ans+1)

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
