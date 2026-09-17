#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: ./new.sh <project>"
  exit 1
fi

dir_name=$(dirname "$0")
use_path="$(pwd)/problems/$1"

if [ -d "$use_path" ]; then
  echo "Path: $use_path already existed"
  exit 1
fi

echo "$use_path"

cp -r "$dir_name/template" "$use_path"
mv "$use_path/SOLUTION_XXX.cpp" "$use_path/$1.cpp"

if sed --version >/dev/null 2>&1; then
  sed -i "s/PROJECT_XXX/$1/g" "$use_path/CMakeLists.txt"
else
  sed -i '' "s/PROJECT_XXX/$1/g" "$use_path/CMakeLists.txt"
fi
