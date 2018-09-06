/*
******************************************************************
**       Advanced Encryption Standard implementation in C.      **
**       By Niyaz PK                                            **
**       E-mail: niyazlife@gmail.com                            **
**       Downloaded from Website: www.hoozi.com                 **
******************************************************************
This is the source code for encryption using the latest AES algorithm.
AES algorithm is also called Rijndael algorithm. AES algorithm is 
recommended for non-classified by the National Institute of Standards 
and Technology(NIST), USA. Now-a-days AES is being used for almost 
all encryption applications all around the world.

THE MAIN FEATURE OF THIS AES ENCRYPTION PROGRAM IS NOT EFFICIENCY; IT
IS SIMPLICITY AND READABILITY. THIS SOURCE CODE IS PROVIDED FOR ALL
TO UNDERSTAND THE AES ALGORITHM.

Comments are provided as needed to understand the program. But the 
user must read some AES documentation to understand the underlying 
theory correctly.

It is not possible to describe the complete AES algorithm in detail 
here. For the complete description of the algorithm, point your 
browser to:
http://www.csrc.nist.gov/publications/fips/fips197/fips-197.pdf

Find the Wikipedia page of AES at:
http://en.wikipedia.org/wiki/Advanced_Encryption_Standard
******************************************************************
*/

// Include stdio.h for standard input/output.
// Used for giving output to the screen.
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// The number of columns comprising a state in AES. This is a parameter
// that could be 4, 6, or 8.  For this example we set it to 4.
#define Nb 4

// xtime is a macro that finds the product of {02} and the argument to
// xtime modulo {1b}  
#define xtime(x)   ((x<<1) ^ (((x>>7) & 1) * 0x1b))

unsigned char multiply(unsigned char a, unsigned char b) {
   int i;

   unsigned char c = 0;
   unsigned char d = b;

   for (int i=0 ; i < 8 ; i++) {
      if (a%2 == 1) c ^= d;
      a /= 2;
      d = xtime(d);
   }
   return c;
}

// MixColumns function mixes the columns of the state matrix
void MixColumns(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
   int i;
   unsigned char Tmp,Tm,t,e,f,g,h;
   t = a;
   Tmp = a ^ b ^ c ^ d;
   Tm = a ^ b ; 
   Tm = xtime(Tm); 
   e = Tm ^ Tmp ^ a ;
      
   Tm = b ^ c; 
   Tm = xtime(Tm); 
   f = Tm ^ Tmp ^ b;

   Tm = c ^ d ; 
   Tm = xtime(Tm); 
   g = Tm ^ Tmp ^ c;

   Tm = d ^ t ; 
   Tm = xtime(Tm); 
   h = Tm ^ Tmp ^ d;
   printf("output: a=0x%02x b=0x%02x c=0x%02x d=0x%02x\n",e,f,g,h);
}

unsigned char htoi(char *x) {
   unsigned char y = 0;
   if (x[1] == 'x' || x[1] == 'X') {
      unsigned char a, b;
      if (x[2]-'0' < 10) a = (x[2]-'0')*16; 
      else if (x[2]-'A' < 6 && x[2] -'A' >= 0) a = (x[2]-'A'+10)*16;
      else a = (x[2]-'a'+10)*16;
      if (x[3]-'0' < 10) b = x[3]-'0'; 
      else if (x[3]-'A' < 6 && x[3] -'A' >= 0) b = x[3]-'A'+10;
      else b = x[3]-'a'+10;
      y = a + b;
   } else y = atoi(x);
   return y;
}

int main(int argc, char **argv) {
   int i;
   
   if (argc != 5) {
      cerr << "Usage: " << argv[0] << " <num> <num> <num> <num>\n";
      cerr << "  test of mixcolumn function\n";
      exit(0);
   }

   unsigned char a = htoi(argv[1]);
   unsigned char b = htoi(argv[2]);
   unsigned char c = htoi(argv[3]);
   unsigned char d = htoi(argv[4]);

   printf("input: a=0x%02x(%d) b=0x%02x(%d) c=0x%02x(%d) d=0x%02x(%d)\n",
	  a, a, b, b, c, c, d, d);
   MixColumns(a, b, c, d);
}
