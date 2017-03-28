/*Using timer_list as a timer inside Linux kernel.
* This timer goes off every 100 msec.
*/
/*----------------------------------------------------------------------*/
/*timer_list data structre*/
static struct timer_list my_timer;

/*A flag to be set true and false every 100 msec*/
bool print_flag = true;

/*This function will be called every 100 msec to set print_flag to true*/
void my_timer_callback(unsigned long data)
{
	print_flag = true;
}

/*A flag to be used to intialize the timer one time only*/
bool key = true;


/*Initializing the timer struct for the first and only time*/
if (key)   {
	init_timer(&my_timer);
	my_timer.expires = jiffies + msecs_to_jiffies(100);
	my_timer.function = my_timer_callback;
	my_timer.data = 0;
	add_timer(&my_timer);
	key = false;
	/*key will never become true again*/
}



/* Put the following code inside a function or a module where you want to timely control something. */

if (print_flag)   {

/*Add your work here. For example, print current kernel time: */
	now = jiffies_to_msecs(tcp_time_stamp);
	trace_printk("Time=%u msec\n", now);
	print_flag = false;


	/*updating the timer*/
		mod_timer(&my_timer, jiffies + msecs_to_jiffies(100));
}	
