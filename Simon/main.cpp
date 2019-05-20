#include "SimonApp.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main() {

	// allocation
	auto app = new SimonApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	_CrtDumpMemoryLeaks();

	return 0;
}