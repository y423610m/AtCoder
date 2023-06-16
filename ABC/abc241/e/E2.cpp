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



void solve() {

    ll n; cin>>n;
    ll k; cin>>k;
    V<ll> A(n); cin>>A;
   // rep(i,n) A[i]%=n;

    ll x = 0;
    V<ll> last(n, -1);
    V<ll> num(n, 0);
    ll period = -1;
    ll inc = 0;
    int i=0;
    while(k){
        if(last[x%n]!=-1){
            period = i-last[x%n];
            inc = x-num[x%n];
            x += A[x%n];
            k--;
            break;
        }
        last[x%n] = i;
        num[x%n] = x;

        x += A[x%n];

        k--;
        i++;
        ES(k) ES(last[x%n]) EL(x) 
    }
    if(k==0) END(x)
    if(period!=0){
        x += inc*(k/period);
        k%=period;
    }
    rep(i,k) x+=A[x%n];
    PL(x)
    return;
}

void solve2(){
    ll n,k; cin>>n>>k;
    V<ll> A(n); cin>>A;

    V<ll> pre(n,-1);
    V<ll> sum(n,-1);

    ll x = 0;
    pre[x%n]=0;
    sum[x%n]=x;
    ll period = 0;
    ll dX =  0;
    int i=0;
    while(k){
        //update
        x += A[x%n];
        //既に到達したか確認
        if(pre[x%n]!=-1){
            period = i+1-pre[x%n];
            dX = x-sum[x%n];
            k--;
            break;
        }
        //到達してない場合の処理
        sum[x%n] = x;
        pre[x%n] = i+1;
        k--;
        i++;
        ES(k) EL(x)
    }
    if(k==0) END(x)
    x += dX*(k/period);
    k%=period;
    rep(i,k) x += A[x%n];
    PL(x)
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
