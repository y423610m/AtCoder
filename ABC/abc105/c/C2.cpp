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

vector<long long> digit0(long long a, int b=2, bool reverse_ = true){
    vector<long long> ret;
    while(a){
        ret.push_back(a%b);
        a/=b;
    }
    if(reverse_) reverse(ret.begin(), ret.end());
    return ret;
}
// vector<ll> dgt10 = digit(100,10) -> {1,0,0}
// vector<ll> dgt10 = digit(100,10,false) -> {0,0,1}
// vector<ll> dgt2 = digit(100,2) -> {1,1,0,0,1,0,0}

vector<ll> digit(ll n, ll base=2, bool reverse_ = true){
   assert(n>=0);
   vector<ll> ret;
   if(n==0){
      ret.push_back(0);
      return ret;
   }
   ll sig = 1;
   ll d = abs(base);
   while(n){
      ret.push_back((n*sig)%d);
      if(ret.back()<0) ret.back() += d;
      n -= ret.back() * sig;
      n /= d;
      sig *= base / abs(base);
   }
   if(reverse_) reverse(ret.begin(), ret.end());
   return ret;
}
/* 負の底ok.abc105 c beat参照
digit(6, 2) = {1,1,0} = 4+2
digit(6, 2, false) = {0,1,1} = 2 + 4  
digit(6, -2) = {1,1,0,1,0} = 16 -8  - 2
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

#define endl "\n"

void solve() {

   END(digit(6, -2))

   srand(0);
   rep(i,1000){
      ll n = rand() % 1000000000;
      ll base = rand() % 10000000;
      if(rand()%2==0) base = -base;
      
      auto ret0 = digit0(n,base);
      auto ret = digit(n,base);
      // if(ret0!=ret){
      //    ES(n) ES(base) ES(ret0) EL(ret)
      // }
      {
         ll a = 0;
         rep(i,ret.size()) a += POW(base, ret.size()-1-i) * ret[i];
         if(a!=n){
            ES(n) ES(base) ES(n) EL(a)
         }
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
