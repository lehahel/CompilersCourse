#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
../bin/ParserExampleWithAst ../tests/01.in
