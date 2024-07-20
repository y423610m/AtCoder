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

#include <boost/multiprecision/cpp_dec_float.hpp>
namespace mp = boost::multiprecision;
/*
https://boostjp.github.io/tips/multiprec-float.html
    mp::cpp_dec_float_100 a,b;

    cpp_dec_float_50 x;
    cpp_dec_float_100 y;

    //ユーザー定義．桁数が1000桁で指数部が64bitで表される型
    typedef mp::number<mp::cpp_dec_float<1000, std::int64_t> > cpp_dec_float_1000_64exp;

    -----OpenGMPによる多倍長------
    #include <boost/multiprecision/gmp.hpp>
    mpf_float_50
    mpf_float_100
    mpf_float_500
    mpf_float_1000
    mpf_float

    -----小数->文字列
    cpp_dec_float_50 x = 3.14;
    x.str();

    -----文字列->小数
    cpp_dec_float_100 x("3.14");// char配列から変換
    cpp_dec_float_100 y(std::string("3.14"));
    x.assign("3.14");

    -----劣精度変換.優精度なら暗黙変換
    cpp_dec_float_50 f50 = static_cast<cpp_dec_float_50>(cpp_dec_float_100(3.14));
ABC169C
*/

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

#define endl "\n"

void solve() {

   ll N; cin>>N;
   ll A,B; cin>>A>>B;
   V<ll> C(N); cin>>C;
   sort(RALL(C));

   map<ll, ll> R, L;
   rep(i,N) R[C[i]]++;

   ll M = 0;
   rep(i, A) M += C[i];

   // rep(i,A){
   //    R[C[i]]--;
   //    L[C[i]]++;
   // }
   ll last = C[A-1];

   auto f = [&](int i)->ll {
      mp::int1024_t res = 1;
      ll c = C[i];
      ll n = R[c] + L[c];
      ll r = R[c];

      rep(i,r) res *= (n-i);
      rep(i,r) res /= (r-i);
      ES(i) ES(n) ES(r) EL(res)

      return static_cast<ll>(res);
   };

   ll sum = 0;
   ll ans = 0;
   for(ll i=0;i<N;i++){
      L[C[i]]++;
      R[C[i]]--;
      sum += C[i];
      if(R.begin()->second==0) R.erase(R.begin());

      // sum / i = M / A
      if(A<=i+1 && i+1<=B && sum * A == M * (i+1)){
         ans += f(i);
      }
      if(R.begin()->second==0) R.erase(R.begin());
   }

   PL(1.0 * M / A) PL(ans)

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
