#!/usr/bin/env tcsh

# EE6470
setenv EE6470 "${HOME}/ee6470"

# SystemC
setenv SYSTEMC_HOME "/tools/linux/gnu/centos5/systemc"
setenv LD_LIBRARY_PATH "${SYSTEMC_HOME}/lib-linux:${LD_LIBRARY_PATH}"
setenv LD_LIBRARY_PATH "${SYSTEMC_HOME}/lib-linux64:${LD_LIBRARY_PATH}"
