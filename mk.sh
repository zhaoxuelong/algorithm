#! /bin/bash
new_dir_name=$1
cp -r ~/algorithm/tmp ./$new_dir_name
if [ $? -ne 0 ]
then
  echo "Make $new_dir_name failed!"
else
  echo "Make $new_dir_name success!"
fi
