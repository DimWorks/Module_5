#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/version.h> 
 
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0) 
#define HAVE_PROC_OPS 
#endif 
 
#define NAME_FILE "test_proc"

int length, temp;
 
char *message;
 
ssize_t read_proc(struct file *filp,char *buf,size_t count,loff_t *offp )
{
    if(count>temp)
    {
        count=temp;
    }
    temp=temp-count;
    copy_to_user(buf,message, count);
    if(count==0)
        temp=length;
 
    return count;
}
 
ssize_t write_proc(struct file *filp,const char *buf,size_t count,loff_t *offp)
{
    copy_from_user(message,buf,count);

    length = count;
    temp = length;
 
    return count;
}
 
#ifdef HAVE_PROC_OPS 
static const struct proc_ops proc_fops = { 
    .proc_read = read_proc, 
    .proc_write = write_proc, 
}; 
#else 
static const struct file_operations proc_fops = { 
    .read = read_proc, 
    .write = write_proc, 
}; 
#endif 
 
void create_new_proc_entry(void)
{
    proc_create(NAME_FILE, 0, NULL, &proc_fops);

    message = kmalloc(10*sizeof(char), GFP_KERNEL);
}
 
 
int proc_init (void) 
{
    create_new_proc_entry();
    return 0;
}
 
void proc_cleanup(void) 
{
    remove_proc_entry(NAME_FILE, NULL);
    kfree(message);
}
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("DimWorks");
module_init(proc_init);
module_exit(proc_cleanup);