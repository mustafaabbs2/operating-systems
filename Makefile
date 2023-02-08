# To compile on a Linux Machine:

# obj-m += simple.o
# all:
# 	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
# clean:
# 	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

# To compile on WSL:

obj-m += simple.o

all:
    make -C $(shell pwd)/WSL2-Linux-Kernel M=$(shell pwd) modules

clean:
    make -C $(shell pwd)/WSL2-Linux-Kernel M=$(shell pwd) clean
