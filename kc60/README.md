# KC60

The KC60 is a GH60 clone that was on Massdrop.  It has a standard 60% layout with
single pin LED backlighting.  This uses a similar configuration for backlighting as
I used on the minivan.

## Backlighting

I have an expanded backlight configuration.  It needs to be included in the Makefile
and if you want to use the variable brightness/breathing, you need to add the 
initialization function to the `matrix.c` file.

Config settings exist to set the number to steps for the backlight (so 1 would be
between 0% on to 100% on and 2 would go 0%,50%,100%).  There is also a binary
setting to turn on the breathing step, which will live between off and the steps
(so 0%, breathing, 50%, 100%).

## Map

The primary and main mod layer are standard, I mostly use the `hjkl` for arrow keys
on this layer (as opposed to `wasd`).  This keyboard drives my desktop and the 
second layer provides KVM macros to swap the primary system on the KVM.
