#!/bin/bash

mkdir -p Build
cd Build
g++ -std=c++11 -Wall -Werror -fPIC -shared -I ../DynamicLib/Include -DAPI_EXPORTS ../DynamicLib/Source/*.cpp -o ../Bin/libDynamicLib.so
g++ -std=c++11 -Wall -Werror -Wl,-rpath='${ORIGIN}' ../Executable/*.cpp -o ../Bin/Executable -I ../DynamicLib/Include -L ../Bin -lDynamicLib

# NOTAS:
# -fPIC es necesario. Créetelo. Es algo sobre Position Independent Code.
# -lDynamicLib debe ir después de ../Executable/*.cpp. Por alguna razon, primero deben definirse los ficheros a compilar y luego las librerías a vincular.
# -Wl,-rpath='${ORIGIN}' Sirve para que busque la librería dinámica en el directorio del ejecutable.
