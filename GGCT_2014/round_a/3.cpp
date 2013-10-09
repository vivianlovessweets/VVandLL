#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		printf("Case #%d:",cs);

		int n,t,i;
		vector<int> v1,v2;
		vector<int> p1,p2;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(t%2==0)
			{
				v2.push_back(t);
				p2.push_back(i);
			}
			else
			{
				v1.push_back(t);
				p1.push_back(i);
			}
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end(),greater<int>());
		int res[10005];
		for(i=0;i<v1.size();i++)
			res[p1[i]]=v1[i];
		for(i=0;i<v2.size();i++)
			res[p2[i]]=v2[i];
		for(i=0;i<n;i++)
			printf(" %d",res[i]);

		printf("\n");
	}
}