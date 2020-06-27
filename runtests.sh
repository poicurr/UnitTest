#!/bin/bash

ROOT=$(pwd)
BUILD_DIR=$ROOT/build/

rm -rf $BUILD_DIR
mkdir $BUILD_DIR && cd $BUILD_DIR

cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make

