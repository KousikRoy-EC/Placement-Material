#include <bits/stdc++.h>
using namespace std;

// 1. Prime no

/*
bool isPrime(int num){
    if(num<=1){
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
       if(num%i==0){
        return false;
       }
    }

    return true;
}

int main(){
    int num;
    cout<<"Enter no to check Prime or not";
    cin>>num;
    isPrime(num)?cout<<"Prime":cout<<"Not Prime";
    return 0;
}
*/

// 2. Fibonacci series

/*
void fibonacci(int num){
    int num1=0;
    int num2=1;
    int sum;
    cout<<num1<<" "<<num2<<" ";

    for(int i=0;i<num-2;i++){
        sum=num1+num2;
        cout<<sum<<" ";
        num1=num2;
        num2=sum;
    }
}

int main(){
    int num;
    cout<<"Enter no to print fibonacci series";
    cin>>num;
    fibonacci(num);
    return 0;
}
*/

// 3. Pallindrome no

/*
bool checkPallindrom(int num){
    string converted=to_string(num);
    string rev=converted;
    reverse(rev.begin(),rev.end());
    return rev==converted ? true : false;
}



bool checkPallindrom(int num)
{
    int revNum = 0;
    int temp;
    int orginalNum = num;

    while (num)
    {
        temp = num % 10;
        revNum = revNum * 10 + temp;
        num = num / 10;
    }

    return revNum == orginalNum;
}

int main()
{
    int num;
    cout << "Enter no to check whether it is pallindrome or not ? ";
    cin >> num;
    if (checkPallindrom(num))
    {
        cout << "Pallindrome";
    }
    else
    {
        cout << "Not Pallindrome";
    }
    return 0;
}

*/





// lcm and gcd of numbers

/*
int gcd(int num1,int num2){
    if(num2==0){
        return num1;
    }
    return gcd(num2,num1%num2);

    ||


    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int lcm(int num1,int num2){
    return (num1*num2)/gcd(num1,num2);
}

int main(){
    int num1,num2;
    cout<<"Enter two numbers";
    cin>>num1>>num2;
    cout<<"The gcd of two numbers is : "<<gcd(num1,num2);
    cout<<"The lcm of two numbers is : "<<lcm(num1,num2);
    return 0;
}
*/





// factorial
/*
int factorial(int num){
    if(num==1){
        return 1;
    }
    return num*factorial(num-1);
}

int main(){
    int num;
    cout<<"Enter no to find Factorial";
    cin>>num;
    cout<<"The factorial of no is : "<<factorial(num);
    return 0;
}
*/

// 4. Armstrong no

/*
unsigned int cube(unsigned int num)
{
    return num * num * num;
}

bool Armstrong(int num)
{
    int originalNum = num;
    int sum=0;
    int temp;
    while (num)
    {
        temp = num % 10;
        sum += cube(temp);
        num = num / 10;
    }
cout<<sum;
    return sum == originalNum ? true : false;
}

int main()
{
    int num;
    cout << "Enter no to find Armstrong or not";
    cin >> num;
    cout <<"\n The no is"<<Armstrong(num);
    return 0;
}

*/

// decimal to binary

/*
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        cout << "0";
        return;
    }

    int binary[32];
    int i = 0;

    while (decimal) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    cout << "Binary representation: ";
    decimalToBinary(decimal);

    return 0;
}
*/

// A year is a leap year if the following conditions are satisfied:

// The year is multiple of 400.
// The year is multiple of 4 and not multiple of 100.

// Anagram
/*
bool anagram(string st1,string st2){
    if(st1.length()!=st2.length()){
        return false;
    }

    char count[256]={0};

    for(int i=0;i<st1.length();i++){
        count[st1[i]]++;
        count[st2[i]]--;
    }

    for(int i=0;i<256;i++){
        if(count[i]!=0){
            return false;
        }
    }
    return true;
}


int main(){
    string st1="listen";
    string st2="silent";

    if(anagram(st1,st2)){
        cout<<"Anagram";
    }
    else{
        cout<<"Not Anagram";
    }
return 0;
}
*/

// program for malloc and calloc in c++
/*
int main(){
    int *ptr;
    int n;
    cout<<"Enter no of elements";
    cin>>n;
    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL){
        cout<<"Memory not allocated";
    }
    else{
        cout<<"Memory allocated successfully";
        for(int i=0;i<n;i++){
            ptr[i]=i+1;
        }
        cout<<"The elements of array are : ";
        for(int i=0;i<n;i++){
            cout<<ptr[i]<<" ";
        }
    }
    return 0;
}

*/

// program for calloc
/*
int main(){
    int *ptr;
    int n;
    cout<<"Enter no of elements";
    cin>>n;
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL){
        cout<<"Memory not allocated";
    }
    else{
        cout<<"Memory allocated successfully";
        for(int i=0;i<n;i++){
            ptr[i]=i+1;
        }
        cout<<"The elements of array are : ";
        for(int i=0;i<n;i++){
            cout<<ptr[i]<<" ";
        }
    }
    return 0;
}
*/

// structure pointer

/*
struct Person {
    string name;
    int age;
};

int main() {

    Person person;
    Person* personPtr;
    personPtr = &person;
    personPtr->name = "John Doe";
    personPtr->age = 25;

    cout << "Name: " << personPtr->name << endl;
    cout << "Age: " << personPtr->age << endl;

    return 0;
}
*/

// Declaring A Pointer To A Function

/*
int addition(int num1,int num2){
    return num1+num2;
}

int main(){
    int (*ptr)(int,int)=addition; // Declaring A Pointer To A Function
    cout<<(*ptr)(2,3);  // Calling A Function Through Function Pointer
    return -1;
}
*/

// Passing a Function's Address as an Argument to Other Function

/*
int addition(int num1,int num2){
    return num1+num2;
}

void print(int (*ptr)(int,int)){
    cout<<(*ptr)(2,3);
}

int main(){
    print(addition);
    return -1;
}
*/

// functional array pointer

/*
int addition(int num1,int num2){
    return num1+num2;
}

int subtraction(int num1,int num2){
    return num1-num2;
}

int multiplication(int num1,int num2){
    return num1*num2;
}

int division(int num1,int num2){
    return num1/num2;
}

int main(){
    int (*ptr[4])(int,int)={addition,subtraction,multiplication,division};
    cout<<ptr[0](2,3)<<endl;
    cout<<ptr[1](2,3)<<endl;
    cout<<ptr[2](2,3)<<endl;
    cout<<ptr[3](2,3)<<endl;
    return -1;
}
*/

// Memory Sharing: A union allows multiple members to share the same memory space. When a union is defined, the memory allocated for it can be used to store any of its members interchangeably.

// Size: The size of a union is determined by the largest member within it. This means the memory allocated for a union is large enough to accommodate its largest member. Other members share the same memory space, potentially leading to a situation where the actual size of the union may be larger than the sum of the sizes of its individual members.

// Member Access: Only one member of the union can be accessed at any given time. Changing the value of one member may affect the values of other members, as they share the same memory location. It is the programmer's responsibility to keep track of which member is currently valid.

// Default Initialization: Unions do not initialize their members by default. It is essential to explicitly assign a value to a member before accessing it to ensure its validity.

/*

union Data
{
    int intValue;
    float floatValue;
    char charValue;
};

int main()
{
    Data myData;

    myData.intValue = 42;
    std::cout << "Integer value: " << myData.intValue << std::endl;

    myData.floatValue = 3.14;
    std::cout << "Float value: " << myData.floatValue << std::endl;
    std::cout << "Integer value: " << myData.intValue << std::endl; // Accessing intValue after modifying floatValue

    myData.charValue = 'A';
    std::cout << "Character value: " << myData.charValue << std::endl;
    std::cout << "Float value: " << myData.floatValue << std::endl; // Accessing floatValue after modifying charValue

    return 0;
}

*/

// pattern 1

/*

*
* *
* * *
* * * *
* * * * *



int main(){
    char arr[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            arr[i][j]='*';
        }
    }

    cout<<"Printing pattern \n";

    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return -1;
}

*/

// Pattern 2

/*

* * * * *
  * * * *
    * * *
      * *
        *




int main(){
    char arr[5][5];

    for(int i=0;i<5;i++){
        for (int k = 0;k<i; k++)
        {
            arr[i][k]=' ';
        }

        for(int j=i;j<5;j++){
            arr[i][j]='*';
        }
    }

    cout<<"Printing pattern \n";

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return -1;
}


*/

// pattern 3

/*
* * * * *
* * * *
* * *
* *
*





int main(){
    char arr[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            arr[i][j]='*';
        }
    }

    cout<<"Printing pattern \n";

      for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return -1;
}

*/

// pattern 4

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

int main(){
    int num;
    cout<<"Enter num";
    cin>>num;

    for (int i = 0; i < num; i++)
    {
       for (int j = 0; j <= i; j++)
       {
            cout<<j+1<<" ";
       }
       cout<<endl;
    }
    return 0;
}
*/

/*

1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

int main(){
    int num;
    cout<<"Enter num";
    cin>>num;

    for (int i = 0; i < num; i++)
    {
       for (int j = 0; j < num - i; j++)
       {
            cout<<j+1<<" ";
       }
       cout<<endl;
    }

    return 0;
}

*/

// pattern 5
/*
   *
  * *
 * * * *
* * * * *



int main(){
    int rows;
    cout<<"Enter rows";
    cin>>rows;

    for (int i = 1; i <= rows; i++)
    {
       for(int space=1;space<=rows-i;space++){
        cout<<" ";
       }

       for(int star=1;star<= 2*i-1;star++){
        cout<<"*";
       }

       cout<<endl;
    }


    return 0;
}

*/

// pattern 7
/*
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *


int main(){
    int rows;
    cout<<"Enter rows";
    cin>>rows;

    for (int i = rows; i >= 1; i--)
    {
       for(int space=1;space<= rows-i;space++){
        cout<<" ";
       }

       for(int star=1;star<= 2*i-1;star++){
        cout<<"*";
       }

       cout<<endl;
    }

    return 0;
}

*/

/*

        *
      * *
    * * *
  * * * *
* * * * *


int main(){

    int num;
    cout<<"Enter num";
    cin>>num;

    for (int i = 0; i<num; i++)
    {
        for(int space=0;space<num-i-1;space++){
            cout<<" ";
        }

        for (int star = 0; star < i+1; star++)
        {
            cout<<"*";
        }

        cout<<endl;

    }

    return 0;
}


*/

/*

*
**
***
****
*****
****
***
**
*




int main(){
    int rows;
    cout<<"Enter rows";
    cin>>rows;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <i+1; j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j <rows-i; j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }

    return 0;
}

*/

/*
    *
   **
  ***
 ****
*****
 ****
  ***
   **
    *




int main(){
    int rows;
    cout<<"Enter rows";
    cin>>rows;


    for (int i = 1; i <= rows; i++)
    {
        for (int p = 0; p < rows-i; p++)
        {
           cout<<" ";
        }

        for (int j = 1; j <i+1; j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j <i; j++)
        {
            cout<<" ";
        }

        for (int k = 0; k < rows-i; k++)
        {
         cout<<"*";
        }


        cout<<endl;
    }

    return 0;
}

*/

/*

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *



void printSpaces(int numSpaces) {
    for (int i = 0; i < numSpaces; i++) {
        std::cout << " ";
    }
}

void printStars(int numStars) {
    for (int i = 0; i < numStars; i++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}

void printDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        printStars(2 * i - 1);
    }

    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        printStars(2 * i - 1);
    }
}

int main() {
    int n;

    cout << "Enter the number of rows (odd number): ";
    cin >> n;

    printDiamond(n);
    return 0;
}


*/

/*

1
11
121
1231
13541
148951

int main(){
    int rows;
    cout<<"Enter rows";
    cin>>rows;

    int array[rows][rows]={0};

    for(int i=0;i<rows;i++){
        for(int j=0;j<i+1;j++){
            if(j==0 || i==j){
                array[i][j]=1;
                cout<<array[i][j]<<" ";
            }
            else{
                array[i][j]=array[i-1][j]+array[i-1][j-1];
                cout<<array[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}

*/

/*

floyds triangle

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15





int main(){
    static int num=1;
    int rows;
    cout<<"Enter rows";
    cin>>rows;

    for(int i=0;i<rows;i++){
        for(int j=0;j<i+1;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

*/
