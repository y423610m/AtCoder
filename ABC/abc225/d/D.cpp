#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define rrep(i, a, n) for (int i = (int)(a); i > (int)(n); i--)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define rrepll(i, a, n) for (ll i = (ll)(a); i > (ll)(n); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()
#define puts(a) cout<<(a)<<" ";
#define putl(a) cout<<(a)<<endl;

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int n,q;
	cin>>n>>q;
	vector<vector<int> > query(q, vector<int>(3));
	rep(i,q){
		cin>>query[i][0]>>query[i][1];
		if(query[i][0]<3)cin>>query[i][2];
	}
	vector<vector<int> > train(n,vector<int>(2,-1));//左，右

	rep(i,q){
		//cout<<i<<" i"<<endl;
		int m = query[i][0];
		int a = query[i][1]-1;
		int b = query[i][2]-1;

		if(m==1){
			train[a][1]=b;
			train[b][0]=a;
		}
		else if(m==2){
			train[a][1]=-1;
			train[b][0]=-1;
		}
		else{
			//rep(i,n) cout<<train[i][0]<<" "<<train[i][1]<<endl;
			vector<int> left, right;
			right.push_back(a);
			int L = train[a][0];
			int R = train[a][1];
			while(L!=-1){
				left.push_back(L);
				L = train[L][0];
			}
			while(R!=-1){
				right.push_back(R);
				R = train[R][1];
			}
			reverse(ALL(left));
			puts(left.size()+right.size())
			rep(i,left.size()) puts(left[i]+1);
			rep(i,right.size()) puts(right[i]+1);
			putl("")
		}

	}

	return;
}

int main() {
	solve();
	return 0;
}
