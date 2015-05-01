TARGET   = main
CC       =gcc
_OBJ     =main.o
_OBJ	+=file.o
OBJ      =$(patsubst %,$(O_DIR)/%,$(_OBJ))
OBJ_BIND = -lcurses
LIBPATH  =../lib
vpath %.c $(LIBPATH)
CFLAGS   =-c -Wall -O -g -I$(LIBPATH)
O_DIR    =bin

include $(LIBPATH)/Makefile
