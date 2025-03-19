#include <iostream>
#include "complex.hpp"
int main (void){
	using cmp = complex_number<double>;
	cmp c1(-2.0,8.0);
	cmp c2(-2.0,1.0);
	cmp c6(3.0,-1);
	
	/* in this output, I control that the complex numbers are
	well defined by the user, and that the methods rp and ip work
	correctly */
	
	std::cout<<"c1 real part: "<<c1.rp()<<" c2 imaginary part: "<<c1.ip()<<std::endl;
	
	/* in this output, I check that the << overload works correctly */
	
	std::cout<<c1<<std::endl;
	std::cout<<c2<<std::endl;
	std::cout<<c6<<std::endl;
	cmp c3;
	
	/* in this output, I check that the default constructor works correctly */
	
	std::cout<<c3<<std::endl;
	cmp c4(6.0);
	
	/* in this output, I check that the explicit constructor works correctly */
	std::cout<<c4<<std::endl;
	
	/* in the following output, I try to use the conjugate method */
	
	std::cout << "The complex conjugate of "<< c1 << " is "<< c1.conjugate() << std::endl;
	
	/* now, let's try the sum of two complex numbers */
	
	std::cout << "(" << c1 << ")" << "+" << "(" << c2 << ")" << " = " << c1+c2 << std::endl;
	std::cout << "(" << c2 << ")" << "+" << "(" << c6 << ")" << " = " << c2+c6 << std::endl;
	
	/* I also check that the product works correctly */
	
	std::cout << "(" << c1 << ")" << "*" << "(" << c2 << ")" << " = " << c1*c2 << std::endl;
	std::cout << "(" << c2 << ")" << "*" << "(" << c6 << ")" << " = " << c2*c6 << std::endl;
	std::cout << "(" << c3 << ")" << "*" << "(" << c6 << ")" << " = " << c3*c6 << std::endl;
	
	/* check with the sum of a complex number and a type T on the right: */
	cmp c7 = c1 + 1.0;
	std::cout << c1 << " + 1 = " << c7 <<std::endl;
	
	/* check with the product of a complex number and a type T on the right: */
	cmp c8 = c1*-2.0;
	std::cout << "(" << c1 << ")" << "*(-2) = " << c8 <<std::endl;
	
	/* check the sum of a complex number and a type T on the left: */
	cmp c9 = -3.0+c2;
	std::cout << -3 << "+" << "(" << c2 << ")" << " = "<< c9 << std::endl;
	
	/* check the product of a complex number and a type T on the right */
	cmp c10 = -3.0*c1;
	std::cout << "(" << -3 << ")*(" << c1 << ") = " << c10 << std::endl;
}