#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

include dpf/Makefile.base.mk

all: libs plugins gen

# --------------------------------------------------------------

libs:
	$(MAKE) -C common
	$(MAKE) -C dpf/dgl ../build/libdgl-opengl.a

plugins: libs
	$(MAKE) all -C plugins/Fractal

ifneq ($(CROSS_COMPILING),true)
gen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh
ifeq ($(MACOS),true)
	@$(CURDIR)/dpf/utils/generate-vst-bundles.sh
endif

dpf/utils/lv2_ttl_generator:
	$(MAKE) -C dpf/utils/lv2-ttl-generator
else
gen:
endif

# --------------------------------------------------------------

clean:
	$(MAKE) clean -C dpf/dgl
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	$(MAKE) clean -C plugins/Fractal
	$(MAKE) clean -C common
	rm -rf bin build

# --------------------------------------------------------------
mingw:
	make WIN32=true CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++
mingwj:
	make -j WIN32=true CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++
.PHONY: plugins
