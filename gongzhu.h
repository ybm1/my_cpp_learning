//
//  gongzhu.h
//  function_examples
//
//  Created by 毕启轩 on 2019/12/22.
//  Copyright © 2019 毕启轩. All rights reserved.
//

#ifndef gongzhu_h
#define gongzhu_h

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip> // 控制精度的函数 fixed和setprecisin
#include <cstdlib>  // 随机数
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void input(int [],int);
void print(const int [],int);
void print_two(const double (*)[5],int,int);
void input_two(double (*)[5]);




void input(int values[],int len){
    string valuesnames[5] ={"体力","智力","魅力","道德","气质"};
    if(len >5){
        cout<< "数组长度只能为5"<< endl;
        return; // 退出返回值为void的函数
    }
    for(int i=0;i<5;i++){
        cout << valuesnames[i]<< ":" << endl;
        cin >> values[i];
    }
    
    
}
// 加上const关键字  保证输入的数组不会发生变化
void print(const int values[],int len){
    string valuesnames[5] ={"体力","智力","魅力","道德","气质"};
    for(int i =0;i<5;i++){
        // ++values[i];// 这里就对数组的值进行了改变，能够直接改变原数组的值
        cout<< valuesnames[i]<<values[i]<< endl;
        
    }
    return;
}


void input_two(double (*arr)[5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    return;
 
}
// 还可以使用
// void print_two(double arr[][5],int row,int col)
// void print_two(double [][5],int row,int col)
// void print_two(double (*arr)[5],int row,int col)
// 列数一定要指定 行数可以不指定
// 的方式来把二维数组传参
void print_two(const double arr[][5],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<< *(*(arr+i)+j);
        }
        cout<< endl;
    }
    return;
}




// 最后以下面结尾
#endif /* gongzhu_h */




