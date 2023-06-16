#include <iostream>
#include <atcoder/scc>

using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;
    scc_graph g(N);
    int ans = 0;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A, --A;
        g.add_edge(i, A);
        if(i == A){
            ++ans;
        }
    }
    for(auto c: g.scc()){
        if(c.size() >= 2){
            ans += c.size();
        }
    }
    cout << ans << endl;
}
