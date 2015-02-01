# Ferdinand Saufler
# 04.11.2014

# vars
TARGET   = main
CC       =gcc
_OBJ     =main.o
OBJ      =$(patsubst %,$(O_DIR)/%,$(_OBJ))
OBJ_BIND =
LIBPATH  =../lib
vpath %.c $(LIBPATH)
CFLAGS   =-c -Wall -O -g -I$(LIBPATH)
O_DIR    =bin

include $(LIBPATH)/Makefile
