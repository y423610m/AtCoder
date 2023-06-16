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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
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

    int n; cin>>n;
    V<string> S(n); cin>>S;
    V<V<int>> cnt(10,V<int>(10,0));//iがj番目に出てくる回数

    rep(i,n){
        rep(j,10){
            cnt[(int)S[i][j]-(int)'0'][j]++;
        }
    }

   // rep(i,10) EL(cnt[i]);

    int ans = INF;
    rep(i,10){
        int num = n;
        int pos = -1;
        int t = 0;
        while(num>0){
            pos = -1;
            int last;
            rep(j,10){
                if(cnt[i][j]>0 && pos<j){
                    if(t%10==j && num!=n){
                        t+=10;
                        //ES(0)
                    }
                    else if(t%10<=j){
                        t+=j-(t%10);
                       // ES(1)
                    }
                    else{
                        t+=10+j-(t%10);
                       // ES(2)
                    }
                    cnt[i][j]--;
                    num--;
                    pos = j;
                //{ES(i) ES(pos) EL(t)}
                }
            }
        }
       // ES(i) EL(t)
        chmin(ans, t);
    }

    PL(ans)

    // rep(i,10){
    //     int t = -1;
    //     rep(j,n){
    //         int pos = 0;
    //         rep(k,S[j].size()){
    //             if((int)(S[j][k]-'0')==i){
    //                 pos = k;
    //                 break;
    //             }
    //         }
    //         if(t==0)
    //         if(t%10>pos) t += (t%10)-pos;
    //         else t += 10 + pos - (t%10);
    //     }
    //     chmin(ans,t);
    // }
    // PL(ans)

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
