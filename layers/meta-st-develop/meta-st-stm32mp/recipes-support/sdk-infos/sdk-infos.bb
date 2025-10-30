DESCRIPTION = "information file to help to use SDK source files"
HOMEPAGE = "www.st.com"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/BSD-3-Clause;md5=550794465ba0ec5312d6919e203a55f9"

SRC_URI:stm32mp1common      = "file://README.HOW_TO.txt.stm32mp1;destsuffix=sources"
SRC_URI:stm32mp2common      = "file://README.HOW_TO.txt.stm32mp2;destsuffix=sources"
SRC_URI:stm32mp2m33tdcommon = "file://README.HOW_TO.txt.stm32mp2-m33td;destsuffix=sources"

SRC_URI:append = " \
    file://generated_build_script-stm32mpx.sh;destsuffix=sources/ \
    "

S = "${WORKDIR}/sources"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(stm32mpcommon)"

inherit archiver
ARCHIVER_MODE[src] = "original"
inherit archiver_stm32mp_clean
