#define SIZE 13
#define LEN 50
#define DOWN_ARROW 80
#define UP_ARROW 72

#include "FMatrix.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int menu(); 
void info(FloatMatrix &);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	FloatMatrix A(3, 3);
	FloatMatrix B(3, 3);
	do
	{
		int choice = menu();
	
		switch (choice)
		{
		
		case 1:
		{
			int r = -1, c = -1;
			cout << "Count of rows: ";
			while (r <= 0)
			{
				cin >> r;
			}
			cout << endl << "Count of columns: ";
			while (c <= 0)
			{
				cin >> c;
			}

			A = FloatMatrix(r, c);
			cin >> A;
			break;
		}
		case 2:
		{
			int r = -1, c = -1;
			cout << "Count of rows: ";
			while (r <= 0)
			{
				cin >> r;
			}
			cout << endl << "Count of columns: ";
			while (c <= 0)
			{
				cin >> c;
			}

			B = FloatMatrix(r, c);
			cin >> B;
			break;
		}
		case 3:
			cout << A;
			_getch();
			break;
		case 4:
			cout << B;
			_getch();
			break;
		case 5:
			cout << endl << "A * B" << endl << A * B << endl;
			cout << endl << "B * A" << endl << B * A << endl;
			_getch();
			break;
		case 6:
		{ 
			int k;
			cout << "Enter a number: ";
			cin >> k;
			cout << endl << k << " * A" << endl << k * A << endl;
			cout << endl << k << " * B" << endl << k * B << endl;
			_getch();
			break;
		}
		case 7:
			cout << endl << "A / B" << endl << A / B << endl;
			cout << endl << "B / A" << endl << B / A << endl;
			_getch();
			break;
		case 8:
		{
			int k;
			cout << "Enter a number: ";
			cin >> k;
			cout << endl << "A / " << k << endl <<  A / k << endl;
			cout << endl << "B / " << k << endl <<  B / k << endl;
			_getch();
			break;
		}
		case 9:
			cout << endl << "A + B" << endl << A + B << endl;
			_getch();
			break;
		case 10:
			cout << endl << "A - B" << endl << A - B << endl;
			cout << endl << "B - A" << endl << B - A << endl;
			_getch();
			break;
		case 11:
		{

			info(A);
			_getch();
			break;
		}
		case 12:
			info(B);
			_getch();
			break;
		case 13:
			return 0;
		default:
			break;
		}
	} while (true);
}


void info(FloatMatrix &M)
{
	cout << "------------------------------------------\n";
	cout << "rows = " << M.get_rows() << "\ncolumns = " << M.get_columns();
	cout << "\n------------------------------------------\n";
	cout << M << endl;
	cout << "\n------------------------------------------\n";
	cout << "Determinant = " << M.Determinant();
	cout << "\n------------------------------------------\n";
	cout << "Norma sqrt = " << M.NormaSqrt();
	cout << "\n------------------------------------------\n";
	cout << "Norma by Rows = " << M.NormaMaxR();
	cout << "\n------------------------------------------\n";
	cout << "Norma by Columns = " << M.NormaMaxC();
	cout << "\n------------------------------------------\n";
	cout << "Transpose matrix \n" << M.transpose();
	cout << "\n------------------------------------------\n";
	cout << "Inverse matrix \n" << M.inverse();
	cout << "\n------------------------------------------\n";
	if (M.IsSquare())
		cout << "Square";
	else
		cout << "Not Square";
	cout << "\n------------------------------------------\n";
	if (M.IsDiagonal())
		cout << "Diagonal";
	else
		cout << "Not Diagonal";
	cout << "\n------------------------------------------\n";
	if (M.IsNull())
		cout << "Null matrix";
	else
		cout << "Not Null";
	cout << "\n------------------------------------------\n";
	if (M.IsE())
		cout << "Is E-matrix";
	else
		cout << "Not E-matrix";
	cout << "\n------------------------------------------\n";
	if (M.IsSymmetric())
		cout << "Is Symmetric";
	else
		cout << "Not Symmetric";
	cout << "\n------------------------------------------\n";
	if (M.IsUTriangle())
		cout << "Upper triangular matrix";
	else
		cout << "Not Upper triangular matrix";
	cout << "\n------------------------------------------\n";
	if (M.IsDTriangle())
		cout << "Lower triangular matrix";
	else
		cout << "Not Lower triangular matrix";
	cout << "\n------------------------------------------\n";
	

}


int menu()
{
	char a[SIZE][LEN] = {
		"Enter matrix A",
		"Enter matrix B",
		"Print matrix A",
		"Print matrix B",
		"A * B (B * A)",
		"k * A (k * B)",
		"A / B (B / A)",
		"A / k (B / k)",
		"A + B",
		"A - B (B - A)",
		"Info(A)",
		"Info(B)",
		"Exit"

		
	};


	int choice = 0;
	int Key = 0;



	do
	{
		system("cls");
		for (int i = 0; i < SIZE; i++)
		{
			if (choice == i)
			{
				cout << "\t>> " << a[i] << endl << endl;
				
			}
			else
			{
				cout << "\t" << a[i] << endl << endl;
				
			}
		}
		Key = _getch();
		if (Key == 224)
		{
			Key = _getch();
			switch (Key)
			{
			case UP_ARROW:
				if (choice - 1 >= 0)
				{
					choice--;
				}
				else
				{
					choice = SIZE - 1;
				}
				break;
			case DOWN_ARROW:
				if (choice + 1 < SIZE)
				{
					choice++;
				}
				else
				{
					choice = 0;
				}
				break;
			default:
				break;
			}
		}

	} while (Key != 13);
	system("cls");
	return choice + 1;



}