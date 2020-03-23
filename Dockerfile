FROM ubuntu:bionic

ARG QMK_REMOTE='https://github.com/qmk/qmk_firmware'
ARG QMK_CHECKOUT='master'
ENV SRC_FOLDER /src/qmk_firmware

RUN apt-get update \
   && apt-get install -y --no-install-recommends \
      avr-libc \
      binutils-arm-none-eabi \
      binutils-avr \
      ca-certificates \
      dfu-programmer \
      dfu-util \
      gcc \
      gcc-arm-none-eabi \
      gcc-avr \
      git \
      libnewlib-arm-none-eabi \
      make \
      python3 \
      unzip \
      wget \
      zip \
   && rm -rf /var/lib/apt/lists/* \
      /var/cache/apt/* \
      /var/log/* \
      /usr/share/man \
      /usr/share/doc

RUN git clone --recurse-submodules "$QMK_REMOTE" $SRC_FOLDER \
   && cd $SRC_FOLDER \
   && git checkout "$QMK_CHECKOUT"

ADD ./docker-entrypoint.sh /usr/bin/build-entrypoint
ENTRYPOINT ["/usr/bin/build-entrypoint"]
CMD ["help"]
