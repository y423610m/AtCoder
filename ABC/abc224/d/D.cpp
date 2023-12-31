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
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int m; cin>>m;
    V<V<int>> G(9);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    V<int> P(8); cin>>P;
    rep(i,8) P[i]--;

    string start = string(9, '9');
    rep(i,8) start[P[i]] = '1'+i;
    string goal = "123456789";
    EL(start)

    map<string, int> mp;
    queue<string> que;
    if(start==goal) END(0)
    mp[start] = 1;
    que.push(start);
    while(!que.empty()){
        string s = que.front();
        //EL(s)
        que.pop();
        int id = -1;
        int cost = mp[s];
        rep(i,9) if(s[i]=='9'){
            id = i;
            break;
        }
        for(int i=0;i<G[id].size();i++){
            swap(s[id], s[G[id][i]]);
            if(mp[s]==0){
                mp[s] = cost+1;
                que.push(s);
            }
            if(s==goal) END(mp[goal]-1)
            swap(s[id], s[G[id][i]]);
        }
    }

    END(-1)

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
