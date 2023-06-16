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
    string S; cin>>S;
    string X; cin>>X;

    V<ll> d(N+1);
    d[N] = 1;
    for(ll i=N-1;i>=0;i--) d[i] = d[i+1]*10%7;

    //i回目で余りがjの時，最終的に7の倍数にできる可能性があるか
    V<V<bool>> dp(N+1,V<bool>(7));
    dp[N][0] = true;
    for(ll i=N-1;i>=0;i--){
        //Sを選んだ時
        int s = S[i]-'0';
        ll D = d[i];
        //rep(j,7) dp[i][j] = dp[i][j]|dp[i+1][(s*10+j)%7];
        rep(j,7) dp[i][(s*D+j)%7] = dp[i][(s*D+j)%7]|dp[i+1][j];

        //0を選んだ時
        rep(j,7) dp[i][j] = dp[i][j]|dp[i+1][j];
    }

    rep(i,N+1) EL(dp[i])



    V<V<bool>> visited(N+1, V<bool>(7));
    visited[0][0] = true;

    rep(i,N){
        rep(j,7)if(visited[i][j]){
            if(X[i]=='T'){//勝てる手があれば進む
                //Sを選んだ時
                int to = (j*d[i]+int(S[i]-'0'))%7;
                if(dp[i+1][to]) visited[i+1][to] = true;
                //0
                to = (j*d[i])%7;
                if(dp[i+1][to]) visited[i+1][to] = true;
            }
            if(X[i]=='A'){//勝てる手があれば進む
                //Sを選んだ時
                int to1 = (j*d[i]+int(S[i]-'0'))%7;
                //0
                int to2 = (j*d[i])%7;
                if(dp[i+1][to1]&dp[i+1][to2]){//7不可避なら全部進む
                    visited[i+1][to1] = true;
                    visited[i+1][to2] = true;
                }
                else{//７にしない道がある！
                    if(!dp[i+1][to1]) visited[i+1][to1] = true;
                    if(!dp[i+1][to2]) visited[i+1][to2] = true;
                }
            }
        }
    }
    rep(i,N+1) EL(visited[i])

    if(visited[N][0]) PL("Takahashi")
    else PL("Aoki")


    return;
}


void solve2(){
    ll N; cin>>N;
    string S,X; cin>>S>>X;

    V<V<bool>> dp(N+1, V<bool>(7));
    dp[N][0] = true;

    ll d = 1;
    for(ll i=N-1;i>=0;i--){
        int s = int(S[i]-'0')*d%7;
        d *= 10; d%=7;
        rep(j,7){
            if(X[i]=='T') dp[i][j] = dp[i+1][j]||dp[i+1][(j+s)%7];
            else dp[i][j] = dp[i+1][j]&&dp[i+1][(j+s)%7];
        }
    }
    if(dp[0][0]) PL("Takahashi")
    else PL("Aoki")

    rep(i,N+1) EL(dp[i])

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
