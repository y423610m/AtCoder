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
#define NAME(a) #a
#define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
#define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
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
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int n,m,Q; cin>>n>>m>>Q;
    map<ll, map<ll, int>> cnt;

    V<V<ll>> Query;
    rep(_, Q){
        int q; cin>>q;
        if(q==1){
            int l,r,x; cin>>l>>r>>x;
            Query.push_back({q,l,r,x});
        }
        else if(q==2){
            int i; cin>>i; i--;
            ll x; cin>>x;
            Query.push_back({q,i,x,-1});
        }
        else{
            int i,j;
            cin>>i>>j;
            Query.push_back({q,i,j,-1});
            cnt[i][j]++;
        }
    }
    
    priority_queue<P, V<P>, greater<P>> LR;
    rep(_, Q){
        ll q = Query[_][0];
        if(q==1){
            ll l = Query[_][1];
            ll r = Query[_][2];
            ll x = Query[_][3];
            LR
        }
        else if(q==2){
            int i; cin>>i; i--;
            ll x; cin>>x;
            val[i] = x;
            last[i] = LR;
        }
        else{
            int i,j;
            cin>>i>>j;
            ll sum = 0;
            rep(i,vp.size())
        }
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
