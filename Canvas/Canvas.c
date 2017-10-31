//
//  Canvas.c
//  Canvas
//
//  Created by Dmytro Anokhin on 30/10/2017.
//  Copyright © 2017 Dmytro Anokhin. All rights reserved.
//

#include "Canvas.h"

#include <stdio.h>
#include <stdlib.h>


// Forwar declarations

void _CanvasDraw(struct Canvas *canvas);

typedef struct DisplayCanvas DisplayCanvas;
void _DisplayCanvasDraw(struct DisplayCanvas *canvas);


// Virtual Tables


typedef struct CanvasVTable {
    void (*draw)(struct Canvas *canvas);
} CanvasVTable;


typedef struct DisplayCanvasVTable {
    void (*draw)(struct DisplayCanvas *canvas);
} DisplayCanvasVTable;


const CanvasVTable kCanvasVTable = {
    _CanvasDraw
};

const DisplayCanvasVTable kDisplayCanvasVTable = {
    _DisplayCanvasDraw
};


// Structures

typedef struct Canvas {
    int width;
    int height;
    const CanvasVTable *vtable;
} Canvas;


typedef struct DisplayCanvas {
    Canvas super;
    ColorSpace colorSpace;
} DisplayCanvas;


// Accessors

int CanvasGetWidth(CanvasRef canvas) {
    return canvas != NULL ? canvas->width : 0;
}

int CanvasGetHeight(CanvasRef canvas) {
    return canvas != NULL ? canvas->height : 0;
}

// Creation and memory management

CanvasRef DisplayCanvasCreate(void) {
    DisplayCanvas *canvas = (DisplayCanvas *)malloc(sizeof(DisplayCanvas));
    
    if (canvas == NULL) {
        return NULL;
    }
    
    canvas->super.width = 320;
    canvas->super.height = 240;
    canvas->super.vtable = (CanvasVTable *) &kDisplayCanvasVTable;
    canvas->colorSpace = wideGamutRGB;
    
    return (CanvasRef)canvas;
};

CanvasRef CanvasCreate(void) {
    Canvas *canvas = (Canvas *)malloc(sizeof(Canvas));
    
    if (canvas == NULL) {
        return NULL;
    }
    
    canvas->width = 320;
    canvas->height = 240;
    canvas->vtable = &kCanvasVTable;
  
    return (CanvasRef)canvas;
};

void CanvasFree(CanvasRef canvas) {
    if (canvas == NULL) {
        return;
    }
    
    free(canvas);
};

// Drawing

void CanvasDraw(CanvasRef canvas) {
    if (canvas == NULL || canvas->vtable == NULL || canvas->vtable->draw == NULL) {
        return;
    }
    
    canvas->vtable->draw(canvas);
}

void _CanvasDraw(struct Canvas *canvas) {
    if (canvas == NULL) {
        return;
    }
    
    printf("width: %d, height: %d\n", canvas->width, canvas->height);
}

void _DisplayCanvasDraw(struct DisplayCanvas *canvas) {
    if (canvas == NULL) {
        return;
    }
    
    printf("width: %d, height: %d, color space: %d\n", canvas->super.width, canvas->super.height, canvas->colorSpace);
}

