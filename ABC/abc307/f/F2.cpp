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

#include "graph/graph_template.hpp"
/*
   ll N,M; cin>>N>>M;
   Edges<int> E = readE<int>(M, -1, true);//weighted?
   Graph<int> G(N, E, false, false);//directed? reverse?
   //Graph<int> G(N); G.read(M, -1, true, true);
*/

#define endl "\n"

void solve() {

   ll N,M; cin>>N>>M;
   Edges<ll> E = readE<ll>(M, -1, true);//weighted?
   Graph<ll> G(N, E, false, false);//directed? reverse?
   EL(0)
   ll K; cin>>K;
   V<ll> A(K); cin>>A; A--; sort(ALL(A));
   EL(1)
   ll D; cin>>D;
   V<ll> X(D); cin>>X;
   EL(2)

   using P = Pll;
   min_heap<P> after;//
   min_heap<P> today;//dist 
   queue<P> que;

   V<ll> ans(N, LINF);
   V<ll> cand(N, LINF);
   rep(i,K){
      ans[A[i]] = 0;
      for(const auto& e:G[A[i]]) if(!binary_search(ALL(A), e.to)) {
         after.push({e.cost, e.to});
         // chmin(cand[e.to], e.cost);
      }
   }

   rep(i,D){
      
      while(!after.empty()){
         auto [d, p] = after.top();
         ES(i) ES(0) ES(d) EL(p)
         if(d>X[i]) break;
         after.pop();
         // if(ans[p]!=i+1) continue;
         if(ans[p]!=LINF) continue;
         today.push({d, p});
         // chmin(ans[p], i+1);

         // for(const auto& e:G[p]){
         //    if(ans[e.to]!=LINF) continue;
         //    // if(cand[e.to]==LINF) continue;
         //    if(d+e.cost <= X[i]){
         //       today.push({d+e.cost, e.to});
         //       chmin(ans[e.to], i+1);
         //    }
         // }
      }
      while(!today.empty()){
         auto [d, p] = today.top();
         ES(i) ES(1) ES(d) EL(p)
         today.pop();
         if(ans[p]!=LINF) continue;
         // chmin(ans[p], i+1);
         ans[p] = i+1;

         for(const auto& e:G[p]){
            if(ans[e.to]!=LINF) continue;
            // if(cand[e.to]==LINF) continue;
            if(d+e.cost <= X[i]){
               today.push({d+e.cost, e.to});
               // chmin(ans[e.to], i+1);
            }
            else {
               after.push({e.cost, e.to});
               // chmin(cand[e.to], e.cost);
            }
         }
      }
   }

   rep(i,K) ans[A[i]] = 0;

   rep(i,N){
      if(ans[i]==LINF) PL(-1)
      else PL(ans[i])
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
