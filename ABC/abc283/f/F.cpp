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

    ll N; cin>>N;
    V<Pll> P(N);
    rep(i,N){
        P[i].fi = i;
        cin>>P[i].se;
    }

    V<ll> ans(N, LINF);

    V<array<ll,3>> Q(N);
    rep(i,N){
        Q[i][0] = P[i].fi+P[i].se;
        Q[i][1] = P[i].fi-P[i].se;
        Q[i][2] = i;
    }
    sort(ALL(Q));

    multiset<Pll> st;
    rep(i,N){
        if(st.size()){
            auto it = st.begin();
            while(next(it)!=st.end()&&next(it)->fi==it->fi) it = next(it);
            int id1 = Q[i][2];
            int id2 = it->se;
            ll d = abs(P[id1].fi-P[id2].fi) + abs(P[id1].se-P[id2].se);
            chmin(ans[id1],d);
            chmin(ans[id2],d);
        }
        st.insert({Q[i][1], Q[i][2]});
    }

    st.clear();
    sort(ALL(Q), [&](auto a, auto b){
        return a[1]<b[1];
    });
    rep(i,N){
        if(st.size()){
            auto it = st.begin();
            while(next(it)!=st.end()&&next(it)->fi==it->fi) it = next(it);
            int id1 = Q[i][2];
            int id2 = it->se;
            ll d = abs(P[id1].fi-P[id2].fi) + abs(P[id1].se-P[id2].se);
            chmin(ans[id1],d);
            chmin(ans[id2],d);
        }
        st.insert({Q[i][0], Q[i][2]});
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

/*
ABC283 4完 16分
A power
B やる
C ランレングス圧縮
D スタックっぽく詰め込んで出す
*/