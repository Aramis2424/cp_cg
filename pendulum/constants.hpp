#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>

#include "color.hpp"

// Earth
const double omega = 7.292e-5;

//Scene
#define FPS24 1000/24
#define FPS30 1000/30
#define FPS60 1000/60

const int WIDTH = 950;
const int HEIGHT = 934;
const FP::color::Color  BACKGROUND_COLOR(0.3, 0.44, 0.63);

// Sphere
const double sx0 = 15;
const double sy0 = 0;
const double sz0 = -26;

const double sr = 2.3;

const FP::color::Color sdiffCol(0.51, 0.51, 0.51);
const FP::vector::Vector salb(0.50, 0.30, 0.6);
//lAlb - яркость
//cAlb - блики
//rAlb - отражательная сила
const double sspec_exp = 20;

const int DEPTH_REFLECT = 1;

// Camera
const double cx0 = 0;
const double cy0 = 2;
const double cz0 = 0;

const double FOV = M_PI / 2.0;

//Light _1_
const double lx1 = 15;
const double ly1 = 35;
const double lz1 = -10;

const double lintens1 = 1.5;

//Light _2_
const double lx2 = -15;
const double ly2 = 35;
const double lz2 = -10;

const double lintens2 = 0.9;

enum state_t
{
    off,
    on
};

enum error_t
{
    OK,
    FALSE = 0,
    TRUE,
};

#endif // CONSTANTS_H
