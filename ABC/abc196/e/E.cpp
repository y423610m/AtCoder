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



void solve() {

    ll N; cin>>N;
    V<Pll> AT(N); cin>>AT;
    V<Pll> newAT;
    newAT.emplace_back(AT[0]);
    repi(i,1,N){
        if(newAT.back().se==1&&AT[i].se==1){
            newAT.back().fi += AT[i].fi;
        }
        else newAT.emplace_back(AT[i]);
    }
    swap(AT, newAT);
    N = AT.size();

    V<unordered_map<ll,ll>> dp(N+1);
    dp[0].reserve(2*N);

    ll Q; cin>>Q;
    V<ll> X(N);
    rep(q,Q){
        ll x; cin>>x;
        ll id = N-1;
        bool escaped = false;
        rep(i,N){
            if(dp[i].find(x)!=dp[i].end()){
                x = dp[i][x];
                escaped = true;
                id = i-1;
                break;
            }
            if(AT[i].se==1) x += AT[i].fi;
            else if(AT[i].se==2) chmax(x, AT[i].fi);
            else chmin(x, AT[i].fi);
            X[i] = x;
        }
        if(escaped){
            for(ll i=id;i>=0;i--){
                dp[i][X[i]] = x; 
            }
        }
        PL(x)
    }

    return;
}

void solve2(){
    ll N; cin>>N;
    V<ll> A(N), T(N);
    rep(i,N) cin>>A[i]>>T[i];

    ll Q; cin>>Q;
    rep(q,Q){
        ll x; cin>>x;
        rep(i,N){
            if(T[i]==1) x += A[i];
            else if(T[i]==2) chmax(x, A[i]);
            else chmin(x, A[i]);
        }
        PL(x)
    }
}

void solve3(){
    int N; cin>>N;
    
    ll l = -LINF, r = LINF, add = 0;
    for(int i=0;i<N;i++){
        ll a; cin>>a;
        int t; cin>>t;
        if(t==1){
            l += a;
            r += a;
            add += a;
        }
        else if(t==2){
            chmax(l,a);
            chmax(r,a);
        }
        else{
            chmin(l,a);
            chmin(r,a);
        }
    }

    int Q; cin>>Q;
    for(int q=0;q<Q;q++){
        ll x; cin>>x;
        x += add;
        chmax(x,l);
        chmin(x,r);
        PL(x)
    }

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
