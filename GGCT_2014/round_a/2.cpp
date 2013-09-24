#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

typedef unsigned long long ULL;

ULL a,b;

void dfs(ULL n)
{
	if(n==1)
	{
		a=b=1;
		return;
	}
	dfs(n/2);
	if(n%2==0)
		b=a+b;
	else
		a=a+b;
}

ULL get(ULL p,ULL q)
{
	if(p==1&&q==1)
		return 1;
	if(p>q)
		return get(p-q,q)*2+1;
	else
		return get(p,q-p)*2;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		printf("Case #%d: ",cs);

		int m;
		ULL n,p,q;
		scanf("%d",&m);
		if(m==1)
		{
			scanf("%llu",&n);
			dfs(n);
			printf("%llu %llu",a,b);
		}
		else
		{
			scanf("%llu%llu",&p,&q);
			printf("%llu",get(p,q));
		}

		printf("\n");
	}
}