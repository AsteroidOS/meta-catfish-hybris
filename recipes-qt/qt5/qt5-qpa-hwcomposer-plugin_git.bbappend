FILESEXTRAPATHS:prepend:catfish := "${THISDIR}/qt5-qpa-hwcomposer-plugin:"
SRC_URI:append:catfish = " \
    file://0002-Add-QCOM_BSP-define-switch.patch;striplevel=2 \
    file://004-Includes-sync.h-which-provides-sync_wait.patch;striplevel=2 \
    file://0001-Synchronize-time-on-LCD.patch;striplevel=2 \
"