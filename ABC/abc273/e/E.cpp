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


    map<int, V<int>> Note;
    
    int Q; cin>>Q;
    V<pair<string, int>> op(Q);
    rep(i, Q){
        cin>>op[i].fi;
        if(op[i].fi!="DELETE") cin>>op[i].se;
    }

    unordered_map<int,int> mp_load;
    unordered_map<int,int> mp_del;
    int cnt_load = 0;
    int cnt_del = 0;
    for(int q=Q-1;q>=0;q--){
        if(op[q].fi=="ADD"){}
        else if(op[q].fi=="DELETE") cnt_del++;
        else if(op[q].fi=="SAVE"){}
        else{
            int page = op[q].se;
            chmax(mp_load[page], cnt_load);
            chmax(mp_del[page], cnt_del);
            cnt_load = 0;
            cnt_del = 0;
        }
    }

    V<int> A;
    A.reserve(Q);

    rep(q,Q){
        if(op[q].fi=="ADD"){
            A.push_back(op[q].se);
            ES(q) EL(0)
        }
        else if(op[q].fi=="DELETE"){
            if(A.size()){
                A.pop_back();
            }
            ES(q) EL(1)
        }
        else if(op[q].fi=="SAVE"){
            int page = op[q].se;
            if(mp_load[page]!=0){
                auto& note = Note[page];
                if(note.size()>0) Note.clear();
                int num = note.size();
                chmin(num, mp_del[page]);
                num++;
                int N = A.size();
                for(int i = max(0, N-num-2);i<A.size();i++){
                    note.push_back(A[i]);
                }
                mp_load[page]--;
            }
            ES(q) EL(2)
        }
        else{//load
            int page = op[q].se;
            swap(A, Note[page]);
            ES(q) EL(3)
        }
        EL(A)
        if(A.size()) PS(A.back())
        else PS(-1)
    }
    PL("")

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

ABC273 4完 40分!
A:再帰せず，普通にK回for
B:5*10**i足したうえで，10**(i+1)割って掛ける．
C:座標圧縮してカウント
D:map[x]=y, map[y]=xみたいなの作って，lower,upper繰り返す．重実装!．
E:解けず．クエリ先読みして，うにゃうにゃしたけど，バグを解決できずタイムアップ．

*/