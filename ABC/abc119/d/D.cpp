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

template<typename T, typename Iterator>
Iterator rlower_bound(Iterator first, Iterator last, T value){
    return lower_bound(first, last, value, [](const T& a, const T& b){return a>b;});
}
template<typename T, typename Iterator>
Iterator rupper_bound(Iterator first, Iterator last, T value){
    return upper_bound(first, last, value, [](const T& a, const T& b){return a>b;});
}
// auto it = rlower_bound(RALL(A), a);

void solve() {

    ll A,B,Q; cin>>A>>B>>Q;
    V<ll> S(A), T(B); cin>>S>>T;
    //S[i]から最短距離
    V<ll> distS(A,LINF), distT(B,LINF);
    rep(i,A){
        auto it = lower_bound(ALL(T),S[i]);
        if(it!=T.end()) chmin(distS[i], abs(*it-S[i]));
        auto itr = rlower_bound(RALL(T),S[i]);
        if(itr!=T.rend()) chmin(distS[i], abs(*itr-S[i]));
    }
    rep(i,B){
        auto it = lower_bound(ALL(S),T[i]);
        if(it!=S.end()) chmin(distT[i], abs(*it-T[i]));
        auto itr = rlower_bound(RALL(S),T[i]);
        if(itr!=S.rend()) chmin(distT[i], abs(*itr-T[i]));
    }
    EL(distS)
    EL(distT)

    rep(_,Q){
        ll x; cin>>x;
        ll ans = LINF;

        rep(__,2){
            //S右
            {
                auto its = lower_bound(ALL(S),x);
                if(its!=S.end()){
                    int id = its-S.begin();
                    chmin(ans, abs(*its-x)+distS[id]);
                }
                auto itsr = rlower_bound(RALL(S),x);
                if(itsr!=S.rend()){
                    int id = S.rend()-itsr-1;
                    chmin(ans, abs(*itsr-x)+distS[id]);
                }
            }
            swap(S,T);
            swap(distS,distT);
        }

        PL(ans)
    }


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
