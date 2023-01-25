# A Kernel Seedling

One sentence description

This is a utility process to report the number of active processes on the machine.

## Building

Explain how to build your kernel module

1.  Compile the module with the command "make".
        This uses the makefile to generate "proc_count.ko" 

## Running

Explain how to run your kernel module and what to expect

1.  Load the compiled module into the kernel by running: "sudo insmod proc_count.ko"
2.  Use the program by running: "cat /proc/count"

This will result in a number representing the number of processes currently running being written to the terminal as a single integer. The module will remain loaded in the kernel.

You can check that the module was loaded correctly by running: "lsmod | grep proc_count" and seeing if proc_count is output to the terminal. If nothing is printed by that command, then something went wrong; try the building and load process again before running. 

You can also check that the file was correctly added by looking for count in the /proc directory.

## Cleaning Up

Explain how to remove your kernel module and clean up the code

1.  Run the command: "sudo rmmod proc_count"

The Kernel should no longer contain the proc_count module and /proc/count will have been deleted.

You can check that the module was unloaded correctly by running: "lsmod | grep proc_count" and seeing if anything is returned. If nothing is printed by that command, then the program was unloaded successfully. 

## Testing

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

Kernel Version: 1.14.8-arch1-1
