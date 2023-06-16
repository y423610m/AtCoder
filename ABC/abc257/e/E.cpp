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

    int n; cin>>n;
    V<ll> C(10);
    C[0] = n;
    rep(i,9) cin>>C[i+1];

    V<ll> dp(n+1);//dp[i]: i円払った時の最高x
    rep(i,n){
        rep(j,10){
            if(i+C[j]<=n) chmax(dp[i+C[j]], dp[i]*10+j);
        }
        EL(dp)
    }
    PL(dp[n])


    return;
}

void solve2() {

    int n; cin>>n;
    V<ll> C(10);
    C[0] = n;
    rep(i,9) cin>>C[i+1];

    V<string> dp(n+1);//dp[i]: i円払った時の最高x
    rep(i,n){
        rep(j,10){
            if(i+C[j]<=n){
                if(dp[i+C[j]].size()<=dp[i].size()) dp[i+C[j]] = dp[i]+char('0'+j);
                else if(dp[i+C[j]].size()==dp[i].size()+1) chmax(dp[i+C[j]], dp[i]+char('0'+j));

                string tmp = dp[i]+char('0'+j);
                ES(tmp)
            }
        }
        EL(dp)
    }
    PL(dp[n])


    return;
}

void solve3(){
    int n; cin>>n;
    V<ll> C(10);
    C[0] = INF;
    rep(i,9) cin>>C[i+1];

    int target = -1; int num = INF;
    for(int i=9;i>=0;i--)if(C[i]<num) {target = i, num=C[i];};

    string ans;
    int N = n;
    string cand = string(N/C[target], char('0'+target));
    N %= C[target];
    ans = cand;
    if(ans.size()==0) END(0)
    cand.pop_back();

    
    for(int i=9;i>target;i++){
        if(N+C[target]>=C[i]){
            ans = cand + char('0'+i);
            break;
        }
    }
    sort(ALL(ans));
    reverse(ALL(ans));


    PL(ans)
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
