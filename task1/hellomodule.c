#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zykov_Vladislav");
MODULE_DESCRIPTION("A Simple Hello World module");

static int __init hellomodule_init(void)
{
    printk(KERN_INFO "Hello world!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hellomodule_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hellomodule_init);
module_exit(hellomodule_cleanup);