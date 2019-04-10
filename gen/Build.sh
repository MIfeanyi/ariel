#!/bin/bash
clear
cd .. && mkdir build/
cd build/
cmake .. && cmake --build .
chmod a+x ariel
./ariel
cd ..
cp build/ariel bin/
rm -r  build