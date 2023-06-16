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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

struct Edge{int from, to, cost, id, used;
};

bool operator<(Edge a, Edge b){
    return a.cost<b.cost;
}




void solve() {
    int n; cin>>n;
    V<int> C(n); cin>>C;

    vector<vector<Edge>> G(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--, v--;
        int w=1;
        G[u].push_back({u,v,w,i,0});
        G[v].push_back({v,u,w,i,0});
    }

    V<ll> dist(n, LINF);
    dist[0]=0;
    vector<bool> ok(n, true);
    ok[0]=true;
    V<int> color(100005);
    auto dfs = [&](auto dfs, int p)->void{
        color[C[p]]++;
        for(int i=0;i<G[p].size();i++){
            int to = G[p][i].to;
            int from = G[p][i].from;
            int cost = G[p][i].cost;
            int id = G[p][i].id;
            if(dist[p]+cost<dist[to]){
                dist[to] = dist[p]+cost;
                if(color[C[to]]==0) ok[to]=true;
                else ok[to]=false;
                dfs(dfs, to);
            }
        }
        color[C[p]]--;
    };

    dfs(dfs, 0);

    rep(i,n) if(ok[i]) PS(i+1)


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
