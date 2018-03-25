#!/bin/bash
clear
cd .. && mkdir build/
cd build/
cmake .. && cmake --build .
chmod a+x ariel
cd ..

mkdir -p AppDir/usr/bin/ && mkdir AppDir/usr/lib
mkdir -p AppDir/share/applications && mkdir -p AppDir/share/icons/highcolor/256x256
cp AppDir/ariel.desktop AppDir/share/applications && cp AppDir/ariel.png AppDir/share/icons/highcolor/256x256
cp build/ariel AppDir/
#read -rsp $'Press any key to continue...\n' -n 1 key #For clarity
wget -nc https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage
chmod a+x linuxdeployqt*.AppImage
./linuxdeployqt*.AppImage AppDir/ariel.desktop -appimage
chmod a+x Ariel_Engine-*.AppImage
echo -e "running generated AppImage"
./Ariel_Engine-x86_64.AppImage

#clean up
cd AppDir/ && rm -R -f -- */ && cd ..
rm -v linuxdeployqt*.AppImage 
rm -r  build