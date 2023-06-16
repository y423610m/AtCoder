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

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/others/cycle_detection2.hpp"

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
    Edge(int from, int to, T cost = 1, int id = -1, int used = false)
    : from(from)
    , to(to)
    , cost(cost)
    , id(id)
    , used(used){}
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

    Graph(int n):g(n), id(0){}

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
    Edges<int> E = readE<int>(M, -1, true, true);
    Graph<int> G(N, E);
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

#line 4 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/others/cycle_detection2.hpp"

/*

*/

template<typename T=int>
struct CycleDetection{
    int N;
    bool directed;


    CycleDetection(int N, bool directed)
    :N(N)
    ,directed(directed)
    ,inLoop(N, false)
    {}

    vector<bool> inLoop;
    void checkLoop(const Graph<T>& G){
        
    }


    vector<int> path;
    vector<int> edges;
    //searchAll:閉路見つけたら終わりなのか，全部探すのか
    void FindOneLoop(const Graph<T>& G){
        vector<int> froms(N,-1);
        vector<int> ids(N,-1);
        vector<int> used(N, 0);
        auto dfs = [&](auto dfs, int idx, int par=-1)->bool{
            used[idx] = 1;
            for(auto& e:G[idx]){
                //無向なら逆流禁止
                if(!directed&&e.to==par) continue;
                //未探索なら，経路覚えて継続
                if(used[e.to]==0){
                    froms[e.to] = idx;
                    ids[e.to] = e.id;
                    if(dfs(dfs, e.to, idx)) return true;
                }
                //閉路発見した
                else if(used[e.to]==1){
                    int cur = idx;
                    path.push_back(e.to);
                    edges.push_back(e.id);
                    while(cur!=e.to){
                        path.push_back(cur);
                        edges.push_back(ids[cur]);
                        cur = froms[cur];
                    }
                    path.push_back(cur);
                    return true;
                }
            }
            used[idx] = 2;
            return false;
        };

        for(int i=0;i<N;i++){
            if(used[i]==0&&dfs(dfs, i)){
                reverse(path.begin(), path.end());
                reverse(edges.begin(), edges.end());
                return;
            }
        }
    }
};
#line 47 "F3.cpp"
/*
    int N,M; cin>>N>>M;
    auto E = readE<int>(M, -1, false);
    Graph<int> G(N, E, false);

    CycleDetection<int> Cycle(N);
    Cycle.undirected_bfs(G);//loop上かどうか調べる
    Cycle.undirected_find_a_loop(G);//一つ閉路探す
    EL(Cycle.onLoop)
    EL(Cycle.path)
    EL(Cycle.edges)
*/

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

void solve() {

    int N; cin>>N;
    int M = N;
    auto E = readE<int>(M, -1, false);
    Graph<int> G(N, E, false);

    CycleDetection<int> Cycle(N, false);
    Cycle.FindOneLoop(G);

    vector<bool> inLoop(N, false);
    auto& path = Cycle.path;
    rep(i,path.size()) inLoop[path[i]] = true;

    dsu tree(N);
    for(const auto& e:E){
        if(inLoop[e.from]&&inLoop[e.to]) continue;
        tree.merge(e.from, e.to);
    }

    int Q; cin>>Q;
    rep(q,Q){
        int u,v;
        cin>>u>>v;
        u--, v--;
        if(tree.same(u,v)) PL("Yes")
        else PL("No")
    }

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
