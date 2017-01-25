# Minivan

The minivan keyboard is a 45% keyboard, so it does not have a number row and is 
missing a column to the immediate right of the mod column on the right side (with
some differences on sizing of that modifier column).

## Backlighting

I have an expanded backlight configuration.  It needs to be included in the Makefile
and if you want to use the variable brightness/breathing, you need to add the 
initialization function to the `matrix.c` file.  The patch is included in the folder
as `matrix.patch`.

Config settings exist to set the number to steps for the backlight (so 1 would be
between 0% on to 100% on and 2 would go 0%,50%,100%).  There is also a binary
setting to turn on the breathing step, which will live between off and the steps
(so 0%, breathing, 50%, 100%).

## Map

The primary and first mod layer are pretty standard with the primary layout from
`u/evangs`.  I am trying to figure out how best to use the second layer and am 
unsure if I want the mouse layer.  The programming layer swap is meant to try and
bring some of the additional keys that I use a lot when programming, but it is a
very unpolished setup.
