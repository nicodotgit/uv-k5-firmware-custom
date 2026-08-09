#!/bin/bash

FIRMWARE_DIR="${PWD}/compiled-firmware"

# Create firmware output directory if it doesn't exist
mkdir -p "$FIRMWARE_DIR"

# -------------------- CLEAN ALL ---------------------
clean() {
    echo "🧽 Cleaning all"
    make clean || true
    rm -f "$FIRMWARE_DIR"/*
}

# ------------------ BUILD VARIANTS ------------------
custom() {
    echo "🔧 Compiling Custom..."
    make clean
    make -s \
        EDITION_STRING=Custom \
        TARGET=f4hwn.custom
    cp f4hwn.custom* "$FIRMWARE_DIR"/
}

standard() {
    echo "📦 Compiling Standard..."
    make clean
    make -s \
        ENABLE_SPECTRUM=0 \
        ENABLE_FMRADIO=0 \
        ENABLE_AIRCOPY=0 \
        ENABLE_NOAA=0 \
        EDITION_STRING=Standard \
        TARGET=f4hwn.standard
    cp f4hwn.standard* "$FIRMWARE_DIR"/
}

bandscope() {
    echo "📺 Compiling Bandscope..."
    make clean
    make -s \
        ENABLE_SPECTRUM=1 \
        ENABLE_FMRADIO=0 \
        ENABLE_VOX=0 \
        ENABLE_AIRCOPY=1 \
        ENABLE_FEAT_F4HWN_SCREENSHOT=1 \
        ENABLE_FEAT_F4HWN_GAME=0 \
        ENABLE_FEAT_F4HWN_PMR=1 \
        ENABLE_FEAT_F4HWN_GMRS_FRS_MURS=1 \
        ENABLE_NOAA=0 \
        ENABLE_FEAT_F4HWN_RESCUE_OPS=0 \
        EDITION_STRING=Bandscope \
        TARGET=f4hwn.bandscope
    cp f4hwn.bandscope* "$FIRMWARE_DIR"/
}

broadcast() {
    echo "📻 Compiling Broadcast..."
    make clean
    make -s \
        ENABLE_SPECTRUM=0 \
        ENABLE_FMRADIO=1 \
        ENABLE_VOX=1 \
        ENABLE_AIRCOPY=1 \
        ENABLE_FEAT_F4HWN_SCREENSHOT=1 \
        ENABLE_FEAT_F4HWN_GAME=0 \
        ENABLE_FEAT_F4HWN_PMR=1 \
        ENABLE_FEAT_F4HWN_GMRS_FRS_MURS=1 \
        ENABLE_NOAA=0 \
        ENABLE_FEAT_F4HWN_RESCUE_OPS=0 \
        EDITION_STRING=Broadcast \
        TARGET=f4hwn.broadcast
    cp f4hwn.broadcast* "$FIRMWARE_DIR"/
}

basic() {
    echo "☘️ Compiling Basic..."
    make clean
    make -s \
        ENABLE_SPECTRUM=1 \
        ENABLE_FMRADIO=1 \
        ENABLE_VOX=0 \
        ENABLE_AIRCOPY=0 \
        ENABLE_FEAT_F4HWN_GAME=0 \
        ENABLE_FEAT_F4HWN_SPECTRUM=0 \
        ENABLE_FEAT_F4HWN_PMR=1 \
        ENABLE_FEAT_F4HWN_GMRS_FRS_MURS=1 \
        ENABLE_NOAA=0 \
        ENABLE_AUDIO_BAR=0 \
        ENABLE_FEAT_F4HWN_RESUME_STATE=0 \
        ENABLE_FEAT_F4HWN_CHARGING_C=0 \
        ENABLE_FEAT_F4HWN_INV=1 \
        ENABLE_FEAT_F4HWN_CTR=0 \
        ENABLE_FEAT_F4HWN_NARROWER=1 \
        ENABLE_FEAT_F4HWN_RESCUE_OPS=0 \
        EDITION_STRING=Basic \
        TARGET=f4hwn.basic
    cp f4hwn.basic* "$FIRMWARE_DIR"/
}

rescueops() {
    echo "🚨 Compiling RescueOps..."
    make clean
    make -s \
        ENABLE_SPECTRUM=0 \
        ENABLE_FMRADIO=0 \
        ENABLE_VOX=1 \
        ENABLE_AIRCOPY=1 \
        ENABLE_FEAT_F4HWN_SCREENSHOT=1 \
        ENABLE_FEAT_F4HWN_GAME=0 \
        ENABLE_FEAT_F4HWN_PMR=1 \
        ENABLE_FEAT_F4HWN_GMRS_FRS_MURS=1 \
        ENABLE_NOAA=1 \
        ENABLE_FEAT_F4HWN_RESCUE_OPS=1 \
        EDITION_STRING=RescueOps \
        TARGET=f4hwn.rescueops
    cp f4hwn.rescueops* "$FIRMWARE_DIR"/
}

game() {
    echo "🎮 Compiling Game..."
    make clean
    make -s \
        ENABLE_SPECTRUM=0 \
        ENABLE_FMRADIO=1 \
        ENABLE_VOX=0 \
        ENABLE_AIRCOPY=1 \
        ENABLE_FEAT_F4HWN_GAME=1 \
        ENABLE_FEAT_F4HWN_PMR=1 \
        ENABLE_FEAT_F4HWN_GMRS_FRS_MURS=1 \
        ENABLE_NOAA=0 \
        ENABLE_FEAT_F4HWN_RESCUE_OPS=0 \
        EDITION_STRING=Game \
        TARGET=f4hwn.game
    cp f4hwn.game* "$FIRMWARE_DIR"/
}

nicodotgit() {
    echo "🧰 Compiling nicodotgit..."
    make clean
    make -s \
        ENABLE_SPECTRUM=1 \
        ENABLE_FMRADIO=1 \
        ENABLE_VOX=0 \
        ENABLE_AIRCOPY=0 \
        ENABLE_FEAT_F4HWN_SCREENSHOT=0 \
        ENABLE_FEAT_F4HWN_GAME=0 \
        ENABLE_FEAT_F4HWN_PMR=0 \
        ENABLE_FEAT_F4HWN_GMRS_FRS_MURS=0 \
        ENABLE_NOAA=0 \
        ENABLE_FEAT_F4HWN_RESCUE_OPS=0 \
        ENABLE_TX1750=0 \
        ENABLE_ALARM=0 \
        ENABLE_FEAT_F4HWN_VOL=0 \
        ENABLE_PWRON_PASSWORD=0 \
        ENABLE_FEAT_F4HWN_SLEEP=0 \
        ENABLE_SHOW_CHARGE_LEVEL=0 \
        ENABLE_DTMF_CALLING=0 \
        ENABLE_FEAT_F4HWN_INV=1 \
        ENABLE_KEEP_MEM_NAME=1 \
        ENABLE_CUSTOM_MENU_LAYOUT=1 \
        ENABLE_SMALL_BOLD=1 \
        ENABLE_COPY_CHAN_TO_VFO=1 \
        ENABLE_AUDIO_BAR=0 \
        ENABLE_FEAT_F4HWN_RESUME_STATE=1 \
        ENABLE_BIG_FREQ=1 \
        ENABLE_RSSI_BAR=1 \
        ENABLE_FEAT_F4HWN_CTR=1 \
        ENABLE_FLASHLIGHT=1 \
        ENABLE_AM_FIX=1 \
        ENABLE_EXPERIMENTAL_CFLAGS=0 \
        EDITION_STRING=nicodotgit \
        TARGET=f4hwn.nicodotgit
    cp f4hwn.nicodotgit* "$FIRMWARE_DIR"/
}

# ------------------ MENU ------------------
case "$1" in
    clean) clean ;;
    custom) custom ;;
    standard) standard ;;
    bandscope) bandscope ;;
    broadcast) broadcast ;;
    basic) basic ;;
    rescueops) rescueops ;;
    game) game ;;
    nicodotgit) nicodotgit ;;
    all)
        bandscope
        broadcast
        basic
        rescueops
        game
        nicodotgit
        ;;
    *)
        echo "Usage: $0 {clean|custom|standard|bandscope|broadcast|basic|rescueops|game|nicodotgit|all}"
        exit 1
        ;;
esac
