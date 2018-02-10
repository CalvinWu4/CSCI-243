/// file: basicShop.c
/// description: The Basic Shop is a program that offers a sequence of named customers a 
/// discount on paying prices of one or more items. 
/// author: Calvin Wu cxw7054@rit.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>
#include "shop_utils.h"

/// main expects a discount rate between 5% and 90% inclusive. After getting the rate, the main processes inputs with
/// the following format of input lines:
/// 	CustomerName // name of customer; a character string
/// 	count // number of items bought; a positive integer.
/// 	price1 // price of item 1; a positive real number.
/// 	price2 // price of item 2; a positive real number.
/// 	... // there are 'count' number of prices.
/// 	priceN // price of item N; a positive real number.
/// main issues no prompts for input. If there are any errors processing lines of input, 
/// the program prints a message/// starting with the text "error: " to the stderr output stream, 
/// and terminates with an EXIT_FAILURE code.
/// @param argc 2
/// @param argv program name, discount as a percentage (double) value
/// @return statusCode. EXIT_SUCCESS if no error, or EXIT_FAILURE

int main(int argc, char * argv[]) {
	if(argc < 2){
		printf("usage: basicShop discount\n");
		printf("	STANDARD INPUT FORMAT:\n");
		printf("	name1   // name of customer; a character string\n");
		printf("	count   // number of items bought; a positive integer.\n");
		printf("	price1  // price of item 1; a positive real number.\n");	
		printf("	price2  // price of item 2; a positive real number.\n");
		printf("	...     // there are 'count' number of prices.\n");
		printf("	priceN  // price of item N; a positive real number.\n");
		printf("	[name2...   ]\n");
		return EXIT_FAILURE;
	}
	else{
	double discount = strtod(argv[1], NUL); 
    	if ((discount > 0 && (discount > FLT_MAX || discount < FLT_MIN)) || 
			(discount < 0 && (discount < -FLT_MAX || discount > -FLT_MIN))){
		fprintf(stderr,"error: unexpected input problem.\n");
		return EXIT_FAILURE;
	}
	int count_customers = 0;
	if(discount >= .05 && discount <= .9){
		printf("Today's discount is %.2f%%.\n", discount*100);
		while(!feof(stdin)){
			char name[MAXNAME];
			char buff[MAXLINE];
			if(fgets(buff, MAXLINE, stdin)==NUL){
				break;
			}
			get_name(name, buff);
			long count = get_count();
			if(count < 1){
				fprintf(stderr, "error: bad count %ld for customer: %s", count, name);
		       		return EXIT_FAILURE;
			}		
			double prices[count];  
			count = get_prices(count, prices);
			calculate_bill(name, discount, count, prices);
			name[0] = NUL;
			buff[0] = NUL;
			count = NUL;
			prices[0] = NUL;
			count_customers++;
		}
		printf("The store closed after serving %d customers.\n", count_customers);
		return EXIT_SUCCESS;		
	}
	else{
		fprintf(stderr,"error: discount is out of range.\ndiscount must be between .05 and .90 inclusive(5%%-90%%)."); 
		return EXIT_FAILURE;
	}
	}
}
