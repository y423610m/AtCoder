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
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

long long POW(long long a, long long b, long long mod = 0){
   long long ret = 1;
   long long tmp = a;
   if(mod) tmp%=mod;
   while(b){
      if(b&1){
         ret *= tmp;
         if(mod) ret%=mod;
      }
      b /= 2;
      if(b) tmp *= tmp;
      if(mod) tmp%=mod;
   }
   return ret;
}
// ll result = POW(5,3); ->125

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
/*
    //メモリの許す限り無限
    mp::cpp_int x = 1;
    mp::int128_t 1e36
    mp::int256_t 1e70
    mp::int512_t 1e150
    mp::int1024_t 1e300

    文字列->整数
    cpp_int x("123");
    x.assign("123");

    整数->文字列
    string s = x.str();
    x.str(0, std::ios_base::oct,hex,)

    劣型変換
    int128_t i128 = static_cast<int128_t>(i256)
*/

void solve() {

    ll K; cin>>K;
    string T,A; cin>>T>>A;

    V<ll> rest(10, K);
    rest[0] = 0;
    V<ll> Ta(10), Ao(10);
    rep(i,4){
        Ta[T[i]-'0']++;
        rest[T[i]-'0']--;
    }
    rep(i,4){
        Ao[A[i]-'0']++;
        rest[A[i]-'0']--;
    }
    EL(rest)
    EL(Ta)
    EL(Ao)


    auto calc = [&](auto& vec)->ll {
        ll res = 0;
        rep(i,10) res += i * POW(10, vec[i]);
        return res;
    };

    ll win = 0;
    ll battle = 0;
    rep(i,10)if(rest[i]){
        ll restI = rest[i];
        rest[i]--;
        Ta[i]++;
        rep(j,10)if(rest[j]){
            ll restJ = rest[j];
            rest[j]--;
            Ao[j]++;
            battle += restI*restJ;
            if(calc(Ta)>calc(Ao)){
                ES(i) EL(j)
                win += restI*restJ;
            }
            rest[j]++;
            Ao[j]--;
        }
        rest[i]++;
        Ta[i]--;
    }
    EL(win)

    PL(1.0*win/battle)

    return;
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
    for(int tt = 0; tt<TT; tt++) solve();
    return 0;
}
