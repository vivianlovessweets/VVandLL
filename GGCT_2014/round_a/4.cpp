#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

typedef unsigned long long ULL;

int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char f[5]="NWSE";

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		printf("Case #%d:",cs);

		int n,i,j,sx,sy,ex,ey;
		char mp[105][105];
		scanf("%d",&n);
		for(i=0;i<n+2;i++)
			for(j=0;j<n+2;j++)
				mp[i][j]='#';
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
			mp[i][n+1]='#';
		}
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		char res[10005];
		int k;
		if(sx==1&&sy==1)
			k=3;
		else if(sx==1&&sy==n)
			k=2;
		else if(sx==n&&sy==n)
			k=1;
		else
			k=0;
		int cx=sx,cy=sy;
		int tx,ty;
		int idx=0;
		bool flag=false;
		while(true)
		{
			if(cx==ex&&cy==ey)
			{
				flag=true;
				break;
			}
			else if(idx==10000)
				break;
			
			int i,lx,ly,tx,ty;
			lx=cx+d[(k+1)%4][0];
			ly=cy+d[(k+1)%4][1];
			if(mp[lx][ly]=='#')
			{
				for(i=0;i<3;i++)
				{
					tx=cx+d[k][0];
					ty=cy+d[k][1];
					if(mp[tx][ty]=='.')
						break;
					k=(k+3)%4;
				}
				if(i==3)
					goto l1;
			}
			else
			{
				tx=lx;
				ty=ly;
				k=(k+1)%4;
			}
			
			res[idx++]=f[k];
			cx=tx;
			cy=ty;
		}
l1:		if(!flag)
			printf(" Edison ran out of energy.");
		else
		{
			res[idx]='\0';
			printf(" %d\n",strlen(res));
			printf("%s",res);
		}

		printf("\n");
	}
}