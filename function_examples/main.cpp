//
//  main.cpp
//  function_examples
//
//  Created by 毕启轩 on 2019/12/21.
//  Copyright © 2019 毕启轩. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip> // 控制精度的函数 fixed和setprecisin
#include <cstdlib>  // 随机数
#include <ctime>
#include <vector>
#include <algorithm>
#include "gongzhu.h" // 自定义了头文件，可以在里面定义函数  在main里面调用
using namespace std;

// 函数原型，与函数定义的头部类似，最后以分号结尾
// 函数原型中的参数名称可以省略，只写参数类型
// C++ 中函数不要返回数组类型，可以是其他任何类型(如果非要返回数组，可以把数组作为结构
// 或者对象组成部分返回)
int sum(int,int);

void change1(int); // 声明了一个返回值为空，参数值为整型的函数
void change2(int &);
double add(double,double);
double subtraction(double,double);
double multi(double,double);
double divi(double,double);

void print_res(double (*)(double,double),double ,double);

void print_res(double (*ptr_cal)(double,double),double num1,
               double num2){
    //double res = (*ptr_cal)(num1,num2);
    double res = ptr_cal(num1,num2);
    cout<< "运算结果为："<< res << endl;
}
//double (*ptr_cal)(double,double);// 声明了一个函数指针
auto ptr_cal = add; //也可用auto的方式进行函数指针的声明，但注意必须要初始化，用auto声明比较简洁

int (*p_sum)(int,int); // 该语句声明了一个指针p_sum,指向一个函数
// 注意 上面的括号一定要加，如果不加，则
// int *p_sum(int,int)表示声明了一个函数p_sum，其返回类型是 double *类型


int main(int argc, const char * argv[]) {
    // 函数
    // 三要素：返回值类型；函数名；参数列表
    int res =sum(2,3);
    cout << "求和为===>\t" << res << endl;
    

    int num = 9;
    cout << "原数字num=\t"<< num << endl;
    change1(num);// 传值，相当于传的是输入的副本，所以原来的变量不受影响
    cout<< "传值后num=\t"<< num << endl;
    
    change2(num);// 传地址，相当于传的是输入的地址，所以原来的变量受影响
    cout<< "传地址后num=\t"<< num << endl;
    // 下面是用数组作为函数的参数
    /*
     传递数组实际上传递的是数组的首地址，不能传递整个数组空间
     当数组名作为实参调用函数时，数组首地址指针就被传递到函数中
     所以数组在经过一些函数的操作会，已经发生了改变
     要防止数组被乱改，可以采用const关键字
     */
    
    int values[5];
    //input(values,5);
    //print(values,5);
    cout << "二维数组作为函数参数"<< endl;
    
    
    double values_tow[2][5] = {{1,2,3,4,5},
                                    {1,2,3,4,5}};
    //input_two(values_tow);
    // 注意二维数组作为参数时的参数的类型
    int row = 2;
    int col =5;
    print_two(values_tow,row,col);
    
    // 函数指针的使用 让其指向函数 以便调用
    p_sum = sum; // 该语句声明了一个指针p_sum,指向了sum函数，即它保存了函数sum的地址
    cout <<"函数指针的使用\t" <<p_sum(2,3) <<"\t"<<
                            (*p_sum)(2,3)<<endl;
    
    
    double n1 = 9;
    double n2 =10;
    string op;
    cout<< "请输入运算符"<<endl;
    cin >> op;
    // 不同与那算就d把函数指针指向不同的函数
    if(op == "+"){
        ptr_cal = add;
    }
    else if (op == "-"){
        ptr_cal = subtraction;
    }
    else if (op == "*"){
        ptr_cal = multi;
    }
    else{
        ptr_cal = divi;
    }
    print_res(ptr_cal,n1, n2);
    return 0;
}

// 返回类型  参数列表  都要制定类型
int sum(int num1,int num2){
    int res = num1 + num2;
    return res;
}


double add(double a,double b){
    return a+b;
}
double subtraction(double a,double b){
    return a-b;
}
double multi(double a,double b){
    return a*b;
}
double divi(double a,double b){
    if(b!=0){return a/b;}
    else{cout<< "除数不能为0"<< endl;
        return 0;
    }
}


void change1(int num){
    num++;
}
void change2(int &num){
    num++;
}























