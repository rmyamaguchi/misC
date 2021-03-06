#!/bin/sh

clear

export BUILD_DIR="./build"
export OUT_DIR="./out"
export OBJ_DIR="$OUT_DIR/obj"

case $1 in
    "bmp")
        export APPNAME="main_bmp"
        export APP_DIR="./libBMP" 
    ;;

    "class")
        export APPNAME="main_class"
        export APP_DIR="./libClass"
    ;;

    "dsw")
        export APPNAME="main_dsw"
        export APP_DIR="./libPatterns/DigitalStopWatch"
    ;;

    "llist")
        export APPNAME="main_llist"
        export APP_DIR="./libLList"
    ;;

    "heap")
        export APPNAME="main_heap"
        export APP_DIR="./libHeap"
    ;;

    "enum")
        export APPNAME="main_enum"
        export APP_DIR="./libEnum"
    ;;

    "clean")
        printf "Cleaning... $OUT_DIR\n"
        make clean -f $BUILD_DIR/Makefile --print-directory
        printf "done\n"
        exit
    ;;
esac

export APP=$OUT_DIR/$APPNAME
export SHAREDOBJ=$OUT_DIR/lib$APPNAME.so

COMP="applic"
if [ "$2" = "share" ]; then
    COMP="shared_obj"
fi

# Compile
printf "Compiling $APP...\n"
make $COMP -f $BUILD_DIR/Makefile --print-directory
printf "done\n\n"

if [ ! -f "$APP" ]; then
    exit
fi
printf "Executing $APP...\n"
$APP