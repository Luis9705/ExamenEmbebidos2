/// @file timer.h
/// @brief TIMER header file.
//  Copyright 2020 Copyright Equipo 2
#ifndef TIMER_H_   /* Include guard */
#define TIMER_H_

#include "timer_params.h" ///<TIMER params header include.

void timer_setup(void);
void timer_rst(void);
void timer_start(void);
void timer_stop(void);
void timer_continue(void);
int timer_get_seconds(void);

#endif  // ABSTRACTION_AND_DOCUMENTATION_TIMER_H_
