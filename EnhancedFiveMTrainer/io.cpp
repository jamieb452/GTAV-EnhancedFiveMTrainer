/*
Some of this code began its life as a part of GTA V SCRIPT HOOK SDK.
http://dev-c.com
(C) Alexander Blade 2015

It is now part of the Enhanced Native Trainer project.
https://github.com/gtav-ent/GTAV-EnhancedNativeTrainer
(C) Rob Pridham and fellow contributors 2015
*/

#include "config_io.h"

DWORD trainerResetTime = 0;

bool trainer_switch_pressed()
{
	return IsKeyJustUp( config->get_trainer_config()->toggle_trainer_menu );
}

void get_button_state(bool *a, bool *b, bool *up, bool *down, bool *l, bool *r)
{
	SettingsConfig *setConf = config->get_trainer_config();

	if (a) *a = IsKeyDown(setConf->key_menu_confirm);
	if (b) *b = IsKeyDown(setConf->key_menu_back);
	if (up) *up = IsKeyDown(setConf->key_menu_up);
	if (down) *down = IsKeyDown(setConf->key_menu_down);
	if (r) *r = IsKeyDown(setConf->key_menu_right);
	if (l) *l = IsKeyDown(setConf->key_menu_left);
}

bool get_key_pressed(int nVirtKey)
{
	return (GetAsyncKeyState(nVirtKey) & 0x8000) != 0;
}

void reset_trainer_switch()
{
	trainerResetTime = GetTickCount();
}