DESCRIPTION = "Small wrapper to sync LCD time"
PR = "r0"
DEPENDS = "libhybris"
SRC_URI = "file://lcd-sync-time.service \
           file://lcd-sync-time.timer \
           file://lcd-sync-time.cpp \
           file://lcd-tools.cpp \
           file://lcd-tools.h \
           file://CMakeLists.txt \
           file://COPYING \
           git://github.com/jarro2783/cxxopts;protocol=https;tag=v3.0.0;destsuffix=third-party/cxxopts/"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://COPYING;md5=84dcc94da3adb52b53ae4fa38fe49e5d"
S = "${WORKDIR}"
PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "catfish"
inherit cmake pkgconfig

do_install:append() {
    install -d ${D}/etc/systemd/system/timers.target.wants/
    cp ${S}/lcd-sync-time.service ${D}/etc/systemd/system/
    cp ${S}/lcd-sync-time.timer ${D}/etc/systemd/system/
    ln -s ../lcd-sync-time.timer ${D}/etc/systemd/system/timers.target.wants/lcd-sync-time.timer
}
