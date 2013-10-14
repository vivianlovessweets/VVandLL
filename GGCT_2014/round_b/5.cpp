#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

typedef long long LL;

char s[10000005],line[1000005];
string str;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	int k=0;
	while(gets(line))
	{
		int len=strlen(line);
		line[len]='\n';
		line[len+1]='\0';
		strcpy(s+k,line);
		k+=len+1;
	}
	s[k]='\0';
	str=s;
	stack<int> st;
	k=0;
	while(true)
	{
		int p=str.find("/*",k);
		int q=str.find("*/",k);
		if(q==-1)
			break;
		if(p==-1||q<p)
		{
			if(st.empty())
			{
				k=q+1;
				continue;
			}
			p=st.top();
			st.pop();
			for(int i=p;i<q+2;i++)
			{
				str[i]=-1;
			}
			k=q+2;
		}
		else
		{
			st.push(p);
			k=p+2;
		}
	}
	printf("Case #1:\n");
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!=-1)
			putchar(str[i]);
	}
}