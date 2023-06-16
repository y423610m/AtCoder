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

    int N; cin>>N;
    int M; cin>>M;

    Edges<int> E,E0;
    rep(i,M){
        int u,v;
        cin>>u>>v;
        if(u==0||v==0) E0.push_back({u,v});
        else E0.push_back({u,v});
    }
    EL(E.size())
    EL(E0.size())

    // Graph<int> G(N+1, E, false);//頂点数，Edges, 有向
    // Dijkstra<int> d1(N+1, INF);//頂点数，初期距離
    // d1.solve(G, 1);//G, start, goal, 通り数える
    // Dijkstra<int> dn(N+1, INF);//頂点数，初期距離
    // dn.solve(G, N);//G, start, goal, 通り数える

    for(auto e:E0) E.push_back(e);

    Graph<int> G0(N+1, E, false);//頂点数，Edges, 有向
    Dijkstra<int> d01(N+1, INF);//頂点数，初期距離
    d01.solve(G0, 1);//G, start, goal, 通り数える
    Dijkstra<int> d0n(N+1, INF);//頂点数，初期距離
    d0n.solve(G0, N);//G, start, goal, 通り数える

    //EL(d1.dist)

    repi(i,1,N+1){
        //ll ans = min(d1.dist[N], dn.dist[1]);
        ll ans = LINF;
        chmin(ans, d01.dist[N]);
        // chmin(ans, d0n.dist[1]);
        // chmin(ans, d01.dist[0]+d0n.dist[0]);
        chmin(ans, d01.dist[0]+d0n.dist[i]);
        chmin(ans, d01.dist[i]+d0n.dist[0]);
        // chmin(ans, d01.dist[i]+d0n.dist[i]);
        if(ans<N+5) PS(ans)
        else PS(-1)
    }
    PL("")

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
