#include "lcd-tools.h"

#include <iostream>
#include <dlfcn.h>
#include <hybris/common/binding.h>

int AsteroidOS::LCD_Tools::SyncTime() {
	void* handler;
	int (*syncTime)();
	handler = android_dlopen("libmcutool.so", RTLD_LAZY);
	if (!handler) {
		std::cerr << "Unable to load libmcutool.so" << std::endl;
		return -1;
	}
	syncTime = (int (*)())
			android_dlsym(handler, "Java_com_mobvoi_ticwear_mcuservice_CoreService_nativeSyncTime");
	if (!syncTime){
		std::cerr << "Unable to get symbol" << std::endl;
		android_dlclose(handler);
		return -1;
	}
	auto res = syncTime();
    if (android_dlclose(handler)){
		std::cerr << "Failed to safely close the library" << std::endl;
		return -1;
	}
	return res;
}
