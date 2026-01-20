
g++ -w \
    /data/data/com.termux/files/home/Project/DeviceHub/Client/src/*.cpp \
    /data/data/com.termux/files/home/Project/DeviceHub/Client/main.cpp \
    -I /data/data/com.termux/files/home/Project/DeviceHub/Client/include
    -o client_build


echo "Client Build complete. Run ./client_build"