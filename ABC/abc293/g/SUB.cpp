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

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
// #define endl "\n"
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
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqr = priority_queue<T, vector<T>, greater<T>>;
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
template<typename T, typename U> void operator++(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first--, p.second--;}//post
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


template< typename T >
struct Combination {
private:
  static vector< T > _fact, _finv, _inv;

  inline static void expand(size_t sz) {
    if(_fact.size() < sz + 1) {
      int pre_sz = max(1, (int) _fact.size());
      _fact.resize(sz + 1, T(1));
      _finv.resize(sz + 1, T(1));
      _inv.resize(sz + 1, T(1));
      for(int i = pre_sz; i <= (int) sz; i++) {
        _fact[i] = _fact[i - 1] * T(i);
      }
      _finv[sz] = T(1) / _fact[sz];
      for(int i = (int) sz - 1; i >= pre_sz; i--) {
        _finv[i] = _finv[i + 1] * T(i + 1);
      }
      for(int i = pre_sz; i <= (int) sz; i++) {
        _inv[i] = _finv[i] * _fact[i - 1];
      }
    }
  }

public:
  explicit Combination(size_t sz = 0) { expand(sz); }

  static inline T fact(int k) {
    expand(k);
    return _fact[k];
  }

  static inline T finv(int k) {
    expand(k);
    return _finv[k];
  }

  static inline T inv(int k) {
    expand(k);
    return _inv[k];
  }

  static T P(int n, int r) {
    if(r < 0 || n < r) return 0;
    return fact(n) * finv(n - r);
  }

  static T C(int p, int q) {
    if(q < 0 || p < q) return 0;
    return fact(p) * finv(q) * finv(p - q);
  }

  static T H(int n, int r) {
    if(n < 0 || r < 0) return 0;
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

template< typename T >
vector< T > Combination< T >::_fact = vector< T >();
template< typename T >
vector< T > Combination< T >::_finv = vector< T >();
template< typename T >
vector< T > Combination< T >::_inv = vector< T >();



struct Mo{
    ll N;
    vector<pair<ll,ll>> LR;
    Mo(ll N):N(N){}

    void query(ll l, ll r){
        LR.emplace_back(l, r);
    }

    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void solve(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        ll Q = (ll) LR.size();
        // ll bs = N / max(1LL, min< ll >(N, sqrt(Q)));
        ll bs = N / min< ll >(N, sqrt(Q));
        
        //bs = sqrt(Q); chmax(bs, 1);
        vector< ll > ord(Q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](ll a, ll b) {
            if(LR[a].first/bs!=LR[b].first/bs) return LR[a].first/bs<LR[b].first/bs;
            return ((LR[a].first/bs) & 1) ? LR[a].second > LR[b].second : LR[a].second < LR[b].second;
        });
        ll l = 0, r = 0;
        for(auto idx : ord) {
            while(l > LR[idx].first) add_left(--l);
            while(r < LR[idx].second) add_right(r++);
            while(l < LR[idx].first) erase_left(l++);
            while(r > LR[idx].second) erase_right(--r);
            out(idx);
        }
    }

    template< typename A, typename E, typename O >
    void solve(const A &add, const E &erase, const O &out) {
        solve(add, add, erase, erase, out);
    }
};
/*
    Mo mo(N);//配列要素数
    rep(q,Q) mo.query(l,r);//順番にクエリ入力

    V<ll> cnt(N);
    V<ll> Ans(Q);
    ll ans = 0;
    auto add = [&](auto i){
        ans -= cnt[A[i]]/2;
        cnt[A[i]]++;
        ans += cnt[A[i]]/2;
    };
    auto erase = [&](auto i){
        ans -= cnt[A[i]]/2;
        cnt[A[i]]--;
        ans += cnt[A[i]]/2;
    };
    auto out = [&](auto q){
        Ans[q] = ans;
    };
    mo.solve(add, erase, out);
    mo.solve(add_left, add_right, erase_left, erase_right, out);
    ABC242G
*/

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
// using mint = atcoder::modint;
// mint::set_mod(MOD);
//制約: a/b -> gcd(b,mod)==1
template<int m> ostream &operator<<(ostream &os, const atcoder::static_modint<m> x) {os<<x.val();return os;}
template<int m> istream &operator>>(istream &is, atcoder::static_modint<m>& x){ll val; is >> val; x = val; return is;}
ostream &operator<<(ostream &os, const atcoder::modint x) {os<<x.val();return os;}
istream &operator>>(istream &is, atcoder::modint& x){ll val; is >> val; x = val; return is;}
#endif

void solve() {

    ll N; cin>>N;
    ll Q; cin>>Q;
    V<ll> A(N); cin>>A;

    Mo mo(N);
    rep(q,Q){
        ll l,r;
        cin>>l>>r;
        l--;
        mo.query(l,r);
    }
    EL(1)

    Combination<mint> C(20005);
    EL(2)

    V<ll> cnt(200005);
    V<ll> Ans(Q);
    ll ans = 0;
    auto f = [&](ll x){
        return x*(x-1)*(x-2)/6;
    };
    auto add = [&](auto i){
        // ans -= C.C(cnt[A[i]], 3);
        ans -= f(cnt[A[i]]);
        cnt[A[i]]++;
        // ans += C.C(cnt[A[i]], 3);
        ans += f(cnt[A[i]]);
    };
    auto erase = [&](auto i){
        // ans -= C.C(cnt[A[i]], 3);
        ans -= f(cnt[A[i]]);
        cnt[A[i]]--;
        // ans += C.C(cnt[A[i]], 3);
        ans += f(cnt[A[i]]);
    };
    auto out = [&](auto q){
        Ans[q] = ans;
    };
    EL(2)

    mo.solve(add, erase, out);
    EL(3)

    rep(q,Q) PL(Ans[q])

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
