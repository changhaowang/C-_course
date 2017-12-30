#include<iostream>
using namespace std;

void main(void)
{
	int A[3][3]={9,8,7,2,4,5,0,1,3};
	int B[3][3]={1,2,3,4,5,6,7,8,9};
	int C[3][3];

	int Ta=0;
	int Tb=0;

	for(int i=0;i<3;i++)
	{
		Ta=Ta+A[i][i];
		Tb=Tb+B[i][i];
	}

	cout<<"¾ØÕóA¼£Îª"<<Ta<<endl;
	cout<<"¾ØÕóB¼£Îª"<<Tb<<endl;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}

	cout<<"A="<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"B="<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"C="<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}

}


