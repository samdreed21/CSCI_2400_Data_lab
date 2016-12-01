/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "Sare7559", 
   /* Student name 1: Replace with the full name of first team member */
   "Samuel David Reed",
   /* Login ID 1: Replace with the login ID of first team member */
   "Sare7559",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4
// rating 1
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
    return (~x & ~y);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	return ~(1 << 31); 
}
// rating 2
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int ans;
	int shiftvalue = (x >> (~0 + n)); //this value will shift x over n-1 times to the right and will return all zeros if x is a positive number and all zeros if x is a negative number.
	int xmask = (x >> 31); //this mask will create all zeros if x is positive and all 1's if x is negative
	ans = (shiftvalue ^ xmask); //if the mask and the shiftvalue have any similarities, then x will not have a two's complement that fits in n-bits. but this will return 0 for the correct answer and 1 for incorrect
	return !ans;
}
	
	/*int twos = ~x+1; 	
	int ans = twos & ~x;
	ans = (twos >> (n + ~0));
	ans = !ans;
	return ans;
	} */
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	int combinedmask;
	int ans;
	int secondmask;
	int firstmask = (1 << n); 
	firstmask = firstmask + (~0); //creates a mask for us to compare our value too.
		
	 secondmask = (x >> 31); //determines if x is negative or positive.
	 combinedmask = firstmask & secondmask; //this will add 1 if x is negative and will add nothing if x was positive. 
	
	
	ans = x + combinedmask;
	return (ans >> n);

	//performing a logical rightshift by K has the same effect as dividing by 2^k and then rounding towards zero. 
	// integer divison always rounds towards zero   
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	return !!(x^y);
//The XOR operator compares x and y and will return 0 if they are equal and a random number (depending on the numbers compared) if they are not
//The double bang operator will make a non-zero number equal to 1 and zero equal to zero, so using this returns 0 if they are the same and 
// one if they are different.
}

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
	int answer;
	 answer = ~(~x & ~y) & ~(x & y);	
  	return answer;
/* To solve this I started out by looking at the truth table for the XOR operator and then comparing it to the and operator. From there
I was able to modify my statements in order to make the truth tables line up.
*/
//see truth tables in the notebook
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
	int answer;
	answer = (x << 31);
	answer = (answer >> 31); 
  	return answer;
/* my code shifts all the bits to the right except for the least significant bit, and then copys that bit and shifts it to the left
making every number equal to the least significant bit. */
}
// rating 3
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
	int answer;	
	int x1 = (x & 0xff);
	int x2 = (x & (0xff << 8));  
	int x3 = (x & (0xff << 16));
	int x4 = (x & (0xff << 24));
	
	x4 = (x4 >> 24) & 0xff;
	x3 = x3 >> 8;
	x2 = x2 << 8;
	x1 = x1 << 24;
	
	 answer = x4 | x3 | x2 | x1;
	return answer;   
	//see notebook notes
	/* first extract each byte into a variable by comparing it to FF (and shfit ff accordingly to extract), then shift all the bytes over so they are in the proper order (x1 x3 x2 x4), then add them all together */
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	int sign = (x >> 31);
	int negop = ((1 << 31) >> (n + (~0))); //(x + (~0)) = (x -1)
	return (sign & ((x >> n)^negop)) | (~sign & (x >> n));
	/* for making if else statements without actually making the statements: Condition & A | Condation & B. where A is the negop and B is our operator for positive. */
	/* so if it is a negative number '1000', when we shift we will get a lot of 1's  '1111' and then we XOR that with a number that will give us only the initial 1 (this is where the the (n-1) comes from, so we 1111^1110 and get 0001 */ 
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	int ans1;
	int diffsigns;
	int signx = (x >> 31);
	int signy = (y >> 31); //these will be 0 if pos and 1 if neg
	
	
	int negy = ~y; //these will be useful because if x and y have the same sign, x + ~y will return a number with a sign bit of 0 (postive)[use this case to see if x is larger] 
			 // if y is larger x + ~y will return a number with a sign bit of 1

	int checksigns = !(signx ^ signy); //this will return 0 if the signs are different and 1 if the signs are the same because it's an exclusive or. the bang is necessary because if the signs are the same
					// we want to use and AND operator on the result of x + ~y so we get the sign bit
	int sumxnegy = x + negy;
	 sumxnegy = (sumxnegy >> 31); //this will give us just the sign bit of sumxnegy and we can now compare it with checksigns using AND
	
	ans1 = sumxnegy & checksigns; //this will return the signbit that tells us if x is greater than y or vise versa (0 if greater, 1 if x<y)
	
	//if they are not the same sign we know that if x is pos and y is neg, x > y and vise versa
	 diffsigns = signx & !signy; //this statement will return 0 if x is positive and y is negative [x > y] and will return a 1 if x is negative and y is positive [y > x]

	return !(diffsigns | ans1); //this or needs the bang operator because we want to return 1 for x>y and 0 for y<x because the above statements are giving 0's for x>y and 1's for y>x and that needs to be reversed
	
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
	int highmask;
	int lowmask;
	int ormask;

	 highmask = ~0;
	
	highmask = (highmask << highbit);
	highmask = (highmask << 1);

//masks all the bits to left of highbit with 1's
	 lowmask = ~(~0 << lowbit);
	
//masks all the bits to the right of lowbit with 1's	
	 ormask = (lowmask | highmask); //returns the mask with the proper digits masked with zeros, just needs to be inverted
		
	return ~ormask;

}
// rating 4
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
	int answer;
	int num = (x >> 31);
	 answer = (x ^ num) + ((~num) +1);
	return answer;
	/* with a positive number, if you shift x over by 31 you will get 0, then if you xor that with the original number you get the original number (the ~sign and +1 will cancel each other out
	because ~(0000) = -1). */	 
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
// I was unable to figure out the bitcount completely on my own, I ended up using sources such as StackOverflow, but because I was not able to solve it completely on my own, I am commenting it out and taking
// the hit on my overall score. If this question comes up on the interview, I will be able to answer questions about the process, I just didn't want to risk being at fault for not completely doing my own
// work. the code below was just me trying to figure out a solution, it gives a 4/4 on btest, but because I didn't do it completely myself I am not using it.
	/*int count, holder, containermask, sumshifter;
	int sum;	

	int masklsb = 0x11 | (0x11 << 8); //this creates a mask that is 0001 0001 0001 0001. this will let us apply this mask to test the two lsbs in the first two bytes
	int masklsb2 = (masklsb | (masklsb << 16)); //this will create the mask 0001 0001 0001 0001 0001 0001 0001 0001 which masks the lsbs in the last two bytes and first two bytes
	sum = (x & masklsb2); //applies masklsb2 which will find the lsb of each nibble in x
	//x = 00000100011111000010010010001010
	//sum=100000000000000000000
	sum = sum + ((x >> 1) & masklsb2); //applies masklsb2 to the second bit of each byte and determines if there is a 1 or not there or not
	//x>>1 = 10001111100001001001000101
	//sum=100000001000000000001 + 100000000000000000000 = 1000000001000000000001
	sum = sum + ((x >> 2) & masklsb2); //applies masklsb2 to the third bit of each byte and determines if there is a 1 or not
	//x>>2 = 1000111110000100100100010	
	//sum = 1000100010000000100000000 + 1000000001000000000001 = 1001100010001000100000001
	sum = sum + ((x >> 3) & masklsb2); //applies masklsb3 to the fourth bit of each byte and determines if there is a 1 or not
	//x>>3 = 100011111000010010010001
	//sum = 10000000000010001 + 1001100010001000100000001 = 1001100100001000100010010
	sum = sum + (sum >> 16); //this will remove and extra bits we didnt add to the total sum (because when adding the answers together there is sometimes a carry over)
	//sum >> 16 = 100110010
	//sum = 1001100100001000100010010 + 100110010 = 1001100100001001001000100
	 containermask = (0xf | (0xf << 8)); //this is a new mask now will maintain the bits we've already checked
	//containermask = 111100001111
	 holder = (containermask & sum); //applies are new mask to the current sum and stores the value
	//holder = 100
	sum = holder + ((sum >> 4) & containermask); 
	//sum = 100 + (100110010000100100100 + 1001100100001001001000100) = 1010001010011001101101100
	sumshifter = (sum + (sum >> 8)); //when we shift the current sum over by 8 and add it to the original sum here
	//sumshifter = 1010001010011001101101100 + 10100010100110011 = 1010001100111100010011111
	count = (sumshifter & 0x3F); //because the maxium size of integer we can have is 32, only need to mask 6 bits for the final sum. this is the correct answer
	
	return count;*/
return 2;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
	int num1 = ~x + 1; //two's complement of the number
	int num2 = (num1 >> 31); 	//creates either all zeros or a number that has a 1 as the least significant bit (far left);
	int num3 = (x >> 31);		//creates a number with all zeros or all 1's
	int ornum = num2 | num3;	//comparing these numbers with or will give you either all zeros (if the value is zero) or your num1. 
	return ornum & 1; 		//comparing the result of the above with the value 1 will either give you all zeros (if original number is zero) or 00000...1 if the number was nonzero.
	
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	int ans;
	int twosx = ~x +1; //take the twos' complement of x to get it's negative
	int signx = (twosx | x);//if we use the OR comparison with x and it's negative we will get a 0 in the sign bit (most signifcant bit) if x is 0 and we will get a 1 if x is nonzero
	ans = (signx >> 31); //by shifting signx 31 to the right, we will get all 1's if the sign bit was non-zero and all zeros if the sign bit was 0, this is close but we need to return 0 if x!=0 and 1 if x=0. 
				// we know that -1 +1 =0 and all 1's = -1, and 0+1=1 so if we add one to ans we will get the desired outcome.
	return (ans + 1);
}











