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
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

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
                //cout<<"loop"<<j<<endl;
            }
        }
    }
    for(ll i=l;i<=r;i++) if(prime_big[i-l]){
        cout<<i<<endl;
        ret.push_back(i);
    }
    return ret;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    // 返り値: a と b の最大公約数
    // ax + by = gcd(a, b) を満たす (x, y) が格納される
    //x,yは初期化不要!
    //ll x,y;
    //ll g = extGCD(a,b,x,y);
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

#include "atcoder/math"

void solve() {
    ll N = 9;
    ll M = 108;
    V<ll> len = {4,9,5,7,11,13,17,19,23};//sum=108
    sort(ALL(len));
    V<ll> L(N), R(N);//半開区間
    L[0] = 0, R[0] = 4;
    repi(i,1,N){
        L[i] = R[i-1];
        R[i] = L[i]+len[i];
    }
    EL(L)
    EL(R)

    V<ll> A(M);
    rep(i,N){
        rep(j,len[i]){
            A[L[i]+j] = L[i] + (j+1)%len[i];
        }
    }
    //EL(A)
    
    //----------------------step1
    PL(M)
    rep(i,M) PS(A[i]+1)
    PL("")

    V<ll> B(M); cin>>B;
    rep(i,M) B[i]--;

    V<ll> d(N);
    rep(i,N) d[i] = B[L[i]]-L[i];
    EL(d)

    // 返り値: a と b の最大公約数
    // ax + by = gcd(a, b) を満たす (x, y) が格納される
    //x,yは初期化不要!
    //ll x,y;
    //ll g = extGCD(a,b,x,y);

    /*
    len[i]*x+d[i] = len[j]*y+d[j]
    len[i]*x - len[j]*y = d[j] - d[i];
    */

    ll ans = d[0];
    rep(i,N-1){
        ll x,y;
        ll GCD = gcd(len[i], len[i+1]);
        GCD = gcd(GCD, abs(d[i+1]-d[i]));
        ll g = extGCD(len[i]/GCD, len[i+1]/GCD,x,y);
        ES(i) ES(x) ES(y) ES(g) EL(GCD)

        ans = lcm(ans, abs(len[i]*x+d[i])%lcm(len[i], len[i+1]));
    }
    PL(ans)

    // PL(atcoder::crt(d,len).first)


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
ABC286 5完
A for
B 初めてコンテストでPython使った
C N回rotate
D dp．なんで3秒なのか良くわからなかった
E 明らかにワーシャルフロイドだけど，ダイクストラでも!?と思って1ぺナ．何度目だこれ．
F [2,29]の素数考えるけど，110超える，適当に8入れておこう．
余り求めてユークリッドとかで行けそうとか思いつつ，解けず．
中国剰余定理ようやく使い道を知った
*/