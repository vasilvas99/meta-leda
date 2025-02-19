EXTRA_IMAGEDEPENDS += "u-boot"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot virtual/bootloader:do_deploy"
UBOOT_EXTLINUX = "0"

#SERIAL_CONSOLES = "115200;ttyS0"

KERNEL_IMAGETYPE = "Image"
KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

UBOOT_SUFFIX = "bin"
KERNEL_BOOTCMD = "booti"
UBOOT_ENTRYPOINT = "0x40008000"
UBOOT_LOADADDRESS = "0x40008000"

# Output of U-Boot's "bdinfo" command on qemu-system-arm:
# boot_params = 0x00000000
# DRAM bank   = 0x00000000
# -> start    = 0x40000000              = 1073741824 dec = 1 GiB
# -> size     = 0x80000000              = 2147483648 dec = 2 GiB
# flashstart  = 0x00000000
# flashsize   = 0x04000000              =   67108864 dec = 64 MiB
# flashoffset = 0x000a9878              =     694392 dec = 678 KiB

MACHINE_FEATURES = "usbgadget usbhost vfat"

IMAGE_BOOT_FILES = "u-boot.${UBOOT_SUFFIX} ${KERNEL_IMAGETYPE} boot.scr"
IMAGE_CLASSES += "qemuboot"

QB_DEFAULT_BIOS = "u-boot.bin"
