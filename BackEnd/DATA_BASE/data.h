#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
// 初始化数据库
std::FILE*
Init_data_base();
// 释放数据库
void Erase_data_base();
/*
* to add the data in the database
* we support three types of add operation
* append_data: add the data to the end of the database
* insert_data: add the data to the specific position of the database
* prepend_data: add the data to the beginning of the database
* @param database: the database to be added
* @param data_to_add: the data to be added
*/
template <typename T>
void append_data(
	std::FILE& database, 
	         T data_to_add);

/*
* to delete the data in the database
* & out of the consideration for the data type
* we use template to make it more flexible here;
* this is a universal data base.
* @param database: the database to be deleted
* @param data_to_delete: the data to be deleted
* @return: void
*/
template<typename T>
void delete_data(
	std::FILE& database,
	         T data_to_delete);

/*
* to update the data in the database
* @param database: the database to be updated
* @param prev_data: the data to be updated
* @param new_data: the new data
* @return: void
*/
template<typename T>
void update_data(
	std::FILE& database,
	         T prev_data,
		     T new_data);
//search the data in the database
template<typename T>
T& search_data(
	std::FILE& database,
		     T flag);

