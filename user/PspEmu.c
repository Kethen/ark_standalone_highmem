/*
  Adrenaline
  Copyright (C) 2016-2018, TheFloW

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <vitasdk.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <taihen.h>

#include "Log.h"
#include "PspEmu.h"

static SceUID ram_patches[3];

int pspemu_module_start(tai_module_info_t tai_info) {
	// Adjust RAM size the way adrenaline did
	uint32_t cmp_a4_3C00000 = 0x7F70F1B3;
	ram_patches[0] = taiInjectData(tai_info.modid, 0, 0x6394, &cmp_a4_3C00000, sizeof(cmp_a4_3C00000));

	uint32_t cmp_v2_3C00000 = 0x7F70F1B5;
	ram_patches[1] = taiInjectData(tai_info.modid, 0, 0x6434, &cmp_v2_3C00000, sizeof(cmp_v2_3C00000));

	uint32_t cmp_a3_3C00000 = 0x7F70F1B2;
	ram_patches[2] = taiInjectData(tai_info.modid, 0, 0x6534, &cmp_a3_3C00000, sizeof(cmp_a3_3C00000));

	return SCE_KERNEL_START_SUCCESS;
}

int pspemu_module_stop() {
	for (int i = 0;i < 3;i++){
		taiInjectRelease(ram_patches[i]);
	}
	
	return SCE_KERNEL_STOP_SUCCESS;
}
