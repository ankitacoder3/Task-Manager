#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task Displayer");
MODULE_AUTHOR("<AUTHOR NAME>");

// Kernel Module to list all tasks from init to the current task and their respective PIDs

void print_task(struct task_struct *task)
{
    printk(KERN_INFO " Task: %s,PID: %d\n", task->comm, task->pid);
}

void print_tasks(void)
{
    struct task_struct *task;
    for_each_process(task)
    {
        print_task(task);
    }
}

// Module Initialization
static int __init Task_Displayer_init(void)
{
    printk(KERN_INFO "Task Displayer Module Loaded\n");
    print_tasks();
    return 0;
}

// Module Exit
static void __exit Task_Displayer_exit(void)
{
    printk(KERN_INFO "Task Displayer Module Unloaded\n");
}

// Call the init and exit functions
module_init(Task_Displayer_init);
module_exit(Task_Displayer_exit);
