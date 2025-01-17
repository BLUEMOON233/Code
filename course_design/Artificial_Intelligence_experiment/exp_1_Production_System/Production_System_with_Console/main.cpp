#include<iostream>
#include"ProductionSystem.h"


int main() {
	SetConsoleOutputCP(CP_UTF8);
	DataBase db;
	db.rules_set_init();
	std::vector<int> test_fact = { 2, 6, 11, 12};
	db.facts_set_select(test_fact);
	db.show_rules();
	db.show_facts();
	db.inference_engine();
}