#!/bin/sh
# COMPILES CROSS-COMPILER FOR i686
# REQUIRES BINUTILS 2.28, GDB 8.0, GCC 7.1.0
# IN DIRECTORY ~/src

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

cd $HOME/src
mkdir build-binutils
cd build-binutils
../binutils-2.28/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

../gdb.8.0/configure --target=$TARGET --prefix="$PREFIX" --disable-werror
make all-gdb
make install-gdb
cd $HOME/src
 
mkdir build-gcc
cd build-gcc
../gcc-7.1.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc