#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

std::vector<int> generate_shifts(const std::string &key, bool reverse = false) {
    std::vector<int> shifts;
    for (size_t i = 0; i < key.length(); ++i) {
        shifts.push_back(static_cast<int>(key[i]) + i);
    }
    if (reverse) {
        std::reverse(shifts.begin(), shifts.end());
    }
    return shifts;
}

std::string encrypt_decrypt_once(const std::string &text, const std::string &key, const std::string &charset, bool reverse = false, bool encrypt = true) {
    std::string result;
    std::vector<int> shifts = generate_shifts(key, reverse);
    size_t charset_len = charset.length();

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        size_t pos = charset.find(c);
        if (pos != std::string::npos) {
            int shift = shifts[i % shifts.size()];
            if (!encrypt) {
                shift = -shift;
            }
            size_t new_pos = (pos + shift + charset_len) % charset_len;
            result += charset[new_pos];
        } else {
            result += c;
        }
    }

    return result;
}

std::string complex_encrypt(const std::string &text, const std::string &key) {
    std::string charset1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=<>?/";
    std::string charset2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?{}[]";

    std::string first_encryption = encrypt_decrypt_once(text, key, charset1, false, true);
    std::string second_encryption = encrypt_decrypt_once(first_encryption, key, charset2, true, true);

    return second_encryption;
}

std::string complex_decrypt(const std::string &encrypted_text, const std::string &key) {
    std::string charset1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=<>?/";
    std::string charset2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?{}[]";

    std::string first_decryption = encrypt_decrypt_once(encrypted_text, key, charset2, true, false);
    std::string original_text = encrypt_decrypt_once(first_decryption, key, charset1, false, false);

    return original_text;
}

int main() {
    char action;
    std::cout << "请选择操作：加密(E)还是解密(D)？ ";
    std::cin >> action;
    action = std::toupper(action);

    if (action != 'E' && action != 'D') {
        std::cout << "无效的选择！" << std::endl;
        return 0;
    }

    std::string text, key;
    std::cout << "请输入文本：";
    std::cin.ignore(); // 忽略之前读取的换行符
    std::getline(std::cin, text);
    std::cout << "请输入密钥：";
    std::getline(std::cin, key);

    if (action == 'E') {
        std::string encrypted_text = complex_encrypt(text, key);
        std::cout << "加密结果：" << encrypted_text << std::endl;
    } else {
        std::string decrypted_text = complex_decrypt(text, key);
        std::cout << "解密结果：" << decrypted_text << std::endl;
    }

    // 暂停2秒
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}
