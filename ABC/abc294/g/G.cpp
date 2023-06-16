#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

// #define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
// #define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
// #define pb(a) push_back(a)
// #define PS(a) cout<<(a)<<" ";
// #define PL(a) cout<<(a)<<endl;
// #define endl "\n"
// //#define ONLINE_JUDGE 1
// #ifdef ONLINE_JUDGE
//    #define ES(a) while(0){}
//    #define EL(a) while(0){}
// #else
//    #define NAME(a) #a
//    #define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
//    #define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
// #endif
// #define END(a) {PL(a) return;}
// #define RES(a) cerr<<"\r"<<NAME(a)<<": "<<(a)<<"   ";
// #define fi first
// #define se second
// #define ALL(a)  (a).begin(),(a).end()
// #define RALL(a)  (a).rbegin(),(a).rend()
// #define SORT(a) sort(a.begin(), a.end());
// #define REVERSE(a) reverse(a.begin(), a.end());
// #define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
// using Pii = pair<int, int>;
// using Pll = pair<ll,ll>;
// template<typename T> using V = vector<T>;
// template<typename T> using pq = priority_queue<T>;
// template<typename T> using pqr = priority_queue<T, vector<T>, greater<T>>;
// template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
// template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
// template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
// template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
// template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
// template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
// template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
// template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
// template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
// template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
// template<typename T, typename U> void operator++(pair<T, U>& p){p.first--, p.second--;}//pre
// template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first--, p.second--;}//post
// template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
// template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
// template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
// template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
// template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
// template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
// template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
// template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
// template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
// template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

#line 1 "test/verify/aoj-2450.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450"

#line 1 "template/template.hpp"
#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  explicit FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};
 
template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}
#line 4 "test/verify/aoj-2450.test.cpp"

#line 1 "structure/segment-tree/lazy-segment-tree.hpp"
/**
 * @brief Lazy-Segment-Tree(遅延伝搬セグメント木)
 * @docs docs/lazy-segment-tree.md
 */
template< typename T, typename E, typename F, typename G, typename H >
struct LazySegmentTree {
private:
  int n{}, sz{}, height{};
  vector< T > data;
  vector< E > lazy;
  const F f;
  const G g;
  const H h;
  const T ti;
  const E ei;

  inline void update(int k) {
    data[k] = f(data[2 * k + 0], data[2 * k + 1]);
  }

  inline void all_apply(int k, const E &x) {
    data[k] = g(data[k], x);
    if(k < sz) lazy[k] = h(lazy[k], x);
  }

  inline void propagate(int k) {
    if(lazy[k] != ei) {
      all_apply(2 * k + 0, lazy[k]);
      all_apply(2 * k + 1, lazy[k]);
      lazy[k] = ei;
    }
  }

public:
  LazySegmentTree() = default;

  explicit LazySegmentTree(int n, const F f, const G g, const H h,
                           const T &ti, const E &ei)
      : n(n), f(f), g(g), h(h), ti(ti), ei(ei) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, ti);
    lazy.assign(2 * sz, ei);
  }

  explicit LazySegmentTree(const vector< T > &v, const F f, const G g, const H h,
                           const T &ti, const E &ei)
      : LazySegmentTree(v.size(), f, g, h, ti, ei) {
    build(v);
  }

  void build(const vector< T > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) data[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) update(k);
  }

  void set(int k, const T &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = x;
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  T get(int k) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    return data[k];
  }

  T operator[](int k) {
    return get(k);
  }

  T prod(int l, int r) {
    if(l >= r) return ti;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    T L = ti, R = ti;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, data[l++]);
      if(r & 1) R = f(data[--r], R);
    }
    return f(L, R);
  }

  T all_prod() const {
    return data[1];
  }

  void apply(int k, const E &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = g(data[k], x);
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  void apply(int l, int r, const E &x) {
    if(l >= r) return;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      for(; l < r; l >>= 1, r >>= 1) {
        if(l & 1) all_apply(l++, x);
        if(r & 1) all_apply(--r, x);
      }
      l = l2, r = r2;
    }
    for(int i = 1; i <= height; i++) {
      if(((l >> i) << i) != l) update(l >> i);
      if(((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template< typename C >
  int find_first(int l, const C &check) {
    if(l >= n) return n;
    l += sz;
    for(int i = height; i > 0; i--) propagate(l >> i);
    T sum = ti;
    do {
      while((l & 1) == 0) l >>= 1;
      if(check(f(sum, data[l]))) {
        while(l < sz) {
          propagate(l);
          l <<= 1;
          auto nxt = f(sum, data[l]);
          if(not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, data[l++]);
    } while((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) {
    if(r <= 0) return -1;
    r += sz;
    for(int i = height; i > 0; i--) propagate((r - 1) >> i);
    T sum = ti;
    do {
      r--;
      while(r > 1 and (r & 1)) r >>= 1;
      if(check(f(data[r], sum))) {
        while(r < sz) {
          propagate(r);
          r = (r << 1) + 1;
          auto nxt = f(data[r], sum);
          if(not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(data[r], sum);
    } while((r & -r) != r);
    return -1;
  }
};

template< typename T, typename E, typename F, typename G, typename H >
LazySegmentTree< T, E, F, G, H > get_lazy_segment_tree
    (int N, const F &f, const G &g, const H &h, const T &ti, const E &ei) {
  return LazySegmentTree{N, f, g, h, ti, ei};
}

template< typename T, typename E, typename F, typename G, typename H >
LazySegmentTree< T, E, F, G, H > get_lazy_segment_tree
    (const vector< T > &v, const F &f, const G &g, const H &h, const T &ti, const E &ei) {
  return LazySegmentTree{v, f, g, h, ti, ei};
}
#line 6 "test/verify/aoj-2450.test.cpp"

#line 2 "graph/tree/heavy-light-decomposition.hpp"

#line 2 "graph/graph-template.hpp"

/**
 * @brief Graph Template(グラフテンプレート)
 */
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }

  inline vector< Edge< T > > &operator[](const int &k) {
    return g[k];
  }

  inline const vector< Edge< T > > &operator[](const int &k) const {
    return g[k];
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;
#line 4 "graph/tree/heavy-light-decomposition.hpp"

/**
 * @brief Heavy-Light-Decomposition(HL分解)
 * @see https://smijake3.hatenablog.com/entry/2019/09/15/200200
 */
template< typename T = int >
struct HeavyLightDecomposition : Graph< T > {
public:
  using Graph< T >::Graph;
  using Graph< T >::g;
  vector< int > sz, in, out, head, rev, par, dep;

  void build() {
    sz.assign(g.size(), 0);
    in.assign(g.size(), 0);
    out.assign(g.size(), 0);
    head.assign(g.size(), 0);
    rev.assign(g.size(), 0);
    par.assign(g.size(), 0);
    dep.assign(g.size(), 0);
    dfs_sz(0, -1, 0);
    int t = 0;
    dfs_hld(0, -1, t);
  }

  /* k: 0-indexed */
  int la(int v, int k) {
    while(1) {
      int u = head[v];
      if(in[v] - k >= in[u]) return rev[in[v] - k];
      k -= in[v] - in[u] + 1;
      v = par[u];
    }
  }

  int lca(int u, int v) const {
    for(;; v = par[head[v]]) {
      if(in[u] > in[v]) swap(u, v);
      if(head[u] == head[v]) return u;
    }
  }

  int dist(int u, int v) const {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  template< typename E, typename Q, typename F, typename S >
  E query(int u, int v, const E &ti, const Q &q, const F &f, const S &s, bool edge = false) {
    E l = ti, r = ti;
    for(;; v = par[head[v]]) {
      if(in[u] > in[v]) swap(u, v), swap(l, r);
      if(head[u] == head[v]) break;
      l = f(q(in[head[v]], in[v] + 1), l);
    }
    return s(f(q(in[u] + edge, in[v] + 1), l), r);
  }

  template< typename E, typename Q, typename F >
  E query(int u, int v, const E &ti, const Q &q, const F &f, bool edge = false) {
    return query(u, v, ti, q, f, f, edge);
  }

  template< typename Q >
  void add(int u, int v, const Q &q, bool edge = false) {
    for(;; v = par[head[v]]) {
      if(in[u] > in[v]) swap(u, v);
      if(head[u] == head[v]) break;
      q(in[head[v]], in[v] + 1);
    }
    q(in[u] + edge, in[v] + 1);
  }

  /* {parent, child} */
  vector< pair< int, int > > compress(vector< int > &remark) {
    auto cmp = [&](int a, int b) { return in[a] < in[b]; };
    sort(begin(remark), end(remark), cmp);
    remark.erase(unique(begin(remark), end(remark)), end(remark));
    int K = (int) remark.size();
    for(int k = 1; k < K; k++) remark.emplace_back(lca(remark[k - 1], remark[k]));
    sort(begin(remark), end(remark), cmp);
    remark.erase(unique(begin(remark), end(remark)), end(remark));
    vector< pair< int, int > > es;
    stack< int > st;
    for(auto &k : remark) {
      while(!st.empty() && out[st.top()] <= in[k]) st.pop();
      if(!st.empty()) es.emplace_back(st.top(), k);
      st.emplace(k);
    }
    return es;
  }

  explicit HeavyLightDecomposition(const Graph< T > &g) : Graph< T >(g) {}

private:
  void dfs_sz(int idx, int p, int d) {
    dep[idx] = d;
    par[idx] = p;
    sz[idx] = 1;
    if(g[idx].size() && g[idx][0] == p) swap(g[idx][0], g[idx].back());
    for(auto &to : g[idx]) {
      if(to == p) continue;
      dfs_sz(to, idx, d + 1);
      sz[idx] += sz[to];
      if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
    }
  }

  void dfs_hld(int idx, int p, int &times) {
    in[idx] = times++;
    rev[in[idx]] = idx;
    for(auto &to : g[idx]) {
      if(to == p) continue;
      head[to] = (g[idx][0] == to ? head[idx] : to);
      dfs_hld(to, idx, times);
    }
    out[idx] = times;
  }
};
#line 8 "test/verify/aoj-2450.test.cpp"

int main() {
  int N, Q, S[200000];
  cin >> N >> Q;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  HeavyLightDecomposition< int64 > tree(N);
  tree.read(N - 1);
  tree.build();

  struct Node {
    int64 ans, all, left, right, length;

    Node() : ans(-infll), all(0), left(-infll), right(-infll), length(0) {}

    Node(int64 val, int64 len) {
      length = len;
      all = val * length;
      ans = left = right = (val > 0 ? all : val);
    }

    Node operator+(const Node &s) const {
      Node ret;
      ret.length = length + s.length;
      ret.ans = max({ans, s.ans, right + s.left});
      ret.all = all + s.all;
      ret.left = max(left, all + s.left);
      ret.right = max(s.right, right + s.all);
      return ret;
    }
  };
  auto F = [](const Node &a, const Node &b) { return a + b; };
  auto G = [](const Node &a, int64 x) { return Node(x, a.length); };
  auto H = [](int64 x, int64 y) { return y; };
  auto seg = get_lazy_segment_tree(N, F, G, H, Node(), infll);
  for(int i = 0; i < N; i++) seg.set(i, Node(S[tree.rev[i]], 1));

  auto QF = [&](int a, int b) { return seg.prod(a, b); };
  auto QG = [](const Node &a, const Node &b) { return a + b; };
  auto QS = [](Node l, const Node &r) {
    swap(l.left, l.right);
    return l + r;
  };

  while(Q--) {
    int T, A, B, C;
    cin >> T >> A >> B >> C;
    --A, --B;
    if(T == 1) {
      tree.add(A, B, [&](int a, int b) { seg.apply(a, b, C); });
    } else {
      cout << tree.query(A, B, Node(), QF, QG, QS).ans << "\n";
    }
  }
}

// void solve() {



//    return;
// }

// int main() {
//    std::cin.tie(nullptr);
//    std::ios_base::sync_with_stdio(false);
//    std::cout << std::fixed << std::setprecision(15);//小数点以下
//    // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
//    // stoll(s,nullptr,base);
//    int TT = 1;
//    //cin>>TT;
//    for(int tt = 0; tt<TT; tt++) solve();
//    return 0;
// }
