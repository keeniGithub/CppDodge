#ifndef BIND
#define BIND

#include <InSDL.hpp>
#include <var.hpp>

void bind_movement(app &app){
    app.bindKey(SDL_SCANCODE_A, [&]() {
        if (!pause) { moved_left = true; facing_right = true; } }, [&]() { 
        if (!pause) { moved_left = false; }
    });
    app.bindKey(SDL_SCANCODE_D, [&]() { 
        if (!pause) { moved_right = true; facing_right = false; } }, [&]() { 
        if (!pause) { moved_right = false; }
    });
    app.bindKey(SDL_SCANCODE_W, [&]() { 
        if (!is_jump) jumped = true; }, [&]() { 
        if (is_jump) jumped = false; 
    });
    app.bindKey(SDL_SCANCODE_SPACE, [&]() { 
        if (!is_jump) jumped = true; }, [&]() { 
        if (is_jump) jumped = false; 
    });
}

void bind_menu(app &app){
    app.bindKey(SDL_SCANCODE_ESCAPE, [&]() {
        if (!pause) {pause = true;}
    }, [](){});
}

void bind_button(app &app, frect &play_button, frect &resume_button, frect &quit_button, frect &pause_button, frect &github_button, frect &player, int x, int y){
    app.bindMouseButton(SDL_BUTTON_LEFT, [&](){ 
        if (!game && play_button.onHover()){
            game = true;
            current_count = -1;
            attack = "";
            attack_counter = 0;
            player.setPosition(x, y);
        }
        else if (pause && resume_button.onHover()) {
            pause = false; 
            game = true;
        }
        else if (pause && quit_button.onHover()){ 
            pause = false;
            game = false; 
        }
        else if (game && pause_button.onHover()){
            pause = true;
        }
        else if (!game && github_button.onHover()){
            system("start https://github.com/keeniGithub/CppDodge");
        }
    });
}

#endif