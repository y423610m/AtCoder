#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
//const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

void solve(){
    int h,n; cin>>h>>n;
    V<V<ll>> dp(n+1, V<ll>(h+1,LINF));
    dp[0][0]=0;
    rep(i,n){
        int a,b; cin>>a>>b;
        rep(j,h+1) chmin(dp[i+1][j], dp[i][j]);
        rep(j,h+1){
            if(j+a<=h) chmin(dp[i+1][j+a], dp[i][j]+b);
            else chmin(dp[i+1][h], dp[i][j]+b);

            if(j+a<=h) chmin(dp[i+1][j+a], dp[i+1][j]+b);
            else chmin(dp[i+1][h], dp[i+1][j]+b);
        }         
    }
    //rep(i,n+1) EL(dp[i])
    PL(dp[n][h])
}

void solve2() {

    // int h,n; cin>>h>>n;
    // V<AB> v;
    // rep(i,n){
    //     ll a,b; cin>>a>>b;
    //     v.push_back({a,b});
    // }

    // sort(ALL(v),[](AB x, AB y){
    //     if( x.a*y.b != x.b*y.a ) return (double)x.a/x.b > y.a>y.b;
    //     else return x.b<y.b;
    // });

    // ll ans = 0;
    // AB ab = v[0];
    // ans += (h/ab.a)*ab.b; 


    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
