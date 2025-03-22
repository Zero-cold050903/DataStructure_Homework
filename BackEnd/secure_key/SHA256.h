#ifndef SHA256_H
#define SHA256_H

#include <iostream>
#include <vector>
#include <array>
#include <string>

// 生成 SHA-256 哈希值（256 位密钥）
std::string generateSHA256Key(const std::string& input);

// 生成随机字符串
std::string generateRandomString(size_t length);

#endif // SHA256_H
