mkdir build
cd build
cmake .. -DCMAKE_GENERATOR_PLATFORM=x64
cmake --build .  
copy Debug\ariel.exe ..\bin\ariel.exe
cd ..
del /S /Q build