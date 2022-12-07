#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>

#include "material.hpp"
#include "color.hpp"

// Earth
const double omega = 7.292e-5;

//Scene
#define FPS24 1000/24
#define FPS30 1000/30
#define FPS60 1000/60

const int WIDTH = 950;
const int HEIGHT = 934;
const FP::color::Color  BACKGROUND_COLOR(0.2, 0.7, 0.8);

// Sphere
const double sx0 = 15;
const double sy0 = 0;
const double sz0 = -26;

const int sr = 2;

const FP::color::Color sdiffCol(0.4, 0.4, 0.3);
const FP::vector::Vector salb(0.35, 0.3, 0.6);
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
const double lx1 = 10;
const double ly1 = 25;
const double lz1 = -5;

const double lintens1 = 1.5;

//Light _2_
const double lx2 = -10;
const double ly2 = 25;
const double lz2 = -5;

const double lintens2 = 0.7;

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
