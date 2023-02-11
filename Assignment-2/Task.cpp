#include "iostream"
#include "string"
#include "cmath"
using namespace std;

class Cuboids
{
	float height;
	float width;
	float depth;

public:

	//Mutators for all Data Members

	void setHeight(float h1)
	{
		if (h1 > 0 && h1 < 35)
		{
			height = h1;
		}
		else
		{
			height = 1;
		}

	}

	void setWidth(float w1)
	{
		if (w1 > 0 && w1 < 35)
		{
			width = w1;
		}
		else
		{
			width = 1;
		}

	}

	void setDepth(float d1)
	{
		if (d1 > 0 && d1 < 35)
		{
			depth = d1;
		}
		else
		{
			depth = 1;
		}

	}

	//All accessors for all data members

	float getHeight()
	{
		return height;
	}


	float getWidth()
	{
		return width;
	}


	float getDepth()
	{
		return depth;
	}

	//Constructor Implmentation

	Cuboids(float h1, float w1, float d1)
	{

		setHeight(h1);
		setWidth(w1);
		setDepth(d1);

	}

	Cuboids(float h1, float w1)
	{

		setHeight(h1);
		setWidth(w1);
		depth = 1;

	}

	Cuboids() 
	{

		height = 1;
		width = 1;
		depth = 1;

	}

	Cuboids(Cuboids& obj)
	{
		height = obj.height;
		width = obj.width;
		depth = obj.depth;
	}

	~Cuboids()
	{
		cout << "Destructor Executed ..." << endl;
	}

	//Member Function 

	void setCuboids(float height1,float width1,float depth1)
	{

		setHeight(height1);
		setWidth(width1);
		setDepth(depth1);

	}

	void getCuboids()
	{
		cout << "Enter The Height of Cuboids :";
		cin >> height;

		setHeight(height);

		cout << "Enter The Width of Cuboids :";
		cin >> width;

		setWidth(width);

		cout << "Enter The Depth of Cuboids :";
		cin >> depth;

		setDepth(depth);

	}

	void putCuboids()
	{

		cout << "The Height of Cuboids :" << height << endl;

		cout << "The Width of Cuboids :"<<width<<endl;
	
		cout << "The Depth of Cuboids :"<<depth<<endl;
	
	}

	//Calculate SurfaceArea

	float getSurfaceArea()
	{

		return (2 * (height * width)) + (2 * (height * depth)) + (2 * (width * depth));

	}

	//Calculate Volume

	float getVolume()
	{

		return ((height*width)*depth);

	}

	float getSpaceDiognal()
	{

		return sqrt((height*height)+(width*width)+(depth*depth));

	}

	void putCuboidsInfo()
	{

		putCuboids();
		cout << "The SurfaceArea :" << getSurfaceArea()<<endl;
		cout << "The Volume :" << getVolume() << endl;
		cout << "The SpaceDiognal :" << getSpaceDiognal() << endl;

	}
};

int main()
{
	Cuboids obj1,obj2(12,0,31);
	obj1.getCuboids();
	obj1.putCuboidsInfo();

	obj2.putCuboidsInfo();


	return 0;
}