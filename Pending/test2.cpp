#include <iostream> 
#include <iomanip> 
using namespace std;

int main() {
    double x, a, b, c; 

    // cin >> a >> b >> c;
    a = 37; b = 10; c=5;
    // 1. 总和
    x = (a * 10) + (b * 6);

    // 1. 总和
    // 2. 如果价格大于100，就折扣10%
    // 3. Apply 优惠券
    // 4. 如果出现负数，就变成 0
    // 5. 最后输出 cout

    x = x * 0.9;
    x *= 0.9; 

    x = x + 5;
    x += 5;

    x = x - 2;
    x -= 2;
    // 计算 x * 0.9
    // 用计算好的值重置掉原本的 x

    if (x >= 100){ //Clause
        // 折扣10%
    }

    if(1){
        //A
    }

    x=x+1;
    if(){
        
    }
    else{
        //B2
    }

    else if(x<=0){ //有没有小过0
        cout<<fixed<<setprecision(2); cout<<"0.00";
    }
}