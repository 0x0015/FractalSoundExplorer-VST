include Makefile.mk

OBJS = 
       #tcc/libtcc.a


all: $(OBJS)

#ifeq ($(WIN32), true)
#tcc/libtcc.a:
#	cd tcc; ./configure --enable-static --config-mingw32 --extra-cflags=-fPIC --enable-cross --with-libgcc -cc=$(CC); make
#else
#tcc/libtcc.a:
#	cd tcc; ./configure --enable-static --extra-cflags=-fPIC -cc=$(CC); make
#endif

clean:
	rm -f *.[od] */*.[od]
	#cd tcc; make clean
