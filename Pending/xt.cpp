// #include 跟着顺序排，空格要统一
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <iostream> 
using namespace std;

int main(){
    double x, a, b, c; // 逗号后面要空格
    cin >> a >> b >> c; // ">>" 跟 Variable 之间要空格

    // 1. 括弧能写尽量写，比较清楚
    x = (a * 10) + (b * 6);
    
    // 2. 10% 折扣 desu
    if (x >= 100) //数学符号之间要空格
        x *= 0.9;

    // 3. 优惠券
    x -= c * 10;

    // 如果小于0，就要变成 0
    x = max(x, 0.0); // 要用到 <algorithm> Library

    cout << fixed << setprecision(2) << x << '\n'; // 答案后面记得空行，标准来的

    return 0;
}