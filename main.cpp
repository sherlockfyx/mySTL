#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

#include "inc/mystring.h"
#include "inc/mysingleton.h"
#include "inc/mystruct.h"

bool Letter(unsigned x){
    unsigned a = (x&0x22222222);
    unsigned b = (x&0x44444444)>>1;
    unsigned c = x>>2;
    return c&(a|b);
}


int main(){


//    cout<<Letter(0xff3435)<<endl;
//    cout<<Letter(0x433435)<<endl;

    return 0;
}

