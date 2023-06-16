#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
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
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

void solve() {

    ll N,M; cin>>N>>M;
    V<ll> A(N); cin>>A;
    //rep(i,N) A[i]%=M;
    //rep(i,N) A.push_back(A[i]+M);
    sort(ALL(A), [&](ll a, ll b){
        return a%M<b%M;
    });

    ll sum = 0;
    rep(i,N) sum += A[i];

    V<bool> checked(N, false);

    ll ans = LINF;
    rep(i,N){
        if(checked[i]) continue;
        ll s = 0;
        int last = A[i];
        int id = i;
        while((id-i+1)<=N&&id<N&&last+1>=A[id]){
            checked[id] = true;
            s += A[id];
            last = A[id];
            id++;
        }
        chmin(ans, sum-s);
    }
    PL(ans)
    return;
}

void solve2(){
    ll N,M; cin>>N>>M;
    V<ll> A(N); cin>>A;
    sort(ALL(A), [&](ll a, ll b){
        return a%M<b%M;
    });

    map<ll,int> ids;
    rep(i,N) ids[A[i]] = i+1;

    ll total = 0;
    rep(i,N) total += A[i];

    dsu tree(N);
    V<ll> sum(N);
    rep(i,N) sum[i] = A[i];

    rep(i,N){
        int j = (i+1)%N;
        if(!tree.same(i,j)&&A[i]==A[j]){
            int leaderi = tree.leader(i);
            int leaderj = tree.leader(j);
            tree.merge(i,j);
            int leader = tree.leader(i);
            if(leader==leaderi) sum[leader] += sum[leaderj];
            else sum[leader] += sum[leaderi];
        }

        j = ids[(A[i]+1)%M];
        if(j==0) continue;
        j--;
        if(!tree.same(i,j)){
            int leaderi = tree.leader(i);
            int leaderj = tree.leader(j);
            tree.merge(i,j);
            int leader = tree.leader(i);
            if(leader==leaderi) sum[leader] += sum[leaderj];
            else sum[leader] += sum[leaderi];
        }
    }
    EL(A)
    ll ans = LINF;
    EL(total)
    rep(i,N){
        ES(i) ES(tree.leader(i)) EL(sum[tree.leader(i)])
        chmin(ans, total-sum[tree.leader(i)]);
    }

    PL(ans)

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
