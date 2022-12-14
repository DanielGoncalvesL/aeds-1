FROM ubuntu:23.04

WORKDIR /app

RUN apt-get update && \
    apt-get install -y build-essential \
    xutils-dev \
    libsdl2-dev \
    libsdl2-gfx-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-net-dev \
    libsdl2-ttf-dev \
    libreadline6-dev \
    libncurses5-dev \
    mingw-w64 \
    cmake

COPY . .

RUN mkdir build

RUN cd build && cmake .. && ls && pwd && make
