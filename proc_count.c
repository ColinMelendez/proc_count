#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static int show()
{
	struct task_struct *task;
	int count = 0;

	for_each_process(task) {
		count++;
	}

	seq_printf(count);
	return 0;
}

static int __init proc_count_init(void)
{
	proc_create_single("proc_count", 0, NULL, show);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	remove_proc_entry("proc_count", NULL);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Colin Melendez");
MODULE_DESCRIPTION("Counts the number of processes");
MODULE_LICENSE("GPL");
