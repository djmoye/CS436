//BEGIN:A program to illustrate buffer overflow
//vulnerability

#include<stdio.h>
#include<string.h>

void func(char *str) {
   char buffer[24];
   // Get the address of an object on the stack
   int *ret;
   // Move ret by the number of items in the stack before the return 
   // address to point to the location of the return address from this function.
   ret = buffer + 40;
   // Modify the return address by adding to it the offset to the command to go to.
   (*ret) += 22;
   strcpy(buffer,str);
}

int main(int argc, char **argv) {
   int x;
   x = 0;
   func(argv[1]);
   x = 1;
   printf("x is 1");
   printf("x is 0");
}

//END
//Some of you might be looking for the command to disable 
//stack overflow protection on linux platforms. The following 
//command should work (i.e., compiling your source code, 
//say overflow.c, with a specific flag on):
//>> gcc overflow.c -o overflow -fno-stack-protector
