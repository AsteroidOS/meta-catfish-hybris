#include "lcd-tools.h"

#include <iostream>
#include <dlfcn.h>
#include <hybris/common/dlfcn.h>

int AsteroidOS::LCD_Tools::SyncTime() {
	auto lib_mcutool = hybris_dlopen("libmcutool.so", RTLD_LAZY);
	if (!lib_mcutool) {
		std::cerr << "Unable to load libmcutool.so" << std::endl;
		return -1;
	}
	auto syncTime = (int (*)())
			hybris_dlsym(lib_mcutool, "Java_com_mobvoi_ticwear_mcuservice_CoreService_nativeSyncTime");
	if (!syncTime) {
		std::cerr << "Unable to get symbol" << std::endl;
		hybris_dlclose(lib_mcutool);
		return -1;
	}
	auto res = syncTime();
	if (hybris_dlclose(lib_mcutool)) {
		std::cerr << "Failed to safely close the library" << std::endl;
		return -1;
	}
	return res;
}
