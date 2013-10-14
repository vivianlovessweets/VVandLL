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

int n,h[10005];
char mp[105][105],tmp[105][105];

int find(int t)
{
	if(h[t]!=t)
		h[t]=find(h[t]);
	return h[t];
}

bool blue_test()
{
	int i,j,p,q;
	for(i=0;i<n*n+2;i++)
		h[i]=i;
	for(i=0;i<n;i++)
	{
		if(mp[i][0]=='B')
		{
			p=find(i*n);
			q=find(n*n);
			if(p!=q)
			{
				h[p]=q;
			}
		}
		if(mp[i][n-1]=='B')
		{
			p=find(i*n+n-1);
			q=find(n*n+1);
			if(p!=q)
			{
				h[p]=q;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<n-1&&mp[i][j]=='B'&&mp[i][j+1]=='B')
			{
				p=find(i*n+j);
				q=find(i*n+j+1);
				if(p!=q)
				{
					h[p]=q;
				}
			}
			if(i<n-1&&mp[i][j]=='B'&&mp[i+1][j]=='B')
			{
				p=find(i*n+j);
				q=find((i+1)*n+j);
				if(p!=q)
				{
					h[p]=q;
				}
			}
			if(i<n-1&&j>0&&mp[i][j]=='B'&&mp[i+1][j-1]=='B')
			{
				p=find(i*n+j);
				q=find((i+1)*n+j-1);
				if(p!=q)
				{
					h[p]=q;
				}
			}
		}
	}
	p=find(n*n);
	q=find(n*n+1);
	if(p==q)
		return true;
	return false;
}

bool red_test()
{
	int i,j,p,q;
	for(i=0;i<n*n+2;i++)
		h[i]=i;
	for(i=0;i<n;i++)
	{
		if(mp[0][i]=='R')
		{
			p=find(i);
			q=find(n*n);
			if(p!=q)
			{
				h[p]=q;
			}
		}
		if(mp[n-1][i]=='R')
		{
			p=find((n-1)*n+i);
			q=find(n*n+1);
			if(p!=q)
			{
				h[p]=q;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<n-1&&mp[i][j]=='R'&&mp[i][j+1]=='R')
			{
				p=find(i*n+j);
				q=find(i*n+j+1);
				if(p!=q)
				{
					h[p]=q;
				}
			}
			if(i<n-1&&mp[i][j]=='R'&&mp[i+1][j]=='R')
			{
				p=find(i*n+j);
				q=find((i+1)*n+j);
				if(p!=q)
				{
					h[p]=q;
				}
			}
			if(i<n-1&&j>0&&mp[i][j]=='R'&&mp[i+1][j-1]=='R')
			{
				p=find(i*n+j);
				q=find((i+1)*n+j-1);
				if(p!=q)
				{
					h[p]=q;
				}
			}
		}
	}
	p=find(n*n);
	q=find(n*n+1);
	if(p==q)
		return true;
	return false;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		int i,j,sr,sb;
		sr=sb=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<n;j++)
			{
				if(mp[i][j]=='R')
				{
					sr++;
				}
				else if(mp[i][j]=='B')
				{
					sb++;
				}
			}
		}
		printf("Case #%d: ",cs);
		if(sr-sb>1||sb-sr>1)
		{
			printf("Impossible\n");
			continue;
		}
		memcpy(tmp,mp,sizeof(mp));
		bool flag_blue=blue_test();
		bool flag_red=red_test();
		if(flag_red&&flag_blue||sr==sb+1&&flag_blue||sb==sr+1&&flag_red)
		{
			printf("Impossible\n");
			continue;
		}
		if(flag_red || flag_blue)
		{
			char c='R';
			if(flag_blue)
				c='B';
			bool flag=false;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					if(tmp[i][j]==c)
					{
						memcpy(mp,tmp,sizeof(mp));
						mp[i][j]='.';
						if(flag_red&&!red_test()||flag_blue&&!blue_test())
							flag=true;
					}
				}
			if(!flag)
			{
				printf("Impossible\n");
				continue;
			}
		}
		if(flag_red)
			printf("Red wins\n");
		else if(flag_blue)
			printf("Blue wins\n");
		else
			printf("Nobody wins\n");
	}
}