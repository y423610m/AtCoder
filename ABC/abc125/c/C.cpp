#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

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
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

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

void solve() {

    ll N; cin>>N;
    V<ll> A(N); cin>>A;
    sort(ALL(A));

    ll GCD = A[0];
    rep(i,N) GCD = gcd(GCD,A[i]);
    rep(i,N) A[i]/=GCD;
    EL(GCD)
    EL(A)

    map<ll,ll> mp, cnt;

    rep(i,N){
        auto divs = enumDivs(A[i]);
        for(auto d:divs){
            cnt[d]++;
            mp[d] += i;
        }
    }

    ll ans = 1;
    ll sum = (N-1)*N/2;

    V<ll> cand(N,1);
    for(auto p:cnt){
        auto [d,n] = p;
        if(n==N-1){
            chmax(cand[sum-mp[d]], d);
        }
    }
    EL(cand)

    rep(i,N) chmax(ans, cand[i]);
    
    PL(ans*GCD)

    return;
}


#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
template<typename T> T RMQop(T a, T b){return max(a,b);}
template<typename T> T RMQe(){return -LINF;}
template<typename T> T RmQop(T a, T b){return min(a,b);}
template<typename T> T RmQe(){return LINF;}
template<typename T> T RSQop(T a, T b){return a+b;}
template<typename T> T RSQe(){return T(0);}
ll op(ll a, ll b){return gcd(a,b);}

template<typename T=ll> using RMQ = segtree<T, RMQop<T>, RMQe<T>>;//Range Max Query
template<typename T=ll> using RmQ = segtree<T, RmQop<T>, RmQe<T>>;// RmQ tree(vec); tree.prod(l,r)
template<typename T=ll> using RSQ = segtree<T, RSQop<T>, RSQe<T>>;

ll seg_target;
bool f(ll vi){return vi<seg_target;}//seg.max_right<f>(x-1)
bool f2(ll vi){return vi>=seg_target;}//seg.max_right<f>(x-1)
//max_right<f>(l):=>[l:N)でfを満たす右端．
//min_left<f>(r):=>[0:r)でfを満たす左端．
//f(e)=trueでなければならない
#endif
void solve2(){
    ll N; cin>>N;
    V<ll> A(N); cin>>A;

    segtree<ll,op,RSQe<ll>> tree(N);
    rep(i,N) tree.set(i, A[i]);

    ll ans = 1;
    rep(i,N) chmax(ans, gcd(tree.prod(0,i), tree.prod(i+1,N)));
    PL(ans)
}


int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
