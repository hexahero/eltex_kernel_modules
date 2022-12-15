#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
 
int len, temp;
 
char *msg;
 
ssize_t read_proc(struct file *filp, char *buf, size_t count, loff_t *offp )
{
    if(count > temp)
        count = temp;
        
    temp = temp-count;
    copy_to_user(buf, msg, count);
    
    if(count == 0)
        temp = len;
 
    return count;
}
 
ssize_t write_proc(struct file *filp, const char *buf, size_t count, loff_t *offp)
{
    copy_from_user(msg, buf, count);
    len = count;
    temp = len;
    return count;
}
 
 static struct proc_ops my_fops={
    .proc_read = read_proc,
    .proc_write = write_proc
 };
 
void create_new_proc_entry(void)  //use of void for no arguments is compulsory now
{
    proc_create("hello", 0, NULL, &my_fops);
    msg = kmalloc(10 * sizeof(char), GFP_KERNEL);
}
 
 
int procio_init (void) {
    create_new_proc_entry();
    return 0;
}
 
void procio_cleanup(void) {
    remove_proc_entry("hello",NULL);
    kfree(msg);
}
 
MODULE_LICENSE("GPL");
module_init(procio_init);
module_exit(procio_cleanup);