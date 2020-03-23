# Keyboard keymaps

Personal keymaps for the various keyboards I have/use.  These are all
based on QMK/TMK.  Previously I used TMK for all of them but eventually
switched to QMK.  This uses docker for building the images to keep the
build platform consistent.

## Usage

ex.
```
$ make kc60
...
$ ls kc60/firmware.hex
kc60/firmware.hex
$ make flash-kc60
...
```

For each of the keyboards, there are two major make targets, the flat
`make <keyboard_name>` which will build the firmware as a hex file that
will be created in the folder.  Then there is a helper `make
flash_<keyboard_name>` that will do the flashing.  It will require sudo
rights, so it will prompt for input if required, then wait some time for
you to put the board into a flashable state, then do the steps to flash
the local firmware onto the board and restart it.
