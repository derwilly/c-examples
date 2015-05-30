OBJ  =main
NAME =amazing-driver

obj-m += $(NAME).o
$(NAME)-objs := $(OBJ).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

install:
	sudo insmod $(NAME).ko

insmod: install

uninstall:
	sudo rmmod $(NAME)

rmmod: uninstall

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
