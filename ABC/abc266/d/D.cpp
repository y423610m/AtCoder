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
#define fi first
#define se second
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

struct Snuke{
    int t;
    int x;
    ll a;

    void get(){
        cin>>t>>x>>a;
    }
};

void solve() {

    int N; cin>>N;
    int TMAX = 100001;
    V<Pii> Snukes(TMAX, Pii(-1, -1));//x,a
    rep(i,N){
        int t,x,a;
        cin>>t>>x>>a;
        Snukes[t] = Pii(x,a);
    }

    //dp[j][k]:=時刻iで穴jにいる時の最大snuke
    V<V<ll>> dp(TMAX, V<ll>(5, -LINF));
    dp[0][0] = 0;
    rep(t,TMAX-1){
        dp[t+1] = dp[t];
        rep(x,5){
            for(int dx=-1;dx<=1;dx++) if(0<=x+dx&&x+dx<5){
                chmax(dp[t+1][x], dp[t][x+dx]);
            }
        }
        if(Snukes[t+1].fi!=-1){
            int x = Snukes[t+1].fi;
            int a = Snukes[t+1].se;
            if(dp[t+1][x]!=-LINF) dp[t+1][x] += a;
        }
    }

    ll ans = 0;
    rep(t,TMAX) rep(x,5) chmax(ans, dp[t][x]);
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
