#include <bits/stdc++.h>
using namespace std;

//const int MOD = 998'244'353;
const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

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
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

//x = n+2m
//y = 2n+m

//2x = 2n+4m
//y = 2n+m

//3m=2x-y

//3y=6n+2x-y
//3n=2y-x

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz,int p) : _fact(sz + 1), _rfact(max(p,sz-p) + 1){
    p = max(p,sz-p);
    _fact[0] = _rfact[p] = 1;
    _rfact[p]=1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[p] /= _fact[p];
    for(int i = p - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

};
//Combination<mint> Comb(MaxSize);
//auto a = Comb.C(p,q);
//auto b = Comb.P(n,r);
//auto c = Comb.H(n,r);

void solve() {

    ll x,y; cin>>x>>y;
    if((x*2-y)%3!=0)END(0)
    if((y*2-x)%3!=0)END(0)
    ll n = (y*2-x)/3;
    ll m = (x*2-y)/3;
    if(n<0||m<0) END(0)
    Combination<mint> Comb(n+m, n);
    PL(Comb.C(n+m,min(m,n)))

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
