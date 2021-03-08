FROM ubuntu:focal

ARG QMK_REMOTE='https://github.com/qmk/qmk_firmware'
ENV SRC_FOLDER /src/qmk_firmware
ENV LC_ALL=C.UTF-8

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
      python3-pip \
      python3-setuptools \
      sudo \
      unzip \
      wget \
      zip \
   && python3 -m pip install wheel \
   && rm -rf /var/lib/apt/lists/* \
      /var/cache/apt/* \
      /var/log/* \
      /usr/share/man \
      /usr/share/doc

ARG QMK_CHECKOUT='0.12.5'
RUN git clone --recurse-submodules "$QMK_REMOTE" $SRC_FOLDER \
   && cd $SRC_FOLDER \
   && git checkout "$QMK_CHECKOUT" \
   && python3 -m pip install -r $SRC_FOLDER/requirements.txt

ADD ./docker-entrypoint.sh /usr/bin/build-entrypoint
ENTRYPOINT ["/usr/bin/build-entrypoint"]
CMD ["help"]
