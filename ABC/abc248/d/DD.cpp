#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N,a; cin >> N;
  
  unordered_map<int,vector<int>> m;
  
  for (int i = 1; i <= N; i++){
    cin >> a;
    if (m.count(a)) m.at(a).push_back(i);
    else m[a] = {i};
  }
  
  int Q; cin >> Q;
  
  for (int i = 0; i < Q; i++){
    int L, R, X;
    cin >> L >> R >> X;
    int ans = 0;
    
    if (m.count(X)){
      //vector<int> v = m.at(X);
      vector<int>::iterator position1;
      vector<int>::iterator position2;
      int l,r;
      position1 = lower_bound(m.at(X).begin(),m.at(X).end(),L);
      //l = distance(m.at(X).begin(), position1);
      position2 = upper_bound(m.at(X).begin()+l,m.at(X).end(),R);
      //ans = distance(m.at(X).begin()+l, position2);
      cout << position2-position1 << endl;
    }
    else cout<<0<<endl;
  }
  
}