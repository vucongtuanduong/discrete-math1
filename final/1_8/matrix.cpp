#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[100],b[105][105];
int n,k;
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	cin>>k; 
}
bool isFinal()
{
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i+1])
		{
			return false;
		}
	}
	return true;
}
void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void genNext()
{
	int r=n;
	while(a[r]<a[r-1])
	{
		r--;
	}
	int idx=r-1;
	for(int i=r;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=r;i<=n;i++)
	{
		if(a[idx]<a[i])
		{
			swap(a[idx],a[i]);
			break;
		}
	}
	
}
void display()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	init();
	int cnt=1;
	while(!isFinal())
	{
		
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=b[i][a[i]];
		}
		if(sum==k)
		{
			cout<<"Cach "<<cnt<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<"Chon phan tu "<<b[i][a[i]]<<" o hang "<<i<<" cot "<<a[i]<<endl;
			}
			cout<<"----------------------------"<<endl;
			cnt++;
		}
		genNext();
	}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=b[i][a[i]];
		}
		if(sum==k)
		{
			cout<<"Cach "<<cnt<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<"Chon phan tu "<<b[i][a[i]]<<" o hang "<<i<<" cot "<<a[i]<<endl;
			}
			cout<<"----------------------------"<<endl;
			cnt++;
		}
	return 0;
}
