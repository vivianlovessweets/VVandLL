#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long LL;

#pragma comment(linker, "/STACK:36777216")
#define INF 0x7fffffff;

int dfs(vector<int> &vt)
{
	if(vt.size()==1)
	{
		return vt[0];
	}
	int i,r;
	for (i=0;i<vt.size();i++)
	{
		r=(r+vt[i])%3;
	}
	vector<int> st;
	for(i=0;i<vt.size();i++)
	{
		if(vt[i]%3==r)
		{
			st.push_back((vt[i]-r)/3);
		}
	}
	return dfs(st)*3+r;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,d;
	while(scanf("%d",&n)>0)
	{
		vector<int> vt;
		for (i=0;i<n;i++)
		{
			scanf("%d",&d);
			vt.push_back(d);
		}
		printf("%d\n",dfs(vt));
	}
}