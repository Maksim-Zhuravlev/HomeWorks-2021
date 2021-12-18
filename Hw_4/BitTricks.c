#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bitAnd(int x, int y) {         
	int result;
	
	x = ~ x;
	y = ~ y;
	result = x | y;
	result = ~ result;
	return result;
}
	
int bitXor(const int x, const int y) {          
	const int not_x = ~ x, not_y = ~ y;
	int result;
	
	result = (~ (x & y)) & (~ (not_x & not_y));
	return result;
}

int thirdBits(void) {
	const int x = 73;
	int result;
	
	result = ((((((x << 9) + x) << 9) + 73) << 9) + 73) << 2;
	return result;
}

int fitsBits(int x, int n) {
	int x_temporary, result;
	
	x = x >> (n - 1);              
	x_temporary = !(x + 1);        
	x = !x;
	result = x | x_temporary;
	return result;
}

int sign(int x) {                    
	const int not_zero = !(!x);     
	int result;
	
	x = x >> 31; 
	result = x | not_zero;        
	return result;
}

int getByte(int x, int n) {
	int result;
	
	x = x >> (n + n + n + n + n + n + n + n);   
	result = x & 0xFF;    
	return result;
}

int logicalShift(int x, int n) {
	int result;
	int temporary_var;
	int zero_n_check = ~((!!n) << 31);
	
	temporary_var = ~(1 << 31);
	x = x >> (!!n);
	x = x & (temporary_var | zero_n_check);     
	result = (x >> (!n + n - 1)) ;
	return result;
}

int addOK(int x, int y) {
	int sum = x + y;
	int sumXorX = sum ^ x;
	int sumXorY = sum ^ y;
	
	return !((sumXorX & sumXorY) >> 31);
}

int bang(int x) {
	x = x | (~x + 1);
	x = x >> 31;
	x++;
	return x;
}

int conditional(int x, int y, int z) {
	int result;
	int mask = !(!x);
	
	mask = ~mask + 1;
	result = (y & mask) | (z & ~mask);
	return result;
}

int isPower2(int x) {
	int result, not_zero, is_positive;
	
	is_positive = x >> 1;
	is_positive = is_positive & 2147483647;
	is_positive = !(is_positive >> 30);
	not_zero = !(!x);
	result = !(x & (x - 1)) & not_zero & is_positive;
	return result;
}


void main() {

}