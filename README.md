# wga-yodeck-custom
custom on and off scripts for the WGA digital signage

## Pi prerequisites
SSH into Pi https://www.yodeck.com/docs/display/YO/Remotely+access+your+Yodeck+player+by+using+SSH

    ssh user@ipaddr

Allow user to access GPIO peripherals

    sudo usermod -aG gpio user
    sudo reboot

Install WiringPi library

    sudo apt-get install wiringpi

Compile and link against wigingpi in home directory

    gcc -lwiringPi -o sony_ir sony_ir.c
    gcc -lwiringPi -o samsung_ir samsung_ir.c

## Yodeck instructions to add script
Found here:
https://www.yodeck.com/docs/pages/viewpage.action?pageId=327908
Use any of the two scripts for this depending on the Yodeck location
