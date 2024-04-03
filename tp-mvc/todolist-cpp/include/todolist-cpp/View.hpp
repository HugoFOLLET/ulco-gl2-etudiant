#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/Board.hh>

std::string showTask(const Task& t);

std::string printBoard(const Board& b);

void showBoard(const Board& b, std::ostream& os);