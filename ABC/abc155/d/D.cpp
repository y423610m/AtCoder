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
template<class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template<typename T, typename F>
T binSearch(T ok, T ng, F check){
    while(abs(ok-ng)>1){
        T mid = (ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}



void solve() {

    ll N,K; cin>>N>>K;
    K--;
    V<ll> A(N);
    sort(ALL(A));
    

    //x以下の値がk個あるか
    auto check = [&](auto x){
        ll cnt = 0;
        EL(x)
        rep(i,N){
            //A[i]*A[i]がx以下かどうか
            auto check2 = [&](auto j)->bool {
                if(A[i]*A[j]<=K) return true;
                else return false;
            };
            if(A[i]>=0) cnt += binSearch(i,N,check2)-i;
            else cnt += abs(binSearch(N-1,i,check2)-(N-1));
        }
        if(cnt>=x) return true;
        return false;
    };

    ll ans = binSearch(-LINF, LINF, check);
    PL(ans)

    return;
}

void solve2(){
    ll N,K; cin>>N>>K;
    V<ll> A(N); cin>>A;
    V<ll> Minus, Zeros, Plus;
    rep(i,N){
        if(A[i]<0) Minus.emplace_back(A[i]);
        if(A[i]==0) Zeros.emplace_back(A[i]);
        if(A[i]>0) Plus.emplace_back(A[i]);
    }
    sort(RALL(Minus));

    auto getMinus = [&](ll x)->ll {
        ll cnt = 0;
        rep(i,Minus.size()){
            if(Minus[i]*)
        }
    };

    auto getZeros = [&]()->ll {
        return ll(zeros.size())*(Plus.size()+Minus.size())
        + ll(Zeros.size()+1)*Zeros.size()/2;
    };

    auto getPlus = [&](ll x)->ll {

    };

    auto getCount = [&](ll x)->ll {
        ll cnt = getMinus(min(x, -1LL));
        if(0<=x) cnt += getZeros();
        if(0<x) cnt += getPlus(x);
        return cnt;
    };

    auto check = [&](ll x)->bool {
        if(K<=getCount(x)) return true;
        else return false;
    };

    ll ans = binSearch(LINF, -LINF, check);
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
