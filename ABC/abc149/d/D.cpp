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



void solve() {

    int n,k; cin>>n>>k;
    int R,S,P; cin>>R>>S>>P;
    string t; cin>>t;

    string s = t;
    rep(i,t.size()){
        if(i-k<0){
            if(t[i]=='r') s[i]='r';
            if(t[i]=='s') s[i]='s';
            if(t[i]=='p') s[i]='p';
        }
        else if(t[i]!=t[i-k]){
            if(t[i]=='r') s[i]='r';
            if(t[i]=='s') s[i]='s';
            if(t[i]=='p') s[i]='p';
        }
        else{
            if(t[i]=='r'&&s[i-k]!=t[i]) s[i]='r';
            else if(t[i]=='s'&&s[i-k]!=t[i]) s[i]='s';
            else if(t[i]=='p'&&s[i-k]!=t[i]) s[i]='p';
            else s[i]='*';      
        }
    }

    ll ans = 0;
    rep(i,s.size()){
        if(s[i]=='r') ans+=P;
        if(s[i]=='s') ans+=R;
        if(s[i]=='p') ans+=S;
    }

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
