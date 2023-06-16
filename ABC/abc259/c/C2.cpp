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


vector<pair<char, int>> RLE(const string& s){
    vector<pair<char, int>> ret;
    for(int i=0;i<(int)s.size();i++){
        if(ret.size()==0) ret.push_back({s[i],1});
        else if(ret.back().first==s[i]) ret.back().second++;
        else ret.push_back({s[i], 1});
    }
    return ret;
}

template <typename T>
vector<pair<T, int>> RLE(const vector<T>& vec){
    vector<pair<T, int>> ret;
    for(int i=0;i<(int)vec.size();i++){
        if(ret.size()==0) ret.push_back({vec[i],1});
        else if(ret.back().first==vec[i]) ret.back().second++;
        else ret.push_back({vec[i], 1});
    }
    return ret;    
}

void solve() {

    string s; cin>>s;
    string t; cin>>t;

    auto RS = RLE(s);
    auto RT = RLE(t);

    if(RS.size()!=RT.size()) END("No")

    rep(i,RS.size()){
        if(RS[i].first!=RT[i].first) END("No")
        if(RS[i].second==RT[i].second) continue;
        if(RT[i].second>RS[i].second && RS[i].second>=2) continue;
        END("No")
    }
    PL("Yes")

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
