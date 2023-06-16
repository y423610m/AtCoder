#line 1 "F3.cpp"
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
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/graph_template.hpp"

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

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/tree/rooted_tree.hpp"

template<typename T>
struct RootedTree{
    int N;
    vector<int> depth;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> numOfChildren;
    vector<T> dist;

    RootedTree(int N, const Graph<T>& G, int root)
    :N(N)
    ,depth(N,-1)
    ,parent(N,-1)
    ,children(N)
    ,numOfChildren(N, 0)
    ,dist(N, -1)
    {
        parent[root] = root;
        dist[root] = 0;
        auto dfs = [&](auto dfs, int v, int d)->int {
            depth[v] = d;
            int num = 0;
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                parent[e.to] = v;
                dist[e.to] = dist[v] + e.cost;
                children[v].push_back(e.to);
                num += dfs(dfs, e.to, d+1);
            }
            numOfChildren[v] = num;
            return num + 1;
        };
        dfs(dfs, root, 0);
    }


};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);

    RootedTree rt(N, G, 0);//2nd arg:root

    EL(rt.depth)
    EL(rt.parent)
    EL(rt.numOfChildren)
    rep(i,N) EL(rt.children[i])
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
    rootの親はroot自身
*/
#line 47 "F3.cpp"
/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);

    RootedTree rt(N, G, 0);

    EL(rt.depth)
    EL(rt.parent)
    EL(rt.numOfChildren)
    rep(i,N) EL(rt.children[i])
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
*/

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/tree/LCA_doubling.hpp"

template<typename T>
struct LCADoubling{
    int N;
    vector<int> depth;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> numOfChildren;
    vector<T> dist;//rootからの距離

    int LOG;
    vector<vector<int>> table;

    LCADoubling(int N, const Graph<T>& G, int root)
    :N(N)
    ,depth(N,-1)
    ,parent(N,-1)
    ,children(N)
    ,numOfChildren(N, 0)
    ,dist(N, -1)
    ,LOG(32-__builtin_clz(N))
    ,table(LOG, vector<int>(N, -1))
    {

        parent[root] = root;
        dist[root] = 0;

        table[0][root] = -1;
        auto dfs = [&](auto dfs, int v, int d)->int {
            depth[v] = d;
            int num = 0;
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                parent[e.to] = v;
                dist[e.to] = dist[v] + e.cost;
                children[v].push_back(e.to);
                num += dfs(dfs, e.to, d+1);
                table[0][e.to] = v;
            }
            numOfChildren[v] = num;
            return num + 1;
        };
        dfs(dfs, root, 0);

        for(int k=0;k+1<LOG;k++){
            for(int i=0;i<N;i++){
                if(table[k][i] == -1) table[k+1][i] = -1;
                else table[k+1][i] = table[k][table[k][i]];
            }
        }
    }

    int lca(int u, int v){
        if(depth[u]>depth[v]) swap(u,v);
        v = climb(v, depth[v]-depth[u]);
        if(u==v) return u;
        for(int i=LOG-1;i>=0;i--){
            if(table[i][u]!=table[i][v]){
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int climb(int u, int k){

        if(depth[u]<k) return -1;
        for(int i=LOG-1;i>=0;i--){
            if((k>>i)&1){
                u = table[i][u];
            }
        }
        return u;
    }

    int distance(int u, int v){
        return dist[u] + dist[v] - dist[lca(u,v)]*2;
    }
};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);

    RootedTree rt(N, G, 0);//2nd arg:root

    EL(rt.depth)
    EL(rt.parent)
    EL(rt.numOfChildren)
    rep(i,N) EL(rt.children[i])
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
    rootの親はroot自身
*/
#line 63 "F3.cpp"

void solve() {

    int N; cin>>N;
    auto E = readE<int>(N-1, -1, false);
    Graph<int> G(N, E, false);

    RootedTree rt(N, G, 0);
    int MaxDist = 0;
    int l = 0;
    rep(i,N){
        if(MaxDist<rt.depth[i]){
            MaxDist = rt.depth[i];
            l = i;
        }
    }

    LCADoubling LTree(N, G, l);
    MaxDist = 0;
    int r = 0;
    rep(i,N){
        if(MaxDist<LTree.depth[i]){
            MaxDist = LTree.depth[i];
            r = i;
        }
    }

    LCADoubling RTree(N, G, r);

    int Q; cin>>Q;
    rep(q,Q){
        int u,k;
        cin>>u>>k;
        u--;
        if(LTree.depth[u]>=k){
            int ans = LTree.climb(u,k);
            cout<<ans+1<<"\n";
            continue;
        }
        if(RTree.depth[u]>=k){
            int ans = RTree.climb(u,k);
            cout<<ans+1<<"\n";
            continue;
        }
        cout<<-1<<"\n";
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
