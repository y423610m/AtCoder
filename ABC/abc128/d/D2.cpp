#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
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

    ll N,K; cin>>N>>K;
    V<ll> A(N); cin>>A;

    //dp[i][j]:=端からi個目まで見て，行動をj回したとき，最大価値
    V<V<ll>> L(N+1,V<ll>(N*3,-LINF));
    V<V<ll>> R(N+1,V<ll>(N*3,-LINF));
    L[0][0] = 0;
    R[0][0] = 0;
    
    //left
    ll sum = 0;
    multiset<ll> st;
    rep(i,N){
        sum += A[i];
        L[i+1][i+1] = sum;

        if(A[i]<0) st.insert(A[i]);
        if(st.size()){
            int cnt = 0;
            ll tmp = 0;
            for(auto a:st){
                cnt++;
                tmp -= a;
                chmax(L[i+1][i+1+cnt], L[i+1][i+1] + tmp);
            }
        }
    }
    rep(l,N+1) EL(L[l])

    //right
    sum = 0;
    st.clear();
    reverse(ALL(A));
    rep(i,N){
        sum += A[i];
        R[i+1][i+1] = sum;

        if(A[i]<0) st.insert(A[i]);
        if(st.size()){
            int cnt = 0;
            ll tmp = 0;
            for(auto a:st){
                cnt++;
                tmp -= a;
                chmax(R[i+1][i+1+cnt], R[i+1][i+1] + tmp);
            }
        }
    }
    rep(r,N+1) EL(R[r])

    //ans
    ll ans = 0;
    rep(l,N+1){
        rep(r,N+1){
            if(l+r>N) continue;
            repi(opl,l,K+1){
                repi(opr,r,K+1){
                    if((opl+opr>K)||(opl+opr>N*2)) continue;
                    chmax(ans, L[l][opl]+R[r][opr]);
                }
            }
        }
    }
    PL(ans)
    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
