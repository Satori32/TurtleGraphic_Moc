#pragma once
#include <stdio.h>
#include <stdint.h>

#include "Point2D.h"

template<class T>
struct RGBOne {
	T C = 0;
};

struct Gray8 {
	uint8_t C = 0;
};

struct Gray16 {
	uint16_t C = 0;
};
struct RGB16
{
	union RGBA {
		struct Color
		{
			uint16_t G : 5;
			uint16_t B : 5;
			uint16_t R : 5;
			uint16_t A : 1;
		};
		uint16_t RGBA = 0;
	};
};
struct RGB16B
{
	union RGBA {
		struct Color
		{
			uint16_t G : 4;
			uint16_t B : 4;
			uint16_t R : 4;
			uint16_t A : 4;
		};
		uint16_t RGBA = 0;
	};
};
struct RGB24
{
	uint8_t B = 0;
	uint8_t G = 0;
	uint8_t R = 0;
};

struct RGB32
{
	uint8_t B = 0;
	uint8_t G = 0;
	uint8_t R = 0;
	uint8_t A = 0;
};

struct FixedSurfaceT {
	//type C = NULL;
	typedef RGB32 C;
	//type Color = C;
	const intmax_t Width = 0;
	const intmax_t Height = 0;

	Color Pixel[Height][Width] = { {0,}, };
};

template<class T, intmax_t W, intmax_t H> FixedSurfaceT ConstructFixedSurfaceT<T, W, H>();
bool Free(FixedSurfaceT& In);
In.Color* Index(FixedSurfaceT& In, intmax_t X, intmax_t Y);
bool SetPixel(FixedSurfaceT& In, intmax_t X, intmax_t Y, In.Color& C);
bool SetPixelF(FixedSurfaceT& In, double X, double Y, In.Color& C);//omake
bool Line(FixedSurfaceT& In, Point2D<double>& A, Point2D<double>& B, In.Color C);
intmax_t Width(FixedSurfaceT& In);
intmax_t Height(FixedSurfaceT& In);