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
template<typename T> using V = vector<T>;
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
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

#include <atcoder/string>
using namespace atcoder;
/*
    string S = "abcdeabcde";
    //S.substr(i)を辞書順に並び替え.O(N)
    vector<int> sa = suffix_array(S);
    //EL(sa) 5 0 6 1 7 2 8 3 9 4

    //各suffix arrayについて，S.substr(i)とS.substr(i+1)の最長共通接頭辞
    //O(N)
    vector<int> lcp = lcp_array(S,sa);//N-1
    //EL(lcp) 5 0 4 0 3 0 2 0 1

    //SとS.substr(i)の最長共通接頭辞.O(N)
    vector<int> z = z_algorithm(S);//
    //EL(z) 10 0 0 0 0 5 0 0 0 0
*/

/**
 * @brief Rolling-Hash(ローリングハッシュ)
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 * @docs docs/rolling-hash.md
 */
struct RollingHash {
  static const uint64_t mod = (1ull << 61ull) - 1;
  using uint128_t = __uint128_t;
  vector< uint64_t > power;
  const uint64_t base;

  static inline uint64_t add(uint64_t a, uint64_t b) {
    if((a += b) >= mod) a -= mod;
    return a;
  }

  static inline uint64_t mul(uint64_t a, uint64_t b) {
    uint128_t c = (uint128_t) a * b;
    return add(c >> 61, c & mod);
  }

  static inline uint64_t generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution< uint64_t > rand(1, RollingHash::mod - 1);
    return rand(mt);
  }

  inline void expand(size_t sz) {
    if(power.size() < sz + 1) {
      int pre_sz = (int) power.size();
      power.resize(sz + 1);
      for(int i = pre_sz - 1; i < sz; i++) {
        power[i + 1] = mul(power[i], base);
      }
    }
  }

  explicit RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

  vector< uint64_t > build(const string &s) const {
    int sz = s.size();
    vector< uint64_t > hashed(sz + 1);
    for(int i = 0; i < sz; i++) {
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
    return hashed;
  }

  template< typename T >
  vector< uint64_t > build(const vector< T > &s) const {
    int sz = s.size();
    vector< uint64_t > hashed(sz + 1);
    for(int i = 0; i < sz; i++) {
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
    return hashed;
  }

  uint64_t query(const vector< uint64_t > &s, int l, int r) {
    expand(r - l);
    return add(s[r], mod - mul(s[l], power[r - l]));
  }

  uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {
    expand(h2len);
    return add(mul(h1, power[h2len]), h2);
  }

  int lcp(const vector< uint64_t > &a, int l1, int r1, const vector< uint64_t > &b, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return low;
  }
};

template<typename T, typename F>
T binSearch(T ok, T ng, F check){
    while(abs(ok-ng)>1){
        T mid = (ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}



void solve() {

    // ll N; cin>>N;
    // V<string> S(N); cin>>S;
    // sort(ALL(S));


    // RollingHash rh(11);
    // V<vector< uint64_t >> T(N);
    // rep(i,N){
    //     T[i] = rh.build(S[i]);
    // }

    // V<ll> ans(N);

    // rep(i,N){

    //     auto check = [&](auto l){
    //         uint64_t hi = rh.query(T[i], 0, l);
    //         rep(j,N) if(i!=j&&S[j].size()>=l){
    //             uint64_t hj = rh.query(T[j], 0, l);
    //             if(hi==hj) return true;
    //             // ES(i) ES(l) ES(h) EL(S[j].substr(0,l))
    //         }
    //         return false;
    //     };

    //     ll ans = binSearch(0LL, len+1, check);
    //     PL(ans)
    // }

    return;
}

void solve2(){
    ll N; cin>>N;
    V<pair<string, int>> S(N);
    rep(i,N){
        cin>>S[i].fi;
        S[i].se = i;
    }

    sort(ALL(S));

    V<ll> ans(N);
    rep(i,N-1){
        auto& [s1, n1] = S[i];
        auto& [s2, n2] = S[i+1];
        rep(j,min(s1.size(), s2.size())){
            if(s1[j]==s2[j]){
                chmax(ans[n1], j+1);
                chmax(ans[n2], j+1);
            }
            else break;
        }
    }
    rep(i,N) PL(ans[i])
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);//小数点以下
    // std::cout << std::setprecision(3);//全体有効数字
    // std::cout << std::defaultfloat;//設定戻す(6桁)
    // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
    // stoll(s,nullptr,base);
    int TT = 1;
    //cin>>TT;
    for(int tt = 0; tt<TT; tt++) solve2();
    return 0;
}
