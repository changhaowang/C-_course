#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	float a,x;
	cout<<"ÊäÈëa£¨a>=0£©"<<endl;
	cin>>a;
	x=20;

	while((fabs(0.5*a/x-0.5*x))>=1e-5)
	{
		x=0.5*(x+a/x);
	}

	x=0.5*(x+a/x);
	cout<<x<<endl;

	return 0;
}