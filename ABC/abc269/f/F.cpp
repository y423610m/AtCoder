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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

void solve() {

    ll N,M; cin>>N>>M;

    int Q; cin>>Q;
    rep(_,Q){
        ll A,B,C,D;
        cin>>A>>B>>C>>D;

        int b = B;
        int d = D;

        if((B-A+1)%2==1) b--;
        if((D-C+1)%2==1) d--;

        mint ans = 0;

        ans += mint(A-1+b-1)*(b-A+1)*M*(d-C+1)
            + mint(b-A+1)*(C+d)*(d-C+1);
        ans /= 4;
        ES(ans)

        if(b!=B){
            ll n = (d-C+1)/2;
            mint s =  ( (mint(B-1)*M+C)*2+mint(n-1)*2 )*n/2;
            //(mint(B-1)*M+C + mint(B-1)*M+(2*(d-C)/2))*((d-C)/2);
            if((B+C)%2==1) s += n;
            ans += s;
        }
        ES(ans)

        if(d!=D){
            ll n = (b-A+1)/2;
            mint s = ( (mint(A-1)*M+D)*2 + mint(n-1)*M*2)*n/2;
            if((A+D)%2==1) s += M*n;
            ans += s;
        }
        ES(ans)

        if(b!=B&&d!=D){
            if((B+D)%2==0) ans += ((B-1)*M+D);
        }
        ES(ans)

        PL(ans)
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
