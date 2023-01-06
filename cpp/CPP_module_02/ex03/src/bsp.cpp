#include "../inc/bsp.hpp"
#include "../inc/Point.hpp"
/*
how to calculate area of triangle:
-	https://mathopenref.com/coordtrianglearea.html
*/
static	float calculateArea(Point const p1, Point const p2, Point const p3) {
	float p1_y = p1.getY().toFloat();
	float p2_y = p2.getY().toFloat();
	float p3_y = p3.getY().toFloat();

	float area = (p1.getX().toFloat() * (p2_y - p3_y)
				+ p2.getX().toFloat() * (p3_y - p1_y)
				+ p3.getX().toFloat() * (p1_y - p2_y) / 2);

	if (area < 0)
		area *= -1;
	return (area);
}

// Point P is in triangle if the area of triangle Δ𝐴𝐵𝐶 = Δ𝐴𝐵𝑃 + Δ𝐴𝑃𝐶 + Δ𝑃𝐵𝐶 
// if the area of Δ𝐴𝐵𝑃 or Δ𝐴𝑃𝐶 or Δ𝑃𝐵𝐶 is 0, 
// this means point P is on the edge of the triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float	areaABC = calculateArea(a, b, c);
	float	areaABP = calculateArea(a, b, point);
	float	areaAPC = calculateArea(a, point, c);
	float	areaPBC = calculateArea(point, b, c);

	if (areaABC == (areaABP + areaAPC + areaPBC)
		&& areaABP != 0 && areaAPC != 0 && areaPBC != 0)
		return (true);
	return (false);
}
