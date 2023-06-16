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
/*
   ll N; cin>>N;
   Edges<ll> E = readE<ll>(N-1, -1, true);//weighted?
   Graph<ll> G(N, E, false);//directed?
   EulerTour<ll> et(N, G, 0);//root
   EulerTour<ll> et(N, G, 0, true, true);//root, mid, out
   et.lca(x,y);
   et.size()

   vector<int> in;//頂点iを始めて訪れた時刻
   vector<int> out;//頂点iを出た時刻
   vector<int> depth;//depth[i]:=頂点iの深さ
   vector<int> parent;//parent[i]:=頂点iの親．
   vector<vector<int>> children;//children[i]:=頂点iの直属の子
   vector<int> numOfChildren;//子孫の数．
   vector<T> dist;//dist[i]:=根から頂点iまでのコスト
   vector<int> order;//order[i]:=時刻iに訪れた頂点
   vector<int> dep;//dep[i]:=時刻iの深さ
*/

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
template<typename T> T opMax(T a, T b){return max(a,b);}
template<typename T> T opMin(T a, T b){return min(a,b);}
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T> T e_LINF(){return -INF;}
template<typename T> T eLINF(){return INF;}

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
#endif

void solve() {

   ll N; cin>>N;
   V<ll> P(N-1); cin>>P; P--;
   Edges<int> E;
   rep(i,N-1) E.push_back({P[i], i+1});
   Graph<int> G(N, E, false);//directed?
   EL(0)
   EulerTour<int> et(N, G, 0);//root

   EL(et.in)
   EL(et.out)

   EL(1)
   RmQ<int> seg(et.size());
   rep(i,N) seg.set(et.in[i], i);
   EL(2)



   ll Q; cin>>Q;
   rep(q,Q){
      ll t;  cin>>t;
      if(t==1){
         ll u,v;
         cin>>u>>v;
         u--, v--;
         int a = seg.prod(et.in[v], et.out[v]);
         if(seg.get(et.in[u])>a) seg.set(et.in[u], a);
         int b = seg.prod(et.in[v], et.in[v]);
         if(seg.get(et.in[v])>b) seg.set(et.in[v], b);
      }
      else{
         ll x; cin>>x;
         x--;
         int a = seg.prod(et.in[x], et.out[x]);
         while(seg.get(et.in[x])>a||seg.prod(et.in[x], et.out[x])!=a ||seg.prod(et.in[a], et.out[a])!=a){
            EL(a)
            seg.set(et.in[x], a);
            x = a;
            a = seg.prod(et.in[x], et.out[x]);
         }
         ES(x)
         PL(seg.prod(et.in[x], et.out[x])+1)
      }
      // rep(i,N){ES(i) EL(seg.prod(et.in[i], et.out[i]))}
   }

   return;
}


void solve2() {

   ll N; cin>>N;
   V<ll> P(N-1); cin>>P; P--;
   Edges<int> E;
   rep(i,N-1) E.push_back({P[i], i+1});
   Graph<int> G(N, E, false);//directed?
   EL(0)
   EulerTour<int> et(N, G, 0);//root

   EL(et.in)
   EL(et.out)

   EL(1)
   RmQ<int> seg(et.size());
   rep(i,N) seg.set(et.in[i], i);
   EL(2)



   ll Q; cin>>Q;
   rep(q,Q){
      ll t;  cin>>t;
      if(t==1){
         ll u,v;
         cin>>u>>v;
         u--, v--;
         while(seg.get(et.in[u])>v){
            int a = seg.get(et.in[a]);
            if(seg.get(et.in[u])>a) seg.set(et.in[u], a);
         }
      }
      else{
         ll x; cin>>x;
         x--;
         PL(seg.prod(et.in[x], et.out[x])+1)
      }
      // rep(i,N){ES(i) EL(seg.prod(et.in[i], et.out[i]))}
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
