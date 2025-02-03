#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/alexcarnes/Documents/GitHub/random-step-lab
  make -f /Users/alexcarnes/Documents/GitHub/random-step-lab/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/alexcarnes/Documents/GitHub/random-step-lab
  make -f /Users/alexcarnes/Documents/GitHub/random-step-lab/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/alexcarnes/Documents/GitHub/random-step-lab
  make -f /Users/alexcarnes/Documents/GitHub/random-step-lab/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/alexcarnes/Documents/GitHub/random-step-lab
  make -f /Users/alexcarnes/Documents/GitHub/random-step-lab/CMakeScripts/ReRunCMake.make
fi

