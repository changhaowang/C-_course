#include <iostream> 
using namespace std; 

class Cylinder
{ 
public:
	Cylinder()
	{

	}
	Cylinder(double r)
	{
		m_radius=r;
	}
	Cylinder(double r,double l)
	{
		m_radius=r;
		m_length=l;
	}
	double m_radius; 
	double m_length; 
	double get_cylinder_volume(); 
	double get_cylinder_area(); 
}; 

int main() 
{ 
	double radius,length;

	cout << "Please Enter Radius(m), Length(m):"; 
	cin >> radius >>length; 

	Cylinder mycylinder;
	mycylinder.m_radius=radius;
	mycylinder.m_length=length;

	Cylinder mycylinder1[2]={Cylinder(10),Cylinder(20)};
	mycylinder1[0].m_length=length;
	mycylinder1[1].m_length=length;
	Cylinder mycylinder2(10,20);

	cout << "This cylinder area = " << mycylinder.get_cylinder_area()<<" m2  "<< "This cylinder volume = "<<mycylinder.get_cylinder_volume()<<" m3"<<endl; 
	cout << "This cylinder area = " << mycylinder1[0].get_cylinder_area()<<" m2  "<< "This cylinder volume = "<<mycylinder1[0].get_cylinder_volume()<<" m3"<<endl; 
	cout << "This cylinder area = " << mycylinder1[1].get_cylinder_area()<<" m2  "<< "This cylinder volume = "<<mycylinder1[1].get_cylinder_volume()<<" m3"<<endl; 
	cout << "This cylinder area = " << mycylinder2.get_cylinder_area()<<" m2  "<< "This cylinder volume = "<<mycylinder2.get_cylinder_volume()<<" m3"<<endl; 
} 

double Cylinder::get_cylinder_volume() 
{ 

	return 3.14*m_radius*m_radius*m_length/4.0; 
} 

double Cylinder::get_cylinder_area() 
{ 

	return 2*3.14*m_radius*m_radius+2*3.13*m_radius*m_length; 
}
