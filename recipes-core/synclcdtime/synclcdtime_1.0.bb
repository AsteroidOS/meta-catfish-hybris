DESCRIPTION = "Small wrapper to sync LCD time"
PR = "r0"
SRC_URI = "file://synclcdtime.service \
           file://synclcdtime.timer \
           file://synclcdtime.c \
           file://CMakeLists.txt \
           file://COPYING"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://COPYING;md5=84dcc94da3adb52b53ae4fa38fe49e5d"
S = "${WORKDIR}"
PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "catfish"
inherit cmake

do_install:append() {
    install -d ${D}/etc/systemd/system/timers.target.wants/
    cp ../synclcdtime.service ${D}/etc/systemd/system/
    cp ../synclcdtime.timer ${D}/etc/systemd/system/
    ln -s ../synclcdtime.timer ${D}/etc/systemd/system/timers.target.wants/synclcdtime.timer
}
