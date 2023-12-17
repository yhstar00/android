#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>

typedef void (*pfnfoo)(void);

//const char g_MainDir[] = "/data/local/tmp/libTargetLibrary.so";
//const char g_TargetSo[] = "libTargetLibrary.so";


int main()
{
    //char absolutepath[256] = {0};
    //snprintf(absolutepath, sizeof(absolutepath), "%s%s",g_MainDir, g_TargetSo);

    //void *handler = dlopen(absolutepath, RTLD_NOW);
    //void *handler = dlopen(g_MainDir, RTLD_NOW);
    void *handler = dlopen("/data/local/tmp/libTargetLibrary.so", RTLD_NOW);
    if(NULL == handler)
    {
        printf("[-] dlopen fail");
        return -1;
    }
    
    pfnfoo foo = (pfnfoo)dlsym(handler, "foo");
    
    foo();
    return 0;
}

