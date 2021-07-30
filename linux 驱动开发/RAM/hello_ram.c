#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static __init int hello_init(void)
{
    printk(KERN_ALERT "Hello, caoyong IoT Studio!\n");
    return 0;
}

static __exit void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, I have found a good job!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("caoyong<1786386686@qq.com>");
MODULE_DESCRIPTION("Linux Kernel hello module (C) caoyong IoT Studio");
MODULE_LICENSE("Dual BSD/GPL");
