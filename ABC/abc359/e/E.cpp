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
using Tiii = tuple<int, int, int>;
using Tiiii = tuple<int, int, int, int>;
using Pll = pair<ll,ll>;
using Tlll = tuple<ll,ll,ll>;
using Tllll = tuple<ll,ll,ll,ll>;
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
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream&, const std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream& os, const std::tuple<T...>& tup){if (n != 0){os << " ";} os << std::get<n>(tup); print_tuple<n+1>(os, tup);}
template <typename... T> std::ostream& operator<<(std::ostream& os, const std::tuple<T...>& tup) {print_tuple<0>(os, tup); return os;}
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>& tup){is>> std::get<n>(tup); input_tuple<n+1>(is, tup);}
template <typename... T> std::istream& operator>>(std::istream& is, std::tuple<T...>& tup) {input_tuple<0>(is, tup); return is;}
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

template <typename T> vector<T> CCompress(vector<T>& A){
   vector<T> B = A;
   sort(B.begin(), B.end());
   B.erase(unique(B.begin(), B.end()), B.end());
   for(int i=0;i<(int)A.size();i++){
      A[i] = (int)(lower_bound(B.begin(), B.end(), A[i]) - B.begin());
   }
   return B;
}
//vector<int> A = {1,100,5,5};
//auto B = CCompress(A);
//-> A={0,2,1,1}, B={1,5,100}

//重複を許さない座標圧縮．同じ数字は先出から割り振る
template<typename T>
void reorder(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(auto& a:A){
        auto it = lower_bound(B.begin(), B.end(), a);
        a = it - B.begin();
        (*it)--;
    }
}

//重複を許さない座標圧縮．同じ数字は後方から割り振る
template<typename T>
void reorder_rev(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(int i=A.size()-1;i>=0;i--){
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        A[i] = it - B.begin();
        (*it)--;
    }
}

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

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
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
#endif

#define endl "\n"

void solve() {

   ll N; cin>>N;
   V<ll> oriH(N);
   rep(i,N) cin>>oriH[i];

   auto comH = oriH;
   auto mp = CCompress(comH);

   
   Lazy::LazyRSQ<ll> segH(N+1);
   Lazy::LazyRSQ<ll> segQ(N);
   ll ans = 1;
   V<ll> result;
   rep(i,N){
      segH.apply(0, comH[i], {0, i+1});
      ll l = segH.prod(comH[i], comH[i]+1).x;
      ll c = segQ.prod(l, i+1).x;
      ll res = (i+1-l)*oriH[i];
      ans += res-c;
      segQ.apply(l, i+1, {0, oriH[i]});
      ES(i) ES(oriH[i]) ES(comH[i]) ES(l) ES(c) ES(res) EL(ans)
      result.push_back(ans);
   }
   PL(result)


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
