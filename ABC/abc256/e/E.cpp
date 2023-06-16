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

    int n; cin>>n;
    V<int> X(n); cin>>X;
    rep(i,n) X[i]--;
    V<int> C(n); cin>>C;

    V<V<int>> after(n);
    V<ll> afterCost(n);
    V<int> afterCnt(n);
    rep(i,n){
        afterCnt[X[i]]++;
        after[X[i]].push_back(i);
        afterCost[X[i]] += C[i];
    }

    priority_queue<Pll, V<Pll> , greater<Pll>> que;//cost, id
    rep(i,n) que.push({afterCost[i],i});

    set<int> P;
    ll ans = 0;
    while(!que.empty()){
        ll c = que.top().first;
        int id = que.top().second;
        que.pop();

        if(P.count(id)) continue;
        
        if(P.count(X[id])) ans += C[id];

        P.insert(id);
        rep(i,after[id].size()){
            P.insert(id);

        }
    }

    PL(ans)




    return;
}

void solve2(){
    int n; cin>>n;
    V<int> X(n); cin>>X;
    rep(i,n) X[i]--;
    V<int> C(n); cin>>C;

    V<V<int>> after(n);
    V<ll> afterCost(n);
    V<int> afterCnt(n);
    rep(i,n){
        afterCnt[X[i]]++;
        after[X[i]].push_back(i);
        afterCost[X[i]] += C[i];
    }

    priority_queue<Pll> pq;//cost, id
    rep(i,n) pq.push({afterCost[i],i});
    ll ans = 0;
    set<int> P;
    //後ろから選ぶ
    while(!pq.empty()){
        ll c = pq.top().first;
        int id = pq.top().second;
        pq.pop();
        //既に選んだ
        if(P.count(id)) continue;
        //更新されてない
        if(c!=afterCost[id]){
            pq.push({afterCost[id], id});
            continue;
        }
        
        if(P.count(X[id])==0) ans += C[id];

        P.insert(id);
        

    }

    PL(ans)

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
