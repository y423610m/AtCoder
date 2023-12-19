#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;
// #define _GLIBCXX_DEQUE_BUF_SIZE 512
// #pragma comment(linker, "/stack:1000000000")


//mint


// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
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
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

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

#define endl "\n"

void solve() {

   ll N,D,W; cin>>N>>D>>W;

   V<Pll> TX(N); cin>>TX;
   sort(ALL(TX));

   ll ans = 0;
   ll sz = 200005;
   Lazy::LazyRMQ<ll> seg(sz);
   rep(i, sz) seg.set(i, {0,1});
   queue<Pll> que;
   rep(i,N){
      {
         auto [t, x] = TX[i];
         ll l = x;
         ll r = x+W;
         chmax(l, 0);
         chmin(r, sz);
         que.push(TX[i]);
         seg.apply(l, r, Lazy::F<ll>{1, 1});
      }
      while(!que.empty() && TX[i].fi-que.front().fi>=D){
         auto [t, x] = que.front();
         ll l = x;
         ll r = x+W;
         chmax(l, 0);
         chmin(r, sz);
         que.pop();
         seg.apply(l, r, Lazy::F<ll>{1, -1});
      }
      ll cand = seg.prod(0, sz).x;
      ES(i) EL(cand)
      chmax(ans, cand);
   }

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

/*
ABC327 6完
A for
B for
C for
D 重み付きUF
E 分子だけで2次元dp.一部小数精度足りず2WA
F 時間でソートして遅延セグ木．[x, x+W)に±1していく
G ?
*/