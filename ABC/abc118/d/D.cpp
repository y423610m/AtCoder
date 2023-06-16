#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
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
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    ll N,M; cin>>N>>M;
    V<ll> A(M); cin>>A;
    sort(ALL(A));
    V<ll> Num = {0,2,5,5,4,5,6,3,7,6};

    ll MaxLen = 0;
    ll val = 1;
    for(auto a:A){
        ll len = N/Num[a];
        if(MaxLen<len){
            MaxLen = len;
            val = a;
        }
        // else if(MaxLen==len){
        //     val = a;
        // }
    }

    string ans(MaxLen,'0'+val);
    N -= MaxLen*Num[val];
    sort(RALL(A));

    rep(i,ans.size()){
        bool updated = false;
        for(auto a:A){
            if(N>=Num[a]-Num[ans[i]-'0']&&a>ans[i]-'a'){
                N -= Num[a]-Num[ans[i]-'0'];
                ans[i] = '0'+a;
                updated = true;
            }
            if(updated) break;
        }
    }

    reverse(ALL(ans));
    sort(RALL(A));

    if(N){
        rep(i,ans.size()){
            if(N==0) continue;
            bool updated = false;
            for(auto a:A){
                if(N==Num[a]-Num[ans[i]-'0']){
                    N = 0;
                    ans[i] = '0'+a;
                    updated = true;
                }
                if(updated) break;
            }
        }
    }
    reverse(ALL(ans));

    EL(N)
    PL(ans)

    return;
}

void solve2(){
    ll N,M; cin>>N>>M;
    V<ll> A(M); cin>>A;
    sort(RALL(A));
    V<ll> Num = {0,2,5,5,4,5,6,3,7,6};

    //dp[i]:=i本でできる最大値
    V<string> dp(N+1,"0");
    dp[0] = "";
    for(auto a:A){
        rep(j,N){
            ll to = j+Num[a];
            if(dp[j]!="0"&&to<=N){
                if(dp[to].size()<dp[j].size()+1) dp[to] = dp[j]+char(a+'0');
                else if(dp[to].size()==dp[j].size()+1) chmax(dp[j+Num[a]], dp[j]+char('0'+a));
            }
        }
    }
    PL(dp[N])
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
