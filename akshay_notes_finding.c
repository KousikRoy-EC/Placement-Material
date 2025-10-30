// Can we write C program without main function :

// yes but we need to compile src file differently as compiler by default consider main as starting point of program 
// cc -nostartfiles test.c

// Can we write C program without any function :

// No

// Compile time erro happens mainly due to syntax or structure of program.

// Run time error happens due to seg fault , bus err within our code etc;

// Advance Syntax to declare a variable

// Storage class | type qualifier | size type | sign type | data type | variable name
// auto            const           short / long   signed       int 
// static          volatile        long long      unsigned     float
// extern                                                      charw
// register


// size of all data type is in bytes only not bits

// 1 byte = 8 bit

// 32 bit processor means it can read or write 4 byte of data simultaneouly

// in hexadecimal no each no represent 4 bit of size so 0x1234 is 2 byte no

// ASCII reference :

// a: 97 - z: 122
// A: 65 - Z: 90
// 0: 48 - 9: 57

// converting small case letter to capital letter we will do 

// char var = 'a';
// var = var - 32;  // OP - A 

// char var = 'A';
// var = var + 32;  // OP - a


// Find no is even or odd 

// int a = 32;
// int r = a & 1;

// if(r==1){
//     printf("ODD");
// }
// else{
//     printf("Even");
// }


// To find no is power of two or not 

// int res = n & (n-1)

// if(res == 0 ) then true;


// To Swap adjacent nibble of a given no or char

// for char there is 8bit only so we can directly do 

// num = n1 >> 4 | n1 << 4;

// To Clear a particular bit of a given no 

// num = num & ~(1<<pos)


// To set a particular bit of a given no 

// num = num | 1 << pos


// Toggle a particular bit in given no;

// num = num ^ (1<<pos);

// printf function return printable char count including null terminator '\0'

// printf("Hello");

// this will return 6 


// To print binary of a decimal no given;

// #include <stdio.h>

// int main(){

//     unsigned int var;
//     scanf("%u",&var);
//     printf("The No entered is : %d \n",var);

//     printf("The Binary represntaion of No : ");

//     for(int i=31;i>=0;i--){
//         printf("%d", (var>>i) & 1 );
//         if(i%8==0){
//             printf(" ");
//         }
//     }
//     return 0;
// }


// To reverse bits of a given no uisng bitwise operator

// #include <stdio.h>

// int main(){

//     unsigned int var;
//     scanf("%u",&var);
//     printf("The No entered is : %d \n",var);

//     for(int i=31,s=0;s<i;s++,i--){
//        int L = ((var >> i) & 1);
//        int R = ((var >> s) & 1);

//        if(L!=R){
//         var = var ^ (1 << i);
//         var = var ^ (1 << s);
//        }
//     }

//     printf("After Reversal the no becomes : %d \n",var);

//     return 0;
// }


// swap adjacent nibble or swap two particular nibble 

// #include <stdio.h>

// int main(){ 
//     unsigned int var;
//     scanf("%u",&var);

//     unsigned int left = var >> 4;
//     unsigned int right = var << 4
//     unsigned int res = left | right;
//     printf("After Swapping the no becomes : %d \n",res);

//     return 0;
// }


// delete particular bit from a given no

// #include <stdio.h>

// int main(){
//     unsigned int var;
//     int pos;
//     scanf("%u",&var);
//     scanf("%d",&pos);

//     unsigned int left = var >> (pos+1);
//     unsigned int right = var & ((1<<pos) - 1);   // this expression clears all the bit left to that pos including pos bit so we are left with right bit only
//     unsigned int res = (left << pos) | right;
//     printf("After Deleting the no becomes : %d \n",res);

//     return 0;
// }


// swap 5th and 7th nibble 

// #include <stdio.h>

// int main(){
//     unsigned int var=0x11223344;
//     unsigned int LEFT = (var & 0x000F0000) << 8;
//     unsigned int RIGHT = (var & 0x0F000000) >> 8;

//     unsigned int res = LEFT | RIGHT | (var & 0x0F0FFFFF);

//     printf("After Swapping the no becomes : %u \n",res);

//     return 0;
// }   



// rotating the bits of a given no

// #include <stdio.h>
// #include <limits.h>  // for sizeof

// unsigned int rotateLeft(unsigned int num, unsigned int n) {
//     unsigned int bits = sizeof(num) * 8; // usually 32
//     n = n % bits; // avoid overflow
//     return (num << n) | (num >> (bits - n));
// }

// int main() {
//     unsigned int num = 0x12345678;
//     unsigned int n = 8;

//     unsigned int result = rotateLeft(num, n);
//     printf("Before: 0x%08X\n", num);
//     printf("After rotating left by %u bits: 0x%08X\n", n, result);

//     return 0;
// }
