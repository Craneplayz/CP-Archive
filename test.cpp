#include <iostream>
using namespace std;

int main() {
    int num;
    int digit;
    int re = 0;
    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> num;

    /// @brief 把Input的数字"num"从后面读起，把数码一个一个地丢到新的数字“re”里面
    do {
        // Do-While Loop 会执行至少一次，如果while里面的条件成立就会执行下一次
        
        digit = num % 10; 
        // num除以10的余数会是他的个位数字
        // 从后面开始拿每个数码 Digit
        
        re = re * 10 + digit; 
        // 要把下一个位数放进 "re" 后的数字，就要先把里面有的数字往前推一个数位
        // 也就是乘 10
        // 之后把上面找到的个位数放在当前 "re" 的个位

        num /= 10;
        // "num" 除以10会丢弃最后一位的数码，记得整数除法是向下取整
        // 到最后会剩下0 —— 跳出Loop

    } while (num != 0);

    cout << "The reversed integer is " << re << endl;
}