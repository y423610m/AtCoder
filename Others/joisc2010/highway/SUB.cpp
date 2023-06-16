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


template< typename T, typename F >
struct SparseTable {
  F f;
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable() = default;

  explicit SparseTable(const vector< T > &v, const F &f) : f(f) {
    const int n = (int) v.size();
    const int b = 32 - __builtin_clz(n);
    //st[i][j]:=長さ1<<iで左端がjである区間のf(l,r);
    st.assign(b, vector< T >(n));
    //長さ1のとき，値は入力
    for(int i = 0; i < int(v.size()); i++) {
      st[0][i] = v[i];
    }
    //長さ1<<iの区間は，長さが1<<(i-1)で，左端がjとj+1<<(i-1)のf()
    // [j, j+1<<(i-1)) と[j+1<<(i-1), j+1<<i)
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    //半開区間なのでv.size()+1
    //lookup[0]=0:l==rのとき，b=?
    //lookup[1]=0:l+1==rのとき，b=0
    //lookup[2]=1:l+2==rのとき，b=1
    lookup.resize(v.size() + 1);
    for(int i = 2; i < int(lookup.size()); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T fold(int l, int r) const {
    int b = lookup[r - l];
    // [l, l+1<<b), [r-1<<b, r)
    return f(st[b][l], st[b][r - (1 << b)]);
  }
};

template< typename T, typename F >
SparseTable< T, F > get_sparse_table(const vector< T > &v, const F &f) {
  return SparseTable< T, F >(v, f);
}

/*
int op(const int& a, const int& b){
    return max(a,b);
}

    int N = 10;
    vector<int> A(N);
    for(int i=0;i<N;i++) A[i] = i;
    SparseTable st(A, &op);
    //auto st = get_sparse_table(A, &op);
    int l = 3, r = 7;
    EL(st.fold(l,r))

ABC282F参照
*/

template<typename T>
struct LCA_RMQ{
    int N;
    vector<int> in;
    vector<int> out;
    vector<int> depth;//depth[i]:=頂点iの深さ
    vector<int> order;//dep[i]:=時刻iの頂点
    vector<int> dep;//dep[i]:=時刻iの深さ
    using F = function<int(int,int)>;
    SparseTable<int, F> st;

    LCA_RMQ(int N, const Graph<T>& G, int root = 0)
    :N(N)
    ,in(N)
    ,out(N)
    ,depth(N,-1)
    {
        order.reserve(N*3-1);
        dep.reserve(N*3-1);

        auto dfs = [&](auto dfs, int v, int d)->void {
            depth[v] = d;
            in[v] = order.size();
            order.emplace_back(v);
            dep.emplace_back(d);
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                dfs(dfs, e.to, d+1);
                order.emplace_back(v);
                dep.emplace_back(d);
            }
            out[v] = order.size();
            order.emplace_back(v);
            dep.emplace_back(d);
        };
        dfs(dfs, root, 0);
        vector<int> vs(order.size());
        iota(vs.begin(), vs.end(), 0);
        F f = [&](int a, int b) { return dep[a] < dep[b] ? a : b; };
        st = get_sparse_table(vs, f);
    }

    int lca(int x, int y) const{
        if(in[x]>in[y]) swap(x,y);
        return x == y ? x : order[st.fold(in[x], in[y])];
    }

    int size(){
        return int(order.size());
    }

    /*
        int N; cin>>N;
        Edges<int> E = readE<int>(N-1, -1, false);//weighted
        Graph<int> G(N, E, false);//directed
        LCA_RMQ tree(N, G, 0);//root

        EL(tree.lca(0,4))//共通祖先id
    */
};


template<typename T>
struct EulerTour{
   int N;
   vector<int> depth;//depth[i]:=頂点iの深さ
   vector<int> parent;//parent[i]:=頂点iの親．
   vector<vector<int>> children;//children[i]:=頂点iの直属の子
   vector<int> numOfChildren;//子孫の数．
   vector<T> dist;//dist[i]:=根から頂点iまでのコスト
   vector<int> order;//order[i]:=時刻iに訪れた頂点
   vector<int> in;//頂点iを始めて訪れた時刻
   vector<int> out;//頂点iを出た時刻
   vector<int> dep;//dep[i]:=時刻iの深さ
   LCA_RMQ<T> lca_rmq;


   EulerTour(int N, const Graph<T>& G, int root = 0, bool memoMid = true, bool memoOut = true)
   :N(N)
   ,depth(N,-1)
   ,parent(N,-1)
   ,children(N)
   ,numOfChildren(N, 0)
   ,dist(N, -1)
   ,in(N,-1)
   ,out(N,-1)
   ,lca_rmq(N, G, root)
   {
      
      order.reserve(N+N*memoMid+N*memoOut);
      dep.reserve(N+N*memoMid+N*memoOut);

      parent[root] = -1;
      dist[root] = 0;

      auto dfs = [&](auto dfs, int v, int d)->void {
         depth[v] = d;
         in[v] = order.size();
         order.emplace_back(v);
         dep.emplace_back(d);

         numOfChildren[v] = 0;
         for(const auto& e:G[v]) if(depth[e.to]==-1){
            parent[e.to] = v;
            dist[e.to] = dist[v] + e.cost;
            children[v].emplace_back(e.to);
            dfs(dfs, e.to, d+1);
            numOfChildren[v] += numOfChildren[e.to] + 1;
            if(memoMid){
               order.emplace_back(v);
               dep.emplace_back(d);
            }
         }
         out[v] = order.size();
         if(memoOut){
            order.emplace_back(v);
            dep.emplace_back(d);
         }
      };
      dfs(dfs, root, 0);
   }

   int lca(int x, int y) const{
      return lca_rmq.lca(x, y);
   }

   T distance(int x, int y)const{
      return dist[x]+dist[y]-dist[lca(x,y)]*2;
   }

   int size(){
      return int(order.size());
   }

   bool AinB(int a, int b){
      if(in[b]<in[a]&&in[a]<=out[b]) return true;
      return false;
   }

   //path update
   template<typename F>
   void add(int u, int v, F f, bool edge = false){
      if(in[u]>in[v]) swap(u,v);
      f(in[u]+edge, in[v]+1);
   }

   /*
      int N; cin>>N;
      Edges<int> E = readE<int>(N-1, -1, false);//weighted
      Graph<int> G(N, E, false);//directed
      EulerTour<int> et(N, G, 0);//root
      EulerTour<int> et(N, G, 0, true, true);
      //root, 途中記録する?, out記録? 

      EL(et.lca(0,4))//共通祖先id
      EL(et.distance(0,4))//2点間の距離

      EL(et.parent[1])
      EL(et.depth[1])
      EL(et.dist[1])//rootからのcost距離
      EL(et.numOfChildren[1])
   */
};

#include <atcoder/segtree>
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T=ll> using RSQ = atcoder::segtree<T, opSum<T>, e0<T>>;



template <typename T>
struct DirectedTreeDistQuery{

   EulerTour<T> et;

   RSQ<T> segDown;
   RSQ<T> segUp;

   //edge:辺の始点出発時刻
   //node:

   DirectedTreeDistQuery(int N, const Graph<T>& G, int root = 0)
   :et(N, G, root, true)
   , segDown(et.size())
   , segUp(et.size())
   {
      for(int i=0;i<N;i++){
         for(const auto& e:G[i]){
            set(e.from, e.to, e.cost);
         }
      }
   }

   void set(int a, int b, T x){
      if(et.in[a]<et.in[b]){
         segDown.set(et.in[b], x);
         segDown.set(et.out[b], -x);
      }
      else{
         swap(a, b);
         segUp.set(et.in[b], x);
         segUp.set(et.out[b], -x);
      }
   }

   void add(int a, int b, T x){
      if(et.in[a]<et.in[b]){
         segDown.set(et.in[b], segDown.get(et.in[b])+x);
         segDown.set(et.out[b], segDown.get(et.out[b])-x);
      }
      else{
         swap(a, b);
         segUp.set(et.in[b], segUp.get(et.in[b])+x);
         segUp.set(et.out[b], segUp.get(et.out[b])-x);
      }
   }

   T query(int a, int b){
      int l = et.lca(a, b);
      return segUp.prod(0, et.in[a]+1) - segUp.prod(0, et.in[l]+1) + segDown.prod(0, et.in[b]+1) - segDown.prod(0, et.in[l]+1);
      // T ans = 0;
      // if(et.in[a]<et.in[l]) ans += segDown.prod(0, et.in[l]+1) - segDown.prod(0, et.in[a]+1);
      // else                  ans += segUp.prod(0, et.in[a]+1) - segUp.prod(0, et.in[l]+1);
      // if(et.in[l]<et.in[b]) ans += segDown.prod(0, et.in[b]+1) - segDown.prod(0, et.in[l]+1);
      // else                  ans += segUp.prod(0, et.in[l]+1) - segUp.prod(0, et.in[b]+1);
      // return ans;
   }
};
/*
   ll N; cin>>N;
   ll Q; cin>>Q;
   Edges<ll> E = readE<ll>(N-1, -1, false);//weighted?
   Graph<ll> G(N, E, false);//directed?

   DirectedTreeDistQuery<ll> dtdq(N, G, 0);
   dtdq.set(E[r].from, E[r].to, s);
   dtdq.add(E[r].to, E[r].from, t);
   PL(dtdq.query(x, y))
*/

void solve() {

   ll N; cin>>N;
   ll Q; cin>>Q;
   Edges<ll> E = readE<ll>(N-1, -1, false);//weighted?
   Graph<ll> G(N, E, false);//directed?

   DirectedTreeDistQuery<ll> dtdq(N, G, 0);
   ///6-5 = 6-2-7-5 = 
   EL(dtdq.et.in)
   EL(dtdq.et.out)
   rep(q,Q){
      char c; cin>>c;
      if(c=='I'){
         ll r,s,t;
         cin>>r>>s>>t;
         r--;
         dtdq.set(E[r].from, E[r].to, s);
         dtdq.set(E[r].to, E[r].from, t);
         // rep(i,N) rep(j,N){ES(i+1) ES(j+1) EL(dtdq.query(i,j))}

      }
      else{
         ll x,y;
         cin>>x>>y;
         x--, y--;
         PL(dtdq.query(x, y))
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
