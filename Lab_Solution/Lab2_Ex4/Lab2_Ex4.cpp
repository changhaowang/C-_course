
#include<iostream>
using namespace std;
int main()
{
	int i,j,k,num,m=0;
	cout<<endl;
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
			for(k=1;k<5;k++)
			{
				if(i!=j&&i!=k&&j!=k)
				{
					m+=1;
					num=100*i+10*j+k;
					cout<<num<<endl;
				}
			}
			cout<<"共有三位数： "<<m<<endl;
			return 0;
}