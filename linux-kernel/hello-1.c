#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


int simple_init(void)
{
    printk(KERN_INFO "Hello world\n"); //kernel equivalent of printf 
    return 0;
}

void simple_exit(void)
{
    printk(KERN_INFO "Goodbye world\n");
}
