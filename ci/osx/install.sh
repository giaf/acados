#!/usr/bin/env bash

travis_retry source "${SCRIPT_DIR}/install_ccache.sh";
travis_retry source "${SHARED_SCRIPT_DIR}/install_swig.sh";