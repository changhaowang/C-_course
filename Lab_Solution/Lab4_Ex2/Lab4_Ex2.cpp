#include <iostream>
using namespace std;

int main()
{
	char password[]="sjtuc++";		//预设的密码
	char c,input[20];				//c用来存放单个字符，input存放输入字符串
	int i;

	cout<<"请输入不超过20个字符的密码\n";
	i=0;
	while((c=getchar()) !='\n' && i<20){	//'\n'作为键盘输入字符结束标志
		*(input+i)=c;
		i++;
	}
	input[i]='\0';							// 字符串最后一个元素
	cout<<"您输入的密码为"<<input<<endl;


	for(i=0;i<20,password[i]!='\0';i++){	//小于20个字符，并且password字符串还没有结束
		if( *(input+i) != *(password+i)){	//逐个比较字符
			cout<<"您输入的密码不正确\n";	
			return 0;
		}
	}
	cout<<"密码正确，欢迎您\n";
	return 0;


}

