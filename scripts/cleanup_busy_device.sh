#!/bin/sh

rm -f /dev/busy
rmmod busy 2> /dev/null || :
