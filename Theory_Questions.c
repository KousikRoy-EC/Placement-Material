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
