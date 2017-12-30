#include <iostream>
using namespace std;
/* 
	move_around_one_step的功能是将数组的
	最后一个移到最前面，其余的向后顺移一个位置
*/
void move_around_one_step(int * vector,int length)
{
	int i;
	int last_item = *(vector + length - 1);
	for(i=length-1; i>=1; i--){
		vector[i] = vector[i-1];	
	}
	vector[0] = last_item;
}

int main()
{
	int i,m,n,a[20];
	cout<<"请整数的个数(不超过20个)"<<endl;
	cin>>n;
	cout<<"最后几个整数需要移动到最前面"<<endl;
	cin>>m;
	cout<<"请输入"<<n<<"个整数"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"输入"<<n<<"个整数为"<<endl;	
	for(i=0;i<n;i++){
		cout<<a[i]<<'\t';
	}
	cout<<endl;
	//每次移动一格，需要移动m次
	for(i=0;i<m;i++){
		move_around_one_step(a,n);
	}
	cout<<"调整后的"<<n<<"个整数为"<<endl;	
	for(i=0;i<n;i++)	
		cout<<a[i]<<'\t';
	cout<<endl;
	return 0;
}
