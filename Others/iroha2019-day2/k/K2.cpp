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

#include "graph/tree/hld/hld.hpp"
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
