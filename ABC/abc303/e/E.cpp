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

#include "graph/graph_template.hpp"
/*
   ll N,M; cin>>N>>M;
   Edges<int> E = readE<int>(M, -1, true);//weighted?
   Graph<int> G(N, E, true);//directed?
   //Graph<int> G(N); G.read(M, -1, true, true);
*/

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

void solve() {

   ll N; cin>>N;
   Edges<int> E = readE<int>(N-1, -1, false);//weighted?
   Graph<int> G(N, E, false);//directed?

   queue<ll> que;
   rep(i,N) que.push(i);

   dsu uf(N);

   V<ll> types(N, 0);//unknown, root, leaf

   while(!que.empty()){
      ll p = que.front(); que.pop();
      ES(0) ES(p) EL(types)
      if(types[p]==0){
         for(auto& e:G[p]){
            if(G[p].size()>G[e.to].size()){types[p] = 1; types[e.to]=2;}
            if(G[p].size()<G[e.to].size()){types[p] = 2; types[e.to]=1;}
            if(types[e.to]==1){types[p] = 2;}
            ES(p) EL(types)
         }
      }
      ES(1) ES(p) EL(types)

      //root
      if(types[p]==1)for(auto& e:G[p]){
         types[e.to] = 2;
         if(!uf.same(p, e.to)){
            uf.merge(p, e.to);
            que.push(e.to);
         }
      }

      ES(2) ES(p) EL(types)

   }

   V<ll> sz(N);
   rep(i,N) sz[i] = G[i].size();

   max_heap<Pll> que2;
   rep(i,N) if(types[i]==0){
      ll cnt = 0;
      for(auto& e:G[i]) if(types[e.to]==0) cnt++;
      que2.push({cnt, i});
   }



   while(!que2.empty()){
      auto [si, p] = que2.top(); que2.pop();
      if(types[p]!=0) continue;

      bool isRoot = true;
      for(auto& e:G[p]) if(types[e.to]==1) isRoot = false;

      if(isRoot){
         types[p] = 1;
         for(auto& e:G[p]){
            types[e.to] = 2;
            if(!uf.same(p, e.to)){
               uf.merge(p, e.to);
            }
         }
      }
   }

   auto groups = uf.groups();
   V<ll> ans;
   for(auto group:groups) ans.push_back(group.size());
   sort(ALL(ans));
   ans--;
   PL(ans)
   EL(types)

   return;
}

void solve2(){
   ll N; cin>>N;
   Edges<int> E = readE<int>(N-1, -1, false);//weighted?
   Graph<int> G(N, E, false);//directed?

   V<ll> types(N);

   queue<ll> que;
   rep(i,N){
      if(G[i].size()==1) {
         que.push(G[i][0].to);
         // types[G[i][0].to] = 1;
         break;
      }
   }

   dsu uf(N);

   while(!que.empty()){
      ll p = que.front(); que.pop();
      EL(p)
      for(const auto& e:G[p]){
         types[e.to] = 2;
         if(!uf.same(e.from, e.to)){
            uf.merge(e.from, e.to);
         }
         for(const auto& e1:G[e.to]) if(e1.to!=p&&types[e1.to]==0){
            // types[e1.to] = 2;
            for(const auto& e2:G[e1.to]) if(e2.to!=e1.to&&types[e2.to]==0){
               // types[e2.to] = 1;
               que.push(e2.to);
               // for(const auto& e3:G[e2.to]) if(e3.to!=e2.to&&types[e3.to]==0){
               //    que.push(e3.to);
               // }
            }
         }
         
      }
   }

   auto groups = uf.groups();
   V<ll> ans;
   for(auto group:groups){
      EL(group)
      ans.push_back(group.size());
   }
   sort(ALL(ans));
   ans--;
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
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}

/*

*/