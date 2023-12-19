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

#include "structure/wavelet_matrix/wavelet_matrix.hpp"
/*
   V<ll> A(N);
   CompressedWaveletMatrix< ll, 31 > mat(A);
   mat.get(a);//昇順index
   mat.access(k);//全体昇順k番目
   mat[k];//上に同じ
   mat.kth_smallest(l, r, k);//区間内昇順k番目
   mat.kth_largest(l, r, k);
   mat.range_freq(l,r,upper);//最頻値?
   mat.range_freq(l,r,lower,upper);
   mat.prev_value(l,r,val);
   mat.next_value(l,r,val);
*/


#define endl "\n"

void solve() {

   ll N,K; cin>>N>>K;
   V<ll> P(N); cin>>P;
   V<ll> len(N);
   {
      ll cnt = 0;
      for(ll i=N-2;i>=0;i--){
         if(P[i]<P[i+1]) cnt++;
         else cnt = 0;
         len[i] = cnt;
      }
   }
   EL(len)

   CompressedWaveletMatrix< ll, 31 > mat(P);

   V<ll> idx(N-K+1);
   rep(i,idx.size()) idx[i] = i;

   auto check = [&](ll a, ll b)->bool {
      ll p = min(a,b);
      ll l = len[p];
      if(l<K){
         ll i = p+l;
         ll va = (a<=i&&i<a+K)? mat.kth_smallest(a, a+K, i-a) :P[i];
         ll vb = (b<=i&&i<b+K)? mat.kth_smallest(b, b+K, i-b) :P[i];
         ES(a)ES(b) ES(i) ES(va) EL(vb)
         if(va!=vb) return va > vb;
      }

      p = max(a,b);
      l = len[p];
      if(l<K){
         ll i = p+l;
         ll va = (a<=i&&i<a+K)? mat.kth_smallest(a, a+K, i-a) :P[i];
         ll vb = (b<=i&&i<b+K)? mat.kth_smallest(b, b+K, i-b) :P[i];
         ES(a)ES(b) ES(i) ES(va) EL(vb)
         if(va!=vb) return va > vb;
      }
      return a<b;
   };

   while(idx.size()>1){
      if(!check(idx[0], idx.back())) swap(idx[0], idx.back());
      idx.pop_back();
   }

   ll id = idx[0];
   EL(idx)
   sort(P.begin()+id, P.begin()+id+K);
   PL(P)

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
