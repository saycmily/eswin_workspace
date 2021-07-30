KERNAL_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
obj-m := hello_pc.o

caoyong:

	$(MAKE) -C $(KERNAL_DIR) M=$(PWD) modules
	make clear


clear:

	rm -f *.o *.cmd *.mod.c
	rm -rf *~ core .depend .tmp_versions Module.symvers modules.order
	rm -f *.mod
	rm -f *.unsigned

clean:

	rm -f hello_pc.ko
