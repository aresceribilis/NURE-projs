#include "Polynomial.h"

int main() {
	setlocale(LC_ALL, "Russian");
    Polynomial_info* data0 = new Polynomial_info(7, 1.1);
    Polynomial_info* data1 = new Polynomial_info(7, -2.2);
    Polynomial_info* data2 = new Polynomial_info(0, -3.3);
	Polynomial_info* data3 = new Polynomial_info(1, 4.4);

	Polynomial_info* data4 = new Polynomial_info(7, 5.);
	Polynomial_info* data5 = new Polynomial_info(1, -6.);
	Polynomial_info* data6 = new Polynomial_info(0, 7.);
	Polynomial_info* data7 = new Polynomial_info(5, -8.);
	Polynomial_info* data8 = new Polynomial_info(1, -9.);

	Polynomial_info* datas0[4] = { data2 , data1, data0, data3 };
	Polynomial_info* datas1[4] = { data0 , data1, data2, data3 };
	Polynomial_info* datas2[5] = { data4 , data5, data6, data7, data8 };

    Polynomial* pol1 = new Polynomial;
	std::cout << pol1->push(4, datas1) << std::endl;
	std::cout << pol1->push(5, datas2) << std::endl;
	std::cout << *pol1;
	Polynomial* pol2 = new Polynomial;
	pol2->push(3, datas2);
	std::cout << *pol2;
	
	std::cout << "\n\n";
	Polynomial pol3 = *pol1 + *pol2;
	std::cout << pol3;
	pol3 = pol3 - *pol2;
	Polynomial_info* data04 = new Polynomial_info(15, 4.4);
	pol3 = pol3 + *data04;
	std::cout << pol3;

	std::cout << "\n\nDoes pol1 and pol3 are equal?";
	*pol1 == *pol2 ? std::cout << "\nPolynomials are equal!!!\n\n" : std::cout << "\nPolynomials are not equal\n\n";
	Polynomial* pp1 = new Polynomial;
	Polynomial* pp2 = new Polynomial;
	pp1->push(4, datas1);
	pp2->push(4, datas0);
	std::cout << "Does pp1 and pp2 are not equal?";
	*pp1 != *pp2 ?  std::cout << "\nPolynomials are not equal\n\n" : std::cout << "\nPolynomials are equal!!!\n\n";

	std::cout << "\n\n";
	std::cout << *pol1;
	std::cout << "when x = 0, pol1 = " << (*pol1)(0.) << "\n";
	std::cout << "when x = 1, pol1 = " << (*pol1)(1.) << "\n";
	std::cout << "when x = -1.01,  pol1 = " << (*pol1)(-1.01) << "\n\n";

	/*Polynomial* pp3 = new Polynomial;
	std::cout << (*pp3)(-1.) << "\n";*/

	std::cout << "\n\n";
	std::cout << "pol1[0] = " << (*pol1)[0] << "\n";
	std::cout << "pol1[1] = " << (*pol1)[1] << "\n";
	std::cout << "pol1[2] = " << (*pol1)[2] << "\n";
	std::cout << "pol1[3] = " << (*pol1)[3] << "\n\n";
	/*std::cout << (*pol1)[4] << "\n";
	std::cout << (*pol1)[5] << "\n";*/
	/*Polynomial* pp3 = new Polynomial;
	std::cout << (*pp3)[1] << "\n";*/

	std::cout << "\nPOINT 1\n";
	Polynomial* pp3 = new Polynomial;
	Polynomial* pp4 = new Polynomial;
	*pp4 = *pp3 + *data0;
	*pp4 = *pp4 + *data1;
	*pp4 = *data0 + *pp4;
	*pp4 = *pp4 + *pp4;
	*pp4 = *pp4 + *pp4;
	*pp4 = *pp4 + *pp4;
	std::cout << *pp4;

	std::cout << "\nPOINT 2\n";
	Polynomial* pp5 = new Polynomial;
	*pp5 = *pp5 - *pp5;
	std::cout << *pp5;

	std::cout << "\nPOINT 3\n";
	Polynomial* pp6 = new Polynomial;
	std::cout << *pol1;
	*pp6 = *pol1;
	std::cout << *pp6;
	*pp6 = *pp6 * 3.001;
	std::cout << *pp6;
	*pp6 = 0 * *pp6;
	std::cout << *pp6;
	*pp6 = 0 * *pp6;
	std::cout << *pp6;

	std::cout << "\nPOINT 4\n";
	Polynomial_info* data01 = new Polynomial_info(0, 0);
	Polynomial_info* data02 = new Polynomial_info(0, 1.5);
	Polynomial_info* data03 = new Polynomial_info(0, 0);
	Polynomial_info* datas00[3] = { data01, data02, data03 };
	Polynomial* pol4 = new Polynomial(3, datas00);
	std::cout << *pol4;

	std::cout << "\nPOINT 5\n";
	std::cout << *pp6;
	std::cout << *pol4;
	std::cout << "\nPOINT 6\n";
	*pp6 = std::move(*pol4);
	std::cout << *pp6;
	std::cout << *pol4;

	std::cout << "\nPOINT 7\n";
	delete pol1;
	Polynomial pp7(std::move(*pp6));
	std::cout << *pp6;
	std::cout << "\nPOINT 8\n";
	delete pol2;
	std::cout << pp7;

	return 0;
}