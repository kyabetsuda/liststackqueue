//
//  error.c
//  liststackque
//
//  Created by 津田準 on 2017/12/02.
//  Copyright © 2017 津田準. All rights reserved.
//

#include "error.h"

void error(char *s){
    fprintf(stderr, s);
    exit(1);
}
