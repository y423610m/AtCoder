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

    int k; cin>>k;
    string s,t;
    cin>>s>>t;

    s = s.substr(0,4);
    t = t.substr(0,4);

    V<int> num(10,k);
    rep(i,s.size()) if('0'<=s[i]&&s[i]<='9') num[s[i]-'0']--;
    rep(i,t.size()) if('0'<=t[i]&&t[i]<='9') num[t[i]-'0']--;

    V<int> ns(10), nt(10);
    rep(i,s.size()) if('0'<=s[i]&&s[i]<='9') ns[s[i]-'0']++;
    rep(i,t.size()) if('0'<=t[i]&&t[i]<='9') nt[t[i]-'0']++;

    V<ll> Pow = {1,10,100,1000,10000, 100000,1000000, 10000000, 100000000, 1000000000, 10000000000LL};

    ll win = 0;
    ll battle = 0;

EL("-----------")
    repi(i,1,10){//takahashi
        if(num[i]>0){
            ll a = num[i];
            num[i]--;
            ns[i]++;
            ll scores = 0;
            rep(ii,10) scores += ii*Pow[ns[ii]];

            repi(j,1,10){
                if(num[j]>0){
                    ll b = num[j];
                    num[j]--;
                    nt[j]++;
                    ll scoret = 0;
                    rep(jj,10) scoret += jj*Pow[nt[jj]];

                    if(scores>scoret) win += a*b;
                    battle += a*b;

                    ES(i) ES(j) ES(scores) ES(scoret) EL("")

                    num[j]++;
                    nt[j]--;                    
                }
            }
            num[i]++;
            ns[i]--;
        }
    }
    PL((double)(win)/(battle))

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
