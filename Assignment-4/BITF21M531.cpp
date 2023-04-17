#include "iostream"
using namespace std;

class RationalNumber
{
	int numirator;
	int denuminator;

public:

	//Provide implementation setter 

	void setNumirator(int numirator)
	{
		this->numirator = numirator;
	}

	void setDenumirator(int denumirator)
	{
		//for resolving not becoming negative the denumirator

		if (denuminator < 0)
		{
			denuminator = abs(denuminator);
		}

		//for checking the non zero value

		if (denumirator != 0)
		{
			this->denuminator = denumirator;
		}
		else
		{
			this->denuminator = 1;
		}
	
	}

	//Provide Implementation of getter

	int getNumirator()
	{
		return this->numirator;
	}

	int getDenumirator()
	{
		return this->denuminator;
	}

	// provide the implementation of constructor

	RationalNumber(int num,int denu)
	{
		setNumirator(num);
		setDenumirator(denu);
	}

	RationalNumber(int num)
	{
		setNumirator(num);
		denuminator = 1;
	}

	//Overload The operator

	//make << operator for obj

	friend ostream& operator <<(ostream& print,const RationalNumber &obj)
	{
		print << obj.numirator<<"/"<<obj.denuminator<<endl;
		return print;
	}

	//make >> operator for obj

	friend istream& operator >>(istream& inp, RationalNumber &obj)
	{
		cout << "Enter The Value of numinator:";
		cin >> obj.numirator;

		cout << "Enter The Value of denuminator:";
		cin >> obj.denuminator;

		return inp;
	}

	//make + operator for obj

	RationalNumber operator+(const RationalNumber &obj) const
	{
		return RationalNumber((this->denuminator!=obj.denuminator?this->numirator * obj.denuminator + this->denuminator * obj.numirator:this->numirator+obj.numirator),this->denuminator!=obj.denuminator?this->denuminator*obj.denuminator:this->denuminator);
	}

	//make - operator for obj

	RationalNumber operator-(const RationalNumber& obj)const 
	{
		return RationalNumber((this->denuminator != obj.denuminator ? this->numirator * obj.denuminator - this->denuminator * obj.numirator : this->numirator - obj.numirator), this->denuminator != obj.denuminator ? this->denuminator * obj.denuminator : this->denuminator);
	}

	//make * operator for obj

	RationalNumber operator*(const RationalNumber& obj) const 
	{
		return RationalNumber((this->numirator * obj.numirator), this->denuminator * obj.denuminator);
	}

	//make / operator for obj

	RationalNumber operator/(const RationalNumber& obj) const
	{
		return RationalNumber((this->numirator * obj.denuminator), this->denuminator * obj.numirator);
	}

	//make < operator for obj

	bool operator<(RationalNumber& obj)
	{
	 return (((float)this->numirator/this->denuminator < (float)obj.numirator/ obj.denuminator));
	}

	//make == operator for obj

	bool operator==(RationalNumber& obj)
	{
		return (((float)this->numirator / this->denuminator == (float)obj.numirator / obj.denuminator));
	}

	//make - operator for obj

	RationalNumber& operator-()
	{
		if (this->numirator > 0)
		{
			setNumirator(-this->numirator);
		}

		return *this;
	}

	//make ! operator for obj

	bool operator!()
	{
		return this->numirator < 0;
	}

};

int main()
{

	//implementation of operation

	RationalNumber obj1(2, 4),obj2(1,4),obj3(1,5);
	RationalNumber sum= obj1 + obj2;
	cout<<sum;
	RationalNumber sub = obj1 - obj2;
	cout << sub;

	RationalNumber mul = obj1*obj2;
	cout << mul;

	RationalNumber div = obj1 / obj2;
	cout << div;

	cout << (obj2<obj1?"Obj2 are greater":"Obj2 are not greater")<<endl;

	if (obj1 == obj2)
	{
		cout << "Both obj are equal"<<endl;
	}
	else
	{
		cout << "Both obj are not equal"<<endl;
	}

	cout <<-obj1<<endl;

	cout <<!obj1<<endl;
	
	/*
	* cout << obj1 + obj2;
	cout << obj1 - obj2;
	cout <<obj1*obj2;
	*/
		
	

	return 0;
}