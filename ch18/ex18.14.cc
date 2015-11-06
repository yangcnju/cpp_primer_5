// Exercise 18.14: Suppose we have the following declaration of the operator*
// that is a member of the nested namespace mathLib::MatrixLib:
// ...
// How would you declare this operator in global scope?
#include <iostream>
#include <initializer_list>
#include <stdexcept>

namespace mathLib {
	namespace MatrixLib {
		class matrix {
			// a simple 2x2 matrix
		public:
			matrix() = default;
      matrix(std::initializer_list<double> il);
			matrix(const matrix &) = default;
			matrix& operator=(const matrix &) = default;
      ~matrix() = default;

			double operator[](unsigned int i) const;
			void print() const 
			{ std::cout << a11 << " " << a12 << std::endl
		              << a21 << " " << a22 << std::endl; }
		private:
			double a11;
			double a12;
			double a21;
			double a22;
		};	// class matrix
    matrix operator* (const matrix &, const matrix &);
	} // namespace MatrixLib
}

using namespace std;

int main()
{
	mathLib::MatrixLib::matrix m1 {3,0,0,3};
	mathLib::MatrixLib::matrix m2 {2,0,0,2};
	mathLib::MatrixLib::matrix m3 = m1*m2;
	m3.print();

	return 0;
}

mathLib::MatrixLib::matrix::matrix(std::initializer_list<double> il)
{
	if(il.size() < 4)
		throw std::range_error("need at least 4 numbers to initialize.");
	auto pos = il.begin();
	a11 = *pos++;
	a12 = *pos++;
	a21 = *pos++;
	a22 = *pos++;
}

double mathLib::MatrixLib::matrix::operator[](unsigned int i) const
{
	if(i > 3)
		throw std::range_error("2x2 matrix. out of range.");
	switch(i) {
		case 0:
			return a11;
			break;
		case 1:
			return a12;
			break;
		case 2:
			return a21;
			break;
		case 3:
			return a22;
			break;
		default:
			throw std::runtime_error("error accessing matrix element.");
			break;
	}
}

mathLib::MatrixLib::matrix mathLib::MatrixLib::operator* 
  (const mathLib::MatrixLib::matrix &lhs, 
	 const mathLib::MatrixLib::matrix &rhs)
{
  double a11 = lhs[0] * rhs[0] + lhs[1] * rhs[2];
	double a12 = lhs[0] * rhs[1] + lhs[1] * rhs[3];
	double a21 = lhs[2] * rhs[0] + lhs[3] * rhs[2];
	double a22 = lhs[2] * rhs[1] + lhs[3] * rhs[3];
  return mathLib::MatrixLib::matrix({a11,a12,a21,a22});
}
