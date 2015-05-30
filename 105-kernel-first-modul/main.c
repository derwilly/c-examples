/* Ferdinand Saufler <mail@saufler.de>
 * 30.05.2015
 * write your first kernel module */

#include <linux/version.h>
#include <linux/module.h>
#include <linux/slab.h>

typedef struct driver {
    char name[15];
    char type[8];
    char version[6];
} Driver;

Driver *d;

static int __init mod_init (void)
{
    d = kmalloc(sizeof(Driver),GFP_KERNEL);
    strcpy(d->name,"amazing-driver");
    strcpy(d->type,"generic");
    strcpy(d->version,"0.0.1");
    printk("%s init_module called\n", d->name);
    printk("type: %s\n",d->type);
    printk("version: %s\n",d->version);
    return 0;
}

static void __exit mod_exit (void)
{
    printk("%s mod_exit called.\n", d->name);
    kfree(d);
}

module_init (mod_init);
module_exit (mod_exit);

// Metainformation
MODULE_AUTHOR ("Ferdinand Saufler");
MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("A generic Kernel Device Driver");
MODULE_SUPPORTED_DEVICE ("none");
