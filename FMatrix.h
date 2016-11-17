#pragma once
#include <iostream>
class FloatMatrix
{
public:
	FloatMatrix(int rows, int columns, double initval = 0.0);
	FloatMatrix(int rows, int columns, double *b);
	FloatMatrix(const FloatMatrix &);
	~FloatMatrix();
	int get_rows();
	int get_columns();
	FloatMatrix & operator=(const FloatMatrix &);
	FloatMatrix & operator=(const FloatMatrix *);
	FloatMatrix   operator*(const FloatMatrix &)const;
	friend FloatMatrix   operator*(const double ,const FloatMatrix &);
	friend FloatMatrix   operator*(const FloatMatrix &, const double );
	FloatMatrix	  operator/(const double );
	FloatMatrix	  operator/(const FloatMatrix &);
	friend FloatMatrix   operator/(const double,const FloatMatrix &);
	FloatMatrix   operator+(const FloatMatrix &);
	FloatMatrix   operator-(const FloatMatrix &);
	FloatMatrix	  operator*=(const FloatMatrix &);
	FloatMatrix	  operator*=(const double );
	FloatMatrix	  operator+=(const FloatMatrix &);
	FloatMatrix	  operator-=(const FloatMatrix &);
	FloatMatrix	  operator/=(const FloatMatrix &);
	FloatMatrix	  operator/=(const double);
	FloatMatrix   operator^(const int);
	FloatMatrix   operator^=(const int);
	const double * operator[](const int)const;
	friend std::istream &operator>>(std::istream &, FloatMatrix &);
	friend std::ostream &operator<<(std::ostream &, const FloatMatrix &);
	FloatMatrix	  transpose()const;
	FloatMatrix	  SubMatrix(int ,int )const;
	FloatMatrix	  inverse()const;

	bool		  operator==(const FloatMatrix &)const;
	bool		  operator!=(const FloatMatrix &)const;
	bool		  IsSquare()const;
	bool		  IsDiagonal()const;
	bool		  IsE()const;
	bool		  IsNull()const;
	bool		  IsSymmetric()const;
	bool		  IsUTriangle()const;
	bool		  IsDTriangle()const;

	void		  Print();
	double		  Determinant()const;
	double		  NormaSqrt()const;
	double		  NormaMaxR()const;
	double		  NormaMaxC()const;
	

private:
	double **M;
	int _columns = 0, _rows = 0;
	void		  SetDiag(double);
	//FloatMatrix	  epsRev();
};

