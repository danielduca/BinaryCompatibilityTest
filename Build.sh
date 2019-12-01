#!/bin/bash

mkdir -p Build
cd Build
g++ -std=c++11 -Wall -Werror -fPIC -shared -I ../SharedLib/Include -DSL_API_EXPORTS ../SharedLib/Source/*.cpp -o ../Bin/libDynamicLib.so
g++ -std=c++11 -Wall -Werror -Wl,-rpath='${ORIGIN}' ../Executable/*.cpp -o ../Bin/Executable -I ../SharedLib/Include -L ../Bin -lSharedLib

# NOTAS:
# -fPIC es necesario. Créetelo. Es algo sobre Position Independent Code.
# -lSharedLib debe ir después de ../Executable/*.cpp. Por alguna razon, primero deben definirse los ficheros a compilar y luego las librerías a vincular.
# -Wl,-rpath='${ORIGIN}' Sirve para que busque la librería dinámica en el directorio del ejecutable.
