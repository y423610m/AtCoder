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

vector<ll> enumPrimes(int n){
    vector<ll> ret;
    if(n<2) return ret;
    vector<bool> prime(n+1, true);
    prime[0]=false;
    prime[1]=false;
    for(ll i=0;i<prime.size();i++){
        if(prime[i]){
            ret.push_back(i);
            for(ll j=2*i;j<prime.size();j+=i){
                prime[j]=false;
            }
        }
    }
    return ret;
}

vector<ll> enumPrimes(ll l, ll r){
    vector<ll> ret;
    if(l<2) l=2;
    if(l>r) return ret;
    vector<bool> prime_small((int)sqrt(r)+2, true);
    vector<bool> prime_big(r-l+1, true);
    prime_small[0]=false;
    prime_small[1]=false;
    for(ll i=0;i<prime_small.size();i++){
        if(prime_small[i]){
            for(ll j=2*i;j<prime_small.size();j+=i){
                prime_small[j]=false;
            }
            for(ll j=max(2*i,(l/i)*i);j<=r;j+=i){
                if(l<=j) prime_big[j-l] = false;
            }
        }
    }
    for(ll i=l;i<=r;i++) if(prime_big[i-l]){
        cout<<i<<endl;
        ret.push_back(i);
    }
    return ret;
}

vector<ll> liniarPrimes(ll N){
    vector<ll> prime;
    vector<ll> lpf(N+1);
    for(ll d=2; d<=N; d++){
        if(lpf[d]==0){
            lpf[d] = d;
            prime.emplace_back(d);
        }
        for(auto p:prime){
            if(p*d>N) break;
            if(p>lpf[d]) break;
            lpf[p*d] = p;
        }
    }
    return prime;
}

vector<ll> lpf(ll N){
    //最小素因数
    ll inf = (1LL<<62)-1;
    vector<ll> lpf(N+1, inf);
    lpf[0] = 1;
    lpf[1] = 1;
    for(ll d=2; d<=N; d++){
        if(lpf[d]==inf){
            lpf[d] = d;
            for(ll e = d*2;e<=N;e+=d){
                lpf[e] = min(lpf[e], d);
            }
        }
    }
    return lpf;
}

vector<ll> gpf(ll N){
    //最大素因数
    vector<ll> gpf(N+1, 0);
    gpf[0] = 1;
    gpf[1] = 1;
    for(ll d=2; d<=N; d++){
        if(gpf[d]==0){
            gpf[d] = d;
            for(ll e = d*2;e<=N;e+=d){
                gpf[e] = d;
            }
        }
    }
    return gpf;
}


void solve() {

   ll N; cin>>N;

   auto P = enumPrimes(1000005);
   EL(P)
   ll ans = 0;
   rep(i,P.size()){
      if(P[i]*P[i]*P[i]*P[i]*P[i]>N) break;
      repi(j,i+1,P.size()){
         if(P[i]*P[i]*P[j]*P[j]*P[j]>N) break;
         repi(k,j+1, P.size()){
            if(P[i]*P[i]*P[j]*P[k]*P[k]>N) break;
            if(P[i]*P[i]*P[j]*P[k]*P[k]<=N){
               ES(k) EL(P[k])
               ans++;
            }
         }
      }
   }
   PL(ans)

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
