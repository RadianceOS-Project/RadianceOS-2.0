# RadianceOS 2.0

## Getting started
It's difficult to get started since you'll need a few things, but basically grab a VM, a WSL instance (Unless you're already using Linux) and install a few things.

Run this:
```
sudo apt install make
sudo apt install build-essential
sudo apt install nasm
sudo apt install qemu
sudo apt install git
sudo apt install xorriso
sudo apt install qemu-system-x86
```

Then run this: `make` and then `make run`, if you have some fancy software it should open up a Qemu window with it in, else, you probably don't and you'll have to stick it in a VM yourself.