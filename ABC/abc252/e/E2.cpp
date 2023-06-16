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


struct dijkstra{

    int N;
    int s;
    vector<ll> dist;
    vector<vector<Edge>> G;
    vector<ll> cnt;
    vector<int> idx;
    vector<int> froms;

    dijkstra(int n_, vector<vector<Edge>>& G_){
        N = n_;
        G = G_;
    }
    
    void set_graph(const vector<vector<Edge>>& G_){
        G = G_;
    }

    vector<ll> solve(int s_, int g=-1){
        s = s_;

        dist = vector<ll>(N, LINF);
        cnt = vector<ll>(N, 0);
        idx = vector<int>(N,-1);
        froms = vector<int>(N,-1);

        dist[s] = 0;
        cnt[s] = 1;
        priority_queue<P,vector<P>,greater<P>> que;//dist, to
        que.push({0,s});

        while(!que.empty()){
            ll d = que.top().first;
            ll now = que.top().second;
            que.pop();
            if(d>dist[now]) continue;
            if(g>=0 && d>dist[g]) continue;
            for(int i=0;i<G[now].size();i++){
                int from = G[now][i].from;
                int to = G[now][i].to;
                int w = G[now][i].cost;
                int id = G[now][i].id;
                if(dist[now]+w<dist[to]){
                    dist[to] = dist[now] + w;
                    que.push({dist[to], to});
                    cnt[to] = cnt[now];
                    idx[to] = id;
                    froms[to] = from;
                }
                else if(dist[now]+w==dist[to]){
                    cnt[to] += cnt[now];
                    cnt[to] %= MOD;
                }
            }
        }
        return dist;
    }
    
    vector<int> find_path(int g){
        vector<int> path;
        if(dist[g]==LINF) return path;
        int p = g;
        while(p!=s){
            path.push_back(p);
            p = froms[p];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> find_path_idx(int g){
        vector<int> path_idx;
        if(dist[g]==LINF) return path_idx;
        int p = g;
        while(p!=s){
            path_idx.push_back(idx[p]);
            p = froms[p];
        }
        reverse(path_idx.begin(), path_idx.end());
        return path_idx;
    }
};




void solve() {

    int n,m;
    cin>>n;
    cin>>m;
    int s = 0;
    int g = n-1;

    vector<vector<Edge>> G(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v;
        u--,v--;
        w = 1;
        cin>>w;
        G[u].push_back({u,v,w,i,0});
        G[v].push_back({v,u,w,i,0});
    }

    dijkstra di(n, G);
    auto dist = di.solve(s);
    
    auto idx = di.idx;
    repi(i,1,idx.size()) PS(idx[i]+1)
    PL("")

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
