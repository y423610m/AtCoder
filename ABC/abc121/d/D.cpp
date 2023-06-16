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

ll acc_xor(ll x){
    //[0,x]の累積xor計算
    ll ans = 0;
    rep(i,60){
        ll n = 0;
        ll d = 1LL<<(i+1);
        n += (x)/d;
        n%=2;
        n *= 1LL<<(i);
        n%=2;
        //端数計算
        ll m = 0;
        m += max(0LL,(x)%d+1-(1LL<<(i)));
        if((n+m)&1) ans += (1LL<<i);
    }
    return ans;
}

ll acc_sum(ll x){
    //[0,x]の累積和 O(logx==60)
    return (x)*(x+1)/2;
}

ll f2(ll x){
    ll ans = 0;
    rep(i,x+1) ans ^= i;
    return ans;
}

ll f(ll x){
    //[0,x]の累積和 O(1)
    if(x<=0) return 0;
    if(x%2==1) return (x+1)/2%2;
    else return ((x+1)/2%2)^x;
}

void solve() {

    ll A,B; cin>>A>>B;
    ES(f(A)) ES(f(A-1)) EL(f(B))
    EL(acc_xor(A-1))

    // rep(i,10){
    //     ES(i) EL(f(i))
    // }

    //PL(acc_xor(A-1)^acc_xor(B))
    PL(f(A-1)^f(B))


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