#include <iostream>
using namespace std;
#define N 4

/* 
	输入一维数组的首地址及数组长度，注意二维数组元素
	在内存中的存放顺序，实现a[i][j] 和a[j][i]的值互换
*/
void transpose(int *a,int dim)
{
	int i,j,temp;
	for(i=0; i<dim; i++){
		for(j=i+1; j<dim; j++){
			temp = *(a+dim*i+j);
			*(a+dim*i+j) = *(a+dim*j+i);
			*(a+dim*j+i) = temp;
		}
	}
}

/*
	输出二维数组元素
*/
void print(int *a,int dim)
{
	int i,j;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			cout<<*(a+dim*i+j)<<" ";
		}
		cout<<endl;
	}

}
int main()
{
	int i,j;
	int a[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j]=(i+1)*10+(j+1);	//赋初值
		}
	}
	cout<<"转置之前"<<endl;
	print(&a[0][0],N);
	transpose(&a[0][0],N);
	cout<<"转置之后"<<endl;
	print(&a[0][0],N);
	return 0;

}
