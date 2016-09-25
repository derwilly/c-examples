TARGET   = main
CC       =gcc
_OBJ     =main.o
_OBJ    +=address.o
_OBJ	+=test_list.o
_OBJ	+=test_file.o
_OBJ	+=test_str.o
_OBJ	+=test_kernel.o
_OBJ	+=test_net.o
OBJ      =$(patsubst %,$(O_DIR)/%,$(_OBJ))
OBJ_BIND =-lchf
LIBPATH  =../
vpath %.c $(LIBPATH)
CFLAGS   =-c -Wall -O -g -I$(LIBPATH)
LDFLAGS  =-L../
O_DIR    =bin

ARCH := $(shell uname -m)

ifeq ($(ARCH),x86_64)
	LD =ld-linux-x86-64.so.2
else
	LD =ld-linux.so.2
endif

# entry point
all: $(TARGET)

# link a binary from the object files
$(TARGET): $(OBJ)
	$(CC) -o $(O_DIR)/$(TARGET) $(OBJ) $(LDFLAGS) $(OBJ_BIND)

# Suffix rules
# $< source file (file.c)
# $@ destination file (file.o)
$(O_DIR)/%.o: %.c dir
	$(CC) $(CFLAGS) $< -o $@

dir:
	mkdir -p $(O_DIR)

valgrind:
	valgrind --tool=memcheck --leak-check=full /lib/$(LD) --library-path ../lib bin/main net

# cleanup the mess
clean:
	rm -rf $(O_DIR)/
	rm -f *~
	rm -f *.orig
