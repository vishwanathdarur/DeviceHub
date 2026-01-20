
g++ -w \
    /data/data/com.termux/files/home/DeviceHub/Client/src/*.cpp \
    /data/data/com.termux/files/home/DeviceHub/Client/main.cpp \
    -I /data/data/com.termux/files/home/DeviceHub/Client/include \
    -o client_build


echo "Client Build complete. Run ./client_build"