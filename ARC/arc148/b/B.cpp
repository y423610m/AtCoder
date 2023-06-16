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

vector<pair<char, int>> RLE(const string& s){
    vector<pair<char, int>> ret;
    for(int i=0;i<(int)s.size();i++){
        if(ret.size()==0) ret.push_back({s[i],1});
        else if(ret.back().first==s[i]) ret.back().second++;
        else ret.push_back({s[i], 1});
    }
    return ret;
}

void solve() {

    int N; cin>>N;
    string S; cin>>S;

    //変換用
    char con[256];
    con['d'] = 'p';
    con['p'] = 'd';

    V<pair<char,int>> R = RLE(S);
    rep(i,R.size()) EL(R[i])

    int l = -1;
    rep(i, R.size()) if(R[i].fi=='p'){
        l = i;
        break;
    }
    if(l==-1) END(S)

    auto ans = R;
    int idr = l;
    repi(r, l, R.size()){
        if(R[r].fi=='p'){
            EL(r)
            auto T = R;
            reverse(T.begin()+l, T.begin()+r+1);
            repi(i,l,r+1) T[i].fi = con[T[i].fi];
            rep(i,T.size()) EL(T[i])

            bool change = false;
            rep(i,R.size()){
                if(ans[i]==T[i]) continue;
                if(ans[i].fi!=T[i].fi){
                    if(ans[i].fi>T[i].fi) change = true;
                    break;
                }
                if(ans[i].fi==T[i].fi){
                    if(ans[i].fi=='d'){
                        if(ans[i].se<T[i].se) change = true;
                    }
                    if(ans[i].fi=='p'){
                        if(ans[i].se>T[i].se) change = true;
                    }
                    break;
                }

            }

            if(change){
                swap(ans, T);
                idr = r;
                ES("change")
            }
            EL("")
        }
    }


    //repi(i,l,idr+1) ans[i].fi = con[ans[i].fi];
    ES(l) EL(idr)
    string A;
    rep(i,ans.size()){
        rep(j,ans[i].se) A += ans[i].fi;
    }
    string B;
    R[l].fi = 'd';
    rep(i,R.size()){
        rep(j,R[i].se) B += R[i].fi;
    }
    PL(min(A,B))

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

/*
1         
pddppdpp 


ng ddppddpp
*/
