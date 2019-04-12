//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Intersection2D.h"

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Check whether a point and circle intersect.
// Params:
//  point = The point in the intersection.
//  circle = The circle in the intersection.
// Returns:
//   True if intersection, false otherwise.
bool PointCircleIntersection(const Vector2D& point, const Circle& circle) {
	if (point.Distance(circle.center) <= circle.radius) {
		return true;
	}
	return false;
}

// Check whether a point and rectangle intersect.
// Params:
//  point = The point in the intersection.
//  rect  = The rectangle in the intersection.
// Returns:
//   True if intersection, false otherwise.
bool PointRectangleIntersection(const Vector2D& point, const BoundingRectangle& rect) {
	if (point.x < rect.top && point.x > rect.bottom && point.y > rect.left && point.y < rect.right) {
		return true;
	}
	return false;
}

// Check whether two circles intersect.
// Params:
//  circle1 = The first circle.
//  circle2 = The second circle.
// Returns:
//   True if intersection, false otherwise.
bool CircleCircleIntersection(const Circle& circle1, const Circle& circle2) {
	if (circle1.center.Distance(circle2.center) >= circle1.radius + circle2.radius) {
		return true;
	}
	return false;
}

// Check whether two rectangles intersect.
// Params:
//  rect1 = The first rectangle.
//	rect2 = The second rectangle.
// Returns:
//   True if intersection, false otherwise.
bool RectangleRectangleIntersection(const BoundingRectangle& rect1, const BoundingRectangle& rect2) {
	if (rect1.left < rect2.right &&
		rect1.right > rect2.left &&
		rect1.bottom < rect2.top &&
		rect1.top > rect2.bottom) {
		return true;
	}
	return false;
}

// Check whether a rectangle and circle intersect.
// Params:
//  rect = The rectangle.
//  circle  = The circle.
// Returns:
//   True if intersection, false otherwise.
bool RectangleCircleIntersection(const BoundingRectangle& rect, const Circle& circle) {

	Vector2D point = circle.center;

	if (point.x > rect.right) {
		point.x = rect.right;
	} else if (point.x < rect.left) {
		point.x = rect.left;
	}

	if (point.y > rect.top) {
		point.y = rect.top;
	} else if (point.y < rect.bottom) {
		point.y = rect.bottom;
	}

	if (point.Distance(circle.center) <= circle.radius) {
		return true;
	}
	
	return false;

}

//------------------------------------------------------------------------------
