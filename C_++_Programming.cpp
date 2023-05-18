#include<iostream>
using namespace std;   //means that we can use names for objects and variables from the standard library

/*
struct Person {
    string name;
    int age;
    float height;
};

int main() {
     Person p1; 
    cout << "Enter Full Name: ";
    cin>> p1.name;
    cout << "Enter Age: ";
    cin >> p1.age;
    cout << "Enter Height: ";
    cin >> p1.height;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Height: " << p1.height << endl;
    return 0;
}
*/
 
 /*
int main()
{
    int arr[] = { 3, 5, 6, 7, 9 };
    int *p = arr;
    int (*ptr)[5] = &arr;
    cout << "p = "<< p <<", ptr = " << ptr << endl;
    cout << "*p = "<< *p <<", *ptr = " << *ptr << endl;     
    cout << "sizeof(p) = "<< sizeof(p) <<
            ", sizeof(*p) = " << sizeof(*p) << endl;
    cout << "sizeof(ptr) = "<< sizeof(ptr) <<
        ", sizeof(*ptr) = " << sizeof(*ptr) << endl;
    return 0;
}
 */


/*
class CharusatId{
    public:
    string name;
    int id;
   
    void printDetails(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Id: " << id << endl;
        cout << "CGPA: " << cgpa << endl;
    }

    int placedIn(string company);


    private:
    float cgpa;


    protected:
     int age;
};

int CharusatId::placedIn(string company){
    cout << name << " is placed in " << company << endl;
    return 0;
}


int main(){
    CharusatId c1;
    c1.name = "Raj";
    c1.age = 20; //cannot be accessed outside of class as it is protected
    c1.id = 47; 
    c1.cgpa = 8.5;//cannot be accessed outside of class as it is private
    c1.printDetails();
    c1.placedIn("TCS");
    return 0;
}


inheritance
class derivedClass:public CharusatId{
    
}
*/