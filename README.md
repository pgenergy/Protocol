# Protocol
[![Build and Release](https://github.com/pgenergy/Protocol/actions/workflows/build.yml/badge.svg)](https://github.com/pgenergy/Protocol/actions/workflows/build.yml)

This repository contains the currently used protocol for the transfer of data.
It is using Protobuf.

Inside of the directory proto all protobuf related files are stored.
In the build directory each build (e.g. cpp) have its own directory with a makefile.

The c-build is based on nanopb for a usage on microcontrollers.
