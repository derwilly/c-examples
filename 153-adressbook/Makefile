TARGET   = main
CC       =gcc
_OBJ     =main.o
_OBJ    +=list.o
_OBJ    +=address.o
OBJ      =$(patsubst %,$(O_DIR)/%,$(_OBJ))
OBJ_BIND =
LIBPATH  =../lib
vpath %.c $(LIBPATH)
CFLAGS   =-c -Wall -O -g -I$(LIBPATH)
O_DIR    =bin

include $(LIBPATH)/Makefile
