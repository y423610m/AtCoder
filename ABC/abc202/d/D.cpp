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
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

vector<long long> digit(long long a, int b=2, bool reverse_ = true){
    vector<long long> ret;
    while(a){
        ret.push_back(a%b);
        a/=b;
    }
    if(reverse_) reverse(ret.begin(), ret.end());
    return ret;
}
// vector<ll> dgt10 = digit(100,10) -> {1,0,0}
// vector<ll> dgt10 = digit(100,10,false) -> {0,0,1}
// vector<ll> dgt2 = digit(100,2) -> {1,1,0,0,1,0,0}

long long POW(long long a, long long b, long long mod = 0){
   long long ret = 1;
   long long tmp = a;
   if(mod) tmp%=mod;
   while(b){
      if(b&1){
         ret *= tmp;
         if(mod) ret%=mod;
      }
      b /= 2;
      if(b) tmp *= tmp;
      if(mod) tmp%=mod;
   }
   return ret;
}
// ll result = POW(5,3); ->125

void solve() {

    int a,b; cin>>a>>b;
    ll k; cin>>k;
    rep(i,b) k+=POW(2,i);

    auto dgt = digit(k,2);
    rep(i,a+b-dgt.size()) cout<<'a';
    rep(i,dgt.size()) cout<<(dgt[i]==0?'a':'b');
    cout<<endl;

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
