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

    int n; cin>>n;

    V<int> d1(n,-1), d2(n,-1);

    for(int i=2;i<n;i++){
        PS("?") PS(1) PL(i+1)
        int d; cin>>d;
        if(d==-1) return;
        d1[i] = d;
    }
    for(int i=2;i<n;i++){
        PS("?") PS(2) PL(i+1)
        int d; cin>>d;
        if(d==-1) return;
        d2[i] = d;
    }
    int ans = INF;
    for(int i=2;i<n;i++) chmin(ans, d1[i]+d2[i]);
    if(ans!=3) {PS("!") END(ans)}


    //ans=3の時だけ注意

    //隣り合ってる場合
    //  ans==3 -> {1,2} {2,1}となる点１つずつある
    //  その2点の距離が１
    vector<int> cand1, cand2;
    for(int i=2;i<n;i++){
        if(d1[i]==1 && d2[i]==2) cand1.push_back(i);
        if(d1[i]==2 && d2[i]==1) cand2.push_back(i);
    }

    //if(!(cand1.size()==1 && cand2.size()==1)) {PS("!") END(3)}
    if(cand1.size()==0 || cand2.size()==0) {PS("!") END(1)}

    PS("?") PS(cand1[0]+1) PL(cand2[0]+1)
    int d; cin>>d;
    if(d!=1){PS("!") END(1)}

    PS("!") PL(3)


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
