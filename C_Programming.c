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



/*
1. What is C programming language?

Ans -> C is a procedural programming language developed by Dennis Ritchie in 1972 at Bell Labs. It's a general-purpose language known for its efficiency, flexibility, and low-level features. It's widely used for system programming, developing operating systems, and embedded systems.

2. What are the differences between C and C++?

Ans -> C++ is an extension of C with additional features like classes, inheritance, polymorphism, and templates. C++ supports object-oriented programming, while C is a procedural language. C++ also includes features like namespaces and exception handling, which are not present in C.

3. What are the basic data types in C?

Ans -> In C, basic data types include int, char, float, double, and void. These types can be modified using qualifiers like signed, unsigned, short, and long.

4. What is a pointer in C and how does it work?

Ans -> A pointer in C is a variable that holds the memory address of another variable. It allows dynamic memory allocation and manipulation of data indirectly. Pointers are used for dynamic memory allocation, passing arguments by reference, and building complex data structures.

5. How do you declare and use a pointer in C?

Ans -> 
int *ptr; // Declaration of a pointer to an integer
int x = 10;
ptr = &x; // Assigning the address of x to the pointer
printf("Value of x: %d\n", *ptr); // Dereferencing the pointer to get the value of x

6. What is a function pointer in C?

Ans -> A function pointer is a variable that stores the address of a
function that can later be called through that function pointer. OR

A function pointer in C is a pointer that points to a function instead of a variable. It allows functions to be passed as arguments to other functions or stored in data structures.
How do you pass arguments to a function in C?

7. How do you pass arguments to a function in C?

Ans -> Arguments are passed to a function in C either by value or by reference. By value means passing the copy of the actual value, while by reference means passing the address of the variable.
What is a structure in C and how is it used?

8. What is a structure in C and how is it used?

Ans -> A structure in C is a user-defined data type that allows grouping together variables of different data types under one name. It's used to represent a record with multiple fields.
What is the difference between a structure and a union in C?

9. What is the difference between a structure and a union in C?

Ans -> A structure is a user-defined data type in C/C++.

A structure creates a data type that can be used to group items of possibly
different types into a single type. A structure is useful when you want to keep
track of multiple variables that belong to different data types.

A union is a special data type available in C that allows to store different
data types in the same memory location. You can define a union with many members,
but only one member can contain a value at any given time. Unions provide an efficient
way of using the same memory location for multiple-purpose.

10. What is a typedef in C?

Ans -> typedef is a keyword in C programming language which is used to assign
alternative names to existing types. The typedef keyword is also used to define
the own data type. OR

typedef is used to create an alias for existing data types, making code more readable and portable. It's often used to define custom data types.

11. What is the difference between malloc and calloc in C?

Ans -> malloc is used to allocate a block of memory of specified size, while calloc is used to allocate a block of memory and initializes all its bits to zero. malloc doesn't initialize the allocated memory, whereas calloc does.

12. What is a memory leak in C?

Ans -> A memory leak in C occurs when you forget to deallocate a block of dynamically
allocated memory when you are done using it. This means that the memory will stay
allocated until the program terminates and will not be available for reuse by other
parts of the program. This can lead to memory shortage and cause the program to crash.

13. How can you prevent a memory leak in C?

Ans -> You can prevent a memory leak in C by deallocating the memory block when you
are done using it. This can be done using the free() function in C.

14. What is the difference between stack and heap memory in C?

Ans -> Stack memory is used for static memory allocation and Heap memory is used for
dynamic memory allocation, both stored in the computers RAM .OR

Stack memory is used for storing local variables and function call information. It's managed by the compiler and is limited in size. Heap memory, on the other hand, is dynamically allocated memory that's managed manually by the programmer. It's larger in size but requires explicit memory management.

15. What is a static variable in C and how is it used?

Ans -> A static variable in C retains its value between multiple function calls.
A static variable is declared with the static keyword. OR

A static variable in C is a variable that retains its value between function calls. It's initialized only once and remains in memory until the program terminates. Static variables are declared using the static keyword.

16. What is the difference between static and dynamic linking in C?

Ans -> Static linking involves linking libraries at compile-time, resulting in a larger executable but with no external dependencies. Dynamic linking links libraries at runtime, resulting in smaller executables but requiring external library files to run.

17. What is a header file in C?

Ans -> A header file in C contains declarations of functions, macros, data types, etc., which are defined in corresponding source files. It allows sharing declarations across multiple source files.

18. How do you include a header file in C?

Ans -> Header files are included using the #include preprocessor directive. For example:

19. What is a preprocessor in C?

Ans -> A preprocessor is a directive to the compiler to perform certain tasks before
the actual compilation begins. All preprocessor commands begin with a hash symbol (#).
It must be the first nonblank character, and for readability, a preprocessor directive
should begin in the first column. OR

The preprocessor in C is a program that processes the source code before compilation. It handles directives like #include, #define, #ifdef, etc., and performs text substitutions and file inclusions.

20. What is the #define directive in C?

Ans -> The #define directive in C is used to define constant or macro. It is a way to
give symbolic names to numerical values. For example, you can use #define to give a
name to a constant representing a magic number or a global configuration value.

or

The #define directive is used to define constants and macros in C. It associates a name with a value or a code snippet, which is replaced throughout the code during preprocessing.

21. What is the #ifdef directive in C?

Ans -> The #ifdef directive is used to check whether a particular identifier has been defined using a #define directive. It allows conditional compilation based on the existence of a macro.

22. What is a macro in C and how is it used?

Ans -> A macro is a fragment of code that is given a name. It is used in place of
a longer piece of code. Macro is defined using #define directive. It is called
macro processor because it allows you to define macros, which are brief abbreviations
for longer constructs.

23. What is the difference between a macro and a function in C?

Ans -> A macro in C is a fragment of code that has been given a name. It's defined using the #define directive and can represent constants, functions, or code snippets. Macros are expanded inline during preprocessing.

OR

Macros are expanded inline during preprocessing, while functions are executed at runtime. Macros lack type checking and can lead to unexpected behavior if not used carefully, whereas functions provide type safety.

24. What is a file in C?

Ans -> A file in C is a sequence of bytes stored on a storage device. It can be a text file, a binary file, or a special file associated with a device. Files are accessed using file handling functions provided by the C standard library.

25. How do you open and close a file in C?

Ans -> Files are opened using the fopen function and closed using the fclose function. For example:

26. What is the difference between read and write operations on a file in C?

Ans -> Read operations are used to read data from a file, while write operations are used to write data to a file. Read operations use functions like fread, fscanf, etc., while write operations use functions like fwrite, fprintf, etc.

27. What is a binary file in C?

Ans -> A binary file in C is a file that contains data in a format that's not human-readable. It typically stores data in its raw form, without any formatting, making it more efficient for storing complex data structures.

28. What is the difference between text and binary files in C?

Ans -> Text files store data in a human-readable format, where each character is represented by its ASCII or Unicode value and may include newline characters. Binary files store data in its raw form, without any formatting, making them more efficient for storing complex data structures.

29. What is a command line argument in C?

Ans -> A command line argument in C is information provided to a program at the time of execution via the command line. They are accessed using the argc and argv parameters of the main function.

30. How do you pass command line arguments to a C program?

Ans -> Command line arguments are passed to a C program when executing it from the command line. For example:

31. What is a structure padding in C?

Ans -> Structure padding in C refers to the insertion of unused bytes between members of a structure to ensure proper alignment of data and optimize memory access. It's done by the compiler to improve performance.

32. How do you declare and use an array in C?

Ans -> Arrays in C are declared by specifying the data type of the elements and the size of the array. For example:

33. What is the difference between an array and a pointer in C?

Ans -> An array in C is a collection of elements of the same data type stored in contiguous memory locations, while a pointer is a variable that holds the memory address of another variable. Arrays have a fixed size, while pointers can be dynamically allocated.

34. What is a multidimensional array in C?

Ans -> A multidimensional array in C is an array that contains arrays as its elements. It's used to represent tabular data or matrices. For example:

35. What is a string in C?

Ans -> In C, a string is an array of characters terminated by a null character '\0'. It's used to represent text data.

36. How do you declare and use a string in C?

Ans -> 
char str[10] = "hello"; // Declaration and initialization of a string
printf("%s\n", str); // Printing the string

37. What is the difference between a string and a character array in C?

Ans -> A string in C is a character array terminated by a null character '\0', while a character array may or may not be a string. Strings are used to represent text data, while character arrays can store any sequence of characters.

38. What is the strlen function in C?

Ans -> The strlen function in C is used to find the length of a string, excluding the null character '\0'. It returns the number of characters in the string.

39. What is the strcpy function in C?

Ans -> The strcpy function in C is used to copy one string to another. It copies the contents of the source string to the destination string, including the null character '\0'.

40. What is the strcat function in C?

Ans -> The strcat function in C is used to concatenate (append) one string to the end of another. It appends the contents of the source string to the destination string, overwriting the null character '\0' at the end of the destination string.

41. What is the strcmp function in C?

Ans -> The strcmp function in C is used to compare two strings lexicographically. It returns an integer less than, equal to, or greater than zero if the first string is found to be less than, equal to, or greater than the second string, respectively.

42. What is the sscanf function in C?

Ans -> The sscanf function in C is used to read formatted input from a string. It works similarly to the scanf function but reads input from a string instead of standard input (stdin).

43. What is the fprintf function in C?

Ans -> The fprintf function in C is used to write formatted output to a file. It works similarly to the printf function but writes output to a specified file stream.

44. What is the fscanf function in C?

Ans -> The fscanf function in C is used to read formatted input from a file. It works similarly to the scanf function but reads input from a specified file stream instead of standard input (stdin).

45. What is a recursive function in C?

Ans -> A recursive function in C is a function that calls itself either directly or indirectly. It's used to solve problems that can be broken down into smaller, similar subproblems.

46. How do you implement a recursive function in C?

Ans ->

Recursive functions in C consist of a base case and a recursive case. The base case defines the terminating condition, while the recursive case calls the function itself with modified arguments. For example:

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1; // Base case
    else
        return n * factorial(n - 1); // Recursive case
}

47. What is the difference between a while and a do-while loop in C?

Ans -> In a while loop, the condition is checked before executing the loop body, so it's possible that the loop body may not execute at all. In a do-while loop, the condition is checked after executing the loop body, ensuring that the loop body executes at least once.

48. What is the difference between a for and a while loop in C?

Ans -> A for loop is used when the number of iterations is known beforehand, and it consists of three parts: initialization, condition, and increment/decrement. A while loop is used when the number of iterations is not known beforehand, and it only consists of a condition.

49. What is a switch statement in C?

Ans -> A switch statement in C is a control flow statement used to select one of several code blocks for execution based on the value of an expression. It's an alternative to using multiple if-else statements.

50. How do you break out of a loop in C?

Ans -> You can break out of a loop in C using the break statement. When encountered within a loop, the break statement immediately terminates the loop and transfers control to the statement immediately following the loop.

*/

