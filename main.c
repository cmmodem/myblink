/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>
#include <stdlib.h>

#include "shell.h"

#include "board.h"
#include "thread.h"
#include "xtimer.h"
#include "periph/gpio.h"
#define LED0_PIN        GPIO5

char blink_thread_stack[THREAD_STACKSIZE_DEFAULT];
static const shell_command_t shell_commands[] = {
    { NULL, NULL, NULL }
};

void *blink_thread(void *arg)
{
    (void) arg;
    gpio_init(LED0_PIN,GPIO_OUT);
    while(1)
    {
        gpio_set(LED0_PIN);
        xtimer_sleep(1);
        gpio_clear(LED0_PIN);
        xtimer_sleep(1);
    }
}
int main(void)
{
    puts("Aplicación my_blink");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    thread_create(blink_thread_stack,sizeof(blink_thread_stack),THREAD_PRIORITY_MAIN-1,THREAD_CREATE_STACKTEST,blink_thread,NULL,"blink");
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);
}
