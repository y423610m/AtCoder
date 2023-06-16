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
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

vector<ll> enumDivs(ll n, bool sorten=true){
    vector<ll> result;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            result.push_back(i);
            if(i*i!=n) result.push_back(n/i);
        }
    }
    if(sorten) sort(result.begin(), result.end());
    return result;
}

map<int, int> prime_factor(int n){
    map<int, int> res;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) res[n]++;
    return res;
}

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


void solve() {

    ll N; cin>>N;
    auto pfactors = prime_factor(N);

    //1*75
    //3*25
    //3*5*5
    //5*15

    V<ll> d3,d5,d15,d25,d75;
    auto primes = enumPrimes(N);
    for(auto p:primes){
        ll d = p;
        ll cnt = 0;
        while(N/d){
            cnt += N/d;
            d *= p;
        }
        if(cnt>=2) d3.push_back(p);
        if(cnt>=4) d5.push_back(p);
        if(cnt>=14) d15.push_back(p);
        if(cnt>=24) d25.push_back(p);
        if(cnt>=74) d75.push_back(p);
    }
    EL(d3)
    EL(d5)

    ll ans = 0;
    //1*75
    ans += d75.size();
    //3*25
    for(auto p1:d3) for(auto p2:d25) if(p1!=p2) ans++;
    //5*15
    for(auto p1:d5) for(auto p2:d15) if(p1!=p2) ans++;
    //3*5*5
    for(auto p1:d3){
        rep(i,d5.size()) if(d5[i]!=p1){
            repi(j,i+1,d5.size()) if(d5[j]!=p1){
                ES(p1) ES(d5[i]) EL(d5[j])
                ans++;
            }
        }
    }
    PL(ans)

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
