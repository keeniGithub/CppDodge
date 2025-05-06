#ifndef VAR
#define VAR

#include <iostream>
#include <SDL3/SDL.h>
#include <InSDL.hpp>
#include <disk.hpp>

using namespace std;

app myapp;

string path = disk_path()+"\\";
string name = "СppDodge";

frect logo(0, 0, 500, 100);
frect menu_background(0, 0, 1200, 600);
frect background(0, 0, 1200, 800);
frect button(0, 0, 400, 75);
frect button_github(0, 0, 400, 75);
frect counter(0, 140, 25, 50);
frect max_counter(0, 180, 25, 50);
frect dash_state(0, 15, 75, 110);
frect lava(0, 0, 1200, 50);
frect platform(0, 0, 600, 150);
frect player(0, 0, 60, 60);
frect pause_background(0, 0, 350, 350);
frect button_resume(0, 0, 250, 80);
frect button_quit(0, 0, 250, 80);
frect button_pause(10, 10, 60, 60);
frect scope(player.getX() - 25, player.getY() - 25, player.getWidth() + 50, player.getHeight() + 50);
frect rocket(0, -100, 48, 96);
frect laser_left(0, 0, 0, 0);
frect laser_right(0, 0, 0, 0);
frect saw_left(0, 0, 100, 100);
frect saw_right(0, 0, 100, 100);
frect warning_left(0, 0, 60, 60);
frect warning_right(0, 0, 60, 60);
frect pipe(0, -150, 48, 135);
frect blob(0, -36, 64, 36);
frect spiky(0, -170, 60, 160);

SDL_FPoint point_pl = {
    static_cast<float>(player.getWidth() / 2),
    static_cast<float>(player.getHeight() / 2)
};

SDL_FPoint point_scp = {
    static_cast<float>(scope.getWidth() / 2),
    static_cast<float>(scope.getHeight() / 2)
};

SDL_FPoint point_sw = {
    static_cast<float>(saw_left.getWidth() / 2),
    static_cast<float>(saw_left.getHeight() / 2)
};

SDL_FPoint point_bl = {
    static_cast<float>(blob.getWidth() / 2),
    static_cast<float>(blob.getHeight() / 2)
};

int x_pf, y_pf;
int x_pl, y_pl;
int x_ct, x_ds, y_lv;
int x_lg, y_lg;
int x_btn, y_btn, y_ghbtn;
int x_pbg, y_pbg;
int x_rsbtn, y_rsbtn;
int h_ls, x_ls;
int x_sw, y_sw;
int x_rkt, y_wrn;
int x_pp, x_bl;
int x_sp = 0;

void set_position(){
    x_pf = (myapp.window.width - platform.getWidth()) / 2;
    y_pf = (myapp.window.height - platform.getHeight());
    x_pl = (myapp.window.width - player.getWidth()) / 2;
    y_pl = (myapp.window.height - platform.getHeight() - player.getHeight());
    x_ct = (myapp.window.width - counter.getWidth()) - 50;
    x_ds = (myapp.window.width - dash_state.getWidth());
    y_lv = (myapp.window.height - lava.getHeight());
    x_lg = (myapp.window.width - logo.getWidth()) / 2;
    y_lg = (myapp.window.height - logo.getHeight()) / 2 - 120;
    x_btn = (myapp.window.width - button.getWidth()) / 2;
    y_btn = (myapp.window.height - button.getHeight()) / 2;
    y_ghbtn = (myapp.window.height - button.getHeight()) / 2 + 100;
    x_pbg = (myapp.window.width - pause_background.getWidth()) / 2;
    y_pbg = (myapp.window.height - pause_background.getHeight()) / 2;
    x_rsbtn = (myapp.window.width - button_resume.getWidth()) / 2;
    y_rsbtn = (myapp.window.height - button_resume.getHeight()) / 2 - 50;
    x_rkt = (myapp.window.width - rocket.getWidth()) / 2;
    h_ls = (myapp.window.height - platform.getHeight());
    x_ls = (platform.getX() + platform.getWidth() - laser_right.getWidth());
    x_sw = (myapp.window.width - platform.getWidth() - saw_left.getWidth()) / 2;
    y_sw = (myapp.window.height - saw_left.getHeight()) + 100;
    y_wrn = (myapp.window.height - platform.getHeight() - warning_left.getHeight());
    x_pp = (myapp.window.width - pipe.getWidth()) / 2;
    x_bl = (myapp.window.width - blob.getWidth()) / 2;

    platform.setPosition(x_pf, y_pf);
    player.setPosition(x_pl, y_pl);
    counter.setX(x_ct);
    max_counter.setX(x_ct);
    dash_state.setX(x_ds);
    lava.setY(y_lv);
    logo.setPosition(x_lg, y_lg);
    button.setPosition(x_btn, y_btn);
    button_github.setPosition(x_btn, y_ghbtn);
    pause_background.setPosition(x_pbg, y_pbg);
    button_resume.setPosition(x_rsbtn, y_rsbtn);
    button_quit.setPosition(x_rsbtn, y_rsbtn + 100);
    rocket.setX(x_rkt);
    laser_left.setX(x_pf + 10);
    laser_right.setX((x_pf + platform.getWidth() - laser_right.getWidth()) - 25);
    warning_left.setX(x_pf - 15);
    warning_right.setX(x_pf + platform.getWidth() - laser_right.getWidth() - 40);
    saw_left.setPosition(x_sw, y_sw);
    saw_right.setPosition(x_sw + platform.getWidth(), y_sw);
    warning_left.setY(y_wrn);
    warning_right.setY(y_wrn);
    pipe.setX(x_pp);
    blob.setX(x_bl);
}

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
bool pause = false;

int anim_y = 0;
int anim_y_back = 0;

unsigned int dash_cooldown_time = 0;
int dash_target_x = 0;
int current_count = 0;
int max_count = 0;
int death_count = 0;

bool rocket_attack_avalible = true;
bool laser_attack_avalible = true;
bool saw_attack_avalible = true;
bool pipe_attack_avalible = true;
bool spiky_attack_avalible = true;

int active_attacks = 0;
int attack_timer = 0;
int attack_elapsed = 0;
int rocket_counter = 0;
int laser_counter = 0;
int saw_counter = 0;
int pipe_counter = 0;
int spiky_counter = 0;

float dash_speed = 0.0f;
float jump_speed = 0;
const float gravity = 10;
const float jump_force = -30;

double degr = 0;
double scp_degr = 0;
double saw_degr = 0;
double bl_degr = 0;

unsigned int last_time = SDL_GetTicks();

#endif