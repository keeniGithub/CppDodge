#ifndef BIND
#define BIND

#include <InSDL.hpp>
#include <var.hpp>

void bind_movement(){
    myapp.bindKey(SDL_SCANCODE_A, [&]() {
        if (!pause) { moved_left = true; facing_right = true; } }, [&]() { 
        if (!pause) { moved_left = false; }
    });
    myapp.bindKey(SDL_SCANCODE_D, [&]() { 
        if (!pause) { moved_right = true; facing_right = false; } }, [&]() { 
        if (!pause) { moved_right = false; }
    });
    myapp.bindKey(SDL_SCANCODE_W, [&]() { 
        if (!is_jump) jumped = true; }, [&]() { 
        if (is_jump) jumped = false; 
    });
    myapp.bindKey(SDL_SCANCODE_SPACE, [&]() { 
        if (!is_jump) jumped = true; }, [&]() { 
        if (is_jump) jumped = false; 
    });
}

void bind_menu(){
    myapp.bindKey(SDL_SCANCODE_ESCAPE, [&]() {
        if (!pause) {pause = true;}
    }, [](){});
}

void bind_button(){
    myapp.bindMouseButton(SDL_BUTTON_LEFT, [&](){ 
        if (!game && button.onHover()){
            game = true;
        }
        else if (pause && button_resume.onHover()) {
            pause = false; 
            game = true;
        }
        else if (pause && button_quit.onHover()){ 
            pause = false;
            game = false; 
        }
        else if (game && button_pause.onHover()){
            pause = true;
        }
        else if (!game && button_github.onHover()){
            system("start https://github.com/keeniGithub/CppDodge");
        }
    });
}

#endif