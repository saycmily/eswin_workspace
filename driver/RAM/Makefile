KERNELDIR := /usr/src/linux-headers-$(shell uname -r)
 
CURRENT_PATH := $(shell pwd)
 
obj-m := hello_ram.o
 
caoyong: kernel_modules

	make clear
 
kernel_modules:

	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules

clear:

	rm -f *.o *.mod.c *mod
	rm -rf *Module.symvers modules.order

clean:

	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean
