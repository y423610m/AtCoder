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

	int t; cin>>t;
	vector<vector<int> > vt(t, vector<int>(3));
	rep(i,t){
		cin>>vt[i][0]>>vt[i][1]>>vt[i][2];
	}

	vector<int> ans(t);

	rep(i,t){
		sort(ALL(vt[i]));
		int a = vt[i][0];
		int b = vt[i][1];
		int c = vt[i][2];

		//if(a==b) ans[i] = b;
		//else if(b==c) ans[i] = b;
		if(true){
			int ANS = INF;
			//aを増やす
			if( (c-a)%3==0 && (c-a)/3<=b) ANS = min(ANS, a + (c-a));//a==c
			if( (b-a)%3==0 && (b-a)/3<=c) ANS = min(ANS, a + (b-a));//a==b
			//b 増やす
			if( (c-b)%3==0 && (c-b)/3<=a) ANS = min(ANS, b + (c-b));//b==c
			
			if(ANS==INF) ans[i] = -1;
			else ans[i]=ANS;
		}
	}

	rep(i,t) putl(ans[i])

	return;
}

int main() {
	solve();
	return 0;
}
