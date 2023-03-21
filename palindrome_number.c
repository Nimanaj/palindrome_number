#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_palindrome_number(int num){
	int length = floor(log10(abs(num))) + 1;
	char str[length];
	int l = length;
	for(int i = 0; i < length; i++){
		int digit = num % 10;
		num = num / 10;
		str[i] = digit + '0';
	}
	
	for(int i = 0; i < length; i++){
		if(str[i] != str[l -1]){
			return false;
		}
		l--;
	}
	return true;
}

void test_equals_b(bool result, bool expected, int line){
	if(result == expected){
		printf("Test pass.\n");
	} else {
		printf("The test faild in line: %d.].\n", line);
	}
}

void main(){
	int num = 121;
	test_equals_b(is_palindrome_number(num), true, __LINE__);
	num = -123;
	test_equals_b(is_palindrome_number(num), false, __LINE__);
	num = 123;
	test_equals_b(is_palindrome_number(num), false, __LINE__);
}