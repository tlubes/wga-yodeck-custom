#include <wiringPi.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

#define LED 0

uint8_t frequency = 40;
char sony_on_str[] = "sony_on";
uint16_t sony_on[] = {0x60, 0x18, 0x18, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3ef};
char sony_off_str[] = "sony_off";
uint16_t sony_off[] = {0x60, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3d7};
char sony_v1_str[] = "sony_v1";
uint16_t sony_v1[] = {0x60, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x318};
char sony_v2_str[] = "sony_v2";
uint16_t sony_v2[] = {0x60, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x330};
uint8_t half_mark;

void mark(uint16_t dur){
    for(uint16_t i = 0; i < dur; i++){
        digitalWrite(LED, HIGH);
        delayMicroseconds(half_mark);
        digitalWrite(LED, LOW);
        delayMicroseconds(half_mark);
    }
}

void space(uint16_t dur){
    for(uint16_t i = 0; i < dur; i++){
        digitalWrite(LED, LOW);
        delayMicroseconds(half_mark);
        digitalWrite(LED, LOW);
        delayMicroseconds(half_mark);
    }
}

int main(int argc, char *argv[]){
    wiringPiSetup();
    pinMode(LED, OUTPUT);
    half_mark = ((1000 / frequency) / 2) - 1;
    if(!strcmp(argv[1], sony_on_str)){
        for(uint8_t i = 0; i < 4; i++){
            for(uint8_t i = 0; i < (sizeof(sony_on) / sizeof(sony_on[0])); i++){
                if (i & 0x01){
                    space(sony_on[i]);
                }else{
                    mark(sony_on[i]);
                }
            }
        }
    }else if(!strcmp(argv[1], sony_off_str)){
        for(uint8_t i = 0; i < 4; i++){
            for(uint8_t i = 0; i < (sizeof(sony_off) / sizeof(sony_off[0])); i++){
                if (i & 0x01){
                    space(sony_off[i]);
                }else{
                    mark(sony_off[i]);
                }
            }
        }
    }else if(!strcmp(argv[1], sony_v1_str)){
        for(uint8_t i = 0; i < 4; i++){
            for(uint8_t i = 0; i < (sizeof(sony_v1) / sizeof(sony_v1[0])); i++){
                if (i & 0x01){
                    space(sony_v1[i]);
                }else{
                    mark(sony_v1[i]);
                }
            }
        }
    }else if(!strcmp(argv[1], sony_v2_str)){
        for(uint8_t i = 0; i < 4; i++){
            for(uint8_t i = 0; i < (sizeof(sony_v2) / sizeof(sony_v2[0])); i++){
                if (i & 0x01){
                    space(sony_v2[i]);
                }else{
                    mark(sony_v2[i]);
                }
            }
        }
    }
}
