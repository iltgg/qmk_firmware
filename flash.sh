#!/bin/bash

# run to compile firmware
# qmk compile -c -kb chocofi -km iltgg -e CONVERT_TO=rp2040_ce

# run to flash firmware with EEPROM handedness (only needed once for certain MCUs)
# qmk flash -kb chocofi -km iltgg -bl uf2-split-left
# qmk flash -kb chocofi -km iltgg -bl uf2-split-right

retVal=0
if [[ $1 == "compile" ]]; then
    qmk compile -kb chocofi -km iltgg -e CONVERT_TO=rp2040_ce
    retVal=$?
fi
if [[ $1 == "clean_compile" ]]; then
    qmk compile -c -kb chocofi -km iltgg -e CONVERT_TO=rp2040_ce
    retVal=$?
fi

if [ $retVal -ne 0 ]; then
    echo "ERROR: Compilation Failed"
    exit $retVal
fi

for ((i = 0; i < 5; i++)); do
    echo "Searching for bootloader $((i+1))/5"
    bootloader=$(sudo lsblk -o NAME,LABEL -J | jq ".blockdevices[] | select(.children[0].label == \"RPI-RP2\") | .children[0].name" --raw-output)
    if [ -z "$bootloader" ]; then
        sleep 2
    fi
done

if [ -z "$bootloader" ]; then
    echo "ERROR: bootloader not found"
    exit 1
fi

echo "MOUNTING BOOTLOADER"

sudo mkdir -p /run/media/$USER/RPI-RP2/
sudo mount /dev/$bootloader /run/media/$USER/RPI-RP2/

echo "COPYING UF2"

sudo cp ~/qmk_firmware/chocofi_iltgg_rp2040_ce.uf2 /run/media/$USER/RPI-RP2

echo "WAITING FOR MCU REBOOT"

while lsusb | grep "Raspberry Pi RP2 Boot" > /dev/null; do
    sleep 1
done

echo "FLASHING COMPLETE"
