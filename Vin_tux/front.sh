#!/bin/bash

g++ -o a driver.cpp
#./a |  awk -F' ' '{ print $1 "  "  $2}'
holdv=0
./a >> hold &
while [holdv -lt 10 ]; do
#sleep 2
#echo > hold
#cat hold
echo 0
done