#include "data.h"
std::FILE* Init_data_base()
{
    std::FILE* fp = std::fopen("data.txt", "r");
    if (fp == nullptr)
    {
        std::fclose(fp);
        fp = std::fopen("data.txt", "w");
    }
    return fp;
}
void Erase_data_base(std::FILE* fp)
{
    std::FILE* fp = std::fopen("data.txt", "w");
    std::fclose(fp);
}
template<typename T>
void apppend_data(T data, std::FILE& fp)
{
    std::fprintf(&fp, "%d\n", data);
    std::fflush(&fp);
    std::fclose(&fp);
}

template <typename T>
void delete_data(T data1, std::FILE* fp)
{
    std::FILE& fp_n = Init_data_base();
    while (std::fscanf(&fp, "%d\n", &data2) != EOF)
    {
        if (data2 != data1)
        {
            apppend_data(data2, fp_n);
        }
    }
    Erase_data_base(fp);
}