#!/bin/bash

gcc src/command/*.c src/*.c lib/*.c -o pit -I "src" -I "src/command" -I "lib"