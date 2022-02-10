#include <stdio.h>
//#include <dlfcn.h>
//#include <hybris/common/binding.h>

int main() {
	printf("Hello World!\n");
//	void* handler;
//	int (*syncTime)();
//	handler = android_dlopen("libmcutool.so", RTLD_LAZY);
//	if (!handler) {
//		fprintf(stderr, "Unable to load libmcutool.so\n");
//		return -1;
//	}
//	syncTime = (int (*)())
//			android_dlsym(handler, "Java_com_mobvoi_ticwear_mcuservice_CoreService_nativeSyncTime");
//	if (!syncTime){
//        fprintf(stderr, "Unable to get symbol\n");
//		return -1;
//	}
//	auto res = syncTime();
////	return res;
	return 0;
}
