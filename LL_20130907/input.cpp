#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long LL;

#define INF 10000000
#define BIG_CASE_NUM 3
#define BIG_MAX_NUM 10000000
#define SMALL_CASE_NUM 1000
#define SMALL_MAX_NUM 1000

int myrand(int n)
{
	return rand()*rand()%n;
}

bool f[INF];

void generate(int max_num)
{
	int n,j,k;
	do 
	{
		n=myrand(max_num);
	} while (n%3!=1);
	printf("%d\n",n);

	memset(f,0,sizeof(f));
	int a=myrand(INF);
	f[a]=1;
	printf("%d",a);

	for(j=0;j<(n-1)/3;j++)
	{
		do 
		{
			k=myrand(INF);
		} while (f[k]);
		f[k]=1;
		printf(" %d %d %d",k,k,k);
	}
	printf("\n");
}

int main()
{
	int i;
	freopen("input.txt","w",stdout);
	for(i=0;i<BIG_CASE_NUM;i++)
	{
		generate(BIG_MAX_NUM);
	}
	for(i=0;i<SMALL_CASE_NUM;i++)
	{
		generate(SMALL_MAX_NUM);
	}
}