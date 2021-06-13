#include "Vector2D.h"
#include "Vector2D.h"
#include "math.h"

float max(float a, float b) {
	if (a > b)
		return a;
	return b;
}

float min(float a, float b) {
	if (a > b)
		return b;
	return a;
}


Vector2D::Vector2D(float xv, float yv) {
	x = xv;
	y = yv;
}

float Vector2D::modulo() {
	return (float)sqrt((double)x * x + (double)y * y);
}

float Vector2D::argumento() {
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario() {
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector2D Vector2D::operator + (Vector2D v) {
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

float Vector2D::operator * (Vector2D v) {
	return x * v.x + y * v.y;
}

Vector2D Vector2D::operator * (float p) {
	Vector2D res;
	res.x = x * p;
	res.y = y * p;
	return res;
}

bool Vector2D::onSegment(Vector2D p, Vector2D q, Vector2D r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

float Vector2D::orientation(Vector2D p, Vector2D q, Vector2D r)
{
	float val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool Vector2D::Interseccion(Vector2D p1, Vector2D q1, Vector2D p2, Vector2D q2)
{
	// Find the four orientations needed for general and
   // special cases
	float o1 = orientation(p1, q1, p2);
	float o2 = orientation(p1, q1, q2);
	float o3 = orientation(p2, q2, p1);
	float o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}
