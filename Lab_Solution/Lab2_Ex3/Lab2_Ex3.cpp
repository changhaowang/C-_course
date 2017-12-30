#include<iostream>
#include<fstream>

using namespace std;
fstream file;
int main()
{
	int a,b;
	file.open("MultiplicationTable.txt",ios::out);

	for(a=1;a<=9;a++)
	{
		for(b=1;b<=a;b++)
		{
			file<<b<<"*"<<a<<"="<<b*a<<"	";
			cout<<b<<"*"<<a<<"="<<b*a<<"	";
		}
		file<<endl;
		cout<<endl;
	}

	file.close();
	return 0;

}
