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

struct Edge{
    int from, to, cost, id, used;
};
bool operator<(const Edge& a, const Edge& b){
    return a.cost<b.cost;
}

// prim with O(N log N)
struct Prim{
    int N;
    ll sum;
    vector<vector<Edge>> G;
    vector<ll> dist;
    vector<bool> visit;
    vector<int> froms;
    vector<int> idx;

    Prim(int n, vector<vector<Edge>>& G_){
        N = n;
        G = G_;
    }

    void set_graph(vector<vector<Edge>>& G_){
        G = G_;
    }

    ll solve(int s){
        sum = 0;
        dist = vector<ll>(N, LINF);
        visit = vector<bool>(N, false);
        froms = vector<int>(N, -1);
        idx = vector<int>(N, -1);

        priority_queue<P, vector<P>, greater<P>> que;//dist, pos
        que.push({0,s});
        dist[s] = 0;
        while(!que.empty()){
            ll d = que.top().first;
            ll pos = que.top().second;
            que.pop();
            if(visit[pos]) continue;
            if(d>dist[pos]) continue;
            visit[pos] = true;
            sum += d;
            for(int i=0;i<(int)G[pos].size();i++){
                int from = G[pos][i].from;
                int to = G[pos][i].to;
                int cost = G[pos][i].cost;
                int id = G[pos][i].id;
                if(!visit[to] && cost<dist[to]){
                    dist[to] = cost;
                    froms[to] = from;
                    idx[to] = id;
                    que.push({cost, to});
                }
            }
        }
        return sum;
    }
};



void solve() {

    int n,m;
    cin>>n>>m;

    vector<vector<Edge>> G(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v;
        u--; v--;
        w = 1;
        cin>>w;
        G[u].push_back({u,v,w,i,0});
        G[v].push_back({v,u,w,i,0});
    }

    Prim prim(n, G);
    ll sum = prim.solve(0);
    // cout<<sum<<endl;

    auto& ans = prim.idx;
    for(int i=1;i<(int)ans.size();i++) cout<<ans[i]+1<<" "; cout<<endl;

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
