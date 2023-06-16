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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

void solve1() {

    int n; cin>>n;
    string s; cin>>s;
    

    V<mint> Eq(n+1);
    V<mint> Ls(n+1);
    Eq[0] = 1;

    rep(i,(n+1)/2){
        Eq[i+1] += Eq[i];

        Ls[i+1] += Eq[i]*(s[i]-'A');
        Ls[i+1] += Ls[i]*26;
    }

    mint ans = Ls[(n+1)/2];

    bool ok = true;
    for(int i=(n)/2-1;i>=0;i--){
        if(s[i]==s[n-1-i]) continue;
        if(s[i]>s[n-1-i]) ok = false;
        break;
    }

    EL(ok)
    if(ok) ans++;

    PL(ans)


    return;
}


char s[1000005];

void solve() {

    int n; scanf("%d", &n);
    //string s;
    scanf("%s", s);
    

    ll ans2 = 0;

    int n1 = (n+1)>>1;
    rep(i,n1){
        ans2 = ans2*26+s[i]-'A';
        if(ans2>=MOD) ans2%=MOD;
    }

    bool ok = true;
    int n2 = (n>>1)-1;
    for(int i=n2;i>=0;i--){
        if(s[i]==s[n-1-i]) continue;
        if(s[i]>s[n-1-i]) ok = false;
        break;
    }

    if(ok) ans2++;
    ans2%=MOD;

    PL(ans2)


    return;
}



int main() {
   //std::cin.tie(nullptr);
   //std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
