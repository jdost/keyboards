#!/usr/bin/env bash

set -euo pipefail

# The default command is "help" which will just spit out a README esque output
if [[ "${1:-}" == "help" ]]; then
   echo "This is the building container for the QMK firmware."
   exit 0
fi
# `$OUTPUT_FOLDER` is where we will move any build artifacts to at the end to make
#   it easier to pull them out (or this could be a volume mount)
OUTPUT_FOLDER=${OUTPUT_FOLDER:-/build}
SRC_FOLDER=${SRC_FOLDER:-/src/qmk_firmware}

cd "$SRC_FOLDER"
# Run a flat `make` if no args made, this would be explicit since the default is to
#  run with "help"
if [[ -z "$@" ]]; then
   make
else
   "$@"
fi
mkdir -p "${OUTPUT_FOLDER}"
# Check if something was built, then copy it into the output location
find . -maxdepth 2 -name "*.hex" -exec mv {} "${OUTPUT_FOLDER}"/firmware.hex \;
