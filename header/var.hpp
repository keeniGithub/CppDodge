#ifndef VAR
#define VAR

#include <iostream>
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

unsigned int dash_cooldown_time = 0;
int dash_target_x = 0;
int count = 0;
int max_count = 0;

float dash_speed = 0.0f;
float jump_speed = 0;
const float gravity = 10;
const float jump_force = -30;

string path = "Z:/cpp/BloxDodge/";
string name = "СppDodge";

#endif