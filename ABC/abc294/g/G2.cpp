
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define overload4(a,b,c,d,e,...) e
#define overload3(a,b,c,d,...) d
#define rep1(a) for(ll i=0;i<(ll)(a);i++)
#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)
#define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)
#define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)
#define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)
#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define fore(...) for (auto&& __VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall(n) (n).rbegin(),(n).rend()
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define END(...) {print(__VA_ARGS__);return;}
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using vl=vector<ll>;
using vi=vector<int>;
using vs=vector<string>;
using vc=vector<char>;
using vvl=vector<vl>;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vvc=vector<vc>;
using vd=vector<double>;
using vp=vector<pl>;
using vb=vector<bool>;
constexpr int dx[8]={1,0,-1,0,1,-1,-1,1};
constexpr int dy[8]={0,1,0,-1,1,1,-1,-1};
constexpr ll MOD=1000000007;
constexpr ll mod=998244353;
constexpr ld EPS=1e-8;
constexpr ld PI=3.1415926535897932384626;
template<typename T,typename U>
ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>
istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
void scan(){}
template<class Head,class... Tail>
void scan(Head&head,Tail&... tail){cin>>head;scan(tail...);}
template<class T>
void print(const T &t){cout<<t<<'\n';}
template<class Head, class... Tail>
void print(const Head &head, const Tail &... tail){cout<<head<<' ';print(tail...);}
template<class... T>
void fin(const T &... a){print(a...);exit(0);}
template<typename T,typename U>
inline bool chmax(T&a,U b){return a<b&&(a=b,true);}
template<typename T,typename U>
inline bool chmin(T&a,U b){return a>b&&(a=b,true);}
template<typename T>
class infinity{
  public:
  static constexpr T MAX=numeric_limits<T>::max();
  static constexpr T MIN=numeric_limits<T>::min();
  static constexpr T value=numeric_limits<T>::max()/2;
  static constexpr T mvalue=numeric_limits<T>::min()/2;
};
#if __cplusplus <= 201402L
template<class T>constexpr T infinity<T>::value;
template<class T>constexpr T infinity<T>::mvalue;
template<class T>constexpr T infinity<T>::MAX;
template<class T>constexpr T infinity<T>::MIN;
#endif
template<typename T>constexpr T INF=infinity<T>::value;
constexpr long long inf=INF<ll>;
inline int popcnt(ull x){
#if __cplusplus>=202002L
return popcount(x);
#endif
x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);
}
template<typename T,typename=void>
struct is_specialize:false_type{};
template<typename T>
struct is_specialize<T,typename conditional<false,typename T::iterator, void>::type>:true_type{};
template<typename T>
struct is_specialize<T,typename conditional<false,decltype(T::first),void>::type>:true_type{};
template<typename T>
struct is_specialize<T,enable_if_t<is_integral<T>::value,void>>:true_type{};
void dump(const char&t){cerr<<t;}
void dump(const string&t){cerr<<t;}
void dump(const bool&t){cerr<<(t?"true":"false");}
template <typename T,enable_if_t<!is_specialize<T>::value,nullptr_t> =nullptr>
void dump(const T&t){cerr<<t;}
template<typename T>
void dump(const T&t,enable_if_t<is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp="inf";if(is_signed<T>::value&&(t==infinity<T>::mvalue||t==infinity<T>::MIN))tmp="-inf";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}
template<typename T,typename U>
void dump(const pair<T,U>&);
template<typename T>
void dump(const T&t,enable_if_t<!is_void<typename T::iterator>::value>* =nullptr){cerr<<"{";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?"":",");}cerr<<"}";}
template<typename T,typename U>
void dump(const pair<T,U>&t){cerr<<"(";dump(t.first);cerr<<",";dump(t.second);cerr<<")";}
void trace(){cerr<<endl;}
template<typename Head,typename... Tail>
void trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<",";trace(forward<Tail>(tail)...);}
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...) do{cerr<<#__VA_ARGS__<<"=";trace(__VA_ARGS__);}while(0)
#endif
struct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};
template<class F>struct REC{F f;REC(F&&f_):f(std::forward<F>(f_)){}template<class...Args>auto operator()(Args&&...args)const{return f(*this, std::forward<Args>(args)...);}};
/**
 * @brief Template(テンプレート)
*/
template<typename T,typename F>
struct sparse_table{
  F f;
  vector<vector<T>>table;
  vector<int>log_table;
  sparse_table()=default;
  sparse_table(const vector<T>&v,const F&f):f(f){
    const int n=(int)v.size();
    const int lg=32-__builtin_clz(n);
    table.assign(lg,vector<T>(n));
    for(int i=0;i<n;i++)table[0][i]=v[i];
    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);
    log_table.resize(n+1);
    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];
  }
  T query(int l,int r){
    int a=log_table[r-l];
    return f(table[a][l],table[a][r-(1<<a)]);
  }
};
template<typename T,typename F>
sparse_table<T,F>make_sparse_table(const vector<T>&v,const F&f){
  return sparse_table<T,F>(v,f);
} 
/**
 * @brief Sparse Table
*/
template<typename T>
struct BIT{
  private:
  int N;
  vector<T>bit;
  public:
  BIT(){}
  BIT(int n){
    N=1;
    while(N<n)N<<=1;
    bit=vector<T>(N+1,0);
  }
  void add(int i,T x){
    i++;
    while(i<=N){
      bit[i]+=x;
      i+=i&-i;    
    }
  }
  T sum(int i){
    T ans=0;
    while(i>0)ans+=bit[i],i-=i&-i;
    return ans;
  }
  T query(int l,int r){
    return sum(r)-sum(l);
  }
};
/**
 * @brief Binary Indexed Tree(BIT)
*/
class euler_tour{
  using F=function<int(int,int)>;
  int n;
  vi in,out,depth,ord,u_cost,d_cost;
  BIT<int>up,down;
  sparse_table<int,F>st;
  vector<vi>g;
  int time;
  void dfs(int v,int p,int d){
    in[v]=time++;
    ord.eb(v);depth.eb(d);
    for(auto&u:g[v])if(u!=p){
      u_cost.eb(1),d_cost.eb(1);
      dfs(u,v,d+1);
      u_cost.eb(-1);d_cost.eb(-1);
      ord.eb(v);depth.eb(d);
    }
    out[v]=time++;
  }
  public:
  euler_tour(){}
  euler_tour(const vector<vi>&g):g(g),n(g.size()),u_cost(1,0),d_cost(1,0),up(2*n-1),down(2*n-1),in(n),out(n),time(0){
    dfs(0,-1,0);
    vector<int>v(g.size()*2-1);
    iota(v.begin(),v.end(),0);
    F f=[&](int a,int b){return depth[a]<depth[b]?a:b;};
    st=sparse_table<int,F>(v,f);
    rep(i,2*n-1){
      up.add(i,u_cost[i]);
      down.add(i,d_cost[i]);
    }
  }
  int lca(int u,int v){
    if(in[u]>in[v])swap(u,v);
    return u==v?u:ord[st.query(in[u],in[v])];
  }
  void query(int p,int q,int s,int t){
    if(in[p]>in[q]){
      swap(p,q);
      swap(s,t);
    }
    up.add(in[q],t-u_cost[in[q]]);
    up.add(out[q],-t-u_cost[out[q]]);
    down.add(in[q],s-d_cost[in[q]]);
    down.add(out[q],-s-d_cost[out[q]]);
    u_cost[in[q]]=t,u_cost[out[q]]=-t;
    d_cost[in[q]]=s,d_cost[out[q]]=-s;
  }
  int calc(int p,int q){
    int r=lca(p,q);
    return up.sum(in[p]+1)-up.sum(in[r]+1)+down.sum(in[q]+1)-down.sum(in[r]+1);
  }
};
signed main(){
  IOSetup();
  int n;
  cin>>n;
  vi p(n-1),q(n-1);
  vector<vi>g(n);
  vi W(n-1);
  rep(i,n-1){
    scan(p[i],q[i]);
    scan(W[i]);
    p[i]--,q[i]--;
    g[p[i]].eb(q[i]);
    g[q[i]].eb(p[i]);
  }
  euler_tour et(g);
  rep(i,n-1){
      et.query(p[i],q[i],W[i],W[i]);
  }
  int m; cin>>m;
  while(m--){
    INT(t);
    if(t==1){
      INT(r,s);
      r--;
      et.query(p[r],q[r],s,s);
    }
    else{
      INT(x,y);
      x--,y--;
      print(et.calc(x,y));
    }
  }
}

/*
ABC294 ABCDEG6完
A やる
B やる
C 合わせてソートしてmap
D set２つ
E 前から順番にやる．
F 分からない．二分探索２回したらできそう？
G HL分解．人様のライブラリペタリ．
*/