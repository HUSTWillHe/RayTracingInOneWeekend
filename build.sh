#! /bin/bash

cd $(dirname $0)
pushd build
cmake .. && make && ./RayTracing > image.ppm && open .
popd