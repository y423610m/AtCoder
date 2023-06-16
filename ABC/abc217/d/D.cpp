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
#define ALL(a) (a).begin(),(a).end()

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;


void solve(){
	set<int> st;
	st.insert(5);
	st.insert(6);
	st.insert(20);
	st.insert(8);

	int x = 10;
	auto it = lower_bound(ALL(st), x);
	auto prit = prev(it);
	cout<<*it - *prit<<endl; 

	return;
}

void solve__() {

	int l,q;
	cin>>l>>q;
	vector<int> vi(1);
	vi[0] = l;

	rep(i,q){
		int c,x;
		cin>>c>>x;
		if(c==1){
			int sum = 0;
			int id = 0;
			int n = int(vi.size());
			while(sum<x && id<n){
				sum += vi[id];
				id++;
			}
			int len = vi[id];
		}
		else{//c == 2
		}
	}

	return;
}


void solve_() {

	int l,q;
	cin>>l>>q;

	vector<bool> vi(l+1);
	vi[0] = true;
	vi[l] = true;
	rep(i,q){
		int c,x;
		cin>>c>>x;
		if(c==1){
			vi[x] = true;
		}
		else{//c == 2
			//左側探索
			int ret = 0;
			int ind = x;
			while(vi[ind]==false){
				ret++;
				ind--;
			}
			//右
			ind = x;
			while(vi[ind]==false){
				ret++;
				ind++;
			}
			cout<<ret<<endl;

			/*
			int ret=0;
			bool found = false;
			rep(j,l+1){
				if(j==x) found = true;
				if(vi[j]==true){//切り口にきた
					if(found){
						cout<<ret<<endl;
						j = l+2;
					}	
					ret = 0;
				}
				ret++;
			}
			if(!found) cout<<ret-1<<endl;
			*/

		}
	}

	return;
}

int main() {
	solve();
	return 0;
}
