//
//  Canvas.h
//  Canvas
//
//  Created by Dmytro Anokhin on 30/10/2017.
//  Copyright © 2017 Dmytro Anokhin. All rights reserved.
//

#ifndef Canvas_h
#define Canvas_h


/// The Canvas represents drawing area. It contains specific information needed to render (such as size, pixel density, color space, etc.), whether the destination is a display, a printer, or a bitmap.
typedef struct Canvas *CanvasRef;

/// The color profile of a display
typedef enum ColorSpace {
    /// Standard RGB color space
    sRGB = 0,
    ///  Wide gamut RGB (DCI-P3) color space
    wideGamutRGB
} ColorSpace;

/// Returns width of the canvas in pixels
extern int CanvasGetWidth(CanvasRef canvas);

/// Returns height of the canvas in pixels
extern int CanvasGetHeight(CanvasRef canvas);

/// Creates canvas for rendering on a display
extern CanvasRef DisplayCanvasCreate(void);

/// Allocates memory for the canvas
extern CanvasRef CanvasCreate(void);

/// Deallocates memory occupied by the canvas
extern void CanvasFree(CanvasRef canvas);

/// Draws canvas to a destination
extern void CanvasDraw(CanvasRef canvas);

#endif /* Canvas_h */
