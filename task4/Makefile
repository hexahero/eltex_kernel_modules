obj-m += netlinkmodule.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc userapp.c -o usrapp
	
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
