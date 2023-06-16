#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
// __uint128_t
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;

constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";

// #define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
// #define ONLINE_JUDGE 1
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
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template<typename T> using V = vector<T>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, unsigned long int sz> using Ar = array< T , sz >;
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, typename U> void operator++(pair<T, U>& p){p.first++, p.second++;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first++, p.second++;}//post
template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp



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

    Edge(ll from, ll to, T cost = 1, int id = -1, int used = false)
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


template<typename EdgeT, typename VertexT>
struct RerootingDP {

   int n, root;
   vector<vector<EdgeT>> outs;
   vector<EdgeT> reverse_edge;
   vector<VertexT> answers;
   vector<int> rev_id;//rev[i]:=親グラフにおいて，親->頂点iの辺が何番目か

   RerootingDP() = default;

   template<typename GraphT, typename MergeT, typename ElT, typename PET, typename PVT>
   VertexT build(int _n, Graph<GraphT>& G, int _root, MergeT Merge, ElT E, PET Put_Edge, PVT Put_Vertex){
      n = _n;
      root = _root;
      outs.resize(n);
      rev_id.resize(n);

      auto dfs = [&](auto dfs, int v, int parent = -1)->VertexT {
         EdgeT val = E(v);
         for(int i=0;i<G[v].size();i++){
         // for (auto &e : G[v]){
            auto& e = G[v][i];
            if(e.to == parent && e.to != G[v].back().to) swap(e, G[v].back());
            if(e.to == parent) continue;
            rev_id[e.to] = i;
            
            EdgeT nval = Put_Edge(dfs(dfs, e.to, v), e);
            outs[v].emplace_back(nval);
            val = Merge(val,nval);
         }
         return Put_Vertex(val,v);
      };

      return dfs(dfs, root);
   }

   template<typename GraphT, typename MergeT, typename ElT, typename PET, typename PVT>
   vector<VertexT> reroot(Graph<GraphT>& G, MergeT Merge, ElT E, PET Put_Edge, PVT Put_Vertex){
      reverse_edge.resize(n);
      reverse_edge[root] = E(-1);
      answers.resize(n);

      auto bfs = [&](auto bfs, int v)->void {
         int siz = outs[v].size();
         vector<EdgeT> lui(siz+1), rui(siz+1);
         lui[0] = E(-1), rui[siz] = E(v);
         for (int i = 0; i < siz; i++) lui[i+1] = Merge(lui[i],outs[v][i]);
         for (int i = siz-1; i >= 0; i--) rui[i] = Merge(outs[v][i],rui[i+1]);
         for (int i = 0; i < siz; i++){
            reverse_edge[G[v][i].to] = Put_Edge(Put_Vertex(Merge(Merge(lui[i],rui[i+1]),reverse_edge[v]),v),G[G[v][i].to].back());
            bfs(bfs, G[v][i].to);
         }
         ES(v) EL(lui)
         answers[v] = Put_Vertex(Merge(lui[siz],reverse_edge[v]), v);
      };

      bfs(bfs, root);
      return answers;
   }

};


// namespace RDP{
//    template<typename EdgeT> EdgeT mergeMax(EdgeT a, EdgeT b){return max(a,b);}
//    template<typename EdgeT> EdgeT e0(){return 0;}
//    template<typename EdgeT, typename VertexT> EdgeT put_edge(VertexT v, int i){return v + 1;}
//    template<typename EdgeT, typename VertexT> VertexT put_vertex(EdgeT e, int v){return e;}

   
//    template<typename EdgeT, typename VertexT>
//    using FarestNode = RerootingDP<EdgeT, VertexT, RDP::merge<EdgeT>, RDP::e<EdgeT>, RDP::put_edge<EdgeT, VertexT>, RDP::put_vertex<EdgeT, VertexT>>;

// }

/*
   ll N; cin>>N;
   Edges<int> E = readE<int>(N-1, -1, false);//weighted?
   Graph<int> G(N, E, false);//directed?
   RDP::FarestNode<ll, ll> rdp;
   rdp.build(N, G, 0);
   auto dp = rdp.reroot(G);

   vertex:その頂点を根とした値を考えるとき
   edge:根以外の木の一部にするとき．
*/

namespace RDP{
   template<typename EdgeT> EdgeT mergeMax(EdgeT a, EdgeT b){return max(a,b);}
   template<typename EdgeT> EdgeT e0(){return 0;}
   template<typename EdgeT, typename VertexT> EdgeT put_edge(VertexT v, int i){return v + 1;}
   template<typename EdgeT, typename VertexT> VertexT put_vertex(EdgeT e, int v){return e;}

   
   // template<typename EdgeT, typename VertexT>
   // using FarestNode = RerootingDP<EdgeT, VertexT, RDP::mergeMax<EdgeT>, RDP::e0<EdgeT>, RDP::put_edge<EdgeT, VertexT>, RDP::put_vertex<EdgeT, VertexT>>;

}

/*
   ll N; cin>>N;
   Edges<int> E = readE<int>(N-1, -1, false);//weighted?
   Graph<int> G(N, E, false);//directed?
   RDP::FarestNode<ll, ll> rdp;
   rdp.build(N, G, 0);
   auto dp = rdp.reroot(G);

   vertex:その頂点を根とした値を考えるとき
   edge:根以外の木の一部にするとき．
   typ90 003
*/

void solve() {

   ll N; cin>>N;
   Edges<ll> E = readE<ll>(N-1, -1, false);//weighted?
   Graph<ll> G(N, E, false);//directed?

   auto Merge = [&](ll a, ll b)->ll {
      return max<ll>(a,b);
   };
   auto El = [&](int p)->ll {
      // if(p<0) return 0;
      // return D[p];
      return 0;
   };
   auto PE = [&](ll v, Edge<ll>& e)->ll {
      return v + e.cost;
   };
   auto PV = [&](ll e, int p)->ll {
      return e;
   };

   RerootingDP<ll, ll> rdp;
   rdp.build(N, G, 0, Merge, El, PE, PV);
   auto dp = rdp.reroot(G, Merge, El, PE, PV);

   ll ans = 0;
   rep(i,N) chmax(ans, dp[i]+1);
   PL(ans)

   return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
