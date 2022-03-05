#include "lcd-tools.h"

#include <cxxopts.hpp>

using namespace AsteroidOS::LCD_Tools;

int main( int argc, char** argv ) {
	cxxopts::Options options("lcd-tools", "Various controls for the TicWatch LCD");
	options.add_options()
			("h,help", "Print usage")
			("sync-time", "Sync display time");
	auto input = options.parse(argc, argv);

	if (input.count("help")) {
		std::cout << options.help() << std::endl;
		return 0;
	}
	if (input["sync-time"].as<bool>()) {
		auto res = SyncTime();
		if (res)
			return res;
		std::cout << "Time synced" << std::endl;
	}
	return 0;
}
