#include "iostream"
using namespace std;
#include "string"

class Employee
{
	string name;
	int id;
	string department;
	string position;

public:
	//defalut constructor 

	Employee() 
	{
		name = "";
		id = 0;
		department = "";
		position = "";
	}

	//parameterized constructor

	Employee(string name1,int id1,string department1,string position1)
	{
		name = name1;
		id = id1;
		department = department1;
		position = position1;
	}

	Employee(string name1, int id1)
	{
		name = name1;
		id = id1;
		department = "";
		position = "";
	}

	//Copy Constructor

	Employee(Employee& obj)
	{
		name = obj.name;
		id = obj.id;
		department = obj.department;
		position = obj.position;
	}


	// ALL Setter For Each Data Member

	void setName(string name1)
	{
		name = name1;
	}

	void setId(int  id1)
	{
		id = id1;
	}

	void setDepartment(string department1)
	{
		department = department1;
	}

	void setPosition(string position1)
	{
		position = position1;
	}

	// ALL Getter For Each Data Member

	string getName()
	{
		return name;
	}

	int getId()
	{
		return id;
	}

	string getDepartment()
	{
		return department;
	}

	string getPosition()
	{
		return position;
    }

	//Member Function

	void setInfo(string name1, int id1, string department1, string position1)
	{
		name = name1;
		id = id1;
		department = department1;
		position = position1;
	}

	void getInfo()
	{

		cout << "Enter The Name of Employee :";
		getline(cin, name);

		cout << "Enter The Id of Employee :";
		cin >> id;

		cin.ignore();
		cout << "Enter The Department of Employee :";
		getline(cin, department);

		cout << "Enter The Position of Employee :";
		getline(cin, position);

	}

	void putInfo() {

		cout << name << "\t\t" << id << "\t\t" << department << "\t\t" << position<<endl;

	}


	//destructor

	~Employee()
	{
		cout << "Destructor Executed...." << endl;
	}
};


int main()
{

	Employee obj1,obj2("Haider Ali", 2, "Computer Science", "Ministery of Education"), obj3(obj2), obj4, obj5;


	obj1.getInfo();
	obj4 = obj1;
	obj5 = obj1;



	cout << "NAME" << "\t\t\t" << "ID" << "\t\t" << "DEPARTMENT" << "\t\t\t" << "POSITION" << endl;

	obj1.putInfo();
	obj2.putInfo();
	obj3.putInfo();
	obj4.putInfo();
	obj5.putInfo();

	





	return 0;
}