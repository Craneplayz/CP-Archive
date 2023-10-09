#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
#define elif else if
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define INF 1e9

// 自己 Data Type
class MyClass {
private:
    // Member 成员
    int _d;

public:
    // Property
    int a, b;
    vector<int> c;

    MyClass() {}

    // Constructor
    // MyClass(int i, int j, int n) {
    //     a = i;
    //     b = j;
    //     for (int i = 0; i < n; i++)
    //         c.push_back(2023);
    // }

    // Initializer list
    MyClass(int i, int j, int n) : a(i),
                                   b(j),
                                   c(n, 2023) {}

    // Function
    int add() {
        return a + b;
    }

    // Optional Parameter
    int addA(const int n = 9) const {
        return a + n;
    }

    int change(){
        d = a;
    }
};

struct {

};

int main() {

    /*
    DataType variableName; - Declare
    variableName = value; - Assign
    DataType variableName = value; - Define
    */
    int a = 1;
    // DataType -> vector<int>
    // variableName -> v
    // value -> null
    vector<int> v;

    // Primitive
    // number (int, double, float, long, long long)
    // bool
    // char
    // array

    // User-defined -> class( Primitive 排列组合)
    // string
    // vector
    // set
    // 

    int arr[3] = {1, 2, 3};
    vector<int> vec = {1, 2, 3};

    int arr1[3];
    // DataType variableName = value;
    // Constructor
    vector<int> vec1 = vector<int>(3, 1); // {1, 1, 1}
    vec1.push_back(2); // vec1 = {1, 1, 1, 2}
    vec1.pop_back(); // vec1 = {1, 1, 1}

    int numberOfElements = sizeof(arr) / sizeof(arr[0]);
    int numberOfElementsInVector = vec1.size();

    sort(arr1, arr1 + numberOfElements);
    sort(vec1.begin(), vec1.end());

    // Container

    // Data Type
    int b(a); // int b = a

    // Variable 名叫 obj，Data Type：MyClass
    // Instantiate
    MyClass obj;
    obj.a = 1;
    obj.b = 2;

    MyClass obj2(1, 2, 3);
    // obj2.a = 1
    // obj2.b = 2
    // obj2.c = { 2023, 2023, 2023 }

    cout << obj.a << " " << obj.b << " " << obj.add() << "\n";

    cout << obj2.addA(3) <<" "<< obj2.addA() << "\n";
    // 1 2 3

    obj2.change();
    obj2.d = 1;

    pair<int, int>
            p;
    p.first = 1;
    p.second = 2;
    cout << p.first << " " << p.second << "\n";

    return 0;
}