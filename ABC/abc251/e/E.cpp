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
#define NAME(a) #a
#define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
#define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<int, int>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int n; cin>>n;
    V<int> A(n); cin>>A;
   // A.push_back(A[0]);

    // A1 not used
    V<V<ll>> dp1(n, V<ll>(2, LINF));
    dp1[0][0]=0;
    rep(i,n-1){
        dp1[i+1][0] = dp1[i][1];
        dp1[i+1][1] = min(dp1[i][0], dp1[i][1]) + A[i+1];
        //ES(dp1[i+1][0]) ES(dp1[i+1][1]) EL("")
    }
    EL("")

    V<V<ll>> dp2(n+1, V<ll>(2, LINF));
    dp2[0][1]=A[0];
    rep(i,n-1){
        dp2[i+1][0] = dp2[i][1];
        dp2[i+1][1] = min(dp2[i][0], dp2[i][1]) + A[i+1];
        //ES(dp2[i+1][0]) ES(dp2[i+1][1]) EL("")
    }

    ll ans = LINF;
    //chmin(ans, dp1[n][0]+A[n-1]);
    chmin(ans, dp1[n-1][1]);
    chmin(ans, dp2[n-1][0]);
    chmin(ans, dp2[n-1][1]);

    PL(ans)


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
