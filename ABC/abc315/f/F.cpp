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



#define endl "\n"

void solve() {

   ll N; cin>>N;
   V<Pll> XY(N); cin>>XY;

   auto calcDist = [&](int i, int j)-> ld {
      return sqrt((XY[i].fi-XY[j].fi)*(XY[i].fi-XY[j].fi) 
      + (XY[i].se-XY[j].se)*(XY[i].se-XY[j].se));
   };

   // dp[i][j]　
   V<V<ld>> dp(N+1, V<ld>(N+1, LINF));
   rep(i,N-1) dp[i][i+1] = calcDist(i,i+1);
   rep(i,N) dp[i][i] = 0;

   // for(ll l=N-2;l>=0;l--){
   //    for(ll r=l+1;r<N;r++){
   //       for(ll m=l;m<=r;m++){
   //          chmin(dp[l][r], dp[l][m]+dp[m][r]);
   //          chmin(dp[l][r], dp[l][m]+);
   //       }
   //    }
   // }

   PL(dp[0][N-1])

   return;
}

void solve2(){
   ll N; cin>>N;
   V<Pll> XY(N); cin>>XY;
   auto calcDist = [&](int i, int j)-> ld {
      return sqrt((XY[i].fi-XY[j].fi)*(XY[i].fi-XY[j].fi) 
      + (XY[i].se-XY[j].se)*(XY[i].se-XY[j].se));
   };

   V<ld> dp(N+1);
   rep(i,N-1) dp[i+1] = calcDist(i,i+1);
   rep(i,N) dp[i+1] += dp[i];

   rep(r,N){
      rep(l,r+1){
         chmin(dp[r], dp[l]+pow<ld>(2, r-l)-calcDist(l,r));
         ES(l) ES(r) EL(dp)
      }
   }
   EL(dp)
   PL(dp[N-1])

}

void solve3(){
   ll N; cin>>N;
   V<Pll> XY(N); cin>>XY;
   auto calcDist = [&](int i, int j)-> ld {
      return sqrt((XY[i].fi-XY[j].fi)*(XY[i].fi-XY[j].fi) 
      + (XY[i].se-XY[j].se)*(XY[i].se-XY[j].se));
   };

   EL(calcDist(0,1))

   //dp[i][j]:=iにいて，j回スキップ
   ll linf = LINF;
   ll M = N+1;
   V<V<ld>> dp(N+1, V<ld>(M+1, linf));
   dp[0][0] = 0;
   // rep(i,N-1) dp[i+1][0] = calcDist(i,i+1);
   // rep(i,N) dp[i+1][0] += dp[i][0];
   // EL(dp[1][0])
   // EL(dp[N-1][0])

   rep(i,N){
      for(ll c=0;c<M;c++) if(dp[i][c]!=linf){
         for(ll skip=0;skip<M;skip++){
            ll to = i + skip + 1;
            ll nxtSkip = c+skip;
            if(to >= N) break;
            if(nxtSkip>=M) break;
            chmin(dp[to][nxtSkip], dp[i][c]+calcDist(i, to));
         }
      }
   }

   rep(i,N){
      ES(i) EL(dp[i])
   }

   ld ans = dp[N-1][0];
   repi(cnt,1,M){
      ld cand = dp[N-1][cnt] + pow<ld>(2, cnt-1);
      chmin(ans, cand);
      ES(cnt) EL(cand)
   }
   PL(ans)

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}

/*
ABC315 5完
A やる
B やる．1WA
C multiset
D 縦横の各列の各文字の個数覚える
E bfs2回くらいした．もっといい実装ありそう．
F dp[i][j]:=iに居て，j回スキップした最小値．解説のスキップの上限が100程度でいいことに気付かず．
*/