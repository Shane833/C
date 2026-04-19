#include <stdio.h>
#include "dbg.h"

int main(){
    Debug_init(".");

    log_info("Hello, there!");

    Debug_close();
    return 0;
}

