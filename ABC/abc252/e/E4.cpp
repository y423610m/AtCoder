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

struct Edge{
    int from, to, cost, id, used;
};

struct warshall_floyed{
    int N;
    vector<vector<ll>> dist;
    vector<vector<int>> froms;
    vector<vector<Edge>> G;
    vector<vector<int>> idx;
    vector<vector<P>> H;

    warshall_floyed(int n, vector<vector<Edge>>& G_){
        N = n;
        G = G_;
        //NOTE warshall floyedは全始点だからリセット不要.ここでdistのサイズ決定する
        dist = vector<vector<ll>>(N, vector<ll>(N, LINF));
        froms = vector<vector<int>>(N, vector<int>(N, -1));
        idx = vector<vector<int>>(N, vector<int>(N, -1));
        for(int i=0;i<N;i++) dist[i][i] = 0;
        H = vector<vector<P>>(G.size());
        for(int u=0; u<(int)G.size(); u++){
            for(int j=0;j<(int)G[u].size();j++){
                int v = G[u][j].to;
                int w = G[u][j].cost;
                int id = G[u][j].id;
                dist[u][v] = w;
                froms[u][v] = u;
                idx[u][v] = id;

                //経路復元はu,v逆!!!
               // H[v].push_back({u,w});
            }
        }
    }

    vector<vector<ll>> solve(){
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                        froms[i][j] = froms[k][j];
                        idx[i][j] = idx[k][j];
                    }
                }
            }
        }
        return dist;
    }

    vector<int> find_path(int s, int g){
        vector<int> path;
        if(dist[s][g]==LINF) return path;
        int p = g;
        while(p!=s){
            path.push_back(p);
            p = froms[s][p];
            // for(auto [to,w]:H[p]){
            //     if(dist[s][to]+w==dist[s][p]){
            //         path.push_back(to);
            //         p = to;
            //         break;
            //     }
            // }
        }
        path.push_back(p);
        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> find_path_idx(int s, int g){
        vector<int> path_idx;
        if(dist[s][g]==LINF) return path_idx;
        int p = g;
        while(p!=s){
            path_idx.push_back(idx[s][p]);
            p = froms[s][p];
            // for(auto [to,w]:H[p]){
            //     if(dist[s][to]+w==dist[s][p]){
            //         path.push_back(to);
            //         p = to;
            //         break;
            //     }
            // }
        }
        reverse(path_idx.begin(), path_idx.end());
        return path_idx;
    }
};



void solve() {

    int n, m;
    cin>>n>>m;
    int s = 0;
    int g = n-1;

    vector<vector<Edge>> G(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v;
        u--,v--;
        w = 1;
        cin>>w;
        G[u].push_back({u,v,w,i,0});
        G[v].push_back({v,u,w,i,0});
    }

    warshall_floyed wf(n, G);
    auto dist = wf.solve();

    auto idx = wf.idx[0];
    for(int i=1;i<(int)idx.size();i++) cout<<(idx[i]+1)<<" ";
    cout<<endl;

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
