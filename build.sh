#!/bin/bash

export CC=/usr/bin/clang CXX=/usr/bin/clang++

mkdir build

cd build

cmake ../

make
