#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cd ../bin/
./ParserExampleWithAst ../tests/01.in
cat outism
cd ..