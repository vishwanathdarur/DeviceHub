

g++ -w \
  Client/src/client.cpp \
  Client/src/commonfunctions.cpp \
  Client/main.cpp \
  -I /home/vishwa/Project/DeviceHub/Client/include \
  -o client_build 

echo "Client Build complete. Run ./client_build"