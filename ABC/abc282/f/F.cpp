#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
//#define ONLINE_JUDGE 1
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
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}


template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Pll query(int a, int b) {
    Monoid L = M1, R = M1;
    Pll ret(INF,INF);
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1){
        L = f(L, seg[a++]);
        EL(a)
        ret.fi=a;
      }
      if(b & 1){
        R = f(seg[--b], R);
        EL(b)
        ret.se=b;
      }
    }
    return ret;
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
//   int N, Q; cin>>N>>Q;
// //SegmentTree< int > seg(N, [](int a, int b) { return min(a, b); }, INF);
// //SegmentTree< int > seg2(N, [](int a, int b) { return min(a, b); }, INF);
// //SegmentTree< int > seg(N, [](int a, int b) { return max(a, b); }, -INF);
// //SegmentTree< int > seg(N, [](int a, int b) { return (a+b); }, 0);
// // 1-indexed
// while(Q--) {
//   int T, X, Y;
//   cin>>T>>X>>Y;
//   if(T == 0){
//       seg.update(X, Y);
//   }
//   else{
//       cout<<seg.query(X,Y+1);
//   }
// }


void solve() {

    ll N; cin>>N;

    SegmentTree<Pll> tree(N, [&](Pll a, Pll b){
        return Pll(min(a.fi,b.fi), max(a.se, b.se));
    }, Pll(INF,-INF));
    rep(i,N) tree.update(i,Pll(i,i+1));
    
    PL(tree.seg.size())
    for(auto s:tree.seg){
        if(s.fi<0||N+1<s.fi){PS(1) PL(1)}
        else if(s.se<0||N+2<s.se){PS(1) PL(1)}
        else PL(s)
    }


    ll Q; cin>>Q;
    rep(q,Q){
        ll l,r; cin>>l>>r;
        l--;
        auto p = tree.query(l,r);
        if(p.fi==INF){PS(p.se) PL(p.se)}
        else if(p.se==INF){PS(p.fi) PL(p.fi)}
        else {PS(p.fi) PL(p.se)}
    }

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}

/*

ABC282 5完
A for
B for for for
C "の数カウントして変換.\
D 二部グラフ判定&UFで連結判定．
E 先に得点全通り計算．コスト高い順にダイクストラ．
F セグ木orスパーステーブルまではわかったけど，間に合わず

*/