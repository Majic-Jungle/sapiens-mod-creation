#!/bin/bash
cmake -H. -Bbuild
sleep 2
cmake --build build -- -j4
