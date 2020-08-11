#include<stdio.h>

int main() {
	/* Enter Power price here*/
	/*1-150 Kw/h*/ double Price1 = 3.24;
	/*151-400 Kw/h*/ double Price2 = 4.22;
	/*400+ Kw/h*/ double Price3 = 4.42;
	double Unit, Paid;
	scanf_s("Enter Power usage (Kw/h) : &.2lf", &Unit);
	if (Unit <= 150 and Unit > 0){
		Paid = Unit * Price1;
		printf_s("Price : &.2lf", Paid);
	}
	else if (Unit <= 400 and Unit > 150){
		Paid = Unit * Price2;
		printf_s("Price : &.2lf", Paid);
	}
	else if (Unit > 400){
		Paid = Unit * Price3;
		printf_s("Price : &.2lf", Paid);
	}
	else {
		printf_s("Error");
	}

}