//camera.h
#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

// class camera {
//     public:
//         camera(
//             double vfov, // top to bottom, in degrees
//             double aspect
//         ) {
//             origin = vec3(0.0, 0.0, 0.0);

//             auto theta = degrees_to_radians(vfov);
//             auto half_height = tan(theta/2);
//             auto half_width = aspect * half_height;

//             lower_left_corner = vec3(-half_width, -half_height, -1.0);

//             horizontal = vec3(2*half_width, 0.0, 0.0);
//             vertical = vec3(0.0, 2*half_height, 0.0);
//         }

//         ray get_ray(double u, double v) {
//             return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
//         }

//     public:
//         vec3 origin;
//         vec3 lower_left_corner;
//         vec3 horizontal;
//         vec3 vertical;
// };

class camera {
    public:
        camera(
            vec3 lookfrom, vec3 lookat, vec3 vup,
            double vfov, // top to bottom, in degrees
            double aspect
        ) {
            origin = lookfrom;
            vec3 u, v, w;

            auto theta = degrees_to_radians(vfov);
            auto half_height = tan(theta/2);
            auto half_width = aspect * half_height;
            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w, u);

            lower_left_corner = origin - half_width*u - half_height*v - w;

            horizontal = 2*half_width*u;
            vertical = 2*half_height*v;
        }

        ray get_ray(double s, double t) {
            return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
        }

    public:
        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
};

#endif