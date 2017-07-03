#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

#include "hid-ids.h"

MODULE_AUTHOR("Matthias Hauber <mail@matthiashauber.de>");
MODULE_DESCRIPTION("HID Evolv DNA 75 driver");
MODULE_LICENSE("GPL");

static int hid_dna75_probe(struct hid_device *hdev, const struct hid_device_id *id);

static struct hid_device_id hid_dna75_id_table[] = {
	{ HID_USB_DEVICE(USB_VENDOR_ID_EVOLV, USB_DEVICE_ID_EVOLV_DNA75) },
	{} // terminating entry
};
MODULE_DEVICE_TABLE(hid, hid_dna75_id_table);

static struct hid_driver hid_dna75_driver = {
	.name = "hiddna75",
	.probe = hid_dna75_probe,
	.id_table = hid_dna75_id_table,
};
module_hid_driver(hid_dna75_driver);

static int hid_dna75_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
	printk(KERN_INFO "[*] Evolv DNA 75 initialized (%04X:%04X)",
			id->vendor, id->product);
	return 0;
}
