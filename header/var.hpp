#ifndef VAR
#define VAR

#include <iostream>
#include <SDL3/SDL.h>
#include <disk.hpp>

using namespace std;

bool moved_left = false;
bool moved_right = false;
bool jumped = false;
bool is_jump = false;
bool facing_right = true;
bool die = false;
bool dash_available = true;
bool dash_in_progress = false;
bool playanim = false;
bool game = false;

int anim_y = 0;
int anim_y_back = 0;

unsigned int dash_cooldown_time = 0;
int dash_target_x = 0;
int current_count = 0;
int max_count = 0;

float dash_speed = 0.0f;
float jump_speed = 0;
const float gravity = 10;
const float jump_force = -30;
double degr = 0;

char letter = disk_letter();
string path = letter+":/cpp/BloxDodge/";
string name = "СppDodge";

unsigned int last_time = SDL_GetTicks();

#endif