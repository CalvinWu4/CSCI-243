/// file: shop_utils.h
/// description: interface for shop utility functions
/// @author Calvin Wu cxw7054@rit.edu

#include <stdbool.h>
#ifndef SHOP_UTIL
#define SHOP_UTIL

/// the null char value.
#define NUL '\0'

/// maximum length of a line of input text
#define MAXLINE 80

///maximum length of C string arrays
#define MAXNAME 20

/// get_name extracts the first C string 'token' from the buffer and fills the name array with the string's values. If the buffer has no token starting with an alphabetic character, then get_name assigns a NULL C string to name and returns false.
/// @param name 	an array that will hold a C string; array entries change
/// @param buff 	an array that holds a text input C string
/// @return bool	true if there was an alphanumeric token, and false otherwise
bool get_name(char name[], char buff[]);

/// Fetch the count of items purchased from stdin.
/// @return count	the number of items in the shopping excursion
long get_count(void);	

/// get_prices gets the prices of the items for the current shopper. get_prices fetches the prices from stdin.
/// @param count	the number of price values to get
/// @param prices	the array to fill with values
/// @return		the number of prices actually received
long get_prices(long count, double prices[]);		

/// calculate_bill computes and prints the prices and savings for the bill of sale represented by the collection of prices of items.
/// @param name		an array that holds the name of the shopper
/// @param discount	the discount multiplier for all prices
/// @param count	the number of valid price values in the prices array
/// @param prices	the array of price values
void calculate_bill(char name[], double discount, long count, double prices[]); 

#endif // SHOP_UTIL
