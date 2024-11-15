#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "Point2D.h"
#include "FixedSurfaceT.h"

//work in progress.

struct TurtleParam {
	typedef double Metric;
	Point2D<Metric> Origin;
	Point2D<Metric> Now;
	Metric Theta = 0;
	Metric Delta = 3;
	bool IsUpIsYPulse = true;
	bool IsLeftIsXMinus = true;
};

struct Type {
	//type Type = NULL;
	typedef double Type;
	//type T = Type;
	T Value;
};

template<class T>
Type CosntructType<T>(const T& X) {
	Type Ty = { T,X };

	return Ty;
}


struct Lambada
{
	Type A;
	Type B;
	Type C;
	Type D;
	Type R;
	R.T(*F)(A.T, B.T,C.T,D.T)=NULL;
};
template<class A, class B, class C, class D, class R>
Lambada ConstructLambada(const A& a, const B& b, const C& c, const D& d,R(*F)(A,B,C,D)) {
	Lambada L;
	L.A = ConstructType<A>(a);
	L.B = ConstructType<B>(b);
	L.C = ConstructType<C>(c);
	L.D = ConstructType<D>(d);
	L.F = F;
}
bool Free(Lambada& In) {
	Free(In.A);
	Free(In.B);
	Free(In.C);
	Free(In.D);
	Free(In.R);
}

In.R.T Call(Lambada& In) {
	In.R, Value = In.F(In.A.Value, In.B.Value, In.C.Value, In.D.Value);
	return In.R.Value;

}

TurtleParam ConstructTurtleParam(Point2D<double>& O, Point2D<double>& N) {
	TurtleParam T;
	T.Origin = O;
	T.Now = N;
	T.Theta = 45;

	return T;
}

struct TurtleGraphics2D{
	typedef RGB24 Color;
	FixedSurfaceT<Color> Pixels;
	TurtleParam Param;
	Color C;
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

bool Turn(TurtleGraphics2D& In, double Theta){
	In.Param.Theta += Theta *(In.Param.IsUpIsYPulse? -1:1);
	In.Param.Theta = fmod(In.Param.Theta+360.0, 360.0);
	return true;
}
bool TurnLeft(TurtleGraphics2D& In) {
	Turn(In,In.Param.Theta - In.Param.Delta);
}
bool TurnRight(TurtleGraphics2D& In) {
	Turn(In, In.Param.Theta + In.Param.Delta);
}
bool SetDelta(TurtleGraphics2D& In, double Delta) {
	In.Param.Delta = Delta;
	return true;
}
bool Forward(TurtleGraphics2D& In, double L) {
	Point2D<double> P = ConstructPoint2D(L*(In.Param.IsLeftIsXMinus? 1:-1), 0);
	P=LotXY(P, In.Param.Theta);
	Point2D<double> A = ConstructPoint2D(In.Param.Origin.X + In.Param.Now, In.Param.Origin.Y + In.Param.Now.Y);
	Point2D<double> B = ConstructPoint2D(In.Param.Origin.X + In.Param.Now.X + P.X, In.Param.Origin.Y + In.Param.Now.Y + P.Y);
	Line(In.Pixels, A, B, In.C);
	return true;
}
bool Curve(TurtleGraphics2D& In, double L, Lambada& L) {
	//do it your self.
	return false;
}
bool Curve(TurtleGraphics2D& In, double L, Lambada& A, Lambada& B, Lambada& C) {
	//do it your self.
	return false;
}
bool SetPen(TurtleGraphics2D& In, TurtleGraphics2D::Color C) {
	In.C = C;
	return true;
}
bool UpToPlus(TurtleGraphics2D& In, bool B) {
	In.Param.IsUpIsYPulse = B;
	return true;
}

bool TurnY(TurtleGraphics2D& In) {
	bool B = In.Param.IsUpIsYPulse;
	In.Param.IsUpIsYPulse = !B;
	return true;
}

bool LeftToMinus(TurtleGraphics2D& In, bool B) {
	In.Param.IsLeftIsXMinus = B;
	return true;
}
bool TurnX(TurtleGraphics2D& In) {
	bool B = In.Param.IsLeftIsXMinus;
	In.Param.IsLeftIsXMinus = !B;

	return true;
}
bool SetOrigin(TurtleGraphics2D& In, Point2D<double>& P) {
	In.Param.Origin = P;
	return true;
}
bool AddOrigin(TurtleGraphics2D& In, Point2D<double>& P) {
	In.Param.Origin.X += In.Param.IsLeftIsXMinus ? P.X : -P.X;
	In.Param.Origin.Y += In.Param.IsUpIsYPulse ? P.Y : -P.Y;
	return true;
}
bool MovePoint(TurtleGraphics2D& In, Point2D<double>& P) {
	In.Param.Now.X = P.X * (In.Param.IsLeftIsXMinus ? 1 : -1);
	In.Param.Now.Y = P.Y * (In.Param.IsLeftIsXMinus ? 1 : -1);
	return true;
}
bool Line(TurtleGraphics2D& In, Point2D<double>& P) {
	//In.Param.Now.X = P.X * (In.Param.IsLeftIsXMinus ? 1 : -1);
	//In.Param.Now.Y = P.Y * (In.Param.IsLeftIsXMinus ? 1 : -1);
	P.X *= (In.Param.IsLeftIsXMinus ? 1 : -1);
	P.Y *= (In.Param.IsLeftIsXMinus ? 1 : -1);
	Point2D<double> A = CosntructPoint2D<double>(In.Param.Origin.X + In.Param.Now.X, In.Param.Origin.Y + In.Param.Now.Y);
	Point2D<double> B = CosntructPoint2D<double>(In.Param.Origin.X + In.Param.Now.X+P.X, In.Param.Origin.Y + In.Param.Now.Y+P.Y);
	Line(In.Pixels, A, B, In.C);
	In.Param.Now.X += P.X;
	In.Param.Now.Y += P.Y;
	return true;
}