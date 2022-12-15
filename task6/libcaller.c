#include <stdio.h>
#include <stdbool.h>

#if defined(LIBSTATIC) || defined(LIBDYNAMIC_S)

#include "mathlib.h"

void test() {

    printf("%.5f\n", add(2, 2));
	printf("%.5f\n", sub(10, 5));
	
	printf("%.5f\n", mul(2, 2));
	printf("%.5f\n", div(10, 5));
	
	printf("%.5f\n", pow2(5));
	printf("%.5f\n", pow3(5));
	printf("%.5f\n", pow4(5));

}

int main(void) {

    test();
	
	return 0;
}

#elif LIBDYNAMIC

#include <dlfcn.h>

void* libHandle;

float (*add)(float, float);
float (*sub)(float, float);

float (*mul)(float, float);
float (*div)(float, float);

float  (*pow2)(float);
float  (*pow3)(float);
float  (*pow4)(float);

bool init_dll() {
        
    libHandle = dlopen("/home/hexahero/Desktop/task6/dynamiclib.so", RTLD_LAZY);
    
    if (!libHandle) {
	    fprintf(stderr,"dlopen() error: %s\n", dlerror());
	    return 0;
    };
    
    return 1;
}

void import_functions() {
    
    add = dlsym(libHandle, "add");
    sub = dlsym(libHandle, "sub");
    
    mul = dlsym(libHandle, "mul");
    div = dlsym(libHandle, "div");

    pow2 = dlsym(libHandle, "pow2");
    pow3 = dlsym(libHandle, "pow3");
    pow4 = dlsym(libHandle, "pow4");
    
}

void test_functions() {
    
    printf("%.5f\n", add(2, 2));
	printf("%.5f\n", sub(10, 5));
	
	printf("%.5f\n", mul(2, 2));
	printf("%.5f\n", div(10, 5));
	
	printf("%.5f\n", pow2(5));
	printf("%.5f\n", pow3(5));
	printf("%.5f\n", pow4(5));

}

int main(void) {
    
    if (!init_dll())
        return 1;

    import_functions();
    test_functions();
	
	dlclose(libHandle);
	
	return 0;
}

#endif