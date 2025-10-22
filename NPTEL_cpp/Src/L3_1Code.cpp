#include <iostream>
using namespace std;

class GeoObject {
public:
	enum ShapeType {CIR = 0, REC, TRG} gCode;
	union {
		class Cir {public: double x, y, r; } c;
		class Rec {public:  double x, y, w, h; } r;
		class Trg {public:  double x, y, b, h; } t;
	};
};

// Function Pointer type
typedef void (*DrowFunc) (GeoObject);

void drawCir(GeoObject go) {
	cout << "Circle: " << go.c.x<< "\t"<< go.c.y << "\t" << go.c.r << endl;
}
void drawRec(GeoObject go) {
	cout << "Rectangle: " << go.r.x << "\t" << go.r.y << "\t" << go.r.w << "\t" << go.r.h<< endl;
}
void drawTrg(GeoObject go) {
	cout << "triangle: " << go.t.x << "\t" << go.t.y << "\t" << go.t.b << "\t" << go.t.h << endl;
}

DrowFunc DrawArr[] = {drawCir, drawRec, drawTrg};

int main()
{
	GeoObject go;

	go.gCode = GeoObject::CIR;
	go.c.x = 2.3; go.c.y = 3.6; go.c.r = 1.2;
	DrawArr[go.gCode](go); // call drawCir() by ptr

	go.gCode = GeoObject::REC;
	go.r.x = 4.5; go.r.y = 1.9; go.r.w = 4.2; go.r.h = 3.8;
	DrawArr[go.gCode](go); // call drawRec() by ptr

	go.gCode = GeoObject::TRG;
	go.t.x = 3.1; go.t.y = 2.8; go.t.b = 4.4; go.t.h = 2.7;
	DrawArr[go.gCode](go); // call drawTrg() by ptr

	return 0;
}