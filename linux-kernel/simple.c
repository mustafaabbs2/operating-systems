//create a simple module to load into the Linux kernel

//you cannot load module into WSL2, you will need to build your own

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// https://github.com/MarziehAhmadiNa/Operating-system-project2/blob/master/LKM2.6.pdf

int simple_init(void)
{
    printk(KERN_INFO "Hello world\n"); //kernel equivalent of printf 
    return 0;
}

void simple_exit(void)
{
    printk(KERN_INFO "Goodbye world\n");
}


module_init(simple_init); //function to be called when the module is loaded
module_exit(simple_exit); //function to be called when the module is removed

//standard practice to have these...
MODULE_LICENSE("GPL"); //module license
MODULE_DESCRIPTION("Simple Module"); //module description
MODULE_AUTHOR("Mustafa"); //module author


