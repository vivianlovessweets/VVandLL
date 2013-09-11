#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long LL;

#pragma comment(linker, "/STACK:36777216")
#define INF 0x7fffffff

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,t;
	while(scanf("%d",&n)>0)
	{
		vector<int> vt;
		vt.reserve(n+1);
		vt.push_back(0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(t>=1&&t<=n)
				vt.push_back(t);
		}
		for(i=1;i<vt.size();i++)
		{
			while(vt[i]<vt.size()&&vt[i]!=i&&vt[vt[i]]!=vt[i])
			{
				swap(vt[i],vt[vt[i]]);
			}
		}
		for(i=1;i<vt.size();i++)
		{
			if(vt[i]!=i)
				break;
		}
		printf("%d\n",i);
	}
}