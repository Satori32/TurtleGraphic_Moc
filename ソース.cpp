#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "Point2D.h"
#include "FixedSurfaceT.h"

struct TurtleParam {
	typedef double Metric;
	Point2D<Metric> Origin;
	Point2D<Metric> Now;
	Metric Theta = 0;
	bool IsUpIsYPulse = true;
	bool IsLeftIsXMinus = true;
};

TurtleParam ConstructTurtleParam(Point2D<double>& O, Point2D<double>& N) {
	TurtleParam T;
	T.Origin = O;
	T.Now = N;
	T.Theta = 45;

	return T;
}

struct TurtleGraphics2D{
	FixedSurfaceT<RGB24> Pixels;
	TurtleParam Param;
};

template<class T,size_t W,size_t H>
TurtleGraphics2D ConstructTurtleGraphics<T, W, H>() {
	TurtleGraphics2D Tu;
	Tu.Pixels = Constteruct<RGB24, W, H>();
	Point2D<double> O;
	O.X = Tu.Width / 2;
	O.T = Tu.Height / 2;
	Point2D<double> N;
	Tu.Param = ConstructTurtleParam(O, N);

	return Tu;
}

bool Line(FixedSurfaceT<In.Color>& In, Point2D<double>& A, Point2D<double>& B,In.Color C) {
	double X = B.X - A.X;
	double Y = B.Y - A.Y;
	double Z = X > Y ? Y : X;
	size_t A = 1.0 / Z;

	for (size_t i = 0; (i * A) <= 1.0; i++) {
		if (Index((In,A.X+((X/Z)*i),A.Y+((Y/Z)*i) == NULL) {return false;}
		(*Index(In, A.X + (X / Z) * i, A.Y + (Y / Z) * i)) = C;
	}

	return true;
}