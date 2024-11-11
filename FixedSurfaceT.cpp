#include "FixedSurfaceT.h"

template<class T, intmax_t W, intmax_t H>
FixedSurfaceT ConstructFixedSurfaceT<T, W, H>() {
	FixedSurfaceT F = { T,W,H };

	return F;
}

bool Free(FixedSurfaceT& In) {
	Free(In);
}
In.Color* Index(FixedSurfaceT& In, intmax_t X, intmax_t Y) {
	if (In.Width <= 0) { return NULL; }
	if (In.Width <= X) { return NULL; }
	if (In.Height <= 0) { return NULL; }
	if (In.Height <= Y) { return NULL; }

	return &In.Pixel[Y][X];
}

bool SetPixel(FixedSurfaceT& In, intmax_t X, intmax_t Y, In.Color& C) {
	if (Index(In, X, Y) == NULL) { return false; }
	(*Index(In, X, Y)) = C;
	return true;
}
bool SetPixelF(FixedSurfaceT& In, double X, double Y, In.Color& C) {//omake
	if (Index(In, In.Width * X, In.Height * Y) == NULL) { return false; }
	(*Index(In, In.Width * X, In.Height * Y)) = C;
	return true;
}
intmax_t Width(FixedSurfaceT& In) {
	return In.Width;
}
intmax_t Height(FixedSurfaceT& In) {
	return In.Height;
}