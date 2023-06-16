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
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    ll N; cin>>N;
    V<ll> P(N), Q(N); cin>>P>>Q;
    for(auto& p:P) p--;
    for(auto& q:Q) q--;

    if(P[0]!=0) END(-1)

    V<ll> posQ(N);
    rep(i,N) posQ[Q[i]] = i;

    V<V<ll>> Child(N);
    V<bool> used(N,false);

    V<ll> L(N), R(N);
    bool ng = false;
    auto dfs = [&](auto dfs, int pl, int pr, int ql, int qr)-> void {
        if(pr-pl<=1) return;
        ll par = P[pl];
        if(posQ[par]<ql||qr<=posQ[par]){
            ng  = true;
            return;
        }
        used[par] = true;
        ES(par) ES(pl) ES(pr) ES(ql) EL(qr)
        // ll pl2 = pl+1;
        // ll pr2 = pl+1+posQ[par];
        // ll ql2 = ql;
        // ll qr2 = posQ[par];

        ll lenL = max(0LL,posQ[par]-ql);
        ll lenR = max(0LL,qr-posQ[par]-1);

        if(lenL>=1) L[par] = P[pl+1]+1;
        else L[par] = 0;
        if(lenL>1){
            ES(par) ES("left") ES(lenL) EL(pl+1)
            dfs(dfs, pl+1, pl+1+lenL, ql, ql+lenL);
        }

        
        if(lenR>=1) R[par] = P[pl+1+lenL]+1;
        else R[par] = 0;
        if(lenR>1){
            ES(par) ES("right") ES(lenR) EL(pl+1+lenL)
            dfs(dfs, pl+1+lenL, pl+1+lenL+lenR, posQ[par]+1, qr);
        }
    };
    dfs(dfs, 0, N, 0, N);
    EL("a")

    if(ng) END(-1)

    rep(i,N){
        PS(L[i]) PL(R[i])
    }

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
