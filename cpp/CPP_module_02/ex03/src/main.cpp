#include "../inc/main.hpp"
#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include "../inc/bsp.hpp"
#include <iostream>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define NORMAL "\e[00m"

static void	checkResult(bool r) {
	if (r)
		std::cout << GREEN << "[PASS] ";
	else
		std::cout << RED << "[FAIL] ";
}

static void	checkIfPointInTriangle(Point const a, Point const b, Point const c, 
									Point const point, bool expectedResult) {
	bool	result = bsp(a, b, c, point);
	checkResult(result == expectedResult);
	if (result)
		std::cout << NORMAL << point << "\tis in triangle" << std::endl;
	else
		std::cout << NORMAL << point << "\tis not in triangle" << std::endl;
}

int main( void ) {
	// 					c				
	// 							p4
	// 
	// 					p3
	// 			
	// 			p2
	// a								b
	// p1
	Point	a(0, 0);
	Point	b(2, 0);
	Point	c(1, 3);
	Point	p1(0, -1);
	Point	p2(0.5, 1);
	Point	p3(1, 1.5);
	Point	p4(2, 3);
	checkIfPointInTriangle(a, b, c, p1, false);
	checkIfPointInTriangle(a, b, c, p2, true);
	checkIfPointInTriangle(a, b, c, p3, true);
	checkIfPointInTriangle(a, b, c, p4, false);
	checkIfPointInTriangle(a, b, c, a, 	false);

	// 
	// f
	// 				p8
	// 			p7
	// 		p6
	// p5
	//		 d								e
	Point	d(1, 0);
	Point	e(10, 0);
	Point	f(0, 5);
	Point	p5(0, 1);
	Point	p6(1, 2);
	Point	p7(2, 3);
	Point	p8(3, 4);
	checkIfPointInTriangle(d, e, f, p5, false);
	checkIfPointInTriangle(d, e, f, p6, true);
	checkIfPointInTriangle(d, e, f, p7, true);
	checkIfPointInTriangle(d, e, f, p8, false);
	checkIfPointInTriangle(d, e, f, e,	false);
	return 0;
}
