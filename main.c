/*
	Author: Gamal Othman
	Email: gamalothman93@gmail.com
	Date: 22 May 2019

	Visualizing Bubble Sort Process
*/


#include <stdio.h>
#include "types.h"
#include "colors.h"

#define ARRAY_LEN		10

u32 unsorted_array[ ARRAY_LEN ] = { 3, 5, 2, 1, 9, 0, 4, 8, 6, 7 };

// print array (array) of length (length)
void
printArray( u32 * array, u32 length )
{
	while( length-- > 1 )
	{
		printf("%d, ", *array++);
	}

	printf("%d", *array);	// print last element
	putchar('\n');
}

// print array with a colored element
void
printArray_colored( u32 * array, u32 length, u32 colorIndex, u8 * color )
{
	u32 * p;
	// loop thru the array
	for( p = array; p < array + length; p++ )
	{
		// if you found element to be colored
		// print it with color (color)
		if( p == array + colorIndex )
		{
			printf( "%s" "%d" RESET_COLOR, color, *p );
		}
		else // normal print
		{
			printf("%d", *p);
		}

		// print comma while it is not the last element
		if( p < array + length - 1 )
		{
			printf(", ");
		} else{}
	}

	putchar('\n');
}

// swap two elements in an array
void
swap( u32 * p, u32 * q )
{
	u32 temp = *p;
	*p = *q;
	*q = temp;
}

// Bubble sort an array
// sorts (arr) of length (length)
void
bubbleSort( u32 * array, u32 length )
{
	u32 * p = NULL;
	u8 flag = 0;

	// repeat the bubble, and every take the last element is put
	// in it's right place, so neglect it
	for( ; length > 0; length--, flag = 0 )
	{
		// loop thru the array, compare each element with the one
		// after it, and bubble it forward if it is bigger
		for( p = array; p < array + length - 1; p++ )
		{
			if( *p > *(p+1) )
			{
				swap( p, p+1 );
				flag = 1;
			}
		}

		// if no swap on a complete loop
		// then array is sorted, so exit
		if( !flag )
			break;
	}
}

// Bubble Sort Visualised with colors and step by step
void
bubbleSort_visualised( u32 * array, u32 length )
{
	u32 * p = NULL;
	u8 swapFlag = 0;
	u8 loopNum = 1;

	printf( BRI_WHI_COLOR "\n*** Visualizing Bubble Sort ***\n" RESET_COLOR );
	printf("\nOriginal Array = ");
	printArray( unsorted_array, ARRAY_LEN );
	printf(BRI_RED_COLOR "Red: " RESET_COLOR "swap happend\n" );
	printf(BRI_GRN_COLOR "Green: " RESET_COLOR "no swap happend\n" );

	// repeat the bubble, and every take the last element is put
	// in it's right place, so neglect it
	for( ; length > 0; length--, swapFlag = 0 )
	{
		printf( "\nBubble %d:\n", loopNum++ );

		// loop thru the array, compare each element with the one
		// after it, and bubble it forward if it is bigger
		for( p = array; p < array + length - 1; p++ )
		{
			// if element is bigger than the one after it, 
			// bubble it forward and print it in red.
			// else, print it green.
			if( *p > *(p+1) )
			{
				swap( p, p+1 );
				swapFlag = 1;
				printArray_colored( unsorted_array, ARRAY_LEN, p - array, BRI_RED_COLOR );
			}
			else
			{
				printArray_colored( unsorted_array, ARRAY_LEN, p - array, BRI_GRN_COLOR );
			}
		}

		// if no swap on a complete loop
		// then array is sorted, so exit
		if( !swapFlag )
			break;
	}
}

int main( void )
{
	bubbleSort_visualised( unsorted_array, ARRAY_LEN );

	puts("\n");
	return 0;
}