DEFAULTTUNE ?= "aarch32"

require conf/machine/include/arm/armv8a/tune-cortexa35.inc

TUNE_PKGARCH_32 = "${ARMPKGARCH}${ARMPKGSFX_THUMB}${ARMPKGSFX_EABI}${ARMPKGSFX_FPU}"

TUNEVALID[aarch32] = "Enable instructions for ARMv8-a"
TUNECONFLICTS[aarch32] = "armv4 armv5 armv6 armv7 armv7a"

MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'aarch32', 'aarch32:', '', d)}"

#TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'aarch32', ' -march=armv8-a -mcpu=cortex-a35', '', d)}"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'aarch32', ' -mcpu=cortex-a35 ', '', d)}"
# CPR: we would like to have: -mcpu=cortex-a35 -mfpu=neon-fp-armv8


TUNEVALID[fp-armv8] = "Enable ARMv8 Vector Floating Point unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'fp-armv8', ' fp-armv8', '', d)}"
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', [ 'fp-armv8', 'neon' ], ' neon-fp-armv8', '', d)}"

# Little Endian base configs
AVAILTUNES += "aarch32 aarch32t"
ARMPKGARCH:tune-aarch32                    ?= "aarch32"
ARMPKGARCH:tune-aarch32t                   ?= "aarch32"
TUNE_FEATURES:tune-aarch32                  = "arm aarch32 neon fp-armv8 callconvention-hard"
#TUNE_FEATURES:tune-aarch32t                 = "${TUNE_FEATURES:tune-aarch32} thumb"
#PACKAGE_EXTRA_ARCHS:tune-aarch32            = "aarch32hf-neon-fp-armv8"
#PACKAGE_EXTRA_ARCHS:tune-aarch32t           = "${PACKAGE_EXTRA_ARCHS:tune-aarch32} aarch32t2hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS:tune-aarch32            = "aarch32hf-neon-fp-armv8"
#PACKAGE_EXTRA_ARCHS:tune-aarch32t           = "${PACKAGE_EXTRA_ARCHS:tune-aarch32} aarch32thf-neon-fp-armv8"

BASE_LIB:tune-aarch32                       = "lib"
BASE_LIB:tune-aarch32t                      = "lib"

#TUNEVALID[cortexa35-a32] = "Enable Cortex-A35 specific processor optimizations"

#AVAILTUNES += "cortexa35_32 cortexa35_32t"
#ARMPKGARCH:tune-cortexa35_32      ?= "cortexa35"
#ARMPKGARCH:tune-cortexa35_32t     ?= "cortexa35"
#TUNE_FEATURES:tune-cortexa35_32   = "${TUNE_FEATURES:tune-aarch32} cortexa35"
#TUNE_FEATURES:tune-cortexa35_32t  = "${TUNE_FEATURES:tune-aarch32t} cortexa35"

#PACKAGE_EXTRA_ARCHS:tune-cortex35_32  = "${PACKAGE_EXTRA_ARCHS:tune-aarch32} cortexa35hf-neon-fp-armv8"
#PACKAGE_EXTRA_ARCHS:tune-cortex35_32t = "${PACKAGE_EXTRA_ARCHS:tune-cortexa35_32} cortexa35t2hf-neon-fp-armv8"
#PACKAGE_EXTRA_ARCHS:tune-cortex35_32  = "${PACKAGE_EXTRA_ARCHS:tune-aarch32} cortexa35 cortexa35hf-neon cortexa35hf-neon-fp-armv8"
#PACKAGE_EXTRA_ARCHS:tune-cortex35_32t = "${PACKAGE_EXTRA_ARCHS:tune-cortexa35_32} cortexa35hf-neon-fp-armv8"

#BASE_LIB:tune-cortexa35-32  = "lib"
#BASE_LIB:tune-cortexa35-32t = "lib"
