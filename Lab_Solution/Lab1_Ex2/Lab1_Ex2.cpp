#include <iostream>		 				//包含头文件isostream
using namespace std;						//使用c++的命名空间std
int main()									//主函数			
{										//函数开始
	int a1, d, n, sum;						// 定义变量
	a1=1;								// 首项赋值
	d=3;									// 公差赋值
	n=100;								// 项数赋值
	sum=n*a1+n*(n-1)/2*d;					//求和并赋值
	cout<<"首项："<<a1<<"，公差："<<d<<"，项数："<<n<<"\n";// 输出等差数列的参数
	cout<<"等差数列的和为"<<sum<<"\n";	// 输出等差数列的和

	return 0;								// 程序执行完毕返回
}										//函数结束
