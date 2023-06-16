#include <bits/stdc++.h>
using namespace std;

//const int MOD = 998'244'353;
const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
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
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

void solve() {

    int n; cin>>n;
    V<ll> A(n); cin>>A;

    ll LCM = 1;
    rep(i,n) LCM = lcm(LCM, A[i]);

    mint ans = 0;
    rep(i,n) ans += LCM/A[i];

    PL(ans)

    return;
}

vector<ll> primes(int n){
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

vector<ll> primes(ll l, ll r){
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

void solve2() {

    int n; cin>>n;
    V<ll> A(n); cin>>A;

    auto primes(1000001);
    

    ll LCM = 1;
    rep(i,n) LCM = lcm(LCM, A[i]);

    mint ans = 0;
    rep(i,n) ans += LCM/A[i];

    PL(ans)

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
