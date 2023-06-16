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
// #define endl "\n"
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


template <typename T>
struct HLD{
   int N;
   vector<int> sz;
   vector<int> in;
   vector<int> out;
   vector<int> head;//頂点iの属する成分の根
   vector<int> parent;
   vector<int> order;//時刻iに通る頂点
   vector<int> depth;//頂点iの深さ

   HLD(int N, Graph<T>& G, int root = 0)
   :N(N),
   sz(N, 0), 
   in(N, 0), 
   out(N, 0), 
   head(N, 0), 
   parent(N, 0), 
   order(N, 0), 
   depth(N, 0)
   {
      auto dfs_sz = [&](auto dfs_sz, int p, int par, int d)->void {
         depth[p] = d;
         parent[p] = par;
         sz[p] = 1;
         for(auto& e:G[p]) if(e.to!=par){
            dfs_sz(dfs_sz, e.to, p, d+1);
            sz[p] += sz[e.to];
            //一番大きな部分木を先頭に
            if(sz[G[p][0].to] < sz[e.to]) swap(G[p][0], e);
         }
      };
      dfs_sz(dfs_sz, root, -1, 0);

      int t = 0;
      auto dfs_hld = [&](auto dfs_hld, int p, int par)->void {
         in[p] = t++;
         order[in[p]] = p;
         for(auto& e:G[p]) if(e.to!=par){
            head[e.to] = (G[p][0].to==e.to? head[p]:e.to);
            dfs_hld(dfs_hld, e.to, p);
         }
         out[p] = t;
      };
      dfs_hld(dfs_hld, root, -1);
   }





   int la(int v, int k){
      while(1){
         int u = head[v];
         if(in[v] - k >= in[u]) return order[in[v]-k];
         k -= in[v] - in[u] + 1;
         v = parent[u];
      }
   }

   int lca(int u, int v){
      for(;; v = parent[head[v]]){
         if(in[u] > in[v]) swap(u,v);
         if(head[u] == head[v]) return u;
      }
   }

   int dist(int u, int v){
      return depth[u] + depth[v] - depth[lca(u,v)]*2;
   }

   template <typename Q>
   void add(int u, int v, const Q q, bool edge = false){
      for(;;v = parent[head[v]]){
         if(in[u] > in[v]) swap(u, v);
         if(head[u] == head[v]) break;
         q(in[head[v]], in[v] + 1);
      }
      q(in[u]+edge, in[v]+1);
   }

   template<typename E, typename Q, typename F, typename S >
   E query(int u, int v, const E e, const Q& q, const F& f, const S& s, bool edge = false){
      E l = e, r = e;
      for(;;v = parent[head[v]]){
         if(in[u] > in[v]) swap(u, v), swap(l, r);
         if(head[u] == head[v]) break;
         l = f(q(in[head[v]], in[v]+1), l);
      }
      return s(f(q(in[u]+edge, in[v]+1), l), r);
   }

   template<typename E, typename Q, typename F>
   E query(int u, int v, const E& e, const Q& q, const F& f, bool edge = false){
      return query(u, v, e, q, f, f, edge);
   }

};

/*

*/
/*
   ll N; cin>>N;
   Edges<int> E = readE<int>(N-1, -1, true);//weighted?
   Graph<int> G(N, E, false);//directed?
   HLD hld(N, G, 0);
   RSQ<ll> seg(N);

   for(auto& e:E){
      //更新．a==bの時もあるので，1点更新の場合は気を付ける．
      //辺の場合はb-1, 頂点ならa
      auto update = [&](int a, int b)->void {//a:in[u]+edge, in[v]+1
         if(a!=b) seg.set(b-1, e.cost);
      };
      hld.add(e.from, e.to, update, true);
   }

   ll u, v;
   cin>>u>>v;
   u--, v--;
   auto e = 0LL;//単位元
   auto q = [&](int a, int b)->ll {return seg.prod(a, b);};//同成分の積．//a:in[u]+edge, in[v]+1
   auto f = [&](ll a, ll b)->ll {return a + b;};//異成分同士の積
   auto g = [&](ll a, ll b)->ll {return a + b;};//異成分同士の積
   PL(hld.query(u, v, e, q, f, g, true))
   abc294G6
*/

#if __has_include(<atcoder/lazysegtree>)
#include <atcoder/lazysegtree>
using namespace atcoder;
#endif

namespace Lazy{
   template<typename T>
   struct S{
      T x;
      ll size=1;
   };

   template<typename T>
   struct F{
      T a,b;
   };

   template<typename T> S<T> opSum(S<T> l, S<T> r){return S<T>{l.x+r.x, l.size+r.size};}
   template<typename T> S<T> opMax(S<T> l, S<T> r){return (l.x>=r.x?l:r);}
   template<typename T> S<T> opMin(S<T> l, S<T> r){return (l.x<=r.x?l:r);}

   template<typename T> S<T> e0(){return S<T>{0, 1};}
   template<typename T> S<T> eLINF(){return S<T>{LINF, 1};}
   template<typename T> S<T> e_LINF(){return S<T>{-LINF, 1};}

   template<typename T>
   S<T> FS(F<T> f, S<T> s){
      return S<T>{f.a*s.x+f.b*s.size, s.size};//ax+b
   }

   template<typename U=ll>
   F<U> FF(F<U> l, F<U> r){
      return F<U>{l.a*r.a, l.a*r.b+l.b};
   }

   template<typename U=ll>
   F<U> f0(){
      return F<U>{1,0};
   }
   template<typename T=ll> using LazyRSQ = lazy_segtree<S<T>, opSum<T>, e0<T>,     F<T>, FS<T>, FF<T>, f0<T>>;
   template<typename T=ll> using LazyRMQ = lazy_segtree<S<T>, opMax<T>, e_LINF<T>, F<T>, FS<T>, FF<T>, f0<T>>;
   template<typename T=ll> using LazyRmQ = lazy_segtree<S<T>, opMin<T>, eLINF<T>,  F<T>, FS<T>, FF<T>, f0<T>>;
   /*
   ll N,Q; cin>>N>>Q;
   V<ll> A(N); cin>>A;
   Lazy::LazyRSQ<mint> tree(N);
   rep(i,N) tree.set(i, {A[i],1});// {x, size}

   tree.apply(l,r,LS::F<mint>{a,b});//ax+b
   cout<<tree.prod(l,r).x<<endl;
   */
}

void solve() {

   ll N; cin>>N;
   ll Q; cin>>Q;
   Edges<int> E = readE<int>(N-1, 0, false);//weighted?
   Graph<int> G(N, E, false);//directed?
   HLD hld(N, G, 0);
   Lazy::LazyRSQ<ll> seg(N);

   int p = 0;
   rep(q,Q){
      ll t; cin>>t;
      if(t==0){
         ll i,k;
         cin>>i>>k;
         //ES(hld.in[i]) ES(hld.order[hld.out[i]]) EL(k/hld.sz[i])
         seg.apply(hld.in[i], hld.out[i], {1, k/hld.sz[i]});
         EL(hld.sz[i])
      }
      else{
         ll i; cin>>i;
         auto e = 0LL;//単位元
         auto q = [&](int a, int b)->ll {
            ll ret = seg.prod(a, b).x;
            seg.apply(a,b,{0,0});
            return ret;
         };//同成分の積．//a:in[u]+edge, in[v]+1
         auto f = [&](ll a, ll b)->ll {return a + b;};//異成分同士の積
         auto g = [&](ll a, ll b)->ll {return a + b;};//異成分同士の積
         PL(hld.query(p, i, e, q, f, g, false))
         p = i;
      }
      rep(i,N){
         ES(i) EL(seg.prod(hld.in[i], hld.in[i]+1).x)
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
