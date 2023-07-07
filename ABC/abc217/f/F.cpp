#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
// constexpr ll MOD = 998'244'353;
constexpr ll MOD = 1000'000'007;
// #define _GLIBCXX_DEQUE_BUF_SIZE 512
// #pragma comment(linker, "/stack:1000000000")

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
// using mint = atcoder::modint;
// mint::set_mod(MOD);
//制約: a/b -> gcd(b,mod)==1
template<int m> ostream &operator<<(ostream &os, const atcoder::static_modint<m> x) {os<<x.val();return os;}
template<int m> istream &operator>>(istream &is, atcoder::static_modint<m>& x){ll val; is >> val; x = val; return is;}
ostream &operator<<(ostream &os, const atcoder::modint x) {os<<x.val();return os;}
istream &operator>>(istream &is, atcoder::modint& x){ll val; is >> val; x = val; return is;}
#endif

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
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
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



#define endl "\n"

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
//Combination<mint> Comb(MaxSize);
//auto a = Comb.C(p,q);
//auto b = Comb.P(n,r);
//auto c = Comb.H(n,r);

void solve2() {

   ll N,M; cin>>N>>M;
   V<Pll> AB(M); cin>>AB;
   sort(ALL(AB)); AB--;

   Combination<mint> C(N*4+10);

   // [l][r][mergable]
   V<V<mint>> dp(N*2, V<mint>(N*2, 0));
   rep(i,N*2) dp[i][i] = 1;
   for(auto [a,b]:AB) if(a+1 == b) dp[a][b] = 1;
   repi(d,1,N*2){
      rep(l,N*2){
         ll r = l + d;
         if(r>=N*2) break;

         for(ll m = l+1; m+1<r; m++){
            if((m-l)%2==0) continue;
            if((r-(m+1))%2==0) continue;
            ll cl = (m-l+1)/2;
            ll cr = (r-(m+1)+1)/2;
            mint c =  C.C(cl+cr, cl);
            dp[l][r] += dp[l][m] * dp[m+1][r] * c;// / (cl+cr-1);
            ES(l) ES(m) ES(m+1) ES(r) EL(dp[l][r])
         }

         if(binary_search(ALL(AB), Pll(l, r))){
            if((r-l)%2==0) continue;

            if(l+1<r-1)  dp[l][r] += dp[l+1][r-1];
         }
      }
   }
   
   PL(dp[0][N*2-1])

   rep(i,N*2){
      ES(i) EL(dp[i])
   }

   return;
}

void solve() {

   ll N,M; cin>>N>>M;
   V<Pll> AB(M); cin>>AB;
   sort(ALL(AB)); AB--;

   Combination<mint> C(N*4+10);

   // [l][r][mergable]
   V<V<mint>> dp(N*2+1, V<mint>(N*2+1, 0));
   rep(i,N*2+1) dp[i][i] = 1;
   // for(auto [a,b]:AB) if(a+1 == b) dp[a][b] = 1;
   repi(d,1,N*2){
      rep(l,N*2){
         ll r = l + d + 1;
         if(r>N*2) break;

         if(binary_search(ALL(AB), Pll(l, r-1))){
            // if((r-l)%2==0) continue;

            for(ll m = l+1; m<=r-1; m++){
               // if((m-l)%2==0) continue;
               // if((r-(m+1))%2==0) continue;
               ll cl = (m-l)/2;
               ll cr = (r-m)/2;
               mint c =  C.C(cl+cr, cl);
               dp[l][r] += dp[l+1][m] * dp[m][r-1] * c;// / (cl+cr-1);
               ES(l) ES(m) ES(m) ES(r) EL(dp[l][r])
            }

            //if(l+1<r-1)  dp[l][r] += dp[l+1][r-1];
         }
      }
   }
   
   PL(dp[0][N*2])

   rep(i,N*2+1){
      ES(i) EL(dp[i])
   }

   return;
}

void solve3(){
   ll N,M; cin>>N>>M;
   V<Pll> AB(M); cin>>AB;
   sort(ALL(AB)); AB--;

   Combination<mint> C(N*4+10);

   V<V<mint>> dp(N+2, V<mint>(N/2+2));
   rep(i,2*N+1) dp[i][0] = 1;

   V<V<mint>> b(N, V<mint>(N));
   b[0][0] = 1;
   for(ll i=1;i<N;i++){
      b[i][0] = 1;
      b[i][i] = 1;
      rep(j,i-1){
         b[i][j+1] = b[i-1][j] + b[i-1][j+1];
      }
   }

   for(ll j=1;j<=N;j++){
      for(ll i = 0; i<2*(N-j)+1; i++){
         dp[i][j] = 0;
         rep(k,j){
            if(binary_search(ALL(AB), Pll(i, i+(2*k) +1)) || binary_search(ALL(AB), Pll(i+(2*k) +1, i))){
               // dp[i][j] += dp[i+1][k] * dp[i+(2*k)+2][j-k-1] * C.C(j*2,2*(k+1));
               dp[i][j] += dp[i+1][k] * dp[i+(2*k)+2][j-k-1] * b[j][k+1];
            }
         }
      }
   }
   PL(dp[0][N])
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