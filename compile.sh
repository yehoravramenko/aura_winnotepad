#!/bin/sh

windres ./resource/resource.rc -O coff -I./include -o ./resource/compiled/resource.res    && 

gcc ./src/*.c ./resource/compiled/*.res -o ./build/aura_winnotepad.exe -I./include -L/lib -Wall