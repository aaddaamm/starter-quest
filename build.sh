#!/bin/zsh

if [ ! -d "bin" ]; then
  mkdir -p bin
  cd bin
  cmake ..
else
  cd bin
fi

make
./Quest