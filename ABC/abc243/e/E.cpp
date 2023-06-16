#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
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
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#include "graph/mst/kruskal.hpp"


void solve() {

    int N; cin>>N;
    int M; cin>>M;

    Edges<ll> E = readE<ll>(M, -1, true);
    Graph<ll> G(N, E, false);

    Kruskal<ll> kr(N);
    kr.solve(E);

    int ans = 0;
    rep(i,M) if(!E[i].used) ans++;
    PL(ans)

    EL(kr.total)

    return;
}

#include "graph/mst/prim.hpp"
/*
    int N; cin>>N;
    int M; cin>>M;
    int s = 0;

    Edges<ll> E = readE<ll>(M, 0, true);
    Graph<ll> G(N, E, false);

    Prim<ll> prim(N, INF);
    prim.solve(G, s);
    PL(prim.total)
*/

void solve2(){
    int N; cin>>N;
    int M; cin>>M;
    int s = 0;

    Edges<ll> E = readE<ll>(M, -1, true);
    Graph<ll> G(N, E, false);

    Prim<ll> prim(N, INF);
    prim.solve(G, s);
    PL(prim.total)
}

void solve3(){
    int N; cin>>N;
    int M; cin>>M;

    Edges<ll> E = readE<ll>(M, -1, true);
    Graph<ll> G(N, E, false);

    sort(ALL(E));

    V<V<ll>> dist(N,V<ll>(N, LINF));
    for(const auto& e:E){
        dist[e.from][e.to] = e.cost;
        dist[e.to][e.from] = e.cost;
    }

    rep(k,N) rep(i,N) rep(j,N) chmin(dist[i][j], dist[i][k]+dist[k][j]);

    int ans = 0;
    for(const auto& e:E){
        bool used = true;
        rep(i,N) if(dist[e.from][i]+dist[i][e.to]<=e.cost) used = false;
        if(!used) ans++;
    }
    PL(ans)

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
