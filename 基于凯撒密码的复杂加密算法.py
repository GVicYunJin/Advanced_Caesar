import time

def generate_shifts(key, reverse=False):
    # 生成一个偏移序列，基于密钥的ASCII值和其位置
    shifts = [ord(char) + index for index, char in enumerate(key)]
    if reverse:
        shifts.reverse()  # 如果指定倒序，则倒序偏移序列
    return shifts

def encrypt_decrypt_once(text, key, charset, reverse=False, encrypt=True):
    charset_len = len(charset)
    shifts = generate_shifts(key, reverse)
    result = []

    for i, char in enumerate(text):
        if char in charset:
            shift = shifts[i % len(shifts)]
            if not encrypt:
                shift = -shift  # 反向偏移解密
            idx = charset.index(char)
            new_idx = (idx + shift) % charset_len
            result.append(charset[new_idx])
        else:
            result.append(char)  # 保留非字符集字符

    return ''.join(result)

def complex_encrypt(text, key):
    # 第一次加密字符集
    charset1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=<>?/"
    # 第二次加密字符集
    charset2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?{}[]"

    # 第一次加密
    first_encryption = encrypt_decrypt_once(text, key, charset1, reverse=False, encrypt=True)
    # 第二次加密（使用相同密钥，但倒序偏移）
    second_encryption = encrypt_decrypt_once(first_encryption, key, charset2, reverse=True, encrypt=True)

    return second_encryption

def complex_decrypt(encrypted_text, key):
    # 第一次加密字符集
    charset1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=<>?/"
    # 第二次加密字符集
    charset2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?{}[]"

    # 先解密第二次加密（倒序偏移解密）
    first_decryption = encrypt_decrypt_once(encrypted_text, key, charset2, reverse=True, encrypt=False)
    # 再解密第一次加密
    original_text = encrypt_decrypt_once(first_decryption, key, charset1, reverse=False, encrypt=False)

    return original_text

def main():
    action = input("请选择操作：加密(E)还是解密(D)？ ").upper()
    if action not in ['E', 'D']:
        print("无效的选择！")
        return
    
    text = input("请输入文本：")
    key = input("请输入密钥：")
    
    if action == 'E':
        encrypted_text = complex_encrypt(text, key)
        print(f"加密结果：{encrypted_text}")
        time.sleep(2)
    else:
        decrypted_text = complex_decrypt(text, key)
        print(f"解密结果：{decrypted_text}")
        time.sleep(2)
while True:
    if __name__ == "__main__":
        main()
