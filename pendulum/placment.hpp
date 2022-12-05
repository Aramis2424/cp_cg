#ifndef PLACMENT_HPP
#define PLACMENT_HPP

#include <cmath>
#include <iostream>

class Placment
{
public:
    void init_place(double latitude)
    {
        std::cout << latitude;
        place.phi = latitude;
        place.omega_z = place.omega * sin(place.phi);
        place.gl = 10 / 50;
        place.omega_0 = sqrt(place.gl);
        place._omega_ = sqrt(place.omega_0*place.omega_0 + place.omega_z*place.omega_z);
        place.omega_minus = place._omega_ - place.omega_z;
        place.omega_plus = place._omega_ + place.omega_z;
    }

    struct
    {
        const double omega = 7.292e-5;
        double omega_z;
        double omega_0;
        double gl;
        double _omega_;
        double omega_minus;
        double omega_plus;
        double phi;
    }place;
};


#endif // PLACMENT_HPP
