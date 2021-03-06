#pragma once
#include "global.h"
#include "coord_draw.h"
#include "color_selector.h"
#include "UI.h"
#include "save_file.h"
#include "EGEEnvironmentController.h"
#include "mouse_draw_circle.h"
#include "mouse_draw_line.h"
#include "mouse_draw_polygon.h"
#include "mouse_draw_rectangle.h"
#include "operator_test.h"

extern WORD g_nTotalShapes;
extern bool g_isFileEdited;
extern EGEEnvironmentController graphicsEnvironment;

void Menu(bool readResult);
void PrintMenu(short int lnToPrint);