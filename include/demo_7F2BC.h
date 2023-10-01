#ifndef DEMO_7F2BC_H
#define DEMO_7F2BC_H

#include "common.h"
#include "demo_9FD4.h"
#include "menu/menu_7EEE4.h"
#include "menu/menu_7F4B4.h"
#include "text_18118.h"
#include "video.h"
#include "fade.h"
#include "main.h"

extern u8 *s_press_start_or_x_button_8012c468;
extern s32 TempsDemo;

void PS1_ShowDemoText();
u8 PS1_DemoLoop();
void PS1_PlayDemo(void);

#endif