#!/bin/bash
 
if [ "$1" == "off" ]; then
    su user -c "/home/user/sony_ir sony_off"
    sleep 1
    su user -c "/home/user/sony_ir sony_off"
    sleep 1
    su user -c "/home/user/sony_ir sony_off"
    sleep 3
    su user -c "/home/user/sony_ir sony_off"
    sleep 1
    su user -c "/home/user/sony_ir sony_off"
elif [ "$1" == "on" ]; then
    su user -c "/home/user/sony_ir sony_on"
    sleep 1
    su user -c "/home/user/sony_ir sony_on"
    sleep 1
    su user -c "/home/user/sony_ir sony_on"
    sleep 3
    su user -c "/home/user/sony_ir sony_on"
    sleep 1
    su user -c "/home/user/sony_ir sony_on"
    sleep 8
    su user -c "/home/user/sony_ir sony_v1"
    sleep 1
    su user -c "/home/user/sony_ir sony_v1"
    sleep 1
    su user -c "/home/user/sony_ir sony_v1"
    sleep 3
    su user -c "/home/user/sony_ir sony_v1"
    sleep 1
    su user -c "/home/user/sony_ir sony_v1"
fi
