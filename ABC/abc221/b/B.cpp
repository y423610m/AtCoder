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

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

void solve() {

	string s,t;
	cin>>s>>t;

	if(s==t){
		cout<<"Yes"<<endl;
		return;
	}

	int a,b;
	int cnt = 0;
	rep(i,s.size()){
		if(s[i]!=t[i]){
			cnt++;
			if(cnt==1) a = i;
			if(cnt==2) b = i;
		}
	}

	if(cnt>=3){
		cout<<"No"<<endl;
		return;
	}

	if( b-a != 1 ){
		cout<<"No"<<endl;
		return;
	}

	if(s[a]==t[b]&&s[b]==t[a]){
		cout<<"Yes"<<endl;
		return;
	}

	cout<<"No"<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
