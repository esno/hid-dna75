# hid-dna75

this is a linux kernel device driver for evolv dna75 chips.
It extends the hid subsystem to support dna75.

# linux kernel

## generic-usb

The `generic-usb` module binds all hid specific devices.
DNA75 is such a device therefore it will be attached/bind to this driver.
`generic-usb` doesn't support this chip but makes a device node to access it.

As long as `generic-usb` manages dna75 by default it cannot be bind to
the hid-dna75 module.

### unbind device

    echo -n "0003:268B:0408.0005" > /sys/bus/hid/drivers/generic-usb/unbind
    echo -n "0003:268B:0408.0005" > /sys/bus/hid/drivers/hid-dna75/bind

### patch kernel

The vendorId and productId has to be added to hid-core blacklist/special device driver list.
