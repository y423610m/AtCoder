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

#include "graph/graph_template.hpp"
/*
   ll N,M; cin>>N>>M;
   Edges<int> E = readE<int>(M, -1, true);//weighted?
   Graph<int> G(N, E, false, false);//directed? reverse?
   //Graph<int> G(N); G.read(M, -1, true, true);
*/

#include "utils/timer.hpp"


#define endl "\n"

void solve() {

   Timer timer;


   ll N,M; cin>>N>>M;
   Edges<ll> E = readE<ll>(M, -1, true);//weighted?
   Graph<ll> G(N, E, true, false);//directed? reverse?

   //dp[i][j]:=mask, pos
   V<V<ll>> dp(1<<N, V<ll>(N, LINF));


   min_heap<Tlll> que;//dist, mask, pos

   {//check dig
      V<ll> in(N);
      V<ll> out(N);
      rep(i,N) for(const auto& e:G[i]){
         in[e.to]++;
         out[e.from]++;
      }

      set<ll> st;
      {//check in
         map<ll,V<ll>> mp;
         rep(i,N) mp[in[i]].push_back(i);
         if(mp[0].size()>=2) END(No)
         if(mp[0].size()==1) st.insert(mp[0][0]);
         else rep(i,N) st.insert(i);
      }

      {//check out
         map<ll,V<ll>> mp;
         rep(i,N) mp[out[i]].push_back(i);
         if(mp[0].size()>=2) END(No)
         if(mp[0].size()==1) st.erase(mp[0][0]);
      }

      for(auto s:st){
         dp[1<<s][s] = 0;
         que.push({0, -(1<<s), s});
      }
   }
   


   while(!que.empty()){
      if(timer.pass(5900)) break;
      auto [d, mask, p] = que.top(); que.pop();
      mask = -mask;
      if(dp[mask][p]<d) continue;
      for(const auto& e:G[p]){
         ll nxtmask = mask | (1<<e.to);
         ll D = dp[mask][p] + e.cost;
         if(dp[nxtmask][e.to] > D) {
            dp[nxtmask][e.to] = D;
            que.push({D, -nxtmask, e.to});

            if(rand()%10 < 5) continue;

            //propagate
            ll m = nxtmask;
            m ^= 1<<e.to;
            m--;
            m &= nxtmask;
            while(m!=0){
               if(dp[m|(1<<e.to)][e.to] > D){
                  dp[m|(1<<e.to)][e.to] = D;
               }
               else break;
               m--;
               m &= nxtmask;
            }
         }
      }
   }

   ll ans = LINF;
   rep(i,N) chmin(ans, dp[(1<<N)-1][i]);

   if(ans==LINF) PL(No)
   else PL(ans)


   return;
}


//Timer timer;
//if(timer.pass()) PL(timer.time())
//TIMER_LOG(timer, "comment")
//timer.print();
void solve1() {

   Timer timer;

   ll N,M; cin>>N>>M;
   Edges<ll> E = readE<ll>(M, -1, true);//weighted?
   Graph<ll> G(N, E, true, false);//directed? reverse?

   //dp[i][j]:=mask, pos
   V<V<ll>> dp(1<<N, V<ll>(N, LINF));
   V<V<ll>> nxt(1<<N, V<ll>(N, LINF));
   rep(i,N) dp[1<<i][i] = 0;

   while(!timer.pass(5800)){
      nxt = dp;
      rep(i,N) for(const auto& e:G[i]){
         ll mask = (1<<N)-1;
         while(mask>0) {
            chmin(nxt[mask|(1<<e.to)][e.to], dp[mask][e.from]+e.cost);
            mask--;
            mask &= 1<<e.from;
         }
      }
      swap(dp, nxt);
   }
   ll ans = LINF;
   rep(i,N) chmin(ans, dp[(1<<N)-1][i]);

   if(ans>INF) PL(No)
   else PL(ans)
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
ABC338 5完
A やる
B map
C Aの数決めて二分探索
D 区間Add, Minの遅延セグ木．使わなかった場合どれだけ距離が長くなるか足していく
E ABをsortして順番にセグ木に入れる．
F dp[mask][現在地]でダイクストラかと思ったが．．．10TLE．解説観て納得しかない．
*/