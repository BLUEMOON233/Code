#pragma once
#include<iostream>
#include<mysql.h>
#include<string>
#include<vector>


struct Rule {
	std::string logic = "Non";
	std::string pre_1 = "NULL";
	std::string pre_2 = "NULL";
	std::string pre_3 = "NULL";
	std::string result = "NULL";
	std::string toStr();
};

class DataBase {
public:
	DataBase();
	void show_facts();
	void show_rules();
	void show_facts_set();
	void show_rules_set();
	void rules_set_init();
	void facts_set_select(std::vector<int> sel);
private:
	MYSQL* mysql;
	const char* username = "root";
	const char* password = "123456";
	const char* db_name = "Production_System_DB";
	const int port = 3306;
};


