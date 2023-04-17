#include <iostream>
using namespace std;

class IntegerSet
{

    int* data; 
    const int size; 

public:

    // Constructor 

    IntegerSet(int size) : size(size)
    {
        data = new int[size]; 

        for (int i = 0; i < size; i++)
        {
            data[i] = 0; 
        }

    }


    IntegerSet(const IntegerSet& obj) : size(obj.size)
    {
        data = new int[size]; 


        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i]; 
        }

    }

    //Destructor

    ~IntegerSet()
    {
        delete[] data; 
    }

    // Stream insertion operator 


    friend ostream& operator<<(ostream& output, const IntegerSet& obj)
    {

        int check = 1;
        for (int i = 0; i < obj.size; i++)
        {
            if (obj.data[i] == 1)
            {
                output << i << " "; 
                check = 0;
            }
        }
        if (check) 
        {
            output << "- - -"<<endl;
        }
        return output;
    }

    // Assignment operator 


    IntegerSet& operator=(const IntegerSet& obj)
    {
        if (this != &obj)
        {
            if (size == obj.size)
            {

                for (int i = 0; i < size; i++) 
                {
                    data[i] = obj.data[i];
                }
            }
            else
            {
                cout << "Error: Sizes of the sets do not match." << endl;
            }

        }

        return *this;
    }

    // Equal operator to check if two sets are equal


    bool operator==(const IntegerSet& obj) const
    {

        if (size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (data[i] != obj.data[i]) 
                {
                    return false; 
                }
            }
        }
        else
        {
            return false;
        }

        return true; 
    }

    // Logical NOT operator 

    IntegerSet operator!() 
    {

        IntegerSet result(size); // Create a new set with the same size
        for (int i = 0; i < size; i++)

        {
            if (data[i])
            {
                result.data[i] = 0;
            }
            else
            {
                result.data[i] = 1;
            }
        }
        return result;
    }
  
        // Function to insert an element into the set

        void insertElement(int k)
        {

            if (k >= 0 && k < size) 
            {
                data[k] = 1;
            }
            else 
            {
               cout << "Element must be between 0 and " << (size - 1) << endl;
            }
        }

        // Function to delete an element from the set

        void deleteElement(int k) 
        {

            if (k >= 0 && k < size) 
            
            {
                data[k] = 0;
            }
            else 
            {
                cout << "  Element must be between 0 and " << (size - 1) <<endl;
            }
        }

        // Function to perform union of two sets

        IntegerSet unionOfSets(const IntegerSet& obj) const 
        {

            IntegerSet obj1(size);

            for (int i = 0; i <size; i++) 
           
            {
                if (data[i] || obj.data[i])
                {
                    obj1.data[i] = 1;
                }
                else
                {
                    obj1.data[i] = 0;
                }
            }
            return obj1;
        }

        // Function to perform intersection of two sets
      
        IntegerSet IntersectionOfSets(const IntegerSet& obj) const
        {
            IntegerSet obj1(size);

            for (int i = 0; i < size; i++)
            {
                if (data[i] && obj.data[i])
                {
                    obj1.data[i] = 1;
                }
                else
                {
                    obj1.data[i] = 0;
                }
            }
            return obj1;
        }
        // Function to find if an element exists in the set

        bool findElement(int key) const 
        {
            if (key >= 0 && key < size)
            {
                if (data[key] == 1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                cout << "Your Index is out of bound " << endl;
            }
        }
    };


int main()
{
    IntegerSet obj1(10);

    //Checking The Insert Function
    obj1.insertElement(1);
    obj1.insertElement(0);
    obj1.insertElement(2);
    

    //Checking the delete function

    IntegerSet obj2(obj1);

    obj2.deleteElement(0);
   

    //Cheking the operator !
    cout << "Reverse The Set" << endl;
    cout << !obj2<<endl;

    //
    IntegerSet obj3 = obj2;
    cout << "Hello" << endl;
    cout <<"Obj1   :  " << obj1<<endl;
    cout <<"obj2   :  " << obj2<<endl;

    cout<< "Intersection :  " << obj1.IntersectionOfSets(obj2) << endl;

    cout << "Union   : " <<obj1.unionOfSets(obj2)<<endl;

    cout << (obj1.findElement(1)?"Found":"Not Found")<<endl;

    
    cout << (obj3==obj2 ? "Equal" : "Not Equal") << endl;











    return 0;
 }