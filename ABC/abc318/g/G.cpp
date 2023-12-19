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

using P = Pll;

#include "graph/graph_template.hpp"
/*
   ll N,M; cin>>N>>M;
   Edges<int> E = readE<int>(M, -1, true);//weighted?
   Graph<int> G(N, E, false, false);//directed? reverse?
   //Graph<int> G(N); G.read(M, -1, true, true);
*/

template<typename T>
struct LowLink {
    const Graph<T> &G;
    vector<int> used, ord, low;
    vector<int> aps;  // articulation points
    vector<P> bridges;
    vector<ll> bridgeIds;
    LowLink(const Graph<T> &G_) : G(G_) {
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)G.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
        sort(aps.begin(), aps.end()); // 必要ならソートする
        sort(bridges.begin(), bridges.end()); // 必要ならソートする
        sort(ALL(bridgeIds));
    }
    int dfs(int id, int k, int par) { // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
        used[id] = true;
        ord[id] = k++;
        low[id] = ord[id];
        bool is_aps = false;
        int count = 0; // 子の数
        for (auto &e : G[id]) {
            if (!used[e.to]) {
                count++;
                k = dfs(e.to, k, id);
                low[id] = min(low[id], low[e.to]);
                if (par != -1 && ord[id] <= low[e.to]) is_aps = true; 
                if (ord[id] < low[e.to]){
                  bridges.emplace_back(min(id, e.to), max(id, e.to)); // 条件を満たすので橋
                  bridgeIds.push_back(e.id);  
                }
            } else if (e.to != par) { // eが後退辺の時
                low[id] = min(low[id], ord[e.to]);
            }
        }
        if (par == -1 && count >= 2) is_aps = true; 
        if (is_aps) aps.push_back(id);
        return k;
    }
};

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

#define endl "\n"

void solve() {

   ll N,M; cin>>N>>M;
   ll A,B,C; cin>>A>>B>>C;
   A--, B--, C--;
   Edges<int> E = readE<int>(M, -1, false);//weighted?
   Graph<int> G(N, E, false, false);//directed? reverse?

   if(G[B].size()<=1) END(No)

   LowLink link(G);

   EL(link.bridgeIds)
   EL(link.aps)

   dsu uf(N);

   for(const auto& e:E){
      if(!binary_search(ALL(link.bridgeIds), e.id)){
         uf.merge(e.from, e.to);
      }
      // if(!binary_search(ALL(link.aps), e.from) && !binary_search(ALL(link.aps), e.to)){
      //    uf.merge(e.from, e.to);
      // }
   }

   if(uf.same(A,B)&&uf.same(B,C)){
      EL(0)
      END(Yes)
   }

   // merge non related trees
   for(const auto& e:E){
      if(uf.same(e.from, e.to)) continue;

      bool hasFrom = false;
      hasFrom |= uf.same(e.from, A);
      hasFrom |= uf.same(e.from, B);
      hasFrom |= uf.same(e.from, C);

      bool hasTo = false;
      hasTo |= uf.same(e.to, A);
      hasTo |= uf.same(e.to, B);
      hasTo |= uf.same(e.to, C);

      if(!(hasTo && hasFrom)){
         uf.merge(e.from, e.to);
         ES(e.from) EL(e.to)
      }
   }

   // if(uf.same(A,B)&&uf.same(B,C)){
   //    EL(1)
   //    END(Yes)
   // }

   // here tree size should be 3
   ll edgeAB = -1;
   ll edgeBC = -1;
   for(const auto& e:E){
      if(uf.same(e.from, e.to)) continue;

      if(uf.same(e.from, A) && uf.same(e.to, B)) edgeAB = e.id;
      if(uf.same(e.from, B) && uf.same(e.to, A)) edgeAB = e.id;
      if(uf.same(e.from, B) && uf.same(e.to, C)) edgeBC = e.id; 
      if(uf.same(e.from, C) && uf.same(e.to, B)) edgeBC = e.id;

      if(uf.same(e.from, A) && uf.same(e.to, C)) {
         EL(2)
         END(No)
      }
      if(uf.same(e.from, C) && uf.same(e.to, A)) {
         EL(3)
         END(No)
      }

   }


   if(edgeAB != -1 && edgeBC!=-1 && edgeAB != edgeBC){
      ES(edgeAB) EL(edgeBC)
      EL(4)
      END(Yes)
   }

   PL(No)

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

/*
ABC318 5完
A for
B for for
C sortして貪欲
D bitDP
E 各数字毎に考える．
F ?
G 最近見かけたlowlinkなるもので行けると思ったが...
*/