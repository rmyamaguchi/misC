#!/bin/sh

clear

export APPNAME="main"
export BUILD_DIR="./build"
export OUT_DIR="./out"
export OBJ_DIR="$OUT_DIR/obj"
export APP=$OUT_DIR/$APPNAME
export SHAREDOBJ=$OUT_DIR/lib$APPNAME.so

# Create output directory
if [ ! -d "$OUT_DIR" ]; then
    mkdir $OUT_DIR
fi
if [ ! -d "$OBJ_DIR" ]; then
    mkdir $OUT_DIR/obj
fi

case $1 in
    "build")
        # Compile
        printf "Compiling $APP...\n"
        make applic -f $BUILD_DIR/Makefile --print-directory
        printf "done\n\n"

        if [ ! -f "$APP" ]; then
            exit
        fi
        printf "Executing $APP...\n"
        $APP
    ;; # end build

    "clean")
        printf "Cleaning... $OUT_DIR\n"
        make clean -f $BUILD_DIR/Makefile --print-directory
        printf "done\n"
    ;; # end clean
esac
