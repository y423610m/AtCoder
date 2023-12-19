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

namespace Long1Bits{
   template<typename T>
   struct S{
      T lenL=1;
      T lenR=1;
      T long0=1;
      T long1=0;
      bool isL1 = false;
      bool isR1 = false;
      ll size=1;
   };

   template<typename T>
   struct F{
      T a;
   };

   template<typename T> S<T> opMax(S<T> l, S<T> r){
      S<T> s;
      s.lenR = r.lenR;
      s.lenL = l.lenL;
      s.isL1 = l.isL1;
      s.isR1 = r.isR1;
      s.long1 = max(r.long1, l.long1);
      s.long0 = max(r.long0, l.long0);
      if(l.isR1&&r.isL1){
         if(s.long1 < l.lenR + r.lenL){
            s.long1 = l.lenR + r.lenL;
            if(l.lenR==l.size) s.lenL = s.long1;
            if(r.lenL==r.size) s.lenR = s.long1;
         }
      }
      if(!l.isR1&&!r.isL1){
         if(s.long0 < l.lenR + r.lenL){
            s.long0 = l.lenR + r.lenL;
            if(l.lenR==l.size) s.lenL = s.long0;
            if(r.lenL==r.size) s.lenR = s.long0;
         }
      }
      s.size = l.size + r.size;
      return s;
   }

   template<typename T> S<T> e(){return S<T>();}

   template<typename T>
   S<T> FS(F<T> f, S<T> s){
      if(f.a==0) return s;
      s.isR1 ^= 1;
      s.isL1 ^= 1;
      swap(s.long1, s.long0);
      return s;
   }

   template<typename U=ll>
   F<U> FF(F<U> l, F<U> r){
      return F<U>{l.a^r.a};
   }

   template<typename U=ll>
   F<U> f0(){
      return F<U>{0};
   }
   template<typename T=ll> using LazyRMQ = lazy_segtree<S<T>, opMax<T>, e<T>, F<T>, FS<T>, FF<T>, f0<T>>;
   /*
   ll N,Q; cin>>N>>Q;
   V<ll> A(N); cin>>A;
   Long1Bit::LazyRMQ<ll> seg(N);
   Long1Bits::S<ll> s;
   s.isL1 = true;
   s.isR1 = true;
   s.long1 = 1;
   s.long0 = 0;
   seg.set(i, s);

   seg.apply(L,R,{1});

   cout<<seg.prod(L,R).long1<<endl;
   */
}

#define endl "\n"

void solve() {

   ll N; cin>>N;
   ll Q; cin>>Q;
   string S; cin>>S;

   Long1Bits::LazyRMQ<ll> seg(N);
   rep(i,N){
      if(S[i]=='1'){
         Long1Bits::S<ll> s;
         s.isL1 = true;
         s.isR1 = true;
         s.lenL = 1;
         s.lenR = 1;
         s.long1 = 1;
         s.long0 = 0;
         seg.set(i, s);
      }
   }

   rep(q,Q){
      ll c,L,R;
      cin>>c>>L>>R;
      L--;
      if(c==1){
         seg.apply(L,R,{1});
      }
      else{
         PL(seg.prod(L,R).long1)
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

/*
ABC322　５完
A for
B T.substr() 誤読した
C lower_bound
D 再起関数で全探索．バグらせなかったのえらい
E 5次元dp.K<5のときはAの末尾に0を追加．メビウス使えば楽そう
F 遅延セグ木．各区間両端が1かどうか，最長1と最長0を保持すればいいはずなんだけど，なぜか合わず．
*/