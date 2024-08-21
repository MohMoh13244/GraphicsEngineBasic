/*
 *  GraphicsEngineBasic
 *  Author: Mohamad El mansour
 *  Version: 2023-11-09
 */
#include "RBM.hpp"

#define Pi 3.141592653589793238462643

RBM::RBM() {
	reset();
}

RBM::~RBM() {
}

void RBM::reset() {
	R = 360;
	S = 5;
	T = 25;
	row = R / 5 + 1;
	col = T + 1;
}

// generate the mesh point and normal of rotation surface

void RBM::RotateCurve() {
	Point pts[col];
	Vector tangents[col];
	int nCtrlPts = curve->nCtrlPts;
	curve->computeBezPtsTan( nCtrlPts,  pts,  tangents);


	// 2. rotate curve to generate surface mesh point and normal data and store in Pts and Normal.
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			Pts[i][j].x = pts[j].x;
			Pts[i][j].y = pts[j].y * cos((Pi / 180) * S * i);
			Pts[i][j].z = pts[j].y * sin((Pi / 180) * S * i);
		}
	}
}



void RBM::setRotationCurve(Bezier *curve1)
{
	curve = curve1;
}
