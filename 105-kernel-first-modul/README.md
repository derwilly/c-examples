Building your first Kernel Modul
================================
Author: Ferdinand Saufler <mail@saufler.de> <br>
Date:   30.05.2015

This example describes how to build your first generic kernel driver.

Build the Driver
----------------
Just switch to the Driver Directory and type:
``` bash
make
```

Make sure you have the headers for your kernel installed before. On Ubuntu
you can install them with:
``` bash
sudo apt-get install linux-headers-$(uname -r)
```

On Arch-Linux use Pacman to get the headers with:
``` bash
sudo pacman -S linux-headers
```

The next step is to load the modul in the running kernel, i created a
makefile-target for you:
``` bash
make insmod

# or use
sudo insmod amazing-diver.ko
```

After that check dmesg, the Driver should print a message like this:
``` config
[ 2138.046530] amazing-driver init_module called
[ 2138.046532] type: generic
[ 2138.046532] version: 0.0.1
[ 2145.073329] amazing-driver mod_exit called.
```

To unload the Driver simply use makefile again:
``` bash
make rmmod

# or use
sudo rmmod amazing-driver
```
