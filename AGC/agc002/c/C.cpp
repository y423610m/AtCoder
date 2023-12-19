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

#include "structure/union_find/update_union_find.hpp"
   /*
   UpdateUnionFind uf(N);
   V<ll> Weight(N);
   rep(i,N) W[i] = A[i];
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {Weight[parent] += Weight[child];};//重みに対して行う処理
   if(!uf.same(x,y)) uf.merge(x, y, cmp, f);
   uf.leader(i); == uf[i];
   abc277D2
   abc295G
   abc239F
   agc002c
   */

#include "structure/union_find/unordered_map_update_union_find.hpp"


#define endl "\n"

struct Seg{
   ll len, l, r;
   Seg(ll len, ll i):len(len){
      l = i;
      r = i;
   }
   Seg(){}
};

Seg operator+(Seg& a, Seg& b){
   Seg seg;
   seg.len = a.len + b.len;
   seg.r = max(a.r , b.r);
   seg.l = min(a.l , b.l);
   return seg;
}

void solve() {

   ll N; cin>>N;
   ll L; cin>>L;
   V<ll> A(N); cin>>A;

   V<Seg> segs(N);
   rep(i,N) segs[i] = Seg(A[i], i);

   queue<ll> que;
   set<ll> st;
   rep(i,N) que.push(i);
   rep(i,N) st.insert(i);

   V<Pll> ans;

   UnorderedMapUpdateUnionFind<ll> uf(N);
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {
      ans.push_back({min(segs[parent].r, segs[child].r), max(segs[parent].l, segs[child].l)});
      segs[parent] = segs[parent] + segs[child];
   };//重みに対して行う処理


   while(!que.empty()){
      ll m = que.front(); que.pop();
      if(!st.contains(m)) continue;

      auto it = st.find(m);

      bool merged = false;
      
      //r
      auto itr = next(it);
      if(itr!=st.end()){
         ll r = *itr;
         if(segs[uf[m]].len+segs[uf[r]].len >= L){
            uf.merge(m, r, cmp, f);
            merged = true;
            st.erase(r);
         }
      }

      it = st.find(m);
      if(it!=st.begin()){
         ll l = *prev(it);
         if(segs[uf[m]].len+segs[uf[l]].len >= L){
            uf.merge(m, l, cmp, f);
            merged = true;
            st.erase(l);
         }
      }

      if(merged) que.push(m);
   }

   if(st.size()==1) {
      PL("Possible")
      ans++;
      reverse(ALL(ans));
      rep(i,ans.size()) PL(ans[i].fi)
   }
   else{
      PL("Impossible")
      EL(st.size())
      EL(ans)
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
