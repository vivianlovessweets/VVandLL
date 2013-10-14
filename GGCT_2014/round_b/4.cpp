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

int n,m,mp[105][105],s[105][105];

struct node
{
	int x,y,t;
}pp,qq;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		int i,j;
		int sx,sy,ex,ey;
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		memset(s,-1,sizeof(s));
		s[sx][sy]=mp[sx][sy];
		queue<node> qu;
		pp.x=sx;
		pp.y=sy;
		pp.t=0;
		qu.push(pp);
		while(!qu.empty())
		{
			pp=qu.front();
			qu.pop();
			if(pp.x==ex&&pp.y==ey)
				break;
			qq.t=pp.t+1;
			for(i=0;i<4;i++)
			{
				qq.x=pp.x+d[i][0];
				qq.y=pp.y+d[i][1];
				if(pp.x<0||qq.y<0||qq.x>=n||qq.y>=m||mp[qq.x][qq.y]==-1)
					continue;
				if(s[qq.x][qq.y]==-1)
				{
					s[qq.x][qq.y]=s[pp.x][pp.y]+mp[qq.x][qq.y];
					qu.push(qq);
				}
				else if(s[qq.x][qq.y]<s[pp.x][pp.y]+mp[qq.x][qq.y])
					s[qq.x][qq.y]=s[pp.x][pp.y]+mp[qq.x][qq.y];
			}
		}

		printf("Case #%d: ",cs);

		if(pp.x==ex&&pp.y==ey)
			printf("%d\n",s[ex][ey]);
		else
			printf("Mission Impossible.\n");
	}
}