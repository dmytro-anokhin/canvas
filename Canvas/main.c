//
//  main.c
//  Canvas
//
//  Created by Dmytro Anokhin on 30/10/2017.
//  Copyright © 2017 Dmytro Anokhin. All rights reserved.
//

#include <stdio.h>
#include "Canvas.h"


int main(int argc, const char * argv[]) {
    CanvasRef canvas = DisplayCanvasCreate();
    CanvasDraw(canvas);
    CanvasFree(canvas);
    
    return 0;
}
