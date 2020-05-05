//  Copyright 2020 Copyright Equipo 2
#ifndef BUTTONS_H_   /* Include guard */
#define BUTTONS_H_

#include <stdint.h>
#include <stdbool.h>
#include "buttons_params.h"


void buttons_setup(void);
bool reset_button_pressed(void);
bool start_button_pressed(void);
bool stop_button_pressed(void);




#endif  // ABSTRACTION_AND_DOCUMENTATION_BUTTONS_H_
