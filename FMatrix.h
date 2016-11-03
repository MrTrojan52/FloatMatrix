#include <iostream>
class FloatMatrix
{
public:
	FloatMatrix(int rows, int columns, double initval);
	FloatMatrix(int rows, int columns, double *b);
	FloatMatrix(const FloatMatrix &);
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
	friend std::istream &operator>>(std::istream &, FloatMatrix &);
	friend std::ostream &operator<<(std::ostream &, const FloatMatrix &);
	FloatMatrix	  transpose();
	FloatMatrix	  SubMatrix(int ,int )const;
	FloatMatrix	  inverse()const;

	bool		  operator==(const FloatMatrix &)const;
	bool		  operator!=(const FloatMatrix &)const;
	bool		  IsSquare()const;
	bool		  IsDiagonal();
	bool		  IsE();
	bool		  IsNull()const;
	bool		  IsSymmetric();
	bool		  IsUTriangle()const;
	bool		  IsDTriangle();

	void Print();
	double Determinant()const;
	double NormaSqrt();
	double NormaMaxR();
	double NormaMaxC();
	~FloatMatrix();

private:
	double **M;
	int _columns = 0, _rows = 0;
};

