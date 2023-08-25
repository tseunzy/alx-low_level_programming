#include <stdio.h>

void pre_main_func(void);

/**
 * pre_main_func - Print specific lines before the main function executes.
 *
 * This function is designed to be executed before main() using the
 * __attribute__((constructor)) attribute. It prints the lines:
 * "You're beat! and yet, you must allow,"
 * "I bore my house upon my back!"
 */
__attribute__((constructor))
void pre_main_func(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
