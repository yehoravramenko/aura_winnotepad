#!/bin/sh

windres ./resource/icon.rc -O coff -I./include -o ./resource/compiled/icon.res    && 

gcc ./src/*.c ./resource/compiled/*.res -o ./build/aura_winnotepad.exe -I./include -L/lib -Wall