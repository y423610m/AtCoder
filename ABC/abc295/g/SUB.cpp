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
constexpr char Yes[] = "Yes";
constexpr char No[] = "No";

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
template<typename T, typename U> void operator++(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first--, p.second--;}//post
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


template<typename T>
struct RootedTree{
    int N;
    vector<int> depth;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> numOfDescendants;
    vector<T> dist;
    V<int> farestDescendant;

    RootedTree(int N, const Graph<T>& G, int root)
    :N(N)
    ,depth(N,-1)
    ,parent(N,-1)
    ,children(N)
    ,numOfDescendants(N, 0)
    ,dist(N, -1)
    ,farestDescendant(N)
    {
        parent[root] = root;
        dist[root] = 0;
        auto dfs = [&](auto dfs, int v, int d)->void {
            depth[v] = d;
            farestDescendant[v] = v;
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                parent[e.to] = v;
                dist[e.to] = dist[v] + e.cost;
                children[v].emplace_back(e.to);
                dfs(dfs, e.to, d+1);
                numOfDescendants[v] += numOfDescendants[e.to]+1;
                if(depth[farestDescendant[v]]<depth[farestDescendant[e.to]]) farestDescendant[v] = farestDescendant[e.to];
            }
            return;
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
    EL(rt.numOfDescendants)
    rep(i,N) EL(rt.children[i])
    EL(rt.farestDescendant)
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
    rootの親はroot自身
*/
/*
   ll N,M; cin>>N>>M;
   Edges<int> E = readE<int>(M, -1, false);//weighted?
   Graph<int> G(N, E, false);//directed?
   //Graph<int> G(N); G.read(M, -1, true, true);

   RootedTree rt(N, G, 0);

   EL(rt.depth)
   EL(rt.parent)
   EL(rt.numOfDescendants)
   rep(i,N) EL(rt.children[i])
   EL(rt.farestDescendant)
   parent[root]=root
   //Edgeは親->子が含まれていれば,有向でも無向でもOK
*/


template<class T>
struct WeightUpdateUnionFind {
   vector<int> par;
   vector<int> sz;
   vector<T> weight;

   WeightUpdateUnionFind(int n = 1)
   :par(n,-1), sz(n,1), weight(n,T())
   {}

   int leader(int x) {
      if (par[x] == -1) {
         return x;
      }
      else {
         int r = leader(par[x]);
         return par[x] = r;
      }
   }

   T& operator[](int i){
      return weight[leader(i)];
   }

   const T& operator[](int i)const{
      return weight[leader(i)];
   }

   bool same(int x, int y) {
      return leader(x) == leader(y);
   }

   template<typename Cmp, typename F>
   bool merge(int x, int y, Cmp cmp, F f) {
      x = leader(x); y = leader(y);
      if (x == y) return false;
      // if (sz[x] < sz[y]) swap(x, y);
      if (!cmp(x,y)) swap(x, y);
      sz[x] += sz[y];
      par[y] = x;
      // weight[x] = f(weight[x], weight[y]);
      f(x, y);
      return true;
   }

   int size(){
      return sz.size();
   }

   int size(int i){
      return sz[leader(i)];
   }

   /*
   WeightUpdateUnionFind<ll> uf(N);
   rep(i,N) uf.setWeight(i,A[i]);
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {uf.weight[parent] += 0uf.weight[child];};//重みに対して行う処理
   if(!uf.same(x,y))uf.merge(x,y,cmp,f);
   uf.leader();
   uf.getWeight(x);
   abc277D2
   abc295G
   */
};
   /*
   WeightUpdateUnionFind<ll> uf(N);
   rep(i,N) uf.setWeight(i,A[i]);
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {uf.weight[parent] += 0uf.weight[child];};//重みに対して行う処理
   if(!uf.same(x,y))uf.merge(x,y,cmp,f);
   uf.leader();
   uf.getWeight(x);
   abc277D2
   abc295G
   */

void solve() {

   ll N; cin>>N;
   V<ll> P(N-1); cin>>P; P--;

   Edges<int> E;
   rep(i,N-1) E.push_back({i+1, P[i]});
   Graph<int> G(N, E, false);//directed?

   RootedTree rt(N, G, 0);

   WeightUpdateUnionFind<ll> uf(N);
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {chmin(uf.weight[parent],uf.weight[child]);};//重みに対して行う処理
   rep(i,N) uf[i] = i;

   ll Q; cin>>Q;
   rep(q,Q){
      ll t; cin>>t;
      if(t==1){
         ll u,v;
         cin>>u>>v;
         u--, v--;
         //uf.merge(u,v, );
         while(uf[u]>v){
            ll p = rt.parent[uf[u]];
            EL(p)
            uf.merge(u, p, cmp, f);
         }
      }
      else{
         ll x;
         cin>>x;
         x--;
         PL(uf[x]+1)
      }
   }

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
