#!/bin/bash

g++ -std=c++17 -w \
  /home/vishwa/Project/MiniVaultDB/src/db/db.cpp \
  /home/vishwa/Project/MiniVaultDB/src/engine/wal.cpp \
  /home/vishwa/Project/MiniVaultDB/src/engine/memtable.cpp \
  /home/vishwa/Project/MiniVaultDB/src/engine/sstable.cpp \
  /home/vishwa/Project/MiniVaultDB/src/util/hash.cpp \
  /home/vishwa/Project/MiniVaultDB/src/util/arena.cpp \
  /home/vishwa/Project/MiniVaultDB/src/util/crc32.cpp \
  /home/vishwa/Project/DeviceHub/Server/src/*.cpp \
  /home/vishwa/Project/DeviceHub/Client/src/*.cpp \
  /home/vishwa/Project/DeviceHub/Client/main.cpp \
  -I /home/vishwa/Project/MiniVaultDB/include \
  -I /home/vishwa/Project/DeviceHub/Client/include \
  -I /home/vishwa/Project/DeviceHub/Server/include \
  -O2 -o full_build

echo "Build complete. Run ./full_build"
