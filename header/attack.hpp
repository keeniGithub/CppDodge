#ifndef ATTACK
#define ATTACK

#include <cstdlib>
#include <ctime>
#include <var.hpp>

void attack_rocket() {
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

void attack_laser() {
    if (attack_counter < 75) {
        warning_left.setY(y_wrn);
        warning_right.setY(y_wrn);
        attack_counter += 1;
    } else if (attack_counter < 150) {
        warning_left.setY(-100);
        warning_right.setY(-100);
        if (laser_left.getWidth() < 20) laser_left.addWidth(1);
        if (laser_right.getWidth() < 20) laser_right.addWidth(1);
        laser_left.setHeight(h_ls);
        laser_right.setHeight(h_ls);
        attack_counter += 1;
    } else if (attack_counter < 300) {
        int center_x = platform.getX() + platform.getWidth() / 2;
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
        if (laser_right.getX() < platform.getX() + platform.getWidth() - 30) {
            laser_left.addX(2);
            laser_right.addX(2);
        } else {
            attack_counter = 601;
        }
    } else if (attack_counter < 900) {
        if (laser_left.getX() > platform.getX() + 10) {
            laser_left.subX(2);
            laser_right.subX(2);
        } else {
            attack_counter = 901;
        }
    } else if (attack_counter < 1100) {
        int left_start = platform.getX() + 10;
        int right_start = platform.getX() + platform.getWidth() - laser_right.getWidth() - 10;

        if (laser_left.getX() > left_start) {
            laser_left.subX(2);
        }
        if (laser_right.getX() < right_start) {
            laser_right.addX(4);
        }
        attack_counter += 1;
    } else if (attack_counter < 1150) {
        if (laser_left.getWidth() > 0) laser_left.subWidth(1);
        if (laser_right.getWidth() > 0) laser_right.subWidth(1);
        attack_counter += 1;
    } else {
        attack_counter = 0;
        attack = "";
        laser_left.setX(platform.getX() + 10);
        laser_right.setX(platform.getX() + platform.getWidth() - laser_right.getWidth() - 10);
        laser_right.subX(20);
        laser_left.setSize(0, 0);
        laser_right.setSize(0, 0);
    }
}

void random_attack() {
    if (attack == "rocket") {
        attack_rocket();
    } else if (attack == "laser") {
        attack_laser();
    }

    attack_elapsed++;
    if (attack_elapsed >= attack_timer * 20) {
        if (rand() % 4 == 0 && attack != "rocket") {
            attack = "laser"; // change to rocket
            rocket.setPosition(x_rkt, -100);
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