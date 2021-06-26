#!/bin/bash
 
if [ "$1" == "off" ]; then
    su user -c "/home/user/samsung_ir samsung_off"
    sleep 1
    su user -c "/home/user/samsung_ir samsung_off"
    sleep 1
    su user -c "/home/user/samsung_ir samsung_off"
    sleep 3
    su user -c "/home/user/samsung_ir samsung_off"
    sleep 1
    su user -c "/home/user/samsung_ir samsung_off"
elif [ "$1" == "on" ]; then
    su user -c "/home/user/samsung_ir samsung_on"
    sleep 1
    su user -c "/home/user/samsung_ir samsung_on"
    sleep 1
    su user -c "/home/user/samsung_ir samsung_on"
    sleep 3
    su user -c "/home/user/samsung_ir samsung_on"
    sleep 1
    su user -c "/home/user/samsung_ir samsung_on"
fi
