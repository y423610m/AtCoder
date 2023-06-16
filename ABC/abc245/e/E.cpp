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

    int n,m; cin>>n>>m;

    V<Pii> AB(n); 
    rep(i,n) cin>>AB[i].first;
    rep(i,n) cin>>AB[i].second;

    V<Pii> CD(m);
    rep(i,m) cin>>CD[i].first;
    rep(i,m) cin>>CD[i].second;



    multimap<int, int> mp;
    rep(i,m){
        mp.insert({CD[i].first, CD[i].second});
    }

    sort(RALL(AB));

    rep(i,n){
        auto [a, b] = AB[i];
        auto s = mp.lower_bound(a);
        bool found = false;
        ES(a) ES(b)
        for(auto it=s;it!=mp.end();it++){
            ES("a") ES(it->first) EL(it->second)
            if(it->second>=b){
                ES(it->first) EL(it->second)
                mp.erase(it);
                found = true;
                break;
            }
        }
        if(!found) END("No")
    }

    PL("Yes")


    return;
}

void solve2(){
    int n,m; cin>>n>>m;
    V<int> A(n), B(n), C(m), D(m);
    cin>>A>>B>>C>>D;

    V<Pii> vp; vp.reserve(n+m);
    rep(i,n) vp.push_back({A[i], -B[i]});
    rep(i,m) vp.push_back({C[i], D[i]});

    sort(RALL(vp));

    multiset<int> st;
    rep(i, vp.size()){
        ES(i) ES(vp[i].first) EL(vp[i].second)
        //choco
        if(vp[i].second<0){
            auto it = st.lower_bound(-vp[i].second);
            if(it==st.end()) END("No")
            st.erase(it);
        }
        else st.insert(vp[i].second);
    }
    PL("Yes")
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
