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

    ll N,Q; cin>>N>>Q;
    ll K = N;

    dsu tree(N+Q);

    V<ll> inBox(N+Q, -1);//ボールiがどの箱に入っているか
    V<ll> member(N);//箱iのメンバー一つ

    rep(i,N){
        inBox[i] = i;
        member[i] = i;
    }


    rep(q,Q){
        ll op; cin>>op;
        if(op==1){
            ll X,Y; cin>>X>>Y; X--,Y--;
            //例外処理
            if(member[X]==-1&&member[Y]==-1){
                //continue;
            }
            else if(member[X]==-1){
                member[X] = member[Y];
                inBox[tree.leader(member[X])] = X;
            }
            else if(member[Y]==-1){
                //continue;
            }
            else{
                tree.merge(member[X], member[Y]);
                inBox[tree.leader(member[X])] = X;
            }
            member[Y] = -1;
        }
        else if(op==2){
            ll X; cin>>X; X--;
            if(member[X]==-1){
                inBox[K] = X;
                member[X] = K;
            }
            else{
                tree.merge(member[X], K);
                inBox[tree.leader(K)] = X;
                member[X] = tree.leader(K);
            }
            K++;
        }
        else{
            ll X; cin>>X; X--;
            PL(inBox[tree.leader(X)]+1)
        }
    }

    // auto groups = tree.groups();
    // for(auto group:groups){
    //     EL(inBox[group[0]]+1)
    //     for(auto m:group){
    //         PS(m+1)
    //     }
    //     PL("")
    // }

    // EL(member)
    // EL(inBox)

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
