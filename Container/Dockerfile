# Use a base ubuntu image
FROM ubuntu:24.04

LABEL description="Ubuntu based C++ development environment for CPSC 365 | UCalgary"
LABEL maintainer="Usman Alim <ualim@ucalgary.ca>"

# Packages to be installed
RUN apt-get update && apt-get install -y \
    git \	
    cmake \
    doxygen \
    build-essential \
    valgrind \
    python3 \
    python3-pip \
    graphviz \
    nano \
    vim \
    emacs \   
    && rm -rf /var/lib/apt/lists/*


# This is needed to produce graph images
RUN pip install gprof2dot --break-system-packages

# Setup timezone and locale (for UTF8 support)
ENV TZ America/Edmonton

RUN apt-get update && apt-get install -y \
    tzdata \
    locales \
    && rm -rf /var/lib/apt/lists/* \
    && sed -i '/en_US.UTF-8/s/^# //g' /etc/locale.gen \
    && locale-gen \
    && ln -fs /usr/share/zoneinfo/${TZ} /etc/localtime \
    && dpkg-reconfigure tzdata

ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

