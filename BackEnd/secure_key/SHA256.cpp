#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
#include <cstring>
std::string generateRandomString(size_t length) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<char> distribution('a', 'z');
    std::string randomStr;
    for (size_t i = 0; i < length; ++i) {
        randomStr += distribution(generator);
    }
    return randomStr;
}
// SHA-256 常量
constexpr std::array<uint32_t, 64> k = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// 初始哈希值
constexpr std::array<uint32_t, 8> initial_hash = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// 右旋函数
uint32_t rotr(uint32_t value, uint32_t bits) {
    return (value >> bits) | (value << (32 - bits));
}

// SHA-256 主循环
std::array<uint32_t, 8> sha256(const std::vector<uint8_t>& data) {
    std::array<uint32_t, 8> hash = initial_hash;

    // 预处理（填充）
    std::vector<uint8_t> padded = data;
    padded.push_back(0x80);
    while ((padded.size() + 8) % 64 != 0) {
        padded.push_back(0x00);
    }
    uint64_t bit_length = data.size() * 8;
    for (int i = 7; i >= 0; --i) {
        padded.push_back(static_cast<uint8_t>(bit_length >> (i * 8)));
    }

    // 处理每个 512 位（64 字节）块
    for (size_t i = 0; i < padded.size(); i += 64) {
        std::array<uint32_t, 64> w{};
        for (size_t j = 0; j < 16; ++j) {
            w[j] = (padded[i + j * 4] << 24) | (padded[i + j * 4 + 1] << 16) |
                   (padded[i + j * 4 + 2] << 8) | (padded[i + j * 4 + 3]);
        }
        for (size_t j = 16; j < 64; ++j) {
            uint32_t s0 = rotr(w[j - 15], 7) ^ rotr(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = rotr(w[j - 2], 17) ^ rotr(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        std::array<uint32_t, 8> vars = hash;
        for (size_t j = 0; j < 64; ++j) {
            uint32_t s1 = rotr(vars[4], 6) ^ rotr(vars[4], 11) ^ rotr(vars[4], 25);
            uint32_t ch = (vars[4] & vars[5]) ^ (~vars[4] & vars[6]);
            uint32_t temp1 = vars[7] + s1 + ch + k[j] + w[j];
            uint32_t s0 = rotr(vars[0], 2) ^ rotr(vars[0], 13) ^ rotr(vars[0], 22);
            uint32_t maj = (vars[0] & vars[1]) ^ (vars[0] & vars[2]) ^ (vars[1] & vars[2]);
            uint32_t temp2 = s0 + maj;

            vars[7] = vars[6];
            vars[6] = vars[5];
            vars[5] = vars[4];
            vars[4] = vars[3] + temp1;
            vars[3] = vars[2];
            vars[2] = vars[1];
            vars[1] = vars[0];
            vars[0] = temp1 + temp2;
        }

        for (size_t j = 0; j < 8; ++j) {
            hash[j] += vars[j];
        }
    }
    return hash;
}

// 生成 SHA-256 密钥的函数
std::string generateSHA256Key(const std::string& input) {
    std::vector<uint8_t> data(input.begin(), input.end());
    auto hash = sha256(data);

    std::ostringstream oss;
    for (uint32_t val : hash) {
        oss << std::hex << std::setw(8) << std::setfill('0') << val;
    }
    return oss.str();
}

