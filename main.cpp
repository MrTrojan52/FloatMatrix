#include "FMatrix.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
	
	double c[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	FloatMatrix A(3, 3, c);

	A.Print();

	//A = A^2;
	cout << A.NormaMaxC() << endl;
	A.Print();
	double tmp[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	FloatMatrix D(6, 2, tmp);
	A /= 5;
	//FloatMatrix C(3, 3, 1);
	//D = A*D;
	//C = C*A;
	//C.Print();
	//B.Print();
	A.Print();
	D.Print();
	printf("\n%f\n", A.Determinant());
	A = A.SubMatrix(0, 0);
	A.Print();
	A /= A ;
	A.Print();
	printf("\n%f\n", A.Determinant());
	D =  2*D;
   
	_getch();
	
}