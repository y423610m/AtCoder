#include <bits/stdc++.h>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>


int main() {
   Eigen::Matrix<int,1,1> mat;
   mat(0,0) = 0;
   for(int i=0;i<3;i++){
      int a;
      cin>>a;
      mat(0,0) += a;
   }

   string S; cin>>S;
   cout<<mat(0,0)<<" "<<S<<endl;

   return 0;
}
