#include<stdio.h>  // header file library that lets us work with input and output functions eg printf(), scanf(), etc
#include<conio.h>  // header file library that lets us work with input and output console functions eg getch(), clrscr(), etc
#include<stdlib.h> // header file library that lets us work with general functions eg malloc(), calloc(), exit(), etc
#include<string.h> // header file library that lets us work with string functions eg strlen(), strcpy(), strcmp(), etc
#include<stdbool.h>   // header file library that lets us work with boolean functions eg true, false, etc
#include<math.h>   // header file library that lets us work with mathematical functions eg sqrt(), pow(), etc
// In C, the bool type is not a built-in data type


/*
int main(){
    printf("Hello this is C programming");
    return 0;
}

*/

/*
escape sequence
/n new line
/t tab
/b backspace
/r beginning of the current line
*/


/*
%d int
%f float
%c char
%s string
%lf double
%ld long double
%u unsigned int
*/


/*
int main(){
    char kousik='A'; //imp character should be enclosed in single quotes
    printf("%c",kousik);
    return 0;
}
*/


/*
The general rules for naming variables are:

Names can contain letters, digits and underscores
Names must begin with a letter or an underscore (_)
Names are case sensitive (myVar and myvar are different variables)
Names cannot contain whitespaces or special characters like !, #, %, etc.
Reserved words (such as int) cannot be used as names







int	    2 or 4 bytes	Stores whole numbers, without decimals
float	4 bytes	        Stores fractional numbers, containing one or more decimals. Sufficient for storing 6-7 decimal digits
double	8 bytes	        Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits
char	1 byte	        Stores a single character/letter/number, or ASCII values


*/


// type conversion
/*
int main(){
    float sum= (float) 2+0.3;
    const int a=6;
    printf("type conevrsion - %f , constant - %d , size of int - %lu",sum,a,sizeof(a));
    return 0;
}
*/

// ternary operator
/*
int time = 20;
(time < 18) ? printf("Good day.") : printf("Good evening.");
*/


// reverse an array
/*  
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
int array[]={1,2,3,4,5,6,7,8,9,10};

int size=sizeof(array)/sizeof(array[0]);

for (int i=0;i<size;i++){
    printf("%d",array[i]);
}

printf("\n");

for(int i=0;i<size/2;i++){
   swap(&array[i],&array[size-i-1]);
}

printf("\n");

for (int i=0;i<size;i++){
    printf("%d",array[i]);
}

return 0;
}
*/


// // malloc and calloc
// the main difference between malloc and calloc is that allocated memory in malloc contains garbage value 
// where as calloc sets allocated memory to zero.
/*
int main(){
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create\n");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf ("Enter an integer ") ;
        scanf("%d",ptr+i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(ptr+i));
    }
    return 0;
}
*/

/*
int main(){
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create\n");
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        ptr[i]=i+1;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ptr[i]);
    }
    return 0;
}
*/

// enum is used to define a group of named constants, which makes a program easy to read and maintain.

/*
enum Kousik_Car{
    Lamborghini,
    Ferrari,
    RollsRoyce=90,
    Tata=45,
};

int main(){
    enum Kousik_Car myCar;
    myCar=Tata;
    printf("%d",myCar);
}
*/



// structure is a group of variables of different data types represented by a single name.

/*
struct Kousik_Marksheet
{
   float CGPA;
   char name[20];
   float roll_no;
};


int main(){
    struct Kousik_Marksheet Kishan;
    Kishan.CGPA=9.5;
    strcpy(Kishan.name,"Kousik"); // we cant directly assign string a value as string in c is array of characters
    Kishan.roll_no=74;
    printf("%f\n",Kishan.CGPA);
    printf("%s\n",Kishan.name);
    printf("%f\n",Kishan.roll_no);
    return 0;
}

*/

// 1. What is C programming language?
// 2. What are the differences between C and C++?
// 3. What are the basic data types in C?
// 4. What is a pointer in C and how does it work?
// 5. How do you declare and use a pointer in C?
// 6. What is a function pointer in C?
// ans - A function pointer is a variable that stores the address of a 
// function that can later be called through that function pointer.

// 7. How do you pass arguments to a function in C?
// 8. What is a structure in C and how is it used?
// 9. What is the difference between a structure and a union in C?

// Ans -> A structure is a user-defined data type in C/C++. 
// A structure creates a data type that can be used to group items of possibly 
// different types into a single type. A structure is useful when you want to keep
// track of multiple variables that belong to different data types.

// A union is a special data type available in C that allows to store different
// data types in the same memory location. You can define a union with many members,
// but only one member can contain a value at any given time. Unions provide an efficient
// way of using the same memory location for multiple-purpose.

// 10. What is a typedef in C?

// Ans -> typedef is a keyword in C programming language which is used to assign
// alternative names to existing types. The typedef keyword is also used to define
// the own data type.

// 11. What is the difference between malloc and calloc in C?
// 12. What is a memory leak in C?

// Ans -> A memory leak in C occurs when you forget to deallocate a block of dynamically
// allocated memory when you are done using it. This means that the memory will stay
// allocated until the program terminates and will not be available for reuse by other
// parts of the program. This can lead to memory shortage and cause the program to crash.


// 13. How can you prevent a memory leak in C?

// Ans -> You can prevent a memory leak in C by deallocating the memory block when you
// are done using it. This can be done using the free() function in C.

// 14. What is the difference between stack and heap memory in C?

// Ans -> Stack memory is used for static memory allocation and Heap memory is used for
// dynamic memory allocation, both stored in the computers RAM .


// 15. What is a static variable in C and how is it used?

// Ans -> A static variable in C retains its value between multiple function calls.
// A static variable is declared with the static keyword.

// 16. What is the difference between static and dynamic linking in C?
// 17. What is a header file in C?
// 18. How do you include a header file in C?
// 19. What is a preprocessor in C?

// Ans -> A preprocessor is a directive to the compiler to perform certain tasks before
// the actual compilation begins. All preprocessor commands begin with a hash symbol (#).
// It must be the first nonblank character, and for readability, a preprocessor directive
// should begin in the first column.

// 20. What is the #define directive in C?

// Ans -> The #define directive in C is used to define constant or macro. It is a way to
// give symbolic names to numerical values. For example, you can use #define to give a
// name to a constant representing a magic number or a global configuration value.

// 21. What is the #ifdef directive in C?
// 22. What is a macro in C and how is it used?

// Ans -> A macro is a fragment of code that is given a name. It is used in place of
// a longer piece of code. Macro is defined using #define directive. It is called
// macro processor because it allows you to define macros, which are brief abbreviations   
// for longer constructs.

// 23. What is the difference between a macro and a function in C?
// 24. What is a file in C?
// 25. How do you open and close a file in C?
// 26. What is the difference between read and write operations on a file in C?
// 27. What is a binary file in C?
// 28. What is the difference between text and binary files in C?
// 29. What is a command line argument in C?
// 30. How do you pass command line arguments to a C program?
// 31. What is a structure padding in C?
// 32. How do you declare and use an array in C?
// 33. What is the difference between an array and a pointer in C?
// 34. What is a multidimensional array in C?
// 35. What is a string in C?
// 36. How do you declare and use a string in C?
// 37. What is the difference between a string and a character array in C?
// 38. What is the strlen function in C?
// 39. What is the strcpy function in C?
// 40. What is the strcat function in C?
// 41. What is the strcmp function in C?
// 42. What is the sscanf function in C?
// 43. What is the fprintf function in C?
// 44. What is the fscanf function in C?
// 45. What is a recursive function in C?
// 46. How do you implement a recursive function in C?
// 47. What is the difference between a while and a do-while loop in C?
// 48. What is the difference between a for and a while loop in C?
// 49. What is a switch statement in C?
// 50. How do you break out of a loop in C?


/*
struct Person {
    int age;
    float height;
};

int main() {
    struct Person p1; 
    printf("Enter age: ");
    scanf("%d", &p1.age);
    p1.height = 5.7;
    printf("Age: %d\n", p1.age);
    printf("Height: %f\n", p1.height);
    return 0;
}
*/

int main(){
char array[]="Hello world";
printf("%d",strlen(array));
printf("\n");
printf("%d",sizeof(array));
return 0;
}