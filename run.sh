#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
../03-parsers-with-ast/bin/ParserExampleWithAst ../tests/03-a.in
