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

//pair同士
template<typename T, typename U> pair<T,U> operator+(const pair<T,U>& a, const pair<T,U>& b){return pair<T,U>(a.first+b.first, a.second+b.second);}
template<typename T, typename U> pair<T,U> operator-(const pair<T,U>& a, const pair<T,U>& b){return pair<T,U>(a.first-b.first, a.second-b.second);}
template<typename T, typename U> T inner_prod(const pair<T,U>& a, const pair<T,U>& b){return a.first*b.first + a.second*b.second;}
template<typename T, typename U> T outer_prod(const pair<T,U>& a, const pair<T,U>& b){return a.first*b.second - a.second*b.first;}
//スカラー
template<typename S, typename T, typename U> pair<T,U> operator+(const S s, const pair<T,U>& p){return pair<T,U>(s+p.first, s+p.second);}
template<typename S, typename T, typename U> pair<T,U> operator+(const pair<T,U>& p, const S s){return pair<T,U>(p.first+s, s+p.second+s);}
template<typename S, typename T, typename U> pair<T,U> operator-(const S s, const pair<T,U>& p){return pair<T,U>(s-p.first, s-p.second);}
template<typename S, typename T, typename U> pair<T,U> operator-(const pair<T,U>& p, const S s){return pair<T,U>(p.first-s, p.second-s);}
template<typename S, typename T, typename U> pair<T,U> operator*(const S s, const pair<T,U>& p){return pair<T,U>(s*p.first, s*p.second);}
template<typename S, typename T, typename U> pair<T,U> operator*(const pair<T,U>& p, const S s){return pair<T,U>(p.first*s, p.second*s);}
template<typename S, typename T, typename U> pair<T,U> operator/(const pair<T,U>& p, const S s){return pair<T,U>(p.first/s, p.second/s);}
//互いに素にする.int, llのみ
template<typename T> pair<T, T> coprime(pair<T, T> p, bool distinct_opposite = false){
    if(p.fi==0&&p.se==0) return p;
    else if(p.fi==0){p.se = (distinct_opposite?p.se/abs(p.se):1);}
    else if(p.se==0){p.fi = (distinct_opposite?p.fi/abs(p.fi):1);}
    else{//firstを正になるように
        T g = (distinct_opposite?gcd(p.fi, p.se):gcd(p.fi, p.se)*(p.fi/abs(p.fi)));
        p.fi/=g; p.se/=g;
    }
    return p;
}
//ノルム
template<typename T> T norm(const pair<T,T>& p){return sqrt(p.fi*p.fi+p.se*p.se);}
template<typename T> T norm2(const pair<T,T>& p){return p.fi*p.fi+p.se*p.se;}
//回転rad
template<typename T> pair<T,T> rotate(pair<T,T> p, double angle){return {p.fi*cos(angle)-p.se*sin(angle), p.fi*sin(angle)+p.se*cos(angle)};}


#include "graph/tree/rerooting_dp.hpp"
/*
ll N; cin>>N;
Edges<ll> E = readE<ll>(N-1, -1, false);//weighted?
Graph<ll> G(N, E, false);//directed?

using EdgeT = ll;
using VertexT = ll;
auto Merge = [&](EdgeT a, EdgeT b)->EdgeT {
   return max(a,b);
};
auto El = [&](int p, bool canAffectSelf = false)->EdgeT {
   if(canAffectSelf) return 0;
   return 0;
};
auto PE = [&](VertexT v, const Edge<ll>& e)->EdgeT {
   return v + e.cost;
};
auto PV = [&](EdgeT e, int p)->VertexT {
   return e;
};

RerootingDP<EdgeT, VertexT> rdp;
rdp.build(N, G, 0, Merge, El, PE, PV);
auto dp = rdp.reroot(G, Merge, El, PE, PV);

vertex:その頂点を根とした値を考えるとき
edge:根以外の木の一部にするとき．
typ90003, abc222f, edpc_v
*/

void solve() {

   ll N; cin>>N;
   Edges<ll> E = readE<ll>(N-1, -1, false);//weighted?
   Graph<ll> G(N, E, false);//directed?

   using EdgeT = Pll;//sum(d), size
   using VertexT = Pll;
   auto Merge = [&](EdgeT a, EdgeT b)->EdgeT {
      return a+b;
   };
   auto El = [&](int p, bool canAffectSelf = false)->EdgeT {
      if(canAffectSelf) return {0,0};
      return {0,1};
   };
   auto PE = [&](VertexT v, const Edge<ll>& e)->EdgeT {
      return {v.fi+v.se*1, v.se};
   };
   auto PV = [&](EdgeT e, int p)->VertexT {
      return e;
   };

   RerootingDP<EdgeT, VertexT> rdp;
   rdp.build(N, G, 0, Merge, El, PE, PV);
   auto dp = rdp.reroot(G, Merge, El, PE, PV);
   rep(i,N) PL(dp[i].fi)

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
