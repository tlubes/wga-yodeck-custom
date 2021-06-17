#!/bin/bash
 
if [ "$1" == "off" ]; then
    su user -c "/home/user/sony_ir samsung_off"
    sleep 1
    su user -c "/home/user/sony_ir samsung_off"
    sleep 1
    su user -c "/home/user/sony_ir samsung_off"
elif [ "$1" == "on" ]; then
    su user -c "/home/user/sony_ir samsung_on"
    sleep 1
    su user -c "/home/user/sony_ir samsung_on"
    sleep 1
    su user -c "/home/user/sony_ir samsung_on"
fi
