#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
//#define ONLINE_JUDGE 1
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
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqr = priority_queue<T, vector<T>, greater<T>>;
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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
// using mint = atcoder::static_modint<MOD>;
using mint = atcoder::modint;
// mint::set_mod(MOD);
//制約: a/b -> gcd(b,mod)==1
template<int m> ostream &operator<<(ostream &os, const atcoder::static_modint<m> x) {os<<x.val();return os;}
template<int m> istream &operator>>(istream &is, atcoder::static_modint<m>& x){ll val; is >> val; x = val; return is;}
ostream &operator<<(ostream &os, const atcoder::modint x) {os<<x.val();return os;}
istream &operator>>(istream &is, atcoder::modint& x){ll val; is >> val; x = val; return is;}
#endif

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
/*
   //メモリの許す限り無限
   mp::cpp_int x = 1;
   mp::int128_t 1e36
   mp::int256_t 1e70
   mp::int512_t 1e150
   mp::int1024_t 1e300

   文字列->整数
   cpp_int x("123");
   x.assign("123");

   整数->文字列
   string s = x.str();
   x.str(0, std::ios_base::oct,hex,)

   劣型変換
   int128_t i128 = static_cast<int128_t>(i256)
*/

template<typename T = long long int >
T POW(long long a, long long b, long long mod = 0){
   T ret = 1;
   T tmp = a;
   if(mod) tmp%=mod;
   while(b){
     if(b&1){
       ret *= tmp;
       if(mod) ret%=mod;
     }
     b /= 2;
     if(b) tmp *= tmp;
     if(mod) tmp%=mod;
   }
   return ret;
}
// ll result = POW(5,3); ->125
// POW<boost::mp::int128_t>(a,x,mod);

void solve() {

   ll A,X,M; cin>>A>>X>>M;

   if(A==1) END(X%M)

   // mint::set_mod(M*(A-1));
   // mint ans = mint(A).pow(X)-1;
   // EL(ans)
   // ans /= A-1;
   EL( (POW<mp::int128_t>(A,X,M*(A-1))/(A-1)))
   PL( ((POW<mp::int128_t>(A,X,M*(A-1))-1+M*(A-1))/(A-1)) %M)

   return;
}

#include "math/matrix/matrix.hpp"
//Matrix<mint> m(H,W)
//m.determinant()
void solve2(){
   ll A,X,M; cin>>A>>X>>M;
   // M = MOD;
   Matrix<mint> mat(2,2);
   mint::set_mod(M);

   /*
   1+A+A**2+..+A**N-1
   S1 = 1
   Si+1 = Si *A + 1
   A 1
   0 1
   */
   mat[0] = {A, 1};
   mat[1] = {0, 1};
   mat ^= X-1;
   EL(mat)
   mint ans = mat[0][0]+mat[0][1];
   PL(ans)
   return;
}

#include "math/matrix/matrix.hpp"
//Matrix<mint> m(H,W)
//m.determinant()
void solve3(){
   ll A,X,M; cin>>A>>X>>M;
   // M = MOD;
   Matrix<mint> mat(2,2);
   mint::set_mod(M);

   /*
   S1 = 1
   Si+1 = Si + A**n

   Si+1 1 A Si
   A*i+1  0 A A**i
   */
   mat[0] = {1, A};
   mat[1] = {0, A};
   mat ^= X-1;
   EL(mat)
   mint ans = mat[0][0]+mat[0][1];
   PL(ans)
   return;
}

void solve4(){
   ll A,X,M; cin>>A>>X>>M;
   mint::set_mod(M);

   map<ll,mint> mp;
   mp[1] = 1;
   auto dfs = [&](auto dfs, ll N)->void {
      EL(N)
      if(N==1){
         mp[1] = 1;
         return;
      }
      ll n = N/2;
      if(mp.find(n)==mp.end()){
         dfs(dfs, n);
      }
      mp[N] = mp[n]+mp[n]*mint(A).pow(n);
      if(n*2!=N) mp[N] += mint(A).pow(N-1);
   };
   dfs(dfs, X);
   PL(mp[X])
   for(auto p:mp) EL(p)

   ll N = 5;
   V<mint> B(N);
   B[0] = 1;
   rep(i,N-1) B[i+1] = B[i]*A;
   EL(B)
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve4();
   return 0;
}
