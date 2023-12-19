#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC optimize(2)
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

#include "graph/tree/complete_binary_tree.hpp"
/*
   CompleteBinaryTree cbt;
   cbt.SetN(N);//頂点数Nの場合
   //cbt.SetDepth(D);//深さD

   // 頂点は1-index
   ll n = cbt.CountDist(v, dist);//vから距離dの頂点数
   ll n = cbt.CountDescendants(v);//vの子孫数
   ll n = cbt.CountDescendantsDist(v, dist);//子孫の中で距離distの頂点数

   //depth, posは0-index
   auto [d, pos] = cbt.GetPosition(v);
   ll v = cbt.GetIndex(d, pos);
   abc321e
*/
	const int S = 1<<5;
	char buf[S], *p = buf, *q = buf;

inline char readchar() {

	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
inline int nextint() {
	int x = 0, c = readchar();
	while(('0' > c || c > '9') && c!=EOF) c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	return x;
}

#define endl "\n"

// int A[(1<<16)+10];
// int tournament[(1<<16+1)];

// void solve() {

//    ll N; cin>>N;
//    rep(i,1<<N) cin>>A[i];

//    // V<ll> A(1<<N); cin>>A;
//    // V<ll> tournament(1<<N+1);

//    CompleteBinaryTree cbt;
//    cbt.SetN(1<<N);//頂点数Nの場合

//    int idx = cbt.GetIndex(cbt.depth-1, 0);
//    rep(i,1<<N) tournament[idx+i] = i;

//    for(ll d=cbt.depth-1;d>=0;d--){
//       for(ll i=0;i<cbt.GetSize(d);i+=2){
//          ll p = cbt.GetIndex(d, i);
//          ll idl = tournament[p];
//          ll idr = tournament[p+1];
//          if(A[idl]>A[idr]) tournament[p/2] = idl;
//          else tournament[p/2] = idr;
//       }
//    }
//    // EL(tournament)
//    PL(tournament[2]+tournament[3]-tournament[1]+1)

//    return;
// }

void solve2(){
   int N=nextint();
   int M = 1<<N;
   // for(int i=0;i<M;i++) cin>>A[i];

   int n = 1<<(N-1);

   int lid = -1, l = -1;
   for(int i=0;i<n;i++){
      int a = nextint();
      if(a>l){
         lid = i;
         l = a;
      }
   }
   int rid = -1, r = -1;
   for(int i=n;i<M;i++){
      int a = nextint();
      if(a>r){
         rid = i;
         r = a;
      }
   }

   if(r<l) printf("%d\n", rid+1);
   else printf("%d\n", lid+1);
}

int main() {
   // std::cin.tie(nullptr);
   // std::ios_base::sync_with_stdio(false);
   // std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
