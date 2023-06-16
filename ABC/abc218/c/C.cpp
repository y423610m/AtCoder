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

	int n; cin>>n;
	vector<string> s(n);
	vector<string> t(n);
	rep(i,n){
		s[i] = "";
		t[i] = "";
	}

	rep(i,n){
		string tmp;
		cin>>tmp;
		s[i] += tmp;
	}
	rep(i,n){
		string tmp;
		cin>>tmp;
		t[i] += tmp;
	}

	//s本体	
	int shiftx = n;
	int shifty = n;
	rep(i,n)rep(j,n)if(s[i][j]=='#'){
		shiftx = min(shiftx,i);
		shifty = min(shifty,j);
	}
	//上詰め
	rep(i,n-shiftx) s[i] = s[i+shiftx];
	string row = "";
	rep(i,n) row += '.';
	rep(i,shiftx) s[n-1-shiftx+i+1] = row;
	//左詰め
	rep(i,n)rep(j,n-shifty) s[i][j] = s[i][j+shifty];
	rep(i,n)rep(j,shifty) s[i][n-1-shifty+j+1] = '.';
	//rep(i,n)cout<<s[i]<<endl;
	//cout<<111<<endl;

	///////////////////t
	////////そのまま
	shiftx = n;
	shifty = n;
	rep(i,n)rep(j,n)if(t[i][j]=='#'){
		shiftx = min(shiftx,i);
		shifty = min(shifty,j);
	}
	//上詰め
	rep(i,n-shiftx) t[i] = t[i+shiftx];
	rep(i,shiftx) t[n-1-shiftx+i+1] = row;
	//左詰め
	rep(i,n)rep(j,n-shifty) t[i][j] = t[i][j+shifty];
	rep(i,n)rep(j,shifty) t[i][n-1-shifty+j+1] = '.';

	//check
	bool check1 = true;
	rep(i,n)if(s[i]!=t[i]) check1 =false;
	//rep(i,n)cout<<t[i]<<endl;
	//cout<<check1<<endl;

	//////////////////180deg
	reverse(ALL(t));
	rep(i,n)reverse(ALL(t[i]));
	shiftx = n;
	shifty = n;
	rep(i,n)rep(j,n)if(t[i][j]=='#'){
		shiftx = min(shiftx,i);
		shifty = min(shifty,j);
	}
	//上詰め
	rep(i,n-shiftx) t[i] = t[i+shiftx];
	rep(i,shiftx) t[n-1-shiftx+i+1] = row;
	//左詰め
	rep(i,n)rep(j,n-shifty) t[i][j] = t[i][j+shifty];
	rep(i,n)rep(j,shifty) t[i][n-1-shifty+j+1] = '.';

	//check
	bool check2 = true;
	rep(i,n)if(s[i]!=t[i]) check2 =false;
	//rep(i,n)cout<<t[i]<<endl;
	//cout<<check2<<endl;

	////////////////////////90
	vector<string> t_(t);
	rep(i,n)rep(j,n) t[i][j] = t_[n-1-j][i];
	shiftx = n;
	shifty = n;
	rep(i,n)rep(j,n)if(t[i][j]=='#'){
		shiftx = min(shiftx,i);
		shifty = min(shifty,j);
	}
	//上詰め
	rep(i,n-shiftx) t[i] = t[i+shiftx];
	rep(i,shiftx) t[n-1-shiftx+i+1] = row;
	//左詰め
	rep(i,n)rep(j,n-shifty) t[i][j] = t[i][j+shifty];
	rep(i,n)rep(j,shifty) t[i][n-1-shifty+j+1] = '.';

	//check
	bool check3 = true;
	rep(i,n)if(s[i]!=t[i]) check3 =false;
	//rep(i,n)cout<<t[i]<<endl;
	//cout<<check3<<endl;


	///////////////////左右反転
	reverse(ALL(t));
	rep(i,n)reverse(ALL(t[i]));
	shiftx = n;
	shifty = n;
	rep(i,n)rep(j,n)if(t[i][j]=='#'){
		shiftx = min(shiftx,i);
		shifty = min(shifty,j);
	}
	//上詰め
	rep(i,n-shiftx) t[i] = t[i+shiftx];
	rep(i,shiftx) t[n-1-shiftx+i+1] = row;
	//左詰め
	rep(i,n)rep(j,n-shifty) t[i][j] = t[i][j+shifty];
	rep(i,n)rep(j,shifty) t[i][n-1-shifty+j+1] = '.';

	//check
	bool check4 = true;
	rep(i,n)if(s[i]!=t[i]) check4 =false;
	//rep(i,n)cout<<t[i]<<endl;
	//cout<<check4<<endl;

	if(check1||check2||check3||check4)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return;

	//rep(i,n)cout<<s[i]<<endl;
	//cout<<check4<<endl;

	

	return;
}

int main() {
	solve();
	return 0;
}
