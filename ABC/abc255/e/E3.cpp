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

    int n,m; cin>>n>>m;
    V<ll> S(n-1), X(m); cin>>S>>X;

    V<ll> A; A.push_back(0);
    rep(i,n-1) A.push_back(S[i]-A.back());

    unordered_map<ll, int> mp;

    rep(i,n){
        rep(j,m){
            ll a0;
            if(i&1) a0 = A[i]-X[j];
            else a0 = -A[i]+X[j];

            mp[a0]++;
        }
    }

    int ans = 0;
    for(auto cand: mp) chmax(ans, cand.second);
    PL(ans)

    return;
}

void solve2() {

    int n,m; cin>>n>>m;
    V<ll> S(n-1), X(m); cin>>S>>X;

    // V<ll> A; A.push_back(0);
    // rep(i,n-1) A.push_back(S[i]-A.back());

    V<ll> A(n);
    rep(i,n-1) A[i+1] = S[i]-A[i]; 

    unordered_map<ll, int> mp;

    int id = 0;
    for(const ll& a:A){
        for(const ll& x: X){
            ll a0;
            if(id&1) a0 = a-x;
            else a0 = -a+x;
            mp[a0]++;
        }
        id++;
    }

    int ans = 0;
    for(auto cand: mp) chmax(ans, cand.second);
    PL(ans)

    return;
}

void solve3() {

    int n,m; cin>>n>>m;
    V<ll> S(n-1), X(m); 
    cin>>S;
    cin>>X;

    V<ll> A(n);
    rep(i,n-1) A[i+1] = S[i]-A[i]; 

    int id = 0;
    V<ll> A0s; A0s.reserve(n*10);
    for(const ll& a:A){
        for(const ll& x: X){
            ll a0;
            if(id&1) a0 = a-x;
            else a0 = -a+x;
            A0s.push_back(a0);
        }
        id++;
    }


    int ans = 0;
    sort(ALL(A0s));
    int cnt = 0;
    for(const ll& a:A0s){
        if((&a)!=&A0s[0] && a==*(prev(&a))) cnt++;
        else cnt = 0;
        chmax(ans, cnt+1);
    }
    PL(ans)

    return;
}

void solve4() {

    int n,m; cin>>n>>m;
    V<ll> A(n), X(m); 
    repi(i,1,n) cin>>A[i];
    cin>>X;

    rep(i,n-1) A[i+1] -= A[i];

    int id = 0;
    V<ll> A0s; A0s.reserve(n*m);
    for(const ll& a:A){
        for(const ll& x: X){
            ll a0;
            if(id&1) a0 = a-x;
            else a0 = -a+x;
            A0s.push_back(a0);
        }
        id++;
    }


    int ans = 0;
    sort(ALL(A0s));
    int cnt = 0;
    for(const ll& a:A0s){
        if((&a)!=&A0s[0] && a==*(prev(&a))) cnt++;
        else cnt = 0;
        chmax(ans, cnt+1);
    }
    PL(ans)

    return;
}

void solve5(){
    int A[5] = {5,4,3,2,1};
    sort(&A[0], &A[5]-1);
    for(const int a:A) PS(a)
}


int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve5();
   return 0;
}
