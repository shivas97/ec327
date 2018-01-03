#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Model.h"
#include "Person.h"

void do_move_command(Model &model);
void do_work_command(Model &model);
void do_stop_command(Model &model);
void do_go_command(Model &model);
void do_run_command(Model &model);
void do_quit_command(Model &model);
void do_list_command(Model &model);
void do_spawn_command(Model &model);

#endif
