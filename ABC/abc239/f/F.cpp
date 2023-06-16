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

#include "structure/union_find/weight_update_union_find.hpp"
   /*
   WeightUpdateUnionFind<ll> uf(N);
   rep(i,N) uf.setWeight(i,A[i]);
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {uf.weight[parent] += uf.weight[child];};//重みに対して行う処理
   if(!uf.same(x,y))uf.merge(x,y,cmp,f);
   uf.leader();
   uf.getWeight(x);
   abc277D2
   abc295G
   */



void solve() {

   ll N,M; cin>>N>>M;
   V<ll> D(N); cin>>D;

   {
      ll sum = 0;
      rep(i,N) sum += D[i];
      if(sum!=2*(N-1)) END(-1);
   }

   Edges<int> E = readE<int>(M, -1, false);//weighted?
   Graph<int> G(N, E, false);//directed?
   EL(1)

   rep(i,N) D[i] -= G[i].size();
   rep(i,N) if(D[i]<0) END(-1);
   EL(1)

   V<V<ll>> A(N);

   WeightUpdateUnionFind<V<ll>> uf(N);
   rep(i,N) rep(j,D[i]) A[i].push_back(i);
   auto cmp = [&](int parent, int child)->bool {return A[parent].size()>=A[child].size();};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {
      // for(auto p : uf[child]){
      //    uf[parent].push_back(p);
      // }
      //ES(uf[child].size()) EL(uf[parent].size())
      rep(i,A[child].size()) A[parent].push_back(A[child].at(i));
   };//重みに対して行う処理
   EL(1)

   for(const auto& e:E){
      EL("merge")
      uf.merge(e.from, e.to, cmp, f);
   }

   V<Pll> ans;

   set<Pll> st;
   rep(i,N) if(uf.leader(i)==i&&A[i].size()>0) st.insert({A[i].size(), i});
   EL(3)

   while(st.size()>1){
      auto itr = prev(st.end());
      auto it = st.begin();
      ans.push_back({A[it->se].back(), A[itr->se].back()});
      A[it->se].pop_back();
      A[itr->se].pop_back();
      Pll nxt = {it->fi+itr->fi-2, uf.leader(itr->se)};
      uf.merge(it->se, itr->se, cmp, f);
      st.erase(it);
      st.erase(prev(st.end()));
      if(nxt.fi!=0) st.insert(nxt);
      EL(st.size())
   }

   EL(ans)

   if(st.size()) END(-1)
   if(uf.size(0)!=N) END(-1)

   ans++;
   rep(i,ans.size()) PL(ans[i]);




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
