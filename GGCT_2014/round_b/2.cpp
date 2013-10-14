#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;

typedef long long LL;

struct node
{
	int sx,sy,ex,ey;
}p[1005];

LL px[1000005],sx[1000005],py[1000005],sy[1000005],t;
LL lx[1000005],rx[1000005],ly[1000005],ry[1000005];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		int n,i,j,k;
		map<int,int> mpx,mpy;
		map<int,int>::iterator it;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&p[i].sx,&p[i].sy,&p[i].ex,&p[i].ey);
			for(j=p[i].sx;j<=p[i].ex;j++)
			{
				mpx[j]+=p[i].ey-p[i].sy+1;
			}
			for(j=p[i].sy;j<=p[i].ey;j++)
			{
				mpy[j]+=p[i].ex-p[i].sx+1;
			}
		}
		int kx=0;
		it=mpx.begin();
		while(it!=mpx.end())
		{
			px[kx]=(*it).first;
			sx[kx]=(*it).second;
			(*it).second=kx;
			kx++;
			it++;
		}
		int ky=0;
		it=mpy.begin();
		while(it!=mpy.end())
		{
			py[ky]=(*it).first;
			sy[ky]=(*it).second;
			(*it).second=ky;
			ky++;
			it++;
		}

		lx[0]=0;
		t=sx[0];
		for(i=1;i<kx;i++)
		{
			lx[i]=lx[i-1]+(px[i]-px[i-1])*t;
			t+=sx[i];
		}
		rx[kx-1]=0;
		t=sx[kx-1];
		for(i=kx-2;i>=0;i--)
		{
			rx[i]=rx[i+1]+(px[i+1]-px[i])*t;
			t+=sx[i];
		}
		ly[0]=0;
		t=sy[0];
		for(i=1;i<ky;i++)
		{
			ly[i]=ly[i-1]+(py[i]-py[i-1])*t;
			t+=sy[i];
		}
		ry[ky-1]=0;
		t=sy[ky-1];
		for(i=ky-2;i>=0;i--)
		{
			ry[i]=ry[i+1]+(py[i+1]-py[i])*t;
			t+=sy[i];
		}

		LL ans,fx,fy,ts;
		ans=LL(1e18);
		for(i=0;i<n;i++)
		{
			for(j=p[i].sx;j<=p[i].ex;j++)
			{
				for(k=p[i].sy;k<=p[i].ey;k++)
				{
					ts=lx[mpx[j]]+rx[mpx[j]]+ly[mpy[k]]+ry[mpy[k]];
					if(ans>ts||ans==ts&&fx>j||ans==ts&&fx==j&&fy>k)
					{
						ans=ts;
						fx=j;
						fy=k;
					}
				}
			}
		}

		printf("Case #%d: %lld %lld %lld\n",cs,fx,fy,ans);
	}
}