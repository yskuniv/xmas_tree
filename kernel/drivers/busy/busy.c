#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>

#define DEVICE_NAME "busy"
#define DEVICE_MAJOR 63

MODULE_DESCRIPTION("Busy device");
MODULE_AUTHOR("ysk");
MODULE_LICENSE("GPL");

static int busy_init(void);
static void busy_exit(void);

static int busy_open(struct inode *inode, struct file *file);
static int busy_close(struct inode *inode, struct file *file);
static ssize_t busy_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
static ssize_t busy_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);

static ssize_t busy_read_write_common(size_t count);
static void do_busy(size_t count);

static const struct file_operations busy_fops = {
    .open = busy_open,
    .release = busy_close,
    .read = busy_read,
    .write = busy_write,
};

static int busy_init(void)
{
    printk("busy device loaded\n");

    register_chrdev(DEVICE_MAJOR, DEVICE_NAME, &busy_fops);

    return 0;
}

static void busy_exit(void)
{
    printk("busy device unloaded\n");

    unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
}

module_init(busy_init);
module_exit(busy_exit);

static int busy_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int busy_close(struct inode *inode, struct file *file)
{
    return 0;
}

static ssize_t busy_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    return busy_read_write_common(count);
}

static ssize_t busy_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    return busy_read_write_common(count);
}

static ssize_t busy_read_write_common(size_t count)
{
    do_busy(count);

    return -EBUSY;
}

static void do_busy(size_t count)
{
    volatile size_t i;

    for (i = 0; i < count; i++)
        ;
}
