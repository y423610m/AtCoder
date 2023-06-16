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

    string s,t;
    cin>>s>>t;

    int si = (int)s.size()-1;
    int ti = (int)t.size()-1;

    while(si>=0 && ti>=0){

        if(s[si]==t[ti]){
            si--;
            ti--;
            continue;
        }

        while(ti>0 && s[si]!=t[ti] && ti+2<t.size() && t[ti]==t[ti+1] && t[ti]==t[ti+2]){
            ti--;
        }
    }
    if(ti==-1 && si==-1) PL("Yes")
    else PL("No")

    return;
}

void solve2(){
    string s; cin>>s;
    string t; cin>>t;

    int ti = 0;
    rep(i,s.size()){
        if(s[i]==t[ti]){
            ti++;
            continue;
        }

        while(ti>=2 && t[ti]==t[ti-1] && t[ti]==t[ti-2]){
            ti++;
            if(ti==t.size()) {ES(1) END("No")}
        }

        if(s[i]==t[ti]){
            ti++;
            continue;
        }

        ES(2) END("No")
    }

    if(ti==t.size()){
        ES(3)
        END("Yes")
    }

    while(ti!=t.size()){
        if(t[ti]!=s.back()) END("No")
        if(s.size()>2 && t[ti]!=s[s.size()-2]) END("No")
        ti++;
    }

    PL("Yes")

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
