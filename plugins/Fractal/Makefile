#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

# --------------------------------------------------------------
# Project name, used for binaries

NAME = Fractal

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	PluginFractal.cpp

FILES_UI  = #\
	#ArtworkCycleShifter.cpp \
	#UICycleShifter.cpp

# --------------------------------------------------------------
# Do some magic
UI_TYPE = external
include ../../dpf/Makefile.plugins.mk

PKG_CONFIG ?= pkg-config

BUILD_CXX_FLAGS += --std=c++17

LINK_OPTS += -lm

ifeq ($(LINUX), true)
#LINK_OPTS += -L../../common/SDL2/x86_64-linux/lib
#LINK_OPTS += $(shell $(PKG_CONFIG) --libs sfml) 
LINK_OPTS += $(shell $(PKG_CONFIG) --libs gl)
LINK_OPTS += -lsfml-graphics -lsfml-window -lsfml-system
LINK_OPTS += -lpthread
endif

ifeq ($(WIN32),true)
BUILD_CXX_FLAGS += -DSFML_STATIC
LINK_OPTS += -L../../common/win_opengl -l:OpenGL32.Lib
LINK_OPTS += -L../../common/dlfcn-win32 -l:libdl.a
#lINK_OPTS += -L/usr/x86_64-w64-mingw32/lib
LINK_OPTS += -L../../dpf/build -l:libdgl-opengl.a
LINK_OPTS += -L../../common/SFML-2.5.1/lib -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lfreetype
#LINK_OPTS += -l:libdgl.a
LINK_OPTS += -static -static-libgcc -static-libstdc++ -lhid
LINK_OPTS += -lmingw32 -mwindows  -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -lglu32 -lopengl32 
#LINK_OPTS += $(DGL_LIBS)
LINK_OPTS += -fno-stack-protector -fstack-protector
LINK_OPTS += $(OBJS_opengl)
else
LINK_OPTS += -ldl
endif


# --------------------------------------------------------------
# Enable all possible plugin types

ifeq ($(LINUX),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_JACK),true)
TARGETS += jack
endif
endif
endif

ifeq ($(HAVE_DGL),true)
TARGETS += lv2_sep
else
TARGETS += lv2_dsp
endif

TARGETS += vst

all: $(TARGETS)

# --------------------------------------------------------------
