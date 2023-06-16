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

#include "graph/tree/euler_tour/euler_tour.hpp"
#include "graph/graph_template.hpp"
/*
   ll N,M; cin>>N>>M;
   Edges<int> E = readE<int>(M, -1, true);//weighted?
   Graph<int> G(N, E, true);//directed?
   //Graph<int> G(N); G.read(M, -1, true, true);
*/

#include "structure/segtree/segtree.hpp"
template<typename T> T opMax(T a, T b){return max(a,b);}
template<typename T> T opMin(T a, T b){return min(a,b);}
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T> T e_LINF(){return -LINF;}
template<typename T> T eLINF(){return LINF;}

template<typename T=ll> using RMQ = segtree<T, opMax<T>, e_LINF<T>>;//Range Max Query
template<typename T=ll> using RmQ = segtree<T, opMin<T>, eLINF<T>>;// RmQ tree(vec); tree.prod(l,r)
template<typename T=ll> using RSQ = segtree<T, opSum<T>, e0<T>>;

ll seg_target;
bool f(ll vi){return vi<seg_target;}//seg.max_right<f>(x-1)
bool f2(ll vi){return vi>=seg_target;}//seg.max_right<f>(x-1)
//max_right<f>(l):=>[l:N)でfを満たす右端．
//min_left<f>(r):=>[0:r)でfを満たす左端．
//f(e)=trueでなければならない
//RMQ<ll> tree(N);
//tree.set(i,0);
//tree.get(i);
//tree.prod(l,r);//半開区間



void solve() {

   ll N; cin>>N;
   Edges<ll> E = readE<ll>(N-1, -1, true);//weighted?
   Graph<ll> G(N, E, false);//directed?

   EulerTour<ll> et(N, G, 0);

   RSQ<ll> seg(3*N-1);
   for(auto e:E){
      int x = e.from;
      int y = e.to;
      if(et.in[x]>et.in[y]) swap(x,y);
      seg.set(et.in[y]-1, e.cost);
      seg.set(et.out[y], -e.cost);
   }

   ll Q; cin>>Q;
   rep(_,Q){
      int t; cin>>t;
      if(t==1){
         int id,w; cin>>id>>w;
         id--;
         auto& e = E[id];
         int x = e.from;
         int y = e.to;
         if(et.in[x]>et.in[y]) swap(x,y);
         seg.set(et.in[y]-1, w);
         seg.set(et.out[y], -w);
      }
      else{
         int x,y; cin>>x>>y; x--,y--;
         if(et.in[x]>et.in[y]) swap(x,y);
         int lca = et.lca(x, y);
         ll ans = 0;
         ans = seg.prod(0, et.in[x]) + seg.prod(0, et.in[y]) - seg.prod(0, et.in[lca])*2;
         PL(ans)
      }
   }

   rep(i,N){
      int x = 0;
      int y = i;
      if(et.in[x]>et.in[y]) swap(x,y);
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
