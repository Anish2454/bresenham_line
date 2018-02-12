#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

	double A = y1 - y0;
	double B = -1 * (x1 - x0);
	if (B == 0) return undefined_slope(x0, y0, y1, s, c);
	double m = -1 * (A / B);
	if ( m <= 1 && m > 0 ) return oct_1(x0, y0, x1, y1, s, c, A, B);
	if ( m > 1 ) return oct_2(x0, y0, x1, y1, s, c, A, B);
	if ( m <= 0 && m > -1) return oct_8(x0, y0, x1, y1, s, c, A, B);
	if ( m < -1 ) return oct_7(x0, y0, x1, y1, s, c, A, B);
}

void oct_1(int x0, int y0, int x1, int y1, screen s, color c, double A, double B){
	int x = x0;
	int y = y0;
	int d = (2 * A) + B;
	while( x <= x1 ){
		plot(s, c, x, y);
		if ( d > 0 ){
			y++;
			d += (2 * B);
		}
		x++;
		d += (2 * A);
	}
}

void oct_2(int x0, int y0, int x1, int y1, screen s, color c, double A, double B){
	int x = x0;
	int y = y0;
	int d = (2 * B) + A;
	while( y <= y1 ){
		plot(s, c, x, y);
		if ( d < 0 ){
			x++;
			d += (2 * A);
		}
		y++;
		d += (2 * B);
	}
}

void oct_8(int x0, int y0, int x1, int y1, screen s, color c, double A, double B){
	int x = x0;
	int y = y0;
	int d = (2 * A) - B;
	while( x <= x1 ){
		plot(s, c, x, y);
		if ( d > 0 ){
			y--;
			d += (2 * B);
		}
		x++;
		d -= (2 * A);
	}
}

void oct_7(int x0, int y0, int x1, int y1, screen s, color c, double A, double B){
	int x = x0;
	int y = y0;
	int d = A - (2 * B);
	while( y >= y1 ){
		plot(s, c, x, y);
		if ( d < 0 ){
			x++;
			d -= (2 * A);
		}
		y--;
		d += (2 * B);
	}
}

void undefined_slope(int x0, int y0, int y1, screen s, color c){
	int y = y0;
	while( y <= y1 ){
		plot(s, c, x0, y);
		y++;
	}
}
