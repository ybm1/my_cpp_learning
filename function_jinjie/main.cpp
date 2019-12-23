//
//  main.cpp
//  function_jinjie
//
//  Created by 毕启轩 on 2019/12/22.
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

using namespace std;

void swap1(int,int);
void swap2(int*,int*);
void swap3(int*,int*);
void swap4(int&,int&);
template<typename T> void sum_t(T,T);

// 注意 形参和实参之间的传递是值传递。
void swap1(int a,int b){
    int tmp = a;
    a =b;
    b= tmp;
    
}
void swap2(int* a,int* b){
    cout<<"swap2内部交换前\t"<< a<<"\t"<<b<<endl;
    int* tmp = a;//此时的tmp是一个指针，这句话的意思是：把a指针的值(注意，指针的值就是它所指向的变量的地址，是地址！)
        // 赋给了tmp，即此时tmp中的保存了原来a所指向的变量的地址，即此时tmp也指向了a所指向的变量
    a =b; // 把b所指的变量的地址赋给了a，即a现在保存了原来b 所指变量的地址，也即a现在指向了原来b所指的变量
    b= tmp; //但是！！！一定要注意，此时只是函数内部把指针的值交换了，并没有真正的修改指针的值，这和swap1函数没有
    //真正交换两个变量的值的情况是相同的  只是内部暂时的交换了  没有真正的交换
    // 要想真正的改变一个变量的值，必须通过其指针来进行操作，即通过指针直接改变指针所指变量的值，如swap4的方法
    // 而想要通过改变指针的指向,就是swap3的做法
     cout<<"swap2内部交换后\t"<< a<<"\t"<<b<<endl;
}

void swap3(int** a,int**b){
    int* tmp =*a;//  **a表示 a是一个指针的指针 这是定义类型 那么*a就是a的值 即他指向的指针 即它保存了它指向的指针的地址
    *a=*b;// *b和上面一样 表示b这个指针的指针所指向的指针的值，即是一个地址 这里就把指针的地址进行了改变
    *b=tmp;
    // 通过指针的指针 来交换指针的值，即改变指针的指向，但是这样还是无法达到交换原两个变量的目的
}

void swap4(int* a,int* b){
    int tmp = *a;// 此时tmp是一个值，就是指针所指向的值
    *a =*b;
    *b= tmp;
  
}
void swap5(int& a,int& b){
    int tmp = a;
    a =b;
    b= tmp;

}
// 下面是一个返回类型是引用的函数 但是要注意不能返回局部引用变量
int &s(int& num1){
    int num =200;
    
    // 注意ref_num是在函数中局部定义的 所以是局部变量
    int& ref_num =num;
    // 局部变量num在运行完毕后，会内存回收
    // 所谓内存回收，并不是把内存的设置清零了
    // 而是原来申请的这块内存已经不归你所用了
    
    num1++;
    return num1;
    
    
    //return ref_num;// 注意这里的返回  这里就不能返回局部引用变量  虽然没有报错，但是返回的却不是原变量的值了
    // 如果没有return的话，默认返回最后修改的变量的值，默认返回传入的引用对象本身
    // 返回引用时，要求函数参数中包含被返回的引用对象
}


// 函数重载 指可以有多个同名的函数，函数名相同，但是参数列表不同(特征标不同)
// 内部是：编译器在编译器，很具参数列表对函数进行重命名
// 注意 如果是 void eating(string & food)那么编译器就无法区别了 这里要注意引用的e特殊性
// 编译器会把类型的引用和类型本身视为同一个特征标 所以就不能区分了 这里注意
// 在函数重载中，有没有const关键字  没有区别

void eating(string food){
    cout<< "吃"<<"1" <<endl;
}

void eating(int food){
    cout<< "吃" <<"2"<<endl;
}

// 书写模板函数

//void sum_t(T a,T b){
//    return a+b;
//}






int main(int argc, const char * argv[]) {
    // insert code here...
    // 引用
    double a =20;
    double &b =a;
    const double &c = 20;// 不能直接引用常量，要加const关键字 引用必须要初始化
    /*
     引用并非对象，而是为已经存在的对象起的一个别名
     引用更接近与const指针，一旦与某个变量关联，就一直效忠于它
     将引用变量作为函数参数时，函数将使用原数据，而非副本
     当数据所占内存比较大时n，建议使用引用参数
     */
    
    int n1 =10;
    int n2 =20;
    //cout<<"交换前："<< "n1="<<n1<<"\t"<<"n2="<<n2<<"\t" <<&n1<<"\t"<<&n2<< endl;
    //swap1(n1,n2);
    //cout<<"swap1交换后："<< "n1="<<n1<<"\t"<<"n2="<<n2<<"\t"<<&n1<<"\t"<<&n2<< endl;
    int *p1 =&n1;
    int *p2 =&n2;
    cout<<"swap2交换前："<< "&n1="<<&n1<<"\t"<<"&n2="<<&n2<<"\t"<< endl;
    cout<<"swap2交换前："<< "p1="<<p1<<"\t"<<"p2="<<p2<<"\t"<< endl;
    swap2(p1,p2);// 指针做参数时，要传入地址
    cout<<"swap2交换后："<< "n1="<<n1<<"\t"<<"n2="<<n2<<"\t"<<&n1<<"\t"<<&n2<< endl;
    //cout<<"swap2交换后："<< "&p1="<<&p1<<"\t"<<"&p2="<<&p2<<"\t"<< endl;
    cout<<"swap2交换后："<< "p1="<<p1<<"\t"<<"p2="<<p2<<"\t"<< endl;
    swap3(&p1,&p2);// 指针做参数时，要传入地址 此时要传入指针的地址  因为swap3的参数类型是指针的指针
    // 形参和实参之间的传递是值传递，所以swap3的类型是指针的指针，它的值就应该是一个指针的地址才对
    cout<<"swap3交换后："<< "n1="<<n1<<"\t"<<"n2="<<n2<<"\t"<<*p1<<"\t"<<*p2<< endl;
    swap4(&n1,&n2);// 指针做参数时，要传入地址
    cout<<"swap4交换后："<< "n1="<<n1<<"\t"<<"n2="<<n2<<"\t"<<&n1<<"\t"<<&n2<< endl;
    swap5(n1,n2);// 还是用变量名传参 不加&
    cout<<"swap5交换后："<< "n1="<<n1<<"\t"<<"n2="<<n2<<"\t"<<&n1<<"\t"<<&n2<< endl;
    // 也可以直接在main里面进行交换，就不涉及到实参和形参的问题了
    int tmp = n1;
    n1=n2;
    n2 =tmp;
    cout<<n1<<"\t"<<n2<<endl;
    
    // 引用作为返回值
//    int& res =s();
//    cout << "res="<< res<< endl;
//
    
    int n =10;
    int& result = s(n); // 个人感觉这里就是result是函数指针
    s(n) = 55;
    cout<< "result="<< result<< endl;
    
    // 默认参数可以在函数原型或者定义中给出，不能再这两个位置同时出现
    // 对于带列表的函数 必须从右向左添加默认值
    // 如 void t1(int a,int b=5,int c=10); 是正确的 调用时：t1(1),t1(1,2);
    // 如 void t2(int a,int b=5,int c);是错误的，因为默认参数的后面的参数必须都有默认值
    // 如void t3(int a=1,int b=5,int c=10)；是正确的,调用：t3();t3(1),t3(1,2)
    
    // 函数重载  指可以有多个同名的函数，函数名相同，但是参数列表不同(特征标不同)
    
    
    
    
    
    return 0;
}
