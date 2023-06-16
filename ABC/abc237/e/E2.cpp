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
#define FI first
#define SE second
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
    int from, to, cost;
};


struct dijkstra{

    int N;
    int s;
    vector<ll> dist;
    vector<vector<Edge>> G;


    dijkstra(int n_, vector<vector<Edge>>& G_){
        N = n_;
        G = G_;
    }


    vector<ll> solve(int s_, int g=-1){
        s = s_;

        dist = vector<ll>(N, LINF);

        dist[s] = 0;
        priority_queue<Pll> que;//dist, to
        que.push({0,s});

        while(!que.empty()){
            int d = que.top().first;
            int now = que.top().second;
            que.pop();
            ES(d) EL(now)
            if(d>dist[now]) continue;
            for(int i=0;i<(int)G[now].size();i++){
                int to = G[now][i].to;
                int w = G[now][i].cost;
                if(dist[now]+w<dist[to]){
                    dist[to] = dist[now] + w;
                    que.push({dist[to], to});
                }
            }
        }
        return dist;
    }
};



void solve() {

    int n,m;
    cin>>n;
    cin>>m;

    V<int> H(n); cin>>H;
    int s = 0;
    int g = n-1;

    vector<vector<Edge>> G(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v;
        u--,v--;
        if(H[u]>H[v]){
            w = H[u]-H[v];
            G[u].push_back({u,v,-w});
            G[v].push_back({v,u,2*w});
        }
        else{
            w = H[v]-H[u];
            G[u].push_back({u,v,2*w});
            G[v].push_back({v,u,-w});            
        }
    }

    dijkstra di(n, G);
    auto dist = di.solve(s);
    ll ans = LINF;
    for(auto d:dist) if(d!=LINF) chmin(ans, d);
    EL(dist)
    PL(-ans)   

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
