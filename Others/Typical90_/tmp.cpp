#include<iostream>
#include<vector>
using namespace std;
int N,M;
int A[10][10];
bool ng[10][10];
int ans=1e9;
bool vis[10];
vector<int> memo;
void dfs(int id,int now,int prv)
{
	if(id==N)
	{
		if(ans>now){
            ans=now;
            cout<<now<<" ";
            for(int i=0;i<memo.size();i++) cout<<memo[i]<<" ";
            cout<<endl;
        }
	}
	else
	{
		for(int i=0;i<N;i++)if(!vis[i])
		{
			if(id&&ng[prv][i])continue;
			vis[i]=true;
            memo.push_back(i);
			dfs(id+1,now+A[i][id],i);
			vis[i]=false;
            memo.pop_back();
		}
	}
}
main()
{
	cin>>N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>A[i][j];
	cin>>M;
	for(int i=0;i<M;i++)
	{
		int x,y;cin>>x>>y;
		x--,y--;
		ng[x][y]=ng[y][x]=1;
	}
	dfs(0,0,-1);
	if(ans==(int)1e9)ans=-1;
	cout<<ans<<endl;
}
