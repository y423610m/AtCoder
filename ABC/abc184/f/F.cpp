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
#define fi first
#define se second
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
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int N; cin>>N;
    ll T; cin>>T;
    V<ll> A(N); cin>>A;
    V<ll> B;
    rep(i,N/2){
        B.push_back(A.back());
        A.pop_back();
    }

    sort(RALL(A));
    sort(RALL(B));

    V<ll> sumA;
    sumA.push_back(0);
    V<ll> sumB;
    sumB.push_back(0);

    ll sum = 0;
    auto dfsA = [&](auto dfsA, int i)->void {
        if(i>=A.size()) return;

        dfsA(dfsA, i+1);
        
        if(sum+A[i]>T) return;
        sum += A[i];
        sumA.push_back(sum);
        dfsA(dfsA, i+1);
        sum -= A[i];
    };
    dfsA(dfsA, 0);

    sum = 0;
    auto dfsB = [&](auto dfsB, int i)->void {
        if(i>=B.size()) return;

        dfsB(dfsB, i+1);
        
        if(sum+B[i]>T) return;
        sum += B[i];
        sumB.push_back(sum);
        dfsB(dfsB, i+1);
        sum -= B[i];
    };
    dfsB(dfsB, 0);

    sort(ALL(sumA));
    sort(ALL(sumB));

    ll ans = max(sumA.back(), sumB.back());
    auto Bbegin = sumB.begin();
    rep(i,sumA.size()){
        ll  s = sumA[i];
        auto it = lower_bound(ALL(sumB), T-s+1);
        if(it==Bbegin) continue;
        chmax(ans, s+(*prev(it)));
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
