#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
// __uint128_t
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;

constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";

// #define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
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
template<typename T, typename U> void operator++(pair<T, U>& p){p.first++, p.second++;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first++, p.second++;}//post
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

//DRUL  SENW
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



void solve() {

   ll H,W,T; cin>>H>>W>>T;
   V<string> A(H); cin>>A;

   auto inGrid = [&](int nx, int ny){
      if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
      return false;
   };

   Pll S, G;
   V<Pll> O;
   rep(h,H) rep(w,W){
      if(A[h][w]=='S') S = {h,w};
      if(A[h][w]=='G') G = {h,w};
      if(A[h][w]=='o') O.push_back({h,w});
   }

   auto f = [&](ll sx, ll sy)->V<V<ll>> {
      V<V<ll>> dist(H,V<ll>(W, LINF));
      dist[sx][sy] = 0;
      queue<Pll> que;
      que.push({sx, sy});
      while(!que.empty()){
         auto [x, y] = que.front(); que.pop();
         rep(d,4){
            ll nx = x+dx[d];
            ll ny = y+dy[d];
            if(inGrid(nx, ny)&&A[nx][ny]!='#'){
               if(dist[nx][ny]>dist[x][y]+1){
                  dist[nx][ny] = dist[x][y]+1;
                  que.push({nx, ny});
               }
            }
         }
      }
      return dist;
   };

   auto dist0 = f(S.fi, S.se);

   if(dist0[G.fi][G.se]>T) END(-1)

   V<V<V<ll>>> dist1(O.size());
   rep(i,O.size()) dist1[i] = f(O[i].fi, O[i].se);

   V<V<ll>> dist2(O.size(), V<ll>(O.size()));
   rep(i,O.size()){
      rep(j,O.size()){
         dist2[i][j] = dist1[i][O[j].fi][O[j].se];
      }
   }

   rep(i,O.size()){
      rep(h,H) EL(dist1[i][h])
      EL("")
   }

   //dp[i][j]:=bitがi,最終地がjであるときの最小移動回数
   V<V<ll>> dp(1<<O.size(), V<ll>(O.size(), LINF));
   rep(i,O.size()) dp[1<<i][i] = dist0[O[i].fi][O[i].se];


   rep(mask, 1<<O.size()){
      rep(last, O.size()) if(dp[mask][last]!=LINF){
         rep(to, O.size()) {
            chmin(dp[mask|(1<<to)][to], dp[mask][last]+dist2[last][to]);
         }
      }
   }

   ll ans = 0;
   rep(i,1<<O.size()) rep(j,O.size()) if(dp[i][j]+dist1[j][G.fi][G.se]<=T) chmax(ans, __builtin_popcountll(i));
   PL(ans)
   // rep(i, 1<<O.size()) EL(dp[i])

   return;
}

//1の数
//__builtin_popcount()
//__builtin_popcountll()
//下から初めて1が現れる場所(1-indexed)
//__builtin_ffs()
//__builtin_ffsll()
//先頭に何個0があるか
//__builtin_clz()
//__builtin_clzll()
//末尾に何個0があるか
//__builtin_ctz()
//__builtin_ctzll()

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
