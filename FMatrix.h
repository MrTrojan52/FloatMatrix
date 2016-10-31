class FloatMatrix
{
public:
	FloatMatrix(int rows, int columns, double initval);
	FloatMatrix(int rows, int columns, double *b);
	FloatMatrix(const FloatMatrix &);

	FloatMatrix & operator=(const FloatMatrix &);
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
	FloatMatrix	  transpose();
	FloatMatrix	  SubMatrix(int ,int )const;
	FloatMatrix	  inverse()const;

	bool		  operator==(const FloatMatrix &);
	bool		  operator!=(const FloatMatrix &);
	bool		  IsSquare()const;
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

