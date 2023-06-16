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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using ull = long long;
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int n; cin>>n;
    ll k; cin>>k;
    V<ll> A(n); cin>>A;
    sort(RALL(A));

    auto f= [&](ll x)->bool{
        ll cnt = 0;
        rep(i,n){
            if(x<=A[i]) cnt += A[i]-x+1;
        }
        if(cnt>=k) return true;
        else return false;
    };

    ll l = 0; ll r = 1000000000001;
    while(l+1<r){
        ll mid = (l+r)/2;
        if(f(mid)) l=mid;
        else r=mid;
        //ES(l) EL(r)
    }
    ll x = l;
    ES("x") EL(x)
    chmax(x, 1);

    ull ans = 0;
    rep(i,n){
        if(A[i]>=x){
            ans += (ull)(A[i]+x)*(A[i]-x+1)/2;
            k -= A[i]-x+1;
            A[i] = x-1;
            //EL(ans)
        }
    }

    //sort(RALL(A));
    if(k<0) ans -= (ull)abs(k)*(x);
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
