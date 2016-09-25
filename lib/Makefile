LIBNAME     =libchf
LIBVERSION  =0
FILEVERSION =0.0.10
TARGET      =$(LIBNAME).so.$(FILEVERSION)
INSTALLLIB  =/usr/local/lib/$(LIBNAME)
INSTALLINC  =/usr/local/include/$(LIBNAME)

CC          =gcc
OBJ         =check.o ctime.o file.o list.o str.o kernel.o net.o
OBJ_BIND    =
CFLAGS      =-c -Wall -O -g -fPIC

# entry point
all: $(TARGET)

# link a binary from the object files
$(TARGET): $(OBJ)
	$(CC) -shared -fPIC -Wl,-soname,$(LIBNAME).so.$(LIBVERSION) -o $(TARGET) $(OBJ)
	# create a static library
	ar rcs $(LIBNAME).a $(OBJ)

# Suffix rules
# $< source file (file.c)
# $@ destination file (file.o)
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.so* *.o *.a

install: installinc installlib

installlib:
	rm -rf $(INSTALLLIB)
	mkdir -p $(INSTALLLIB)
	cp $(TARGET) $(INSTALLLIB)
	ln -s $(INSTALLLIB)/$(TARGET) $(INSTALLLIB)/$(LIBNAME).so.$(LIBVERSION)
	ln -s $(INSTALLLIB)/$(TARGET) $(INSTALLLIB)/$(LIBNAME).so
	cp $(LIBNAME).a $(INSTALLLIB)
	echo $(INSTALLLIB) > /etc/ld.so.conf.d/$(LIBNAME).conf
	ldconfig

installinc:
	rm -rf $(INSTALLINC)
	mkdir -p $(INSTALLINC)
	cp *.h $(INSTALLINC)

uninstall:
	rm -rf $(INSTALLLIB)
	rm -f /etc/ld.so.conf.d/$(LIBNAME).conf
	ldconfig
