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

struct Edge{
    int from, to, cost, id, used;
};

bool operator<(Edge a, Edge b){
    return a.cost<b.cost;
}



// vector<bool> visit(n,false);
// auto dfs = [&](auto dfs, int p, int lastcolor=-1)->void{
//     for(int i=0;i<G[p].size();i++){
//         int to = G[p][i].to;
//         int from = G[p][i].from;
//         int cost = G[p][i].cost;
//         int id = G[p][i].id;
//         if(!visit[to]){
//             visit[to]=true;
//             dfs(dfs, to, c);
//         }
//     }
// };

// queue<pair<ll,ll>> que;// cost, pos
// que.push({0,0});
// visit[0] = true;
// while(!que.empty()){
//     ll d = que.front().first;
//     ll p = que.front().second;
//     que.pop();
//     for(int i=0;i<G[p].size();i++){
//         int to = G[p][i].to;
//         int from = G[p][i].from;
//         int cost = G[p][i].cost;
//         int id = G[p][i].id;
//         if(!visit[to]){
//             visit[to]=true;
//             que.push({d+cost, to});
//         }
//     }    
// }

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

void solve() {

    int n,m; cin>>n>>m;
    vector<vector<Edge>> G(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--, v--;
        int w=1;
        //cin>>w;
        G[u].push_back({u,v,w,i,0});
        G[v].push_back({v,u,w,i,0});
    }

    mint ans = 1;
    int node = 0;
    int edge = 0;
    V<bool> checked(n);
    auto dfs = [&](auto dfs, int p)->void{
        checked[p] = true;
        node+=1;
        edge+=G[p].size();
        ES(p) ES(node) EL(edge)
        rep(j,G[p].size()){
            int to = G[p][j].to;
            if(!checked[to]) dfs(dfs, to);
        } 
    };
    rep(i,n){
        if(checked[i]) continue;

        node = 0;
        edge = 0;
        dfs(dfs, i);

        if(edge == 2*node) ans *= 2;
        else ans = 0;

    }

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
