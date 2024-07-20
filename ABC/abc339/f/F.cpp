#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// using ll = long long int;
using ll = int;
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
// constexpr ll INF = (1LL<<30)-1;
// constexpr ll LINF = (1LL<<62)-1;
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


#if __has_include(<atcoder/convolution>)
#include <atcoder/convolution>
using namespace atcoder;
/*
V<int> A(n), B(m);
auto C = atcoder::convolution<MOD>(A, B);
*/
#endif

#define endl "\n"

void solve() {

   ll N; cin>>N;
   V<string> S(N); cin>>S;

   //sort
   sort(ALL(S), [&](auto& a, auto b){
      if(a.size()!=b.size()) return a.size()<b.size();
      return a<b;
   });

   V<V<ll>> G(N);
   rep(i,N){
      G[i].reserve(S[i].size());
      rep(j,S[i].size()){
         G[i].push_back(S[i][j]-'0');
      }
   }
   rep(i,N) EL(G[i])

   ll M = 2000;
   vector<ll> All(M*N);
   rep(i,N){
      rep(j,G[i].size()){
         All[M*(i+1)-G[i].size()+j] = G[i][j];
      }
   }
   // reverse(ALL(All));

   map<V<ll>, ll> cnt;
   rep(i,N) cnt[G[i]]++;

   ll ans = 0;

   auto Process = [&](vector<ll>& a, int id, vector<ll>& cache)->void {
      cache.clear();
      rep(i,M){
         cache.push_back(a[M*id+i]);
      }
      reverse(ALL(cache));
      while(cache.back()==0) cache.pop_back();
      rep(i,cache.size()){
         if(cache[i]>=10){
            ll r = cache[i]/10;
            cache[i] %= 10;
            if(i+1<cache.size()) cache[i+1] += r;
            else cache.push_back(r);
         }
      }
      reverse(ALL(cache));
   };

   vector<ll> prod;
   //積計算．すぐ終わるはず
   rep(i,N){
      auto res = atcoder::convolution(G[i], All);
      reverse(ALL(res));
      res.resize(M*(N+1));
      reverse(ALL(res));
      EL(res.size())
      rep(j,N){
         Process(res, j, prod);
         ES(i) ES(j) ES(G[i]) ES(G[j]) EL(prod)
         if(prod.size() > G.back().size()) break;
         // Process(prod);
         if(prod.size() == G.back().size() && prod>G.back()) break;
         ll cand = cnt[prod];
         ans += cand;
         // if(i!=j) ans += cand;
         EL(cand)
      }
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

/*
ABC339 ５完
A python
B やる
C 累積和の最小値
D 4次元dp
E 遅延セグ木
F convolutionとか多倍長整数とか考えたもののTLE

*/