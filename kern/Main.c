// this is a stripped down version of https://github.com/LiEnby/NoPspEmuDrm

#include <vitasdkkern.h>
#include <taihen.h>

#include "HighMem.h"

void _start() __attribute__ ((weak, alias("module_start")));
int module_start(SceSize args, void *argp) {	
	// Enable extra PSP memory
	init_highmem();
	
	return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize args, void *argp) {
	term_highmem();
		
	return SCE_KERNEL_STOP_SUCCESS;
}
