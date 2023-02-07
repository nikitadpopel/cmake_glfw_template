git -c http.sslVerify=false submodule update --init --recursive
mkdir build
cd build
cmake ..
cmake --build .
cd ..