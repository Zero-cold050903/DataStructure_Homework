#include "data.h"

std::basic_fstream<char>&
Init_data_base()
{
    std::basic_fstream<char> data_base;
    data_base.open("data.txt", std::ios::in || std::ios::out);
    return data_base;
}
void Erase_data_base(std::basic_fstream<char>& data_base)
{
    data_base.close();
    std::remove("data.txt");
}
template <typename T>
void
append_data(std::basic_fstream<char>& data_base, T data)
{
    data_base << data << std::endl;
}
template <typename T>
void
prepend_data(std::basic_fstream<char>& data_base, T data)
{
    data_base.seekp(0, std::ios::beg);
    data_base << data << std::endl;
}
template <typename T>
void
delete_data(std::basic_fstream<char>& data_base, T data, int pos)
{
    data_base.seekp(pos, std::ios::beg);
    data_base << data << std::endl;
}