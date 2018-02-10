/// 
/// File: triangle.c 
/// 
/// A program to print out multiple triangles "right-up" triangles.
/// of the form:
///     *
///   ***
/// *****
/// 
/// @author TODO_AUTHOR_ID_ : Calvin Wu
/// 
// // // // // // // // // // // // // // // // // // // // // // // // 

// TODO_ADD_#INCLUDES_ HERE

#include <stdio.h>	//printf
#include <math.h>	//modulo 
#include <stdlib.h>	//return EXIT_SUCCESS



/**
 *  Function: drawTriangle
 *
 *  Description: function to draw a triangle whose height/width is "size"
 * 
 *  @param size  the size of the triangle to draw
 */
// TODO_WRITE_DRAWTRIANGLE_FUNCTION HERE

int drawTriangle (int size) {
	if (size % 2 == 0) {    //incr by 1 if even
		size+=1;
	}
	if (size == 1) {    //don't right justify if 1
        printf("*\n");
        printf("\n");
	}
	else{
		for (int i = 1; i <= size; i+=2) { //rows
		    int count = size - i;   //right justify
		    while(count>0) {
		        printf(" ");
		        count-=1;
		    }
		    for (int j = 1; j <= i; j++) {  //columns
		        printf("*");
		    }
		    		printf("\n");
		}
		printf("\n");
	}
	return 0;
}
/**
 *  Function: main 
 *
 *  Description: program to draw 3 triangles of size 1, 4, and 6.
 *
 *  @returns errorCode  error Code; EXIT_SUCCESS if no error
 */
// TODO_WRITE_MAIN_FUNCTION HERE

int main () {
	drawTriangle(1);
	drawTriangle(4);
	drawTriangle(6);
	return EXIT_SUCCESS; 
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 

