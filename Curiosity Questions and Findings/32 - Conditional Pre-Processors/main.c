#include <stdio.h>
#include "dbg.h"

int main(){
    //Debug_init(".");

    //log_info("Hello, there!");
    
    debug("Hello there!");
    
    log_err("This is an Error");

    log_warn("This is a Warning");

    log_info("This is an Info");
    
    int a = 5;
    //check(1 == 2, "False Result %d", a);
    
    //sentinel("Wasn't supposed to hit this!");
    
    //check_mem(5 == 6);

    check_debug(3 == 4, "Wrong Result");

error:
    //Debug_close();
    return 0;
}

