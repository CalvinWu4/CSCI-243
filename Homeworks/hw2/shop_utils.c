/// file: shop_utils.c
/// description: Utility functions for a shop
/// author: Calvin Wu cxw7054@rit.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include "shop_utils.h"


/// Return true IFF first alphabetic token was copied from buff into name.
bool get_name(char name[], char buff[]){
	if(isalpha(buff[0])){
		strncpy(name, buff, MAXNAME);
		return true;
	}
	else{
		strncpy(name, buff, MAXNAME);		
		fprintf(stderr, "error: invalid name %s.\nerror: input did not contain a name.\n", name);	
		name = NUL;
		return false;
		EXIT_FAILURE;
	}
}	

/// Fetch the count of items purchased from stdin.
long get_count(void){
	char count[MAXLINE];
	fgets(count,MAXLINE,stdin);
	return strtol(count,NUL,10);
}

/// Fetch up to count prices from stdin and put into the prices array.
long get_prices(long count, double prices[]){
	long i = 0;
	char line[MAXLINE];
	while(i < count){
		fgets(line, MAXLINE, stdin);
		double d = strtod(line, NUL); 
    		if ((d > 0 && (d > FLT_MAX || d < FLT_MIN)) || (d < 0 && (d < -FLT_MAX || d > -FLT_MIN))){
			fprintf(stderr,"error: unexpected input problem.\n");
			return i;
		}
		else{
			prices[i] = d;
			i++;
		}
	}
	return i;
}

/// Calculate and present the bill and savings for this shopper's actions.
void calculate_bill(char name[], double discount, long count, double prices[]){
	double total = 0;
	double savings = 0;
	printf("Customer: %s", name);
	printf("	List $	Sale $\n");
	for(int i = 0; i < count; i++){
		printf("	$ %.2f	$ %.2f\n", prices[i], prices[i] - prices[i] * discount);
		total += prices[i] - (prices[i] * discount);
		savings += prices[i] * discount;
	}
		printf("Total: $%.2f. Savings: $%.2f.\n", total, savings);
}
