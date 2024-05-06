#!/bin/bash

# qmk compile -c -kb chocofi -km iltgg -e CONVERT_TO=rp2040_ce

bootloader=$(sudo lsblk -o NAME,LABEL -J | jq ".blockdevices[] | select(.children[0].label == \"RPI-RP2\") | .children[0].name" --raw-output)

if [ -z "$bootloader" ]; then
    echo "ERROR: bootloader not found"
    exit
fi

echo "MOUNTING BOOTLOADER"

sudo mkdir -p /run/media/$USER/RPI-RP2/
sudo mount /dev/$bootloader /run/media/$USER/RPI-RP2/
sudo chmod a+rw /run/media/$USER/RPI-RP2/
sudo chown $USER:$USER /run/media/$USER/RPI-RP2/

if [[ $1 == "left" ]]; then
    qmk flash -kb chocofi -km iltgg -bl uf2-split-left
elif [[ $1 == "right" ]]; then
    qmk flash -kb chocofi -km iltgg -bl uf2-split-right
else
    echo "COPYING UF2"

    sudo cp ~/qmk_firmware/chocofi_iltgg_rp2040_ce.uf2 /mnt/RPI-RP2

    echo "WAITING FOR MCU REBOOT"

    while lsusb | grep "Raspberry Pi RP2 Boot" > /dev/null; do
        sleep 1
    done

    echo "FLASHING COMPLETE"
fi
