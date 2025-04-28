#ifndef BIND
#define BIND

#include <InSDL.hpp>
#include <var.hpp>

void bind_movement(app &app){
    app.bindKey(SDL_SCANCODE_A, [&]() { 
        moved_left = true; facing_right = true; }, [&]() { 
        moved_left = false;
    });
    app.bindKey(SDL_SCANCODE_D, [&]() { 
        moved_right = true; facing_right = false; }, [&]() { 
        moved_right = false;
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

void bind_button(app &app, frect &button){
    app.bindMouseButton(SDL_BUTTON_LEFT, [&](){ 
        if (!game && button.onHover()) game = true; 
    });
}

#endif