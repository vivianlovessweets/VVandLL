#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;

typedef unsigned long long ULL;

int dis[2005][2005];
int f[80005];
bool g[2005];

struct node
{
	int k,w;
}pp,qq;

bool operator<(node p,node q)
{
	return p.w>q.w;
}

vector<vector<node> > vt;

int get(int a,int b)
{
	priority_queue<node> pq;
	pp.k=a;
	pp.w=0;
	pq.push(pp);
	memset(g,0,sizeof(g));
	while(!pq.empty())
	{
		pp=pq.top();
		pq.pop();
		if(pp.k==b)
			break;
		if(g[pp.k])
			continue;
		g[pp.k]=true;
		int i;
		for(i=0;i<vt[pp.k].size();i++)
		{
			qq.k=vt[pp.k][i].k;
			qq.w=pp.w+vt[pp.k][i].w;
			if(g[qq.k])
				continue;
			pq.push(qq);
		}
	}
	if(pp.k==b)
		return pp.w;
	return -1;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		printf("Case #%d:\n",cs);

		int n,m,i,j,k;
		char t[5];
		map<string,int> mp;
		scanf("%d",&n);
		k=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",t);
			if(mp.find(t)==mp.end())
				mp[t]=k++;
			f[i]=mp[t];
		}
		scanf("%d",&m);
		int a,b,c;
		memset(dis,-1,sizeof(dis));
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(dis[f[a]][f[b]]==-1||dis[f[a]][f[b]]>c)
				dis[f[a]][f[b]]=c;
		}
		vt.clear();
		vt.resize(k);
		for(i=0;i<k;i++)
			for(j=0;j<k;j++)
			{
				if(i==j||dis[i][j]==-1)
					continue;
				pp.k=j;
				pp.w=dis[i][j];
				vt[i].push_back(pp);
			}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",get(f[a],f[b]));
		}

		printf("\n");
	}
}