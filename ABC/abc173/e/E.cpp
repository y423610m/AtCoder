#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long;
// const ll MOD = 998'244'353;
const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define endl "\n"
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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
istream &operator>>(istream &is, mint& x){ll val; is >> val; x = val; return is;}
#endif

void solve() {

    ll N,K; cin>>N>>K;
    V<ll> A(N); cin>>A;
    if(K==N){
        mint ans = 1;
        rep(i,N) ans *= A[i];
        END(ans)
    }

    bool hasPositive = false;
    rep(i,N) if(A[i]>=0) hasPositive = true;
    if(!hasPositive&&K%2){
        sort(RALL(A));
        mint ans = 1;
        rep(i,K) ans *= A[i];
        END(ans)
    }

    sort(ALL(A), [](ll a, ll b){
        return abs(a)>abs(b);
    });
    mint ans = 1;
    V<ll> p,m;
    int sig = 0;
    bool has0 = false;
    rep(i,K){
        ans *= abs(A[i]);
        if(A[i]<0) sig++;
        if(A[i]>=0) p.push_back(abs(A[i]));
        else m.push_back(abs(A[i]));
        if(A[i]==0) has0 = true;
    }
    if(sig%2==0) END(ans)
    if(has0) END(0)

    bool firstM = false;
    bool firstP = false;
    ll newP, newM;
    repi(i,K,N){
        if(A[i]>=0){
            if(firstP){
                newP = abs(A[i]);
                firstP = true;
            }
        }
        else{
            if(firstM){
                newM = abs(A[i]);
                firstM = true;
            }
        }
    }
    if(firstP&&!firstM){
        ans /= m.back();
        ans *= newP;
    }
    else if(!firstP&&firstM){
        ans /= p.back();
        ans *= newM;
    }
    END(ans)

    // newP/m.back()>=newM/p.back()
    if(newP*p.back()>=newM*m.back()){
        ans /= m.back();
        ans *= newP;
    }
    else{
        ans /= p.back();
        ans *= newM;
    }

    PL(ans)

    return;
}

void solve2(){
    ll N,K; cin>>N>>K;
    V<Pll> A(N);
    rep(i,N) cin>>A[i].se;
    rep(i,N) A[i].fi = abs(A[i].se);

    sort(RALL(A));

    if(A[K-1].fi==0) END(0)

    ll cnt = 0;
    rep(i,K) if(A[i].se<0) cnt++;

    mint ans = 1;
    rep(i,K) ans *= A[i].fi;
    if(cnt%2==0) END(ans)

    ll pi = K-1, ni = K-1, pj = K, nj = K;
    while(pi>=0&&A[pi].se<0) pi--;
    while(ni>=0&&A[ni].se>0) ni--;
    while(pj<N &&A[pj].se<=0) pj++;
    while(nj<N &&A[nj].se>=0) nj++;

    if(pi>=0&&ni>=0&&pj<N&&nj<N){
        //pj/ni>nj/pi
        if(A[pj].fi*A[pi].fi>A[ni].fi*A[nj].fi) END(ans*A[pj].fi/A[ni].fi)
        else END(ans*A[nj].fi/A[pi].fi)
    }

    if(ni>=0&&pj<N) END(ans*A[pj].fi/A[ni].fi)
    if(pi>=0&&nj<N) END(ans*A[nj].fi/A[pi].fi)

    if(A.back().fi==0) END(0)

    ans = 1;
    reverse(ALL(A));
    rep(i,K) ans *= A[i].se;
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
