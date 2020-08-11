/*อ้างอิงข้อมูลและวิธีการคำนวนจาก https://www.bangkokbiznews.com/news/detail/877175 */
#include<stdio.h>

double Unit, Paid; /*หน่วยไฟฟ้า จะถูก Section_price หักออกไปเรื่อยๆ, ค่าไฟรวม*/
double Price[500]; 
double service_charge = 8.19; /*ค่าบริการ*/
double Ft = -11.60; /*ค่าไฟฟ้าผันแปร*/

/*ใช้แบ่งคิดค่าไฟในแต่ละช่วง เช่นใช้ไฟ Unit=100 หน่วย แล้วจะแบ่งช่วงหน่วยที่ 1-15 คิดเป็นหน่วยละ 2 บาท จะเขียน function ว่า Section_price(2, 1, 15) และ function จะหักหน่วยไฟฟ้าที่คิดแล้วออกไป*/
void Section_price(double price, int min, int max) { 
	double paid_buffer, Unit_buffer;
	if (max == -1) { /*ถ้าใส่ค่า max = -1 function จะเอาหน่วยไฟฟ้าที่เหลือทั้งหมดมาหาค่าไฟ ไม่สนว่าจะมีอยู่กีหน่วยและจะไม่มีหน่วยไฟฟ้าเหลือให้คิดอีกภายหลัง*/
		paid_buffer = Unit * price;
		Paid += paid_buffer;
		Unit_buffer = Unit;
		Unit = 0;
		printf("Unit %d+,   Unit count : %.0lf,   Price per Unit : %.2lf,   Price +%.2lf,   Sum Price : %.2lf\n", min, Unit_buffer, price, paid_buffer, Paid);
	}
	else if (Unit >= (max - min + 1)) { /*ถ้าหน่วยไฟฟ้ามากกว่าความยาวช่วง max-min ที่รับมา จะหักหน่วยไฟฟ้าออกเท่ากับช่วง max-min และเอาหน่วยที่หักมาคูณกับค่าไฟต่อหน่วยไปรวมกับค่าไฟรวม*/
		paid_buffer = (max - min + 1) * price;
		Paid += paid_buffer;
		Unit_buffer = max - min + 1;
		Unit -= Unit_buffer;
		printf("Unit %d-%d,   Unit count : %.0lf,   Price per Unit : %.2lf,   Price + %.2lf,   Sum Price : %.2lf\n", min, max, Unit_buffer, price, paid_buffer, Paid);
	}
	else { /*ถ้ามีเศษหน่วยไฟฟ้าเหลืออยู่ จะเอาหน่วยไฟฟ้าที่เหลือทั้งหมดมาคูณค่าไฟต่อหน่วยเลย*/
		paid_buffer = Unit * price;
		Paid += paid_buffer;
		Unit_buffer = Unit;
		Unit = 0;
		printf("Unit %d-%d,   Unit count : %.0lf,   Price per Unit : %.2lf,   Price + %.2lf,   Sum Price : %.2lf\n", min, max, Unit_buffer, price, paid_buffer, Paid);
	}
	
}

int main() {
	/*ใส่ค่าไฟ*/
	/*ค่าไฟในแต่ละช่วงเมื่อใช้ไฟตำ่กว่า 150 หน่วย*/
	/*1-15 Kw/h when usage <= 150 Kw/h*/ Price[0] = 2.34;
	/*16-25 Kw/h when usage <= 150 Kw/h*/ Price[1] = 2.98;
	/*26-35 Kw/h when usage <= 150 Kw/h*/ Price[2] = 3.24;
	/*36-100 Kw/h when usage <= 150 Kw/h*/ Price[3] = 3.62;
	/*101-150 Kw/h when usage <= 150 Kw/h*/ Price[4] = 3.71;

	/*ค่าไฟในแต่ละช่วงเมื่อใช้ไฟมากกว่ากว่า 150 หน่วย*/
	/*1-150 Kw/h when usage > 150 Kw/h*/ Price[5] = 3.24;
	/*151-400 Kw/h when usage > 150 Kw/h*/ Price[6] = 4.22;
	/*400+ Kw/h when usage > 150 Kw/h*/ Price[7] = 4.42;

	printf("Enter Power Usage (Kw/h): ");
	scanf_s("%lf", &Unit); /*รับค่า*/
	if (Unit <= 150) { /*กรณีที่หน่วยไฟฟ้าที่ใช้ตำ่กว่า 150 จะแบ่งออกเป็น 5 ช่วง แต่ละช่วงจะมีราคาต่อหน่วยตั้งแต่ Price[0-4]*/
		printf("Under 150 Kw/h\n");
		Section_price(Price[0], 1, 15); /*หักคิด 15 หน่วยแรก*/
		Section_price(Price[1], 16, 25); /*หักคิด 10 หน่วยต่อมา*/
		Section_price(Price[2], 26, 35); /*หักคิด 10 หน่วยต่อมา*/
		Section_price(Price[3], 36, 100); /*หักคิด 65 หน่วยต่อมา*/
		Section_price(Price[4], 101, 150); /*หักคิด 50 หน่วยต่อมา*/
	}
	else if(Unit > 150) { /*กรณีที่หน่วยไฟฟ้าที่ใช้มากกว่ากว่า 150 จะแบ่งออกเป็น 3 ช่วง แต่ละช่วงจะมีราคาต่อหน่วยตั้งแต่ Price[5-7]*/
		printf("Over 150 Kw/h\n");
		Section_price(Price[5], 1, 150); /*หักคิด 150 หน่วยแรก*/
		Section_price(Price[6], 151, 400); /*หักคิด 250 หน่วยต่อมา*/
		Section_price(Price[7], 401, -1); /*คิดหน่วยที่เหลือ*/
	}
	printf("\nPrice : %.2lf\n", Paid); /*ค่าไฟเปล่า*/
	printf("+ Service charge 8.19 Bath : %.2lf\n", Paid += service_charge); /*บวกค่าบริการ*/
	printf("Ft %.2lf : %.2lf Bath\n", Ft, Paid += Ft); /*บวกค่าผันแปร*/
	printf("+ Vat 7%% : %.2lf Bath\n", Paid += Paid*0.07); /*บวกภาษี*/
	printf("\n Total = %.2lf Bath\n", Paid); /*ราคาจ่ายสุทธิ*/

}