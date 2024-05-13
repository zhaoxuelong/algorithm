#! /bin/bash
cc=$1
if [ -z "$cc" ]
then
  cc="sol.cc"
fi
cc_len=${#cc}
cc_out=${cc:0:($cc_len)-3}
g++ -std=c++20 $cc -o $cc_out
if [ $? -ne 0 ]
then
  echo "Compile $cc failed!"
else
  echo "Compile $cc success!"
fi
