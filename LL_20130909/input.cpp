#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long LL;

int myrand(int n)
{
	return rand()*rand()%n+1;
}

void generate(int max_num,int m,int s)
{
	int n=myrand(max_num);
	printf("%d\n",n);

	m+=s;
	printf("%d",myrand(m)-s);
	for(int i=1;i<n;i++)
	{
		printf(" %d",myrand(m)-s);
	}

	printf("\n");
}

int main()
{
	int i;
	freopen("input.txt","w",stdout);
	for(i=0;i<10;i++)
	{
		generate(10,10,3);
	}
	for(i=0;i<1000;i++)
	{
		generate(1000,500,10);
	}
	for(i=0;i<3;i++)
	{
		generate(10000000,100000,100);
	}
}