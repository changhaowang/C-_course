#include<iostream>
using namespace std;
#define PI 3.1415926
class shape 
{
protected:     
	double s; 
public: 
    void show() 
   {
	   cout<<"s= "<<s<<endl;   
	} 
}; 
 class Rectangle:public shape
 {   
	 double x,y;     
 public: 
       Rectangle(double x1=0,double y1=0) 
	   {x=x1;y=y1;}        
	   void  GetArea()
	   {s=x*y;}     
 }; 
 class Circle:public shape    
 {   
	 double r;      
 public: 
	 Circle(double r1=0)         
	 {r=r1;}          
	 void  GetArea()         
	 {s=r*r*PI; }    
 }; 
class Square:public Rectangle    
{   
	double a;     
public: 
	Square(double a1=0 )  
	{a=a1;}        
	void  GetArea()         
	{s=a*a; }    
};
void main()
{
	Rectangle rect(5,10);
	rect.GetArea();
	cout<<"rectangle area:"<<endl;
	rect.show();
	Square square(10);
	square.GetArea();
	cout<<"square area:"<<endl;
	square.show();
	Circle circle(5);
	circle.GetArea();
	cout<<"circle area:"<<endl;
	circle.show();
}

