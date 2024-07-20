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
using Tiii = tuple<int, int, int>;
using Tiiii = tuple<int, int, int, int>;
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


using ll = long long;

template<typename KeyT, typename ParentT, typename SizeT, typename ChildT, typename WeightT>
struct UnionFindBase
{

   int n;
   ParentT parent;//unordered_map<KeyT, KeyT> or vector<int>
   SizeT sz;//unordered_map<KeyT, int> or vetor<int>
   ChildT children;//unordered_map<KeyT, vector<KeyT>> or vector<vector<int>>
   WeightT diffWeight;

   UnionFindBase(int n) : n(n)
   {
   }

   bool same(KeyT a, KeyT b){
      return leader(a) == leader(b);
   }

   bool merge(KeyT a, KeyT b, ll w = 0){
      auto MergeF = [&](KeyT p, KeyT c)->bool {return sz[p] >= sz[c];};
      auto UpdateF = [&](KeyT p, KeyT c)->void {};
      return mergeMU(a, b, MergeF, UpdateF, w);
   }

   bool mergeM(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, ll w = 0){
      auto UpdateF = [&](KeyT p, KeyT c)->void {};
      return mergeMU(a, b, MergeF, UpdateF, w);
   }

   bool mergeU(KeyT a, KeyT b, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      auto MergeF = [&](KeyT p, KeyT c)->bool {return sz[p] >= sz[c];};
      return mergeMU(a, b, MergeF, UpdateF, w);
   }

   // template <typename MergeT, typename UpdateT>
   // bool mergeMU(KeyT a, KeyT b, MergeT MergeF, UpdateT UpdateF){
   bool mergeMU(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      w += weight(a);
      w -= weight(b);
      KeyT x = leader(a);
      KeyT y = leader(b);
      if(x==y) return false;
      if (!MergeF(x, y)) swap(x, y), w=-w;
      sz[x] += sz[y];
      parent[y] = x;
      children[x].emplace_back(y);
      UpdateF(x, y);
      diffWeight[y] = w;
      return true;
   }

   KeyT leader(KeyT x){
      if(parent[x]==x) return x;
      KeyT l = leader(parent[x]);// Need to call this before updating weight.
      diffWeight[x] += diffWeight[parent[x]];
      return parent[x] = l;
   }

   ll diff(KeyT x, KeyT y) {
      return weight(y) - weight(x);
   }

   ll weight(KeyT x) {
      leader(x);
      return diffWeight[x];
   }

   int size(KeyT x) {
      return sz[leader(x)];
   }

   int size(){
      return parent.size();
   }

   vector<KeyT> group(KeyT a){
      a = leader(a);
      vector<KeyT> mem;
      auto dfs = [&](auto dfs, const KeyT& x)->void {
         mem.push_back(x);
         for(const KeyT& nxt: children[x]){
            dfs(dfs, nxt);
         }
      };
      dfs(dfs, a);
      return mem;
   }
};

struct UnionFind : public UnionFindBase<int, vector<int>, vector<int>, vector<vector<int>>, vector<ll> >
{
   UnionFind(int n) : UnionFindBase(n)
   {
      parent.resize(n, -1);
      sz.resize(n, 1);
      for(int i=0;i<n;i++) parent[i] = i;
      children.resize(n);
      diffWeight.resize(n);
   }

   vector<vector<int>> groups(){
      vector<vector<int>> result;
      for(int i=0;i<n;i++) if(parent[i]==i){
         result.emplace_back(group(i));
      }
      return result;
   }
};

template <typename KeyT>
struct UnionFindUM : public UnionFindBase<KeyT, unordered_map<KeyT, KeyT>, unordered_map<KeyT, int>, unordered_map<KeyT, vector<KeyT>>, unordered_map<KeyT, ll> >
{

   using base = UnionFindBase<KeyT, std::unordered_map<KeyT, KeyT>, std::unordered_map<KeyT, int>, unordered_map<KeyT, vector<KeyT>>, unordered_map<KeyT, ll>>;
   using base::UnionFindBase;
   // using UnionFindBase<KeyT, std::unordered_map<KeyT, KeyT>, std::unordered_map<KeyT, int>>::UnionFindBase;

   UnionFindUM() : base(0)
   {
   }

   void _EnsureExistance(const KeyT& x){
      if( this->parent.find(x) == this->parent.end() ) {
         this->n++;
         this->parent[x] = x;
         this->sz[x] = 1;
         this->diffWeight[x] = 0;
      }
   }

   void Add(KeyT x){
      _EnsureExistance(x);
   } 

   bool same(KeyT a, KeyT b){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::leader(a) == base::leader(b);
   }

   bool merge(KeyT a, KeyT b, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::merge(a, b, w);
   }

   bool mergeM(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::mergeM(a, b, MergeF, w);
   }

   bool mergeU(KeyT a, KeyT b, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::mergeU(a, b, UpdateF, w);
   }

   bool mergeMU(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::mergeMU(a, b, MergeF, UpdateF, w);
   }

   KeyT leader(KeyT x){
      _EnsureExistance(x);
      return base::leader(x);
   }

   int size(KeyT x) {
      _EnsureExistance(x);
      return base::size(x);
   }

   ll diff(KeyT x, KeyT y) {
      _EnsureExistance(x);
      _EnsureExistance(y);
      return base::diff(x, y);
   }

   ll weight(KeyT x){
      _EnsureExistance(x);
      return base::weight(x); 
   }

   vector<KeyT> group(KeyT a){
      _EnsureExistance(a);
      return base::group(a);
   }

   vector<vector<KeyT>> groups(){
      vector<vector<KeyT>> result;
      for(const auto& [x, p]:this->parent) if(x==p) {
         result.emplace_back(group(x));
      }
      return result;
   }
};
/*
UnionFind uf(N);
UnionFindUM<ll> uf(N);//unordered_map
auto MergeF = [&](int p, int c)->bool {return uf.sz[p]>=uf.sz[c];}
auto UpdateF = [&](int p, int c)->void {W[p]+=W[c];}
uf.merge(x, y, w=0);
uf.mergeM(x, y, MergeF, w=0);
uf.mergeU(x, y, UpdateF, w=0);
uf.mergeMU(x, y, MergeF, UpdateF, w=0);
size(x)
group(x)
Add(x)
*/

#define endl "\n"

void solve() {

   ll N,M,Q; cin>>N>>M>>Q;
   // UnionFind uf(N+1);
   UnionFindUM<ll> uf(N+1);//unordered_map
   rep(i,M){
      ll a,b,c;
      cin>>a>>b>>c;
      a--, b--;
      if(uf.same(a, b)&&uf.diff(a,b)!=c){
         uf.merge(a, N, 0);
      }
      uf.merge(a, b, c);
   }

   rep(q,Q){
      ll x,y;
      cin>>x>>y;
      x--, y--;
      if(!uf.same(x,y)) PL("nan")
      else if(uf.same(x, N)) PL("inf")
      else PL(uf.diff(x, y))
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
