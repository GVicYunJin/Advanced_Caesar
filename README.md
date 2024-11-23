# 高级凯撒密码项目说明

## 一、项目概述
本项目实现了一种基于凯撒密码的复杂加密算法，旨在解决传统凯撒密码在安全性和效率方面的不足。通过引入两次不同字符集的加密过程以及动态的密钥生成策略，提高了加密的安全性；同时，在算法实现上进行优化，提升了加密和解密的速度，并降低了资源占用。项目包含离线版和在线版，提供了多种使用方式。

## 二、算法原理
1. **加密过程**
   - 首先根据用户输入的密钥生成偏移序列，偏移量基于密钥中字符的ASCII值和其在密钥中的位置。
   - 第一次加密使用字符集`"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=<>?/"`，对输入文本中的每个字符在该字符集中找到其位置，并根据偏移量进行移动，生成新的加密字符。
   - 第二次加密对第一次加密结果使用字符集`"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?{}[]"`，且使用相同密钥但偏移量序列反转，再次对字符进行替换和位移，最终得到加密文本。
2. **解密过程**
   - 解密与加密相反，首先使用第二个字符集进行倒序偏移解密，找到每个字符在字符集中的原始位置。
   - 然后使用第一个字符集再次解密，根据原始偏移量恢复字符，最终得到原始文本。

## 三、代码结构
1. **离线版**
   - `generate_shifts`函数：根据密钥生成偏移序列，可选择是否倒序。
   - `encrypt_decrypt_once`函数：对文本进行一次加密或解密操作，根据字符是否在字符集内进行相应处理。
   - `complex_encrypt`函数：执行复杂加密操作，包括两次字符集加密。
   - `complex_decrypt`函数：执行复杂解密操作，对应两次字符集解密。
   - `main`函数：获取用户输入的操作、文本和密钥，调用加密或解密函数并输出结果，主循环确保程序可多次运行。
2. **在线版**
   - HTML部分：构建了加密和解密的用户界面，包括输入文本框、密钥输入框、加密和解密按钮以及结果显示区域。
   - CSS部分：定义了页面的样式，如背景渐变、按钮样式、响应式设计等，增强了视觉效果和用户体验。
   - JavaScript部分：实现了与离线版类似的加密和解密逻辑，包括`generateShifts`、`encryptDecryptOnce`、`complexEncrypt`、`complexDecrypt`函数，以及`encrypt`和`decrypt`函数用于获取用户输入并调用相应加密或解密函数来更新结果显示区域。

## 四、使用方法
1. **离线版**
   - 运行离线版程序，根据提示选择加密（`E`）或解密（`D`）操作。
   - 输入要处理的文本和密钥，程序将输出加密或解密后的结果。
2. **在线版**
   - 打开在线版页面（地址：http://ks.gvicyunjin.cn:3333/）。
   - 在输入文本框中输入要加密或解密的文本，在密钥输入框中输入密钥。
   - 点击相应的加密或解密按钮，结果将显示在指定区域。

## 五、未来规划
1. 使用C++语言重新编写程序，编译为系统底层文件，提高可移植性。
2. 提供更多接口，方便其他项目引入该加密算法。
3. 开发适用于更多系统环境（如Linux、安卓等）的版本，并使用多种语言（C++、C、Java、JS、php、go等）编写程序，以扩大应用范围。

## 六、注意事项
1. 在选择密钥时，尽量使用复杂且不易被猜测的字符串，以提高加密安全性。
2. 对于特殊字符集的使用，需注意不同设备和软件环境的兼容性，避免加密后的数据在某些情况下无法正确解密或显示。

## 七、开源协议
本项目遵循MIT License开源协议，欢迎大家使用、修改和分发代码，但需保留版权声明和许可声明。

## 八、贡献指南
如果您对本项目感兴趣并希望贡献代码或提出改进建议，欢迎通过以下方式参与：
1. Fork本项目仓库。
2. 创建新的分支进行修改。
3. 提交Pull Request，详细说明您的修改内容和目的。

## 九、联系方式
如果您在使用过程中遇到问题或有任何疑问，可以通过以下方式联系我们：
1. 邮件：2418874224@qq.com
2. GitHub Issue：在项目仓库中创建新的Issue。

## 十、致谢
感谢所有参与本项目的人员，包括开发团队成员（组长：郭子路，成员：龚毅夫，张智宸）以及指导老师薛仙。同时，也感谢使用和关注本项目的用户，希望本项目能为大家在信息安全领域的研究和应用提供一定的帮助。







# Project Description of Advanced_Caesar_V1.0

## I. Project Overview
This project implements a complex encryption algorithm based on the Caesar cipher, aiming to address the deficiencies in security and efficiency of the traditional Caesar cipher. By introducing a two-round encryption process with different character sets and a dynamic key generation strategy, the security of encryption is enhanced. Meanwhile, optimizations in the algorithm implementation improve the speed of encryption and decryption and reduce resource consumption. The project includes an offline version and an online version, providing multiple usage methods.

## II. Algorithm Principle
1. **Encryption Process**
   - Firstly, an offset sequence is generated based on the user-entered key, where the offset is calculated from the ASCII value of the characters in the key and their positions in the key.
   - The first encryption uses the character set `"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=<>?/"`. For each character in the input text, its position in this character set is found, and it is shifted according to the offset to generate a new encrypted character.
   - The second encryption is performed on the result of the first encryption using the character set `"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?{}[]"`. The same key is used, but the offset sequence is reversed, and the characters are replaced and shifted again to obtain the final encrypted text.
2. **Decryption Process**
   - Decryption is the reverse of encryption. Firstly, the second character set is used for reverse offset decryption to find the original position of each character in the character set.
   - Then, the first character set is used again for decryption to restore the characters based on the original offset, and finally, the original text is obtained.

## III. Code Structure
1. **Offline Version**
   - The `generate_shifts` function: Generates an offset sequence based on the key and can optionally reverse it.
   - The `encrypt_decrypt_once` function: Performs a single encryption or decryption operation on the text, handling characters according to whether they are in the character set.
   - The `complex_encrypt` function: Executes the complex encryption operation, including two rounds of character set encryption.
   - The `complex_decrypt` function: Performs the complex decryption operation, corresponding to two rounds of character set decryption.
   - The `main` function: Obtains the user's input for the operation, text, and key, calls the encryption or decryption function, and outputs the result. The main loop ensures that the program can be run multiple times.
2. **Online Version**
   - HTML Part: Builds the user interface for encryption and decryption, including input text boxes, key input boxes, encryption and decryption buttons, and a result display area.
   - CSS Part: Defines the page styles, such as background gradients, button styles, and responsive design, enhancing the visual effect and user experience.
   - JavaScript Part: Implements the encryption and decryption logic similar to the offline version, including functions like `generateShifts`, `encryptDecryptOnce`, `complexEncrypt`, `complexDecrypt`, and functions `encrypt` and `decrypt` that are used to obtain user input and call the corresponding encryption or decryption functions to update the result display area.

## IV. Usage
1. **Offline Version**
   - Run the offline version program and select the encryption (`E`) or decryption (`D`) operation according to the prompts.
   - Enter the text and key to be processed, and the program will output the encrypted or decrypted result.
2. **Online Version**
   - Open the online version page (address: http://ks.gvicyunjin.cn:3333/).
   - Enter the text to be encrypted or decrypted in the input text box and the key in the key input box.
   - Click the corresponding encryption or decryption button, and the result will be displayed in the specified area.

## V. Future Plans
1. Rewrite the program in C++ and compile it into system-level files to improve portability.
2. Provide more interfaces to facilitate other projects to integrate this encryption algorithm.
3. Develop versions suitable for more system environments (such as Linux, Android, etc.) and use multiple languages (C++, C, Java, JS, php, go, etc.) to write programs to expand the application range.

## VI. Precautions
1. When choosing a key, try to use a complex and hard-to-guess string to improve encryption security.
2. For the use of special character sets, pay attention to the compatibility of different devices and software environments to avoid situations where encrypted data cannot be correctly decrypted or displayed on certain devices.

## VII. Open Source License
This project follows the MIT License open source license. Everyone is welcome to use, modify, and distribute the code, but the copyright notice and license statement must be retained.

## VIII. Contribution Guide
If you are interested in this project and want to contribute code or make improvement suggestions, you are welcome to participate in the following ways:
1. Fork this project repository.
2. Create a new branch for modifications.
3. Submit a Pull Request, detailing your modification content and purpose.

## IX. Contact Information
If you encounter problems or have any questions during use, you can contact us in the following ways:
1. Email:2418874224@qq.com
2. GitHub Issue: Create a new Issue in the project repository.

## X. Acknowledgments
Thanks to all the personnel involved in this project, including the development team members (Team Leader: Guo Zilu, Members: Gong Yifu, Zhang Zhichen) and the instructor Xue Xian. Also, thanks to the users who use and pay attention to this project. We hope this project can provide some help in the research and application of the information security field.