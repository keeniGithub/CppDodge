#ifndef ATTACK
#define ATTACK

#include <cstdlib>
#include <ctime>
#include <var.hpp>

void init_attack_timer() {
    srand(static_cast<unsigned>(time(0)));
    attack_timer = rand() % 12 + 5; // Увеличен диапазон для более редких атак
    attack_elapsed = 0;
}

void rocket(frect &rocket, int x) {
    cout << attack_counter << endl;
    if (attack_counter < 800) {
        attack_counter += 2;
        if (attack_counter > 400)
            rocket.addY(15);
    } else {
        attack_counter = 0;
        attack = "";
    }
}

void laser(frect &laser_left, frect &laser_right, frect &warning_left, frect &warning_right, int platform_x, int platform_width, int warning_y, int laser_h, int right_start) {
    if (attack_counter < 75) {
        warning_left.setY(warning_y);
        warning_right.setY(warning_y);
        attack_counter += 1;
    } else if (attack_counter < 150) {
        warning_left.setY(-100);
        warning_right.setY(-100);
        if (laser_left.getWidth() < 20) laser_left.addWidth(1);
        if (laser_right.getWidth() < 20) laser_right.addWidth(1);
        laser_left.setHeight(laser_h);
        laser_right.setHeight(laser_h);
        attack_counter += 1;
    } else if (attack_counter < 300) {
        int center_x = platform_x + platform_width / 2;
        if (laser_left.getX() < center_x - laser_left.getWidth() - 10) {
            laser_left.addX(2);
        }
        if (laser_right.getX() > center_x + 10) {
            laser_right.subX(2);
        }
        attack_counter += 2;
    } else if (attack_counter < 375) {
        attack_counter += 1;
    } else if (attack_counter < 600) {
        if (laser_right.getX() < platform_x + platform_width - 30) {
            laser_left.addX(2);
            laser_right.addX(2);
        } else {
            attack_counter = 601;
        }
    } else if (attack_counter < 900) {
        if (laser_left.getX() > platform_x + 10) {
            laser_left.subX(2);
            laser_right.subX(2);
        } else {
            attack_counter = 901;
        }
    } else if (attack_counter < 1100) {
        int left_start = platform_x + 10;

        if (laser_left.getX() > left_start) {
            laser_left.subX(2);
        }
        if (laser_right.getX() < right_start) {
            laser_right.addX(4);
        }
        attack_counter += 1;
    } else if (attack_counter < 1200) {
        if (laser_left.getWidth() > 0) laser_left.subWidth(1);
        if (laser_right.getWidth() > 0) laser_right.subWidth(1);
        attack_counter += 1;
    } else {
        attack_counter = 0;
        attack = "";
        laser_left.setX(platform_x + 10);
        laser_right.setX(platform_x + platform_width - laser_right.getWidth() - 10);
        laser_left.setSize(0, 0);
        laser_right.setSize(0, 0);
    }
}

void random_attack(frect &frocket, int x_rkt, frect &laser_left, frect &laser_right, frect &warning_left, frect &warning_right, int platform_x, int platform_width, int warning_y, int laser_h, int right_start) {
    if (attack == "rocket") {
        rocket(frocket, x_rkt);
    } else if (attack == "laser") {
        laser(laser_left, laser_right, warning_left, warning_right, platform_x, platform_width, warning_y, laser_h, right_start);
    }

    attack_elapsed++;
    if (attack_elapsed >= attack_timer * 20) {
        if (rand() % 4 == 0 && attack != "rocket") {
            attack = "laser"; // change to rocket
            frocket.setPosition(x_rkt, -100);
            cout << "attack rocket" << endl;
        } else if (rand() % 4 == 0 && attack != "laser") {
            attack = "laser";
            cout << "attack laser" << endl;
        }
        attack_elapsed = 0;
        attack_timer = rand() % 12 + 5;
    }
}

#endif