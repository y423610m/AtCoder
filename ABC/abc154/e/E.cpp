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



void solve() {

    string s; cin>>s;
    int K; cin>>K;
    
    //dp[i][j][smaller] : 上からi桁目までで，0でない桁がj個の数
    V<V<ll>> dp(K+1, V<ll>(2));
    dp[0][0]=1;
    dp[0][1]=1;

    rep(i,s.size()){
        auto nxt = V<V<ll>>(K+1, V<ll>(2));

        //0を選ぶ場合

        //0->0
        if(s[i]=='0') rep(j,K) nxt[j+1][0] += dp[j][0];
        //0->1
        if(s[i]!='0') rep(j,K) nxt[j+1][1] += dp[j][0];
        //1->1
        rep(j,K) nxt[j+1][1] += dp[j][1];

        //0以外を選ぶ場合
        //0->0
        if(s[i]!='0') rep(j,K+1) nxt[j][0] += dp[j][0];
        //0->1
        if(s[i]!='0') rep(j,K+1) nxt[j][1] += dp[j][0]*(s[i]-'0');
        //1->1
        rep(j,K+1) nxt[j][1] += dp[j][1]*9;

        dp = nxt;
        rep(j,K+1) ES(dp[j][0]) EL("")
        rep(j,K+1) ES(dp[j][1]) EL("")
    }
    PL(dp[K][0]+dp[K][1])

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
