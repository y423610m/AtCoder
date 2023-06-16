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

    int N,Q; cin>>N>>Q;
    V<int> P(N);
    repi(i,1,N) cin>>P[i];
    rep(i,N) P[i]--;

    V<V<int>> child(N);
    repi(i,1,N){
        child[P[i]].push_back(i);
    }

    V<int> depth(N);
    auto dfs = [&](auto dfs, int p, int d)->void{
        depth[p] = d;
        for(auto c:child[p]){
            dfs(dfs, c, d+1);
        }
    };
    dfs(dfs,0,0);


    V<bool> reversed(N, false);
    V<int> reversed_child(N);
    rep(q,Q){
        int M; cin>>M;
        V<int> r(M); cin>>r;
        rep(i,M) r[i]--;
        rep(i,M) reversed[r[i]] = true;
        rep(i,M) if(r[i]!=0) reversed_child[P[r[i]]]++;
        sort(ALL(r),[&](int a, int b){
            return depth[a]<depth[b];
        });


        int ans = 0;
        for(auto p:r){
            //放置できる?
            if(p==0){
                ans++;
            }
            else if(!reversed[P[p]]) ans++;

            //for(auto c:child[p]) if(!reversed[c]) ans++;
            ans += child[p].size() - reversed_child[p];
        }
        ES(q)
        PL(ans)
        rep(i,M) reversed[r[i]] = false;
        rep(i,M) if(r[i]!=0) reversed_child[P[r[i]]] = 0;
    }

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
