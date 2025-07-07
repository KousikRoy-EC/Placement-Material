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



51. what is storage class in C?

Ans -> Storage class in C is a keyword that specifies the visibility and lifetime of a variable, function, or block of code. There are four storage classes in C: auto, static, extern, and register.

auto: Default for local variables.
static:
Use for global variables that must not be accessed outside the file.
Use inside a function to retain the value between function calls.
register: Optimize variables like loop counters for performance.
extern: Share global variables between multiple files.

52. What is the difference between global and local variables in C?

Ans -> Global variables in C have external linkage and can be accessed from any function within the same translation unit. Local variables in C have automatic linkage and can only be accessed within the function in which they are declared.

53. processing steps in C

Source Code (.c)
        |
    Preprocessor
        |
Preprocessed File (.i)
        |
     Compiler
        |
  Assembly Code (.s)
        |
    Assembler
        |
  Object File (.o)
        |
     Linker
        |
   Executable (a.out)

The preprocessor handles all preprocessor directives (lines starting with #), such as #include, #define, and #ifdef. It produces an intermediate file called the preprocessed file.

Key Tasks:
Expand macros defined using #define.
Include the contents of header files (e.g., #include <stdio.h>).
Remove comments from the source code.
Process conditional compilation (#ifdef, #endif, etc.).


The compiler takes the preprocessed file and translates it into assembly code. Assembly code is a low-level, human-readable representation of machine instructions.

Key Tasks:
Syntax analysis: Ensures the code follows the rules of C.
Semantic analysis: Checks data types, scope rules, and consistency.
Optimization: Improves code efficiency without changing functionality.


The assembler converts the assembly code into machine code (binary instructions that the CPU can execute). This process generates an object file.

Key Tasks:
Translate assembly instructions into binary instructions.
Generate relocation information for symbols (e.g., function or variable references).


The linker combines the object file(s) and required libraries into a single executable file.

Key Tasks:
Resolve external symbols: Functions or variables used in one file but defined in another.
Combine multiple object files if the program is split across multiple .c files.
Link standard libraries (e.g., libc for printf, scanf, etc.).


54 . pointer and its types
	                     
Null Pointer	                                                                       
A pointer that is initialized to NULL (a special value indicating the pointer does not point to any valid memory location).
int *ptr = NULL;

Void Pointer	
A pointer with no specific data type. It can point to any type of data but cannot be dereferenced directly without typecasting.
void *ptr;
int a = 10;
ptr = &a;

Wild Pointer

A pointer that is not initialized and points to an unknown memory location, leading to undefined behavior.
int *ptr; // Wild pointer
*ptr = 10; // Undefined behavior

Dangling Pointer	
A pointer that refers to a memory location which has already been freed or deallocated.
int *ptr = (int *)malloc(sizeof(int));
*ptr = 100;

free(ptr); // Memory deallocated
// ptr is now a dangling pointer

Function Pointer	       
Array Pointer	           
Pointer to Pointer	       

Constant Pointer	
A pointer whose address it holds cannot be changed after initialization.
int a = 10, b = 20;
int *const ptr = &a;

*ptr = 15; // Allowed
ptr = &b;  // Error: Address cannot be changed       


Pointer to Constant	    
A pointer pointing to a constant value. The value it points to cannot be modified, but the pointer itself can change.
const int a = 10;
const int *ptr = &a;

*ptr = 20; // Error: Cannot modify the value
ptr = &b;  // Allowed: Pointer can change

55. what is big and small endian values

Ans -> Big endian and little endian are two different ways of storing multi-byte values in memory.

Big Endian:

Most significant byte (MSB) is stored at the lowest address.

Example:

int value = 0x12345678;

In big endian format, the value 0x12345678 would be stored as follows:

| MSB | LSB |
12     | 34    | 56    | 78    |

Little Endian:

Least significant byte (LSB) is stored at the lowest address.

Example:

int value = 0x12345678;

In little endian format, the value 0x12345678 would be stored as follows:

| LSB | MSB |
78    | 56    | 34    | 12    |


56. what is static function and variable and where it is stored

Ans ->
A static function in C is a function that has a scope limited to the file in which it is declared. This means that the function is not visible or accessible outside the file, effectively making it private to that file.

A static function can also use static variables. These variables retain their value between function calls.
eg

#include <stdio.h>

void staticFunction() {
    static int count = 0;
    printf("Static Function Call: %d\n", ++count);
}

int main() {
    staticFunction();
    staticFunction();
    return 0;
    // Static Function Call: 1
    // Static Function Call: 2
}


*/


extern keyword is used to declare variables or functions that have external linkage, meaning they are defined in another file or translation unit. 
If an extern variable refers to a global variable, it is typically stored in the data segment or BSS segment of memory:
Data Segment: If the variable is initialized.
BSS Segment: If the variable is uninitialized (has no explicit initialization value).
extern variables cannot themselves be static as static enforces internal linkage, conflicting with extern




A static variable inside a function or file has local scope but retains its value between function calls because it has a lifetime equivalent to the program's lifetime.
A static variable is initialized to zero (0) by default if not explicitly initialized.



volatile when a variable may change due to external events, interrupts, or hardware interactions.
Global volatile variables: Stored in the data or BSS segment (depending on whether they are initialized).
Local volatile variables: Stored in the stack.
Dynamic volatile variables: Stored in the heap.


auto	
Local (block scope)	    
Stack       	
Visible within the block only	
Default storage class for local variables.
default value is garbage



The register keyword in C is used as a hint to the compiler that a variable will be frequently accessed and should be stored in a CPU register (if possible) for faster access,
register keyword allocate temproray memory location so it cannot be used fior globalo or static variable however can be used inside a function where faster access of variable is required]
The compiler attempts to store register variables in CPU registers for faster access.
If registers are unavailable, the variable will be stored in stack memory (like a regular variable).



Global const variables: Stored in the read-only data section of memory (RODATA).
Local const variables: Stored in the stack like regular local variables.
Dynamic const variables: Allocated in the heap.
Initialization: Must be initialized at the time of declaration because their value cannot be changed later.
Once initialized, the value of a const variable cannot be modified directly or indirectly.





jagged array arre array of different sized columng in 2D matrix allocated dynamically

if we assign the range of a datatype and then do ++ or increment the 
identifier then it will point to the starting range of it or nrgative first range if
 it is unsigned array.

main(){
    char ch=127; //char is of one byte so it ranges form -128 to 127;
    ch++;
    printf("%d",ch); // this will print -128 
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Declaration Type	                   Storage Location	                        Scope                               Lifetime
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int *ptr;  (inside a function)	       Stack	                                Block (function-local)	            Auto (deallocated when function exits)
static int *ptr; (inside a function)   Data (BSS)	                            Block (function-local)	            Retains value across function calls
int *ptr; (outside a function)	       Data (BSS)	                            Global (entire file)	            Exists for entire program
int *ptr = malloc()	                   Stack (ptr), Heap (allocated memory)	    Block (function-local)	            Heap memory persists until free(ptr); is called

pointer size is compiler dependent and mostly it is 32bit - 4 byte or 64 bit - 8 byte platform dependent

ptr itself is stored in stack (if local) or data section (if static/global).
It can point to memory in stack or heap.
Heap memory persists until explicitly freed.
Scope and lifetime depend on declaration type.

When a class contains a virtual function, it introduces a Virtual Table (V-Table) to
handle dynamic (runtime) polymorphism. The memory for virtual functions is stored in
different sections of memory, primarily the code segment and heap (for objects with new).

When a class contains a virtual function, a V-Table (Virtual Table) is created. 
Each object of this class contains a V-Ptr (Virtual Table Pointer), which points to 
the V-Table.

this v table contains function pointer pointing to all the virtual member fn of that class 

V-Table:

Stored in the Data Segment (Read-Only Section).
Created once per class that has virtual functions.
Contains function pointers for all virtual functions of that class.

V-Ptr (Virtual Table Pointer):

Stored inside each object (on Heap/Stack depending on object allocation).
Points to the V-Table of the class.

Function Implementation:

The compiled function itself is stored in the Code Segment.

* Extra 8 bytes per object (for V-Ptr) means larger object size.



Pointers and const

Pointer to const Data: The data the pointer points to cannot be modified.

const int *ptr = &value; // Read-only access to 'value'
*ptr = 20; // Error
ptr = &other_value; // Allowed

const Pointer: The pointer itself cannot point to another location.

int *const ptr = &value; // Pointer cannot change
*ptr = 20; // Allowed
ptr = &other_value; // Error

const Pointer to const Data: Neither the data nor the pointer can change.

const int *const ptr = &value; // Fully immutable
*ptr = 20; // Error
ptr = &other_value; // Error

*/


As soon as pointer is declared memory is reserved for that pointer no matter whether we point to any variable or not

pointer to a function and calling it

-------------------------------

float OneThird(float);
float OneFifth(float);

int main()
{
float(*pf)(float);
pf = OneThird;
printf("%f\n", (*pf)(3.0));
return 0;
}

float OneThird(float x)
{
return x / 3;
}

float OneFifth(float x)
{
return x / 5;
}

-------------------------------
The parentheses around *pf are
needed to indicate that pf is a pointer.



Array of function pointers

---------------------------------


#include <stdio.h>

 int add(int, int);
 int subtract(int, int);

 int main(void)
 {
 int a, choice;
 int(*fptr[2])(int, int) = { add, subtract };

 printf("Enter your choice:\n");
 printf("\t0:\taddition (10 + 2)\n\t1:\tsubtraction (10 - 2)\n");
 scanf("%d%*c", &choice);

 a=(*fptr[choice])( 10, 2);

 printf("The requested operation gives: %d\n", a);
return 0;
}

int add(int x, int y)
{
return x + y;
}

int subtract(int x, int y)
{
return x - y;
}

------------------------------------------------------

NULL macro is defined in stdio.h and stddef.h

----------------------------------------

#include<stdio.h>

int main()
{
    static char *s[] = {"black", "white", "pink", "violet"};
    char **ptr[] = {s+3, s+2, s+1, s}, ***p;
    p = ptr;
    ++p;
    printf("%s", **p);
    // printf("%s", ***p);    
    // Seg fault beacuse p points to prt array 
    // *p points to ptr[0] (value: s + 3).
    // **p points to s[3] (value: "violet").
    // ***p attempts to dereference "violet" as a pointer, which is invalid.
    return 0;
}

-----------------------------------------



*++p is equivalent to *(++p) because ++ (pre-increment) has higher precedence than *.
The pointer p is incremented before its value is dereferenced.



*p++ is equivalent to *(p++) because ++ (post-increment) has higher precedence.
The pointer p is incremented after its value is dereferenced.



Syntax	Pointer    Modifiable?	         Data Modifiable?
const char*	       YeS			No
char *const	       No			Yes
const char* const      No			No



Cannot use Static for function parameters

The size of pointer is 4 byte but it is compiler dependent 



In C, the char type is implementation-dependent, meaning it can either be signed or unsigned based on the system or compiler being used. By default:

On most systems (such as those following the typical 2's complement representation for integers), a char is signed.




   int main() {
       int x = 2147483647;
       x = x + 1;
       printf("%d", x);
       return 0;

Signed integer overflow.

 

   int main() {
       unsigned int a = 1;
       int b = -1;
       if (a > b)
           printf("True");
       else
           printf("False");
       return 0;
   }
  
prints false as there is type conversion happen between signed and unsigned int signed int is converted to unsigned int 
so int b = -1
represent as in 4 bit represented as 0001
2's compliment of this is calculate using first find 1's compliment 1110
then add 1 to find its 2's compliment 1111 for 64 bit system this conversion becomes very high possitive no 



  int main() {
       printf("%d", printf("Hello"));
       return 0;
   }

this code prints Hello then the amount of character in printf for here Hello5 is the output





Unsigned Representation
All bits are used to represent the magnitude.


Signed Representation (Two's Complement)
The MSB is used as the sign bit:
0 → Positive number
1 → Negative number

malloc allocates a void pointer then we typecast it to use it as int * ptr




int main() {
char *str = "Hello";
str[0] = 'M';
printf("%s", str);
}

"Hello" is a string literal and is stored in a read-only section of memory.
char *str is a pointer that holds the address of this string literal.


Visibility:
static functions are file-local (only visible within the same file).
Normal functions are globally accessible (across files, given proper declarations and linkage).
Linkage:
static functions have internal linkage, meaning they don’t collide with functions of the same name in other files.
Normal functions have external linkage by default, meaning they are accessible from other files in the program.
Thus, whether to use a static function or a normal function depends on whether you want the function to be used only inside the current file or across multiple files in the program.



FORK RELATED QUESTION FOR OS

#include <stdio.h>
#include <unistd.h>

int main(){
    if(fork() && fork())
	fork();
    
    printf("Hello\n");
    return 0;
}

      1p        1c
    1p  1c    1c  1c
    1C





log2n n + 1  gives no of integer in a number




void *memset(void *ptr, int value, size_t num) is used to fill a block of memory with a specific value. It is typically used to initialize or reset a block of memory.

char str[10];
memset(str, 'A', sizeof(str));






float num = 3.14;
// C-Style Cast (Allowed but not explicit)
int a = (int) num;
// C++ `static_cast` (Preferred) provide type checking during compilation older cast does not do that which results in crash of the program.
int b = static_cast<int>(num);
std::cout << a << " " << b;  // Output: 3 3





/* Thread in CPP */

// By default main function is our main thread.
// we can create multiple thread inside this main thread.
// By using thread you can reduce the time of execution by half.

// In c++ we can create thread in 5 different ways.
// Function Pointers
// Lambda functions
// Functors
// member functions
// static member function

/*

function pointer method based thread creation

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

void evenCheck(int var) { 
    bool result = (var % 2 == 0);
    cout << (result ? "The number is even\n" : "The number is not even\n");
}

int main() {
    int value = 42;
    std::thread t1(evenCheck, value); 
    t1.join(); 

    cout << "Function is completed\n"; 
    return 0;
}
*/


/*

lambda function method based thread creation

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
   auto fun= [](int x){
        while(x){
            cout<<x<<endl;
            x--;    
        }
   };

   std::thread t(fun,10);
   t.join();
   return 0;
}
*/


/*

functor method based thread creation

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Base{
public:
void operator ()(int x){
 while(x){
            cout<<x<<endl;
            x--;    
        }
}
};

int main(){
std::thread t((Base()),10);
t.join();
return 0;
}
*/


/*

non static member function based thread creation

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Base{
public:
void run(int x){
 while(x){
            cout<<x<<endl;
            x--;    
        }
}
};

int main(){
Base b;
std::thread t(&Base::run,&b,10);
t.join();
return 0;
}
*/



/*
static member function based thread creation

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Base{
public:
static void run(int x){
 while(x){
            cout<<x<<endl;
            x--;    
        }
}
};

int main(){
std::thread t(&Base::run,10);
t.join();
return 0;
}
*/


// Once thread started execution we wait for that thread to be executed by calling join on that thread object
// double join will termiate the program
// Before joining a object of thread we should check whether it is joinable or not using function joinable();

// Detach is used to detach newly created thread from parent thread so it does not wait for thread to get completed  
// alway check before detaching a thread that it is joinable() otherwise we may end up double detaching and double detach()
// will result in program termination


// either of join or detach should be called on thread because the destructor of thread is called  and checks whether the thread is joinable or ot if yes  then it terminates it.



Simple example to demonstrate working of thread in cpp as soon as you create thread t1,t2 it starts executing and join waits for that to get executed fully.
and we should alway put a condition before detahing or joining a thread in cpp. whether it is joinable or not.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void fun1()
{
    cout << "This is fun1" << endl;
}

void fun2()
{
    cout << "This is fun2" << endl;
}

int main()
{
    thread t1(fun1);
    thread t2(fun2);

    if (t1.joinable())
        t1.join();


    cout<<"Thread of fun2 is still to be executed";
    
    if (t2.joinable())
        t2.join();

    return 0;
}




#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <chrono>
#include <vector>
using namespace chrono;
using namespace std;

// Instead of locking unlocking manually try to use lock_guard which provides efficient way to deal with mutext as it automatically unlocks when mutex goes out of scope.

/*
int counter = 0;
mutex mtx1;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        lock_guard<mutex> lock(mtx1);
        ++counter;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout << "Final Counter: " << counter << endl;
    return 0;
}

*/

// But still as we do it inside a loop it alway runs for locking and unclocking mechanism an efficient way of doing it is using a local variable for updateing the result locally and at final updating it using lock guard mutex.
// Locking the entire loop is inefficient and makes the code single-threaded.
// Using lock_guard makes your code safer and cleaner.
// Accumulating locally and updating once reduces locking overhead.
// Reduces the number of lock/unlock operations, which improves performance.

/*

int counter = 0;
mutex mtx1;

void increment() {
    int localCounter = 0;  // Use a local variable to accumulate
    for (int i = 0; i < 100000; ++i) {
        ++localCounter;
    }
    lock_guard<mutex> lock(mtx1);  // Only one lock for the final update
    counter += localCounter;
}

int main() {
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout << "Final Counter: " << counter << endl;
    return 0;
}

*/




// DeadLock when multiple thread share the same resources and the two thread for one another to release the resource there comes in a dead lock situation
// Thread 1 locks mtx1 and waits for mtx2.
// Thread 2 locks mtx2 and waits for mtx1.
// Both threads are waiting on each other, creating a circular dependency.
// Neither thread can proceed, causing a deadlock.

/*

mutex mtx1, mtx2;

void thread1() {
    lock_guard<mutex> lockA(mtx1);  // Lock mutex 1
    cout << "Thread 1 acquired mtx1\n";
    this_thread::sleep_for(chrono::milliseconds(50));  // Simulate some work

    lock_guard<mutex> lockB(mtx2);  // Trying to lock mutex 2
    cout << "Thread 1 acquired mtx2\n";
}

void thread2() {
    lock_guard<mutex> lockB(mtx2);  // Lock mutex 2
    cout << "Thread 2 acquired mtx2\n";
    this_thread::sleep_for(chrono::milliseconds(50));  // Simulate some work

    lock_guard<mutex> lockA(mtx1);  // Trying to lock mutex 1
    cout << "Thread 2 acquired mtx1\n";
}

int main() {
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
*/


// To prevent this deadlock situation there is a way of mutex and try lock

// 1) lock(mtx1, mtx2); ensures that both locks are acquired at once in a consistent order.

/*
mutex mtx1, mtx2;

void thread1() {
    lock(mtx1, mtx2);  // Acquire both locks without worrying about the order
    lock_guard<mutex> lockA(mtx1, adopt_lock);  // Adopt the locked state
    lock_guard<mutex> lockB(mtx2, adopt_lock);  // Adopt the locked state
    cout << "Thread 1 acquired both mtx1 and mtx2\n";
}

void thread2() {
    lock(mtx1, mtx2);  // Acquire both locks without worrying about the order
    lock_guard<mutex> lockA(mtx1, adopt_lock);  // Adopt the locked state
    lock_guard<mutex> lockB(mtx2, adopt_lock);  // Adopt the locked state
    cout << "Thread 2 acquired both mtx1 and mtx2\n";
}

int main() {
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
*/


// 2) Instead of waiting indefinitely, use try_lock() with a timeout to avoid blocking.

/*
mutex mtx1, mtx2;

void thread1() {
    while (true) {
        if (mtx1.try_lock()) {
            cout << "Thread 1 acquired mtx1\n";
            this_thread::sleep_for(chrono::milliseconds(50));
            if (mtx2.try_lock()) {
                cout << "Thread 1 acquired mtx2\n";
                mtx2.unlock();
            }
            mtx1.unlock();
            break;
        }
        cout << "Thread 1 failed to acquire mtx1, retrying...\n";
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void thread2() {
    while (true) {
        if (mtx2.try_lock()) {
            cout << "Thread 2 acquired mtx2\n";
            this_thread::sleep_for(chrono::milliseconds(50));
            if (mtx1.try_lock()) {
                cout << "Thread 2 acquired mtx1\n";
                mtx1.unlock();
            }
            mtx2.unlock();
            break;
        }
        cout << "Thread 2 failed to acquire mtx2, retrying...\n";
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main() {
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
*/

// Why Use try_lock() Instead of lock()?
// Non-blocking: The try_lock() function does not block the thread if the mutex is already locked. It immediately returns false.
// Efficient Retry Mechanism: The code can periodically retry without getting stuck.
// Avoids Deadlock: Unlike lock(), it helps avoid deadlock situations by allowing the thread to back off and retry later.


// Difference between sleep and wait function to delay the execution of task'

// sleep() does not release any mutex or lock while sleeping.
// wait() releases the associated mutex while waiting, allowing other threads to acquire it.

// sleep() wakes up automatically after the specified time.
// wait() wakes up only when notified by another thread using notifyOne and notifyAll fun



// Semaphore is a synchronization mechanism used to control access to a common resource in a concurrent system, such as a multi-threaded environment. It is essentially an integer counter that is used to track the number of available resources.

// Binary Semaphore (Mutex): A special case where the semaphore value can only be 0 or 1, essentially functioning like a mutex.
// Counting Semaphore: A general-purpose semaphore that can take any non-negative integer value, used to control access to a pool of resources (e.g., limiting the number of threads accessing a limited resource).

// Key Properties of Semaphores:

// 1. Initialization: The semaphore is initialized with a certain value (e.g., 1 for binary semaphore, greater than 1 for counting semaphores).
// 2. Wait (P Operation): When a thread calls `wait()` (also known as P operation), it decreases the semaphore's value. If the value is greater than 0, the thread continues execution. If the value is 0, the thread waits.
// 3. Signal (V Operation): When a thread calls `signal()` (also known as V operation), it increases the semaphore's value, potentially allowing a waiting thread to proceed.

// Why Are Semaphores Used?
// Semaphores are used to manage concurrent access to shared resources, such as:
// - Limiting the number of threads that can access a resource at the same time.
// - Preventing race conditions and ensuring mutual exclusion.
// - Coordinating threads in complex workflows.

/*
class Printer {
public:
    void print(int thread_id) {
        cout << "Thread " << thread_id << " is using the printer." << endl;
    }
};

semaphore sem(1);  // Binary semaphore, initially set to 1 (only one thread can access the printer at a time)
Printer printer;

void printJob(int thread_id) {
    sem.acquire();  // Wait operation (P): Decreases the semaphore's count. If the count is 0, thread waits.
    
    printer.print(thread_id);  // Critical section: Only one thread can print at a time.

    sem.release();  // Signal operation (V): Increases the semaphore's count, allowing another thread to proceed.
}

int main() {
    vector<thread> threads;

    // Creating multiple threads to simulate concurrent print jobs
    for (int i = 0; i < 5; ++i) {
        threads.push_back(thread(printJob, i));  // Each thread tries to use the printer
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
*/



/*
Addition of Binary string
11101
01011

sum % 2 gives the binary digit (either 0 or 1) to store at the current position.

sum / 2 gives the carry to pass to the next iteration.

Expression	Purpose
sum % 2	Get the binary digit to store
sum / 2	Calculate carry
s1[i] - '0'	Convert '0' or '1' to 0 or 1 as ascii character of 0 is 48 and 1 is 49 so 49-49 = 1
+ '0'	Convert 0 or 1 to '0' or '1'

*/



Language	Need to cast malloc?	Why?
C		void* auto-converts to any pointer type  eg . char* ptr = malloc(100); // ✅ Valid in C
C++	        void* doesn't auto-convert in C++        eg . char* ptr = (char*)malloc(100); // ✅ Required in C++




/* Difference in C and CPP structure */

Feature				C Struct		C++ Struct
Functions inside struct		❌ Not allowed		✅ Allowed
Constructors/Destructors	❌ Not allowed		✅ Allowed
Access specifiers		❌ Only public		✅ Public/Private/Protected
Typename usage			Must write struct	struct not needed on variable
Inheritance			❌ Not possible		✅ Possible


Note - : - The concept of padding is also there for classes and objects in cpp 

/* Difference in Class and Structure in CPP */

In struct, everything is public unless you specify otherwise.

In class, everything is private unless you specify otherwise.


/* Difference in malloc and new Keyword for memory allocation on heap */

Note - new keyword is only supported in C++ and not C


Feature					malloc							new
Language				C (also available in C++ for compatibility)		C++ only
Type					Standard library function (<stdlib.h> or <cstdlib>)	Operator
Purpose					Allocates raw memory (specified bytes)			Allocates memory and initializes objects (calls constructors)
Return Type				void* (requires explicit cast in C++)			Typed pointer (no cast needed, type-safe)
Initialization				No initialization (memory contains garbage)		Calls constructors; can initialize primitives (e.g., new int())
Deallocation				free()							delete (single object) or delete[] (arrays)
Error Handling				Returns NULL on failure					Throws std::bad_alloc (or returns NULL with std::nothrow)
Constructor/Destructor			Does not call constructors or destructors		Calls constructors on allocation, destructors on deallocation



/* Difference between Shallow and deep copy */

Feature			|	Shallow Copy					|	Deep Copy

Memory			|	Copies pointer value				|	Allocates new memory and copies content
Relationship		|	Original and copy share memory			|	Completely independent copies
Speed			|	Faster (only pointer copy)			|	Slower (requires memory allocation)
Memory Usage		|	Less memory usage				|	More memory usage
Freeing Memory		|	Free only once					|	Free both individually
Risk			|	High risk of bugs (double free, data clash)	|	Safer for independent modification


void deep_copy(Student *src, Student *dest) {
    dest->id = src->id;
    dest->name = (char *)malloc(strlen(src->name) + 1); // Allocate new memory
    strcpy(dest->name, src->name);                      // Copy content
}

void shallow_copy(Student *src, Student *dest) {
    dest->id = src->id;
    dest->name = src->name;  // Only the pointer is copied
}


Note :  In normal struct copy (s2 = s1), shallow copy happens by default in C.
If the struct has no pointers, then shallow copy is enough!



/* Pointer to a Constant , Constatnt Pointer , Constant Pointer pointing to a constant*/

Feature			Pointer to Constant (const T* ptr)			Constant Pointer (T* const ptr)
Syntax			const T* ptr or T const* ptr				T* const ptr
Data Modifiable?	No (cannot modify *ptr)					Yes (can modify *ptr)
Pointer Reassignable?	Yes (can change ptr)					No (cannot change ptr)
Example Declaration	const int* ptr = &a;					int* const ptr = &a;
Use Case		Read-only data access					Fixed memory location


const T* const ptr : Neither the data pointed to nor the pointer itself can be modified.

const int* ptr: Pointer to a constant int. You cannot modify the int through ptr, but you can make ptr point to a different int.

int* const ptr: Constant pointer to an int. You cannot reassign ptr to a different address, but you can modify the int it points to.




/* Static Mmeber in Class */

Aspect				Static Members				Instance Members
Storage				Single copy in static/global memory	One copy per object (heap/stack)
Lifetime			Entire program duration			Duration of the object's lifetime
Access				Via class name or object		Via object only
Memory Allocation		Allocated once at program start		Allocated per object creation
Sharing				Shared across all instances		Unique to each instance
Function Access			Can only access static members		Can access both static and instance members

example 

class MyClass {
public:
    static int staticVar; // Static member variable
    int instanceVar;      // Instance member variable

    static void staticMethod() { // Static member function
        std::cout << "Static method called" << std::endl;
    }
};

// Definition of static member outside the class
int MyClass::staticVar = 0;





