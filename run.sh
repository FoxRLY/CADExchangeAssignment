#!/bin/bash
scriptDir=$(dirname -- "$(readlink -f -- "$BASH_SOURCE")")
cd "$scriptDir"
cmake -B build -G Ninja &&
ninja -C build &&
./build/curvemain
