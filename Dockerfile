FROM ubuntu:xenial

RUN apt-get update && \
	apt-get install -y \
	build-essential \
	git cmake autoconf \
	libtool pkg-config \
	libboost-all-dev \
	libboost-filesystem-dev \
	libboost-system-dev \
	libboost-dev \
	make
