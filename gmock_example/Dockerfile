FROM ubuntu:bionic

RUN apt-get update && \
	apt-get install -y \
	build-essential \
	git cmake autoconf \
	libtool pkg-config \
	zlib1g-dev

WORKDIR /opt/project

CMD mkdir build && cd build && cmake .. && cmake --build . && cd tests && ctest -V