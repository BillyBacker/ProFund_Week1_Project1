#include<stdio.h>

double Unit, Paid;
double Price[500];
double service_charge = 8.19;
double Ft = -11.60;

void Section_price(double price, int min, int max) {
	double paid_buffer, Unit_buffer;
	if (max == -1) {
		paid_buffer = Unit * price;
		Paid += paid_buffer;
		Unit_buffer = Unit;
		Unit = 0;
		printf("Unit %d+,   Unit count : %.0lf,   Price per Unit : %.2lf,   Price +%.2lf,   Sum Price : %.2lf\n", min, Unit_buffer, price, paid_buffer, Paid);
	}
	else if (Unit >= (max - min + 1)) {
		paid_buffer = (max - min + 1) * price;
		Paid += paid_buffer;
		Unit_buffer = max - min + 1;
		Unit -= Unit_buffer;
		printf("Unit %d-%d,   Unit count : %.0lf,   Price per Unit : %.2lf,   Price + %.2lf,   Sum Price : %.2lf\n", min, max, Unit_buffer, price, paid_buffer, Paid);
	}
	else {
		paid_buffer = Unit * price;
		Paid += paid_buffer;
		Unit_buffer = Unit;
		Unit = 0;
		printf("Unit %d-%d,   Unit count : %.0lf,   Price per Unit : %.2lf,   Price + %.2lf,   Sum Price : %.2lf\n", min, max, Unit_buffer, price, paid_buffer, Paid);
	}
	
}

int main() {
	/* Enter Power price here*/
	/*1-15 Kw/h when usage <= 150 Kw/h*/ Price[0] = 2.34;
	/*16-25 Kw/h when usage <= 150 Kw/h*/ Price[1] = 2.98;
	/*26-35 Kw/h when usage <= 150 Kw/h*/ Price[2] = 3.24;
	/*36-100 Kw/h when usage <= 150 Kw/h*/ Price[3] = 3.62;
	/*101-150 Kw/h when usage <= 150 Kw/h*/ Price[4] = 3.71;

	/*1-150 Kw/h when usage > 150 Kw/h*/ Price[5] = 3.24;
	/*151-400 Kw/h when usage > 150 Kw/h*/ Price[6] = 4.22;
	/*400+ Kw/h when usage > 150 Kw/h*/ Price[7] = 4.42;
	scanf_s("%lf", &Unit);
	if (Unit <= 150) {
		printf("Under 150 Kw/h\n");
		Section_price(Price[0], 1, 15);
		Section_price(Price[1], 16, 25);
		Section_price(Price[2], 26, 35);
		Section_price(Price[3], 36, 100);
		Section_price(Price[4], 101, 150);
	}
	else if(Unit > 150) {
		printf("Over 150 Kw/h\n");
		Section_price(Price[5], 1, 150);
		Section_price(Price[6], 151, 400);
		Section_price(Price[7], 401, -1);
	}
	printf("\nPrice : %.2lf\n", Paid);
	printf("+ Service charge 8.19 Bath : %.2lf\n", Paid += service_charge);
	printf("Ft %.2lf : %.2lf Bath\n", Ft, Paid += Ft);
	printf("+ Vat 7%% : %.2lf Bath\n", Paid += Paid*0.07);
	printf("\n Total = %.2lf Bath\n", Paid);

}