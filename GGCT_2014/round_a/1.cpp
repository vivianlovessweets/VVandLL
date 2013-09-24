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
	int T,cs;
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	char a[10005],b[10005];
	string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string sus[12]={"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		printf("Case #%d: ",cs);
		scanf("%s%s",a,b);
		int i,j;
		vector<int> vt(1,0);
		for(i=0;b[i]!='\0';i++)
		{
			if(b[i]=='-')
			{
				b[i]='\0';
				vt.push_back(i+1);
			}
		}
		vector<string> ans;
		int k=0;
		for(i=0;i<vt.size();i++)
		{
			int n;
			sscanf(b+vt[i],"%d",&n);
			vector<pair<int,int> > vp;
			for(j=k;j<k+n;j++)
			{
				if(vp.size()==0||a[j]-'0'!=vp[vp.size()-1].first)
				{
					vp.push_back(make_pair(a[j]-'0',1));
				}
				else
				{
					vp[vp.size()-1].second++;
				}
			}
			for(j=0;j<vp.size();j++)
			{
				if(vp[j].second==1||vp[j].second>10)
				{
					for(int l=0;l<vp[j].second;l++)
					{
						ans.push_back(num[vp[j].first]);
					}
				}
				else
				{
					string str=sus[vp[j].second];
					str+=" ";
					str+=num[vp[j].first];
					ans.push_back(str);
				}
			}
			k+=n;
		}
		printf("%s",ans[0].data());
		for(i=1;i<ans.size();i++)
		{
			printf(" %s",ans[i].data());
		}
		printf("\n");
	}
}