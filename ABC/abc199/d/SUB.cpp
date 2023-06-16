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

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif


/*
struct Edge;
edges = vectpr<Edge>;
readE()
Graph G;

TO DO: find_path, find_edges
*/


//////////////////Graph Template
template<typename T=int>//cost type
struct Edge{
    int from, to;
    T cost;
    int id, used;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int id = -1, int used = false)
    : from(from)
    , to(to)
    , cost(cost)
    , id(id)
    , used(used){}

    operator int() const { return to; }
};

// bool operator<(Edge a, Edge b){
//     return a.cost<b.cost;
// }

template <typename T = int>
using Edges = vector< Edge< T > >;

template<typename T>
vector< Edge< T > > readE(int M, int padding = -1, bool weighted = false){
    vector< Edge< T > > E;
    E.reserve(M);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u += padding;
        v += padding;

        T w = 1;
        if(weighted) cin>>w;

        E.emplace_back(u,v,w,i,0);
    }
    return E;
}




template <typename T = int>//cost type
struct Graph{
    vector< vector< Edge< T > > > g;
    int id;

    Graph() = default;

    explicit Graph(int n):g(n), id(0){}

    Graph(int n, const Edges<T>& E, bool directed = false):g(n), id(0){
        for(const auto& e: E){
            g[e.from].emplace_back(e);
            if(!directed) g[e.to].emplace_back(e.to, e.from, e.cost, e.id, e.used);
        }
    }

    size_t size()const{return g.size();}

    void add_directed_edge(int from, int to, T cost = 1){
        g[from].emplace_back(from, to, cost, id++, 0);
    }

    void add_edge(int from, int to, T cost = 1){
        g[from].emplace_back(from, to, cost, id, 0);
        g[to].emplace_back(to, from, cost, id++, 0);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false){
        for(int i=0;i<M;i++){
            int u,v; cin>>u>>v;
            u += padding; v += padding;

            T w = 1;
            if(weighted) cin>>w;

            if(directed) add_directed_edge(u,v,w);
            else add_edge(u,v,w);
        }
    }

    inline vector< Edge< T > > &operator[](const int& k){return g[k];}
    inline const vector< Edge< T > > &operator[](const int& k)const{return g[k];}

};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

void solve() {

    ll N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?

    dsu uf(N);
    for(const auto& e:E) uf.merge(e.from,e.to);
    
    auto groups = uf.groups();
    V<ll> color(N,-1);
    ll ans = 1;
    for(auto group:groups){
        sort(ALL(group));
        EL(group)
        auto dfs = [&](auto dfs, int i)->ll {
            if(i==group.size()) return 1;
            ll p = group[i];
            ll res = 0;
            rep(c,3){
                color[p] = c;
                bool ok = true;
                for(const auto& e:G[p]) if(color[e.to]==c) ok = false;
                if(ok) res += dfs(dfs,i+1);
                color[p] = -1;
            }
            return res;
        };
        color[group[0]] = 0;
        ans *= dfs(dfs,1)*3;
    }
    PL(ans)

    return;
}

void solve2() {

    ll N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?

    dsu uf(N);
    for(const auto& e:E) uf.merge(e.from,e.to);
    
    auto groups = uf.groups();
    V<ll> color(N,-1);
    V<bool> visited(N,false);

    ll ans = 1;
    rep(s,N) if(!visited[s]){
        visited[s] = true;
        auto dfs = [&](auto dfs, int p, int from)->ll {
            visited[p] = true;
            ll res = 0;
            rep(c,3) if(color[p]!=c){
                bool ok = true;
                for(const auto& e:G[p]) if(color[e.to]==c) ok = false;
                if(ok){
                    ll cand = 0;
                    color[p] = c;
                    for(const auto& e:G[p]) if(color[e.to]==-1){
                        cand += dfs(dfs,e.to,p); 
                    }
                    res += cand;
                    color[p] = -1;
                }
            }
            ES(p) EL(res)
            return res;
        };

        color[s] = 0;
        for(const auto&e: G[s]) ans *= dfs(dfs,e.to,s)*3;
        color[s] = -1;
    }


    PL(ans)

    return;
}



void solve3() {

    ll N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?

    dsu uf(N);
    for(const auto& e:E) uf.merge(e.from,e.to);
    
    auto groups = uf.groups();
    V<ll> color(N,-1);
    ll ans = 1;
    V<bool> visited(N,false);
    queue<int> que;
    V<int> from(N);
    rep(i,N) from[i] = i;
    for(auto group:groups){
        //sort(ALL(group));
        que.push(group[0]);
        visited[group[0]] = true;
        group.clear();
        while(!que.empty()){
            int p = que.front(); que.pop();
            group.emplace_back(p);
            for(const auto& e: G[p]) if(!visited[e.to]){
                visited[e.to] = true;
                que.push(e.to);
                from[e.to] = p;
            }
        }
        EL(group)
        auto dfs = [&](auto dfs, int i)->ll {
            if(i==group.size()) return 1;
            ll p = group[i];
            ll res = 0;
            V<int> cnt(3);
            rep(c,3)if(color[from[p]]!=c){
                color[p] = c;
                bool ok = true;
                for(const auto& e:G[p]) if(color[e.to]==c) ok = false;
                if(ok) res += dfs(dfs,i+1);
                color[p] = -1;
            }
            return res;
        };
        color[group[0]] = 0;
        ans *= dfs(dfs,1)*3;
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
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
