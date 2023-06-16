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

    ll n,Q,x; cin>>n>>Q>>x;
    V<ll> W(n); cin>>W;

    ll totalW = 0;
    rep(i,n) totalW += W[i];

    ll initNum = (x/totalW)*n;
    x %= totalW;

    //iから入れ始めた際，何個いれるか
    V<ll> num(n, initNum);
    ll sum = 0;
    ll id = 0;
    queue<ll> que;
    rep(i,n){
        while(sum<x){
            sum += W[id];
            que.push(W[id]);
            id++;
            id%=n;
        }
        num[i] += (ll)que.size();
        if(que.size()>0){
            sum -= que.front();
            que.pop();
        }
    }
    EL(num)


    //ダブリングで５０回くらい
    V<V<ll>> dp(62, V<ll>(n,0));
    rep(i,n) dp[0][i] = (num[i]+i)%n;
    rep(i,61){
        rep(j,n){
            dp[i+1][j] = dp[i][dp[i][j]];
           // dp[i+1][j] = (dp[i+1][j]+1)%n;
        }
    }

    rep(i,3) EL(dp[i])

    rep(_,Q){
        ll k; cin>>k; k--;
        ll from = 0;
        rep(i,60){
            if(k&1){
                from = dp[i][from];
            }
            k/=2;
        }
        ES(from)
        PL(num[from])

    }

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
