#include "FMatrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

FloatMatrix::FloatMatrix(int r,int c,double initval )
{
	_rows = r;
	_columns = c;
	M = new double *[r];
	for (int i = 0; i < r; i++)
	{
		M[i] = new double[c];
	
		for (int j = 0; j < c; j++)
		{
			M[i][j] = initval;
		}
	}
}

FloatMatrix::FloatMatrix(int r, int c, double *b)
{
	_rows = r;
	_columns = c;
	int tmp = 0;
	M = new double *[_rows];
	for (int i = 0; i < _rows; i++)
	{
		M[i] = new double[_columns];
		
		for (int j = 0; j < _columns; j++)
		{
			M[i][j] = b[tmp++];
		}
	}

}

FloatMatrix::FloatMatrix(const FloatMatrix &B)
{
	_rows = B._rows;
	_columns = B._columns;
	M = new double *[_rows];
	for (int i = 0; i < _rows; i++)
	{
		M[i] = new double[_columns];

		for (int j = 0; j < _columns; j++)
		{
			M[i][j] = B.M[i][j];
		}
	}
}

int FloatMatrix::get_rows()
{
	return _rows;
}

int FloatMatrix::get_columns()
{
	return _columns;
}

FloatMatrix::~FloatMatrix()
{
	for (int i = 0; i < _rows; i++)
	{
		
			delete[] M[i];
			M[i] = NULL;
		
		
	}
	delete[] M;
	M = NULL;

}

FloatMatrix & FloatMatrix::operator=(const FloatMatrix &B)
{
	if (this == &B)
	{
		return (*this);
	}
	else
	{
		for (int i = 0; i < _rows; i++)
		{
			delete[] M[i];
			M[i] = NULL;
		}
		delete[] M;
		M = NULL;

		_rows = B._rows;
		_columns = B._columns;
		M = new double *[_rows];
		for (int i = 0; i < _rows; i++)
		{
			M[i] = new double[_columns];

			for (int j = 0; j < _columns; j++)
			{
				M[i][j] = B.M[i][j];
			}
		}
		return (*this);

	}
}

FloatMatrix & FloatMatrix::operator=(const FloatMatrix * B)
{
	return *this = *B;
}


FloatMatrix FloatMatrix::operator*(const FloatMatrix &B)const
{
	FloatMatrix result(_rows, B._columns,0.0);
	if (!(*this).IsNull() && ((*this).inverse() == B) )
	{
		result.SetDiag(1.0);
		return result;
	}
	if (_columns == B._rows)
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < B._columns; j++)
			{
				for (int k = 0; k < _columns; k++)
				{
					result.M[i][j] += M[i][k] * B.M[k][j];
				}
			}
		}
		return result;
	}
	else
	{
		cout << endl << "Multiply is impossible:Matrix have different sizes!" << endl << "Returned " << _rows <<" x "<< _columns << " null matrix!";
		return  FloatMatrix(_rows, _columns, 0.0);
	}
}

FloatMatrix FloatMatrix::operator/(const double c)
{
	FloatMatrix result(*this);
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			result.M[i][j] /= c;
		}
	}
	return result;
}

FloatMatrix FloatMatrix::operator/(const FloatMatrix &B)
{
	FloatMatrix result(*this);
	return result * B.inverse();
}

FloatMatrix operator/(const double c,const FloatMatrix &B)
{
	return c*B.inverse();
}

FloatMatrix operator*(const FloatMatrix &B, const double c)
{
	FloatMatrix result(B);
	for (int i = 0; i < B._rows; i++)
	{
		for (int j = 0; j < B._columns; j++)
		{
			result.M[i][j] *= c;
		}
	}
	return result;
}

FloatMatrix  operator*( const double c,const FloatMatrix &B)
{
	return B * c;
}



FloatMatrix  FloatMatrix::operator+(const FloatMatrix &B)
{
	FloatMatrix result(*this);
	if (_rows == B._rows && _columns == B._columns)
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _columns; j++)
			{
				result.M[i][j] = M[i][j] + B.M[i][j];
			}
		}
		return result;
	}
	else
	{
		cout << endl << "Addition is impossible:Matrix have different sizes!" << endl << "Returned " << _rows << " x " << _columns << " null matrix!";
		return  FloatMatrix(_rows, _columns, 0.0);
	}
}

FloatMatrix FloatMatrix::operator-(const FloatMatrix &B)
{
	
	if (_rows == B._rows && _columns == B._columns)
	{
		
		return *this + (-1.0)*B;
	}
	else
	{
		cout << endl << "Substraction is impossible:Matrix have different sizes!" << endl << "Returned " << _rows << " x " << _columns << " null matrix!";
		return  FloatMatrix(_rows, _columns, 0.0);
	}
}

FloatMatrix FloatMatrix::operator*=(const FloatMatrix &B)
{
	*this = *this * B;
	return *this;
}

FloatMatrix FloatMatrix::operator*=(const double c)
{
	*this = *this * c;
	return *this;
}

FloatMatrix FloatMatrix::operator+=(const FloatMatrix &B)
{
	*this = *this + B;
	return *this;
}

FloatMatrix FloatMatrix::operator-=(const FloatMatrix &B)
{
	*this = *this - B;
	return *this;
}

FloatMatrix FloatMatrix::operator/=(const FloatMatrix &B)
{
	*this = *this / B;
	return *this;
}

FloatMatrix FloatMatrix::operator/=(const double c)
{
	*this = *this / c;
	return *this;
}

FloatMatrix FloatMatrix::operator^(const int c)
{
	int _pow = abs(c);
	FloatMatrix result(*this);

	if (_rows == _columns)
	{
		if (_pow == 0)
		{
			for (int i = 0; i < _rows; i++)
			{
				for (int j = 0; j < _columns; j++)
				{
					if (i == j)
						result.M[i][j] = 1;
					else
						result.M[i][j] = 0;
				}
			}
		}
		else
		{
			for (unsigned i = 1; i < _pow; ++i)
				result *= *this;

			if (c < 0)
			{
				result = result.inverse();
			}
		}
		return result;
	}


}

FloatMatrix FloatMatrix::operator^=(const int c)
{
	return *this^c;
}

const double * FloatMatrix::operator[](const int i)const
{
	return M[i];
}



std::istream &operator>>(std::istream &input, FloatMatrix &B)
{
	cout << endl << "Your matrix is " << B._rows << " x " << B._columns << endl;
	cout << "Enter " << B._rows * B._columns << " numbers" << endl;
	for (int i = 0; i < B._rows; i++)
	{
		for (int j = 0; j < B._columns; j++)
		{
			cout << endl << "M[" << i << "][" << j << "] = ";
			input >> B.M[i][j];
		}
		
	}
	return input;
}

std::ostream &operator<<(std::ostream &output, const FloatMatrix &B)
{
	output << endl;
	for (int i = 0; i < B._rows; i++)
	{
		for (int j = 0; j < B._columns; j++)
		{
			output << setw(5) << fixed  << B.M[i][j] << " ";
		}
		output << endl;
	}
	return output;
}

FloatMatrix FloatMatrix::transpose()const
{
	FloatMatrix result(_columns, _rows);
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			result.M[j][i] = M[i][j];
		}
	}
	return result;
}

FloatMatrix FloatMatrix::SubMatrix(int r, int c)const
{
	int k = 0;
	if ((_rows > 1) && (_columns > 1))
	{
		FloatMatrix result(_rows - 1, _columns - 1);
		if (IsSquare())
		{
			for (int i = 0; i < _rows; i++)
			{
				for (int j = 0; j < _columns; j++)
				{
					if (i != r && j != c)
					{
						
						result.M[k / result._columns][k % result._columns] = M[i][j];
						k++;
					}
				}
			}
		}
		else
		{
			cout << "Unable to allocate sub-matrix: Matrix - is not a square!" << endl << "Returned " << _rows << " x " << _columns << " null matrix!";
			return  FloatMatrix(_rows, _columns, 0.0);
		}
		return result;
	}
	else
	{
		cout << "Unable to allocate sub-matrix: The matrix has a small size!" << endl << "Returned " << _rows << " x " << _columns << " null matrix!";
		return  FloatMatrix(_rows, _columns, 0.0);
	}

}

FloatMatrix FloatMatrix::inverse()const
{
	FloatMatrix Minors(_rows, _columns);
	FloatMatrix result(_rows, _columns);
	if (IsSquare() &&  (Determinant() != 0))
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _columns; j++)
			{
				Minors.M[i][j] = pow(-1, i + j)*SubMatrix(i, j).Determinant();
			}
		}

		Minors = Minors.transpose();

		result = (1 / Determinant())*Minors;
		return result;
	}
	else
	{
		cout << endl << "Can not find the inverse matrix!"<< endl << "Returned " << _rows << " x " << _columns << " null matrix!";
		return  FloatMatrix(_rows, _columns, 0.0);
	}
}

bool FloatMatrix::operator==(const FloatMatrix &B)const
{
	if ((_rows != B._rows) || (_columns != B._columns))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _columns; j++)
			{
				if (M[i][j] != B.M[i][j])
				{
					return false;
					
				}
			}
		}
	}
	return true;
}

bool FloatMatrix::operator!=(const FloatMatrix &B)const
{
	return !(*this == B);
}

bool FloatMatrix::IsSquare()const
{
	if (_rows == _columns)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FloatMatrix::IsDiagonal()const
{
	if (IsUTriangle() && IsDTriangle())
	{
		return true;
	}
	else
	{
		return false; 
	}
}

bool FloatMatrix::IsE()const
{
	if (IsDiagonal())
	{
		for (int i = 0; i < _rows; i++)
		{
			if (M[i][i]  != 1)
				return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}


bool FloatMatrix::IsNull()const
{
	FloatMatrix r(_rows, _columns, 0.0);
	if (*this == r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FloatMatrix::IsSymmetric()const
{
	FloatMatrix result(*this);
	if ((*this == result.transpose()) && IsSquare())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FloatMatrix::IsUTriangle()const
{

	if (IsSquare())
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = i+1; j < _rows-i ; j++)
			{
				if (M[j][i]  != 0)
				{
					return false;

				}
			}
		}
	}
	else
	{
		return false;
	}
	return true; 
}

bool FloatMatrix::IsDTriangle()const
{
	FloatMatrix result(*this);
	return result.transpose().IsUTriangle();
}

double FloatMatrix::Determinant()const
{
	double det = 0.0;
	if (IsSquare())
	{
		if (_rows == 2)
		{
			return M[0][0] * M[1][1] - M[1][0] * M[0][1];
		}
		else if (_rows == 1)
		{
			return M[0][0];
		}

		for (int j = 0; j < _columns; j++)
		{
			det += M[0][j] * pow(-1, j) * SubMatrix(0, j).Determinant();
		}
		
		return det;
	}
	else
	{
		cout << endl << "The determinant is not found: The Matrix is not square!" << endl << "Returned 0.0!";
		return 0.0;
	}
	
}

double FloatMatrix::NormaSqrt()const
{
	double res = 0.0;
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			res += M[i][j] * M[i][j];
		}
	}
	return sqrt(res);
}

double FloatMatrix::NormaMaxR()const
{
	double max = DBL_MIN;
	double sum = 0.0;
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			sum += M[i][j];
		}
		if (sum > max)
			max = sum;
		sum = 0.0;
	}
	return max;
}

double FloatMatrix::NormaMaxC()const
{
	FloatMatrix result(*this);
	return result.transpose().NormaMaxR();
}

void FloatMatrix::Print()
{
	cout << endl;
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			cout << setw(5) << M[i][j] << " ";
		}
		cout << endl;
	}

}

void FloatMatrix::SetDiag(double k)
{
	for (int  i = 0; i < min(_rows,_columns); i++)
	{
		M[i][i] = k;
	}
}

/*FloatMatrix FloatMatrix::epsRev()
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			if (fabs(M[i][j]) < DBL_EPSILON)
			{
				M[i][j] = 0.0;
			}
		}
	}
	return *this;
}*/