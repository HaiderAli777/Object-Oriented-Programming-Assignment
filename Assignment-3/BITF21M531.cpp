#include "iostream"
using namespace std;

class Circle
{
	int x;
	int y;
	float radius;
	static const double PI;

public:

	//Provide The All Implementation of All Constructor

	Circle(int x, int y, float radius)
	{

		setX(x);
		setY(y);
		setRadius(radius);

	}

	Circle(int x, int y)
	{

		setX(x);
		setY(y);
		radius = 5;

	}


	Circle(int x, float radius)
	{

		setX(x);
		setRadius(radius);
		y = 0;

	}

	Circle()
	{
		x = 0;
		y = 0;
		radius = 5;
	}

	Circle(const Circle& object)
	{
		setX(object.x);
		setY(object.y);
		setRadius(object.radius);
	}



	//Implementation of destructor

	~Circle()
	{
		cout << "Destructor Executed ...." << endl;
	}



	//All setter  for Data Member

	void setX(int x)
	{
		if (x >= -50 && x <= 50)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}

	}

	void setY(int y)
	{
		if (y >= -50 && y <= 50)
		{
			this->y = y;
		}
		else
		{
			this->y = 0;
		}
	}

	void setRadius(float radius)
	{
		if (radius >= 1 && radius <= 10)
		{
			this->radius = radius;
		}
		else
		{
			this->radius = 5;
		}
	}


	//Now Make All The getter

	int getX() const
	{
		return x;
	}

	int getY() const
	{
		return y;
	}

	float getRadius() const
	{
		return radius;
	}

	//Implementation of Member Function

	void setCircle(int x, int y, float radius)
	{

		setX(x);
		setY(y);
		setRadius(radius);

	}

	void getCircle()
	{
		cout << "Enter The Value Of x :";
		cin >> x;
		setX(x);

		cout << "Enter The Value of y :";
		cin >> y;
		setY(y);

		cout << "Enter The Value of Radius :";
		cin >> radius;
		setRadius(radius);
	}

	void putCircle() const
	{

		
		cout << "The X-axis Of Circle :" << x << endl;
		cout << "The Y-axis Of Circle :" << y << endl;
		cout << "The Radius Of Circle :" << radius << endl;

	}

	double getArea() const
	{
		return PI * (radius * radius);
	}

	float getDiameter() const
	{
		return  (radius * 2);
	}


	double getCircumference() const
	{
		return  (2 * PI * radius);
	}

	Circle add(const Circle& obj1) const
	{
		return Circle(this->x + obj1.x, this->y + obj1.y, this->radius + obj1.radius);
	}

	 bool IsEqual(const Circle& obj) const
	{
		return (obj.x == this->x && obj.y == this->y && obj.radius == this->radius);
	}

	int findCircle(const Circle arr[], int size) const
	{

		for (int i = 0;i < size;i++)
		{
			if (IsEqual(arr[i]))
			{
				return i;
			}
		}
		return -1;

	}

	void UpdateCircle(Circle arr[], int size) const
	{
		for (int i = 0;i < size;i++)
		{
			if (this->x == arr[i].x && this->y == arr[i].y)
			{
				arr[i].radius = this->radius;
			}
		}
	}


};

const double Circle::PI = 3.141593;

int main()
{
	Circle obj1(1,2,3.5), obj2,ar1[2]={Circle(),Circle(1,2,3.5)}, ar2[2]={Circle(),Circle(1,2,7.5)};

	//Using the get circle function

	obj2.getCircle();

	//Checking All The Farmula Function

	cout<<"The Area of circle :" << obj2.getArea() << endl;
	cout << "The circumference of circle :" << obj2.getCircumference() << endl;
	cout <<"The diameter of circle :" << obj2.getDiameter() << endl;

	//Checking The Add function

	obj1.add(obj2).putCircle();

	//Checking The IsEqual function

	if (obj1.IsEqual(obj2))
	{
		cout << "Both Object are Equal" << endl;
	}
	else
	{
		cout << "Objects are not Equal" << endl;
	}

	//Checking the findCircle

	cout<<"The index of equal state circle :" << obj1.findCircle(ar1, 2) << endl;

	//Checking the UpdateCircle

	obj2.UpdateCircle(ar2, 2);
	for (int i = 0;i < 2;i++)
	{
		cout <<endl<< i+1 << " st) Object" << endl;

		ar2[i].putCircle();

	}

	return 0;
}