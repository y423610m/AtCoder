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
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int N; cin>>N;
    V<Pii> LR(N); cin>>LR;

    int MAX = 10'000'002;
    //imos
    V<int> Ls(MAX);
    V<int> Rs(MAX);
    rep(i,N){
        Ls[LR[i].fi]++;
        Rs[LR[i].se]++;
    }
    int tmp = 0;
    rep(i,MAX){
        tmp += Rs[i];
        Rs[i] = tmp;
    }
    tmp = 0;
    for(int i=MAX-1;i>=0;i--){
        tmp += Ls[i];
        Ls[i] = tmp;
    }
    EL("a")

    V<ll> X;
    rep(i,N){
        EL(i)
        auto [L, R] = LR[i];

        if(abs(Rs[L]-Ls[L])!=abs(Rs[R]-Ls[R])){
            if(abs(Rs[L]-Ls[L])<abs(Rs[R]-Ls[R])) X.push_back(L);
            else X.push_back(R);
            continue;
        }

        L--, R++;
        while(L+3<R){
            int c1 = (L*2+R*1)/3;
            int c2 = (L*1+R*2)/3;
            chmax(c1, 0);
            chmax(c2, 0);
            if(abs(Rs[c1]-Ls[c1])<abs(Rs[c2]-Ls[c2])) R = c2;
            else L = c1;
            ES(L) EL(R)
        }
        L++, R--;
        int x;
        if(abs(Rs[L]-Ls[L])<abs(Rs[R]-Ls[R])) x = L;
        else if(abs(Rs[L-1]-Ls[L+1])>abs(Rs[R-1]-Ls[R+1]))x = R;
        else if(Rs[L]>Ls[R]) x = L;
        else x = R;
        EL(x)
        X.push_back(x);
    }
    EL("b")

    ll ans = 0;
    ll sum = 0;
    SORT(X);
    rep(i,X.size()){
        ans += X[i]*i-sum;
        sum += X[i];
    }
    PL(ans)
    EL(X)
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
