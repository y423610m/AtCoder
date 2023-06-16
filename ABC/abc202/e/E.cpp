#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
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
template<class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}




#include "graph/tree/LCA_RMQ.hpp"
/*
    int N; cin>>N;
    Edges<int> E = readE<int>(N-1, -1, false);//weighted
    Graph<int> G(N, E, false);//directed
    LCA_RMQ tree(N, G, 0);//root

    EL(tree.lca(0,4))//共通祖先id
    EL(tree.distance(0,4))//2点間の距離

    EL(tree.parent[1])
    EL(tree.depth[1])
    EL(tree.dist[1])//rootからの距離
    EL(tree.numOfChildren[1])
*/



void solve() {

    ll N; cin>>N;
    Edges<int> E;
    rep(i,N-1){
        int p; cin>>p;
        p--;
        E.emplace_back(p,i+1,1);
    }
    Graph<int> G(N, E, false);
    LCA_RMQ tree(N, G, 0);//root

    set<int> D;

    V<V<int>> mp(N+2);
    rep(i,N){
        mp[tree.distance(0,i)].push_back(tree.in[i]);
        //mp[tree.distance(0,i)].push_back(tree.out[i]);
    }

    ll Q; cin>>Q;
    rep(q,Q){
        int u,d;
        cin>>u>>d;
        u--;
        if(D.find(d)==D.end()) sort(ALL(mp[d]));
        D.insert(d);
        int ans = lower_bound(ALL(mp[d]), tree.out[u])-lower_bound(ALL(mp[d]), tree.in[u]);
        PL(ans)
    }
    EL(tree.depth)
    EL(tree.in)
    EL(tree.out)

    rep(i,N) rep(j,N){
        PS(i) PS(j) PL(tree.distance(i,j))
    }

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
