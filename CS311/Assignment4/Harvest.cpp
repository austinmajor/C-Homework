/*
File Name: Harvest.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 4
*/

#include "Tickets.h"
#include "Input.h"
#include "Output.h"

int main() {
	Tickets t;

	Input::inputTickets(t);
	Output::outputTickets(t);
	Output::outputSummary(t);
}
