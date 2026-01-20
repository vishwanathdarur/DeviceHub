

g++ -w \
  /home/vishwa/Project/DeviceHub/Client/src/*.cpp \
  /home/vishwa/Project/DeviceHub/Client/main.cpp \
  -I /home/vishwa/Project/DeviceHub/Client/include \
  -o client_build 

echo "Client Build complete. Run ./client_build"