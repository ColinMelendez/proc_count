#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

// function that will be called when the count file is accessed to count 
// and display the number of processes
static int proc_count_show(struct seq_file *m, void *v)
{
	// initialize a placeholder task_struct pointer and a counter
	struct task_struct *task;
	int count = 0;

	// iterate through the list of processes and increment the counter
	for_each_process(task) {
		count++;
	}

	// print the counter representing the number of processes to the /proc/count file
	seq_printf(m, "%d\n", count);
	return 0;
}

static int __init proc_count_init(void)
{
	// set up the count file in /proc to trigger the count-showing function when accessed
	proc_create_single("count", 0, NULL, proc_count_show);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	// clean-up by removing the count file from /proc
	remove_proc_entry("count", NULL);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Colin Melendez");
MODULE_DESCRIPTION("Counts the number of processes");
MODULE_LICENSE("GPL");
