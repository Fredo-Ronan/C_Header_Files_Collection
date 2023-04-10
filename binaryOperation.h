/*
	v1.0.0
	Created by Fredo Ronan
	<https://github.com/Fredo-Ronan>
	=========== {IMPORTANT NOTE} ===========

	To use this binaryOperation.h, you must define the constant "bits" inside your own header file
	before include this header file

	EXAMPLE :

		asume this is your includes of your main.c program

		``
		#include <stdio.h>
		#include <stdlib.h>
		``

		You must define the constant "bits" just after those include like this

		``
		#include <stdio.h>
		#include <stdlib.h>
		#define bits {integer number} ---> e.g #define bits 8
		``

		After that, you can include this header file inside your project directory like this

		``
		#include <stdio.h>
		#include <stdlib.h>
		#define bits 8
		#include "binaryOperation.h"
		``
	That will make your constant more flexible to change the size or the length of bit in binary
*/


/*
	can be use to initialize the array of character for store the binary values
*/
void init_binaries(char binary[])
{
	int i;

	for(i=0;i<bits;i++)
	{
		binary[i] = ' ';
	}
}


/*
	Convert from binary to decimal and return integer decimal result (return value "int")

	{IMPORTANT}
	Use array of character to store the binary value
*/
int binary_to_decimal(char binary[])
{
	int pangkat = 7;
	int i, j, kali;
	int hasil = 0;
	
	for(i=0;i<bits;i++)
	{
		kali = 1;
		if(binary[i]=='1')
		{
			for(j=0;j<pangkat;j++)
			{
				kali = kali * 2;
			}
			
			hasil = hasil + kali; 
		}
		
		pangkat--;
	}
	
	return hasil;
}


/*
	Convert from decimal to binary (no return value "void")

	Use binary array of character to store the binary and put into
	the char binary[] parameter
*/
void decimal_to_binary(int decimal, char binary[])
{
	int i;
	int decimalTemp = decimal;
	
	for(i=7;i>=0;i--)
	{
		if(decimalTemp%2==0)
		{
			binary[i] = '0';
		}
		else
		{
			binary[i] = '1';
		}
		decimalTemp = decimalTemp/2;
	}
}


/*
	Convert long data type decimal to binary (no return value "void")


	1. Use binary array of character to store the binary and put into
	  the char binary[] parameter for the output

	2. This function takes the long data type of decimal value to convert
	  into binary

	{MAIN PURPOSE}
	3. Usefull for converting decimal value with long data type to binary
*/
void decimal_to_binary_long(long decimal, char binary[]){
	long i;
	long decimalTemp = decimal;
	
	for(i=bits-1;i>=0;i--)
	{
		if(decimalTemp%(long)2==0)
		{
			binary[i] = '0';
		}
		else
		{
			binary[i] = '1';
		}
		decimalTemp = decimalTemp/2;
	}
}