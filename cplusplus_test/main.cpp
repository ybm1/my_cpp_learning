//
//  main.cpp
//  cplusplus_test
//
//  Created by 毕启轩 on 2019/12/7.
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
/*
 以#号开头是预处理指令
 include 可以没有，如果有必须放在开头
 iostream是输入输出流
*/

using namespace std;
/*
 命名空间 避免起名字的冲突 std相当于python中的os库 count和endl是std中的函数
 相当于from os import *
*/

// 模板类
template<class T>
// 只能算基本类型的数组长度 如整形 char型  不能计算字符串型的数组长度
// 因为整形元素和char型元素的大小固定 而字符串型的c元素大小不固定
int length(T& arr)
{
    //cout << sizeof(arr[0]) << endl;
    //cout << sizeof(arr) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    /*
     把字符串插入到输出流里面l;
     endl 为end line 相当于换行 重启一行
     endl不仅换行 还是清空缓冲区 相当于c的fflush(stdin)
     而\n就是h换行
    */
    // 变量命名不要用拼音
    int a_1 = 2;
    string a_2 ="a";
    string a_3 = "abc";
    double a_4 = 3.1412;
    bool a_5 = true;
    cout << "英雄:白起\n"
         << "demage: \t 300\n"
         << "weapon: \t 青龙偃月\n" << endl;
    cout << "Hello, World!\n" << a_2 << endl;
    printf("Hello, world! %d\n",a_1);
    cout << "a_1:" << a_1 << "\n"
         << "a_2:" << a_2 << "\n"
         << "a_3:" << a_3 << "\n"
         << "a_4:" << a_4 << "\n"
         << "a_5:" << a_5 << endl;
    //printf("a_2: %s\n",a_2);
    cout << a_1 << endl;
    
    const double pi = 3.14; // 定义了常量 下面不能再修改pi，否则报错
    double len = 3;
    double wid = 5;
    double s = pi*pow(len, wid)+len*wid;
    cout << "s= " << s << endl;
    double a_6 = 10/3;
    cout << fixed;
    cout << setprecision(6);
    cout << a_5 << endl;
    /*
    // cin的使用
    cout << "开始输入char" << endl;
    char c1, c2, c3;
    cin >> c1;
    cin >> c2;
    cin >> c3;
    cout << c1 << "\t" << c2 << "\t" << c3 << endl;
    cout << "开始输入string" << endl;
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    cout << s1 << "\t" << s2 << "\t" << s3 << endl;

    cout << "开始输入int" << endl;
    int b1,b2,b3;
    b1 = cin.get();
    b2 = cin.get();
    b3 = cin.get();
    cin >> b1;
    cin >> b2;
    cin >> b3;
    cout << b1 << "\t" << b2 << "\t" << b3 << endl;
     为整型起别名
    typedef int zhengxing;
    zhengxing a =3;
     */
    
    cout << setw(4) << "|" <<"控制输出的宽度精度后的s*a_6:" << setw(4) << "|"<< s*a_6 << endl;
    // setW只管后面的设置宽度
    
    
    // 运算
    
    int d1 = 300;
    int d2 = 9;
    int d3 = 31;
    d2 = (d1++) - (--d1);
    cout << "连加连减" << "\t" << d1 << "\t" << d2 << "\t" << endl;
    
    cout << "除法" << d1/d3 << endl;
    cout << "取模" << d1%d3 << endl;
    cout << "取模" << d3%d1 << endl;
    cout << "乘法" << d1*d3 << endl;
    cout << "加法" << d1+d3 << endl;
    
    cout.setf(ios_base::fixed, ios_base::floatfield);
    int e1 =300, e2=9;
    double e3 =(double) e1/e2;
    // 后面加上double是强制类型转换  如果不加 结果是33.000000
    cout << "double 除法" << e3 << endl;
    
    cout << sizeof(e1++) << endl;
    cout << "e1==>" << e1 << endl;
    /*
     sizeof 是运算符 不是函数  只用来计算变量的所占的字节数
     在这里 ++ 自增运算不会做
    */
    
    int num =1;
    int sums=0;
    while(num<=100){
        sums=sums+num;
        num++;
    }
    cout << "1-100累加和===>" << sums << endl;
    
    int year = 2015;
    double sale = 800;
    //double peak = sale;
    while(sale < 2000){
        sale = sale * 1.25;
        year ++;
        cout << "year="<< year << "sale=" << sale << endl;
    }
    cout << year << endl;
    
    int k=1, n=10, m=1;
    while(k<=n){
        m=m*2;
        n--;
        cout << "m="<< m <<"\t"<<"n="<<n << "\t" << "k="<<"\t" << k << endl;
        
    }
    cout << "m=" << m << endl;
    
    int n1 =0;
    while(n1++<=2);
    cout << n1 << endl;
    
    
    
    
    int randnum;
    int a = 1;
    int b = 9;
    srand((unsigned)time(NULL));// 不同的随机种子对应了不同的数字
    for(int i =0; i< 10; i++){
        
        randnum = rand()%(b-a) +a;
        cout<<"["<<a<<","<<b<<")之间的随机数===>" << randnum << endl;
    }
    
    
    /*
     要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
     要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
     要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
     通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
     要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
     要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
    */
    
    // for循环
    const int N =20;
    for(int j=0;j<=N;j=j+1){
        cout<< "j==>" << j<< endl;
    }
    // 打印菱形星号
    for(int i =0;i<4;i++)
    {
        for(int k=0;k<=2-i;k++){
            cout<<" ";
        }
        for(int j=0;j<=2*i;j++ ){
            cout <<"*" ;
        }
        cout<< "\n";
        
        
    }
    
    for(int i=0;i<4;i++){
        for(int k=0;k<=i;k++){
            cout<<" ";
        }
        for(int j=0;j<=4-2*i;j++ ){
            cout <<"*" ;
        }
        cout<< "\n";
    }

    
    
    // 打印菱形和空心字母
    for(int i =0;i<4;i++)
    {
        for(int k=0;k<=2-i;k++){
            cout<<" ";
        }
        for(int j=0;j<=2*i;j++ ){
            cout << (char)('A' + i);// 强制类型转换
        }
        cout<< "\n";
        
        
    }
    
    for(int i=0;i<4;i++){
        for(int k=0;k<=i;k++){
            cout<<" ";
        }
        for(int j=0;j<=4-2*i;j++ ){
            if(j==0 ||j==(4-2*i)){
                cout <<(char)('E'+i) ;
            }
            else{
                cout << " ";
            }
        }
        cout<< "\n";
    }

    // 数组 数组中的元素类型必须一致
    // 静态数组大小一旦确定，大小就不能再改了
    int nums1[20] = {1,'a',3,6,10}; // 可以少给不能多给，少给的默认为0
    int nums2[] = {1,2,3,0,0,10,22,12,1,2,1,6};
    int nums3[100] = {}; // 初始化一个长度为100的元素为0的数组
    cout<< nums3[99]<<endl;
    int nums4[26];
    double ds[30];
    string strs[20];
    cout<< nums1[1]<<endl;
    
    cout<< "数组长度"<< length(nums3) << endl;
    
    // 求数组最大值
    
    int l[] ={1,2,3,0,0,10,22,12,1,2,1,6};
    int max_value = l[0];
    int max_index = 0;
    for(int i =0;i<length(l);i++){
        if(l[i]>max_value){
            max_value = l[i];
            max_index = i;
        }
        
    }
    cout<< "最大值"<< max_value << "最大值索引"<< max_index<< endl;
    // 求奇数个数和偶数个数
    int odd = 0;
    int even =0;
    for(int i=0;i<length(l);i++ ){
        if(l[i]%2==0){
            odd++;
        }
        else{
            even++;
        }
    }
    cout<< "奇数个数"<< odd << "偶数个数"<< even << endl;
    
    // 查找
    
    int target = 22;
    int target_index = -1;
    for(int i=0;i<length(l);i++){
        if(l[i]== target){
            target_index = i;
        }
    }
    cout<< "目标数字在数组中的索引是："<<target_index << endl;
    // 数组排序
    // https://www.nowcoder.com/discuss/85719
    
    
    // 二维数组
    
    string stu_names[] = {"刘备","关羽","张飞"};
    string cour_names[] = {"语文","数学","英语"};
    const int row =3;
    const int col =3;
    double scores[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<< stu_names[i]<< "的" << cour_names[j]<< "成绩";
            scores[i][j] = i*j+1;
            cout<<"\t" <<scores[i][j];
        }
        cout<<"\n";
    }
    
    // 向量容器vector，其大小可以动态变化，可以快速索引等
    // https://blog.csdn.net/weixin_43930512/article/details/91040416
    vector<double> v;
    // 末尾c追加数字,即Python的list的append方法
    v.push_back(0);
    v.push_back(1);
    vector<double> vd = {1,2,1,2,3,5,2};
    // 数组长度
    cout << "元素的长度(用.size()方法)"<< vd.size()<< endl;
    // 迭代器
    vector<double>::iterator it; //得到迭代器对象-实际是一个指针对象
    // 从第一个元素开始迭代
    for(it = vd.begin();it != vd.end();++it){
        cout<< "用迭代器拿到元素" << *it << endl;
        
    }
    // 排序
    cout<< endl;
    sort(vd.begin(),vd.end());
    
    for(it = vd.begin();it != vd.end();++it){
        cout<< "排序后" << *it << endl;
        
    }
    // 逆序
    cout << endl;
    reverse(vd.begin(), vd.end());
    for(it = vd.begin();it != vd.end();++it){
        cout<< "逆序排后" << *it << endl;
    }
    
    vector<int> vi = {};
    cout << "空数组的长度为:"<< vi.size() << endl;
    
    // 指针 一个值为内存地址的变量 一般用16进制表示
    // &为取地址符
    // 一个变量的类型与其指针变量的类型，一定是一致的。
    int y = 999;
    int *p_y = &y;// 给指针赋值必须用&
    cout<< "指针存放的该int变量的地址为： " << p_y <<"\n"
                <<"该int变量的值为:"<< y << "\n"
                <<"或用*指针变量名取该int变量的值:" <<*p_y << endl;
    // 当*放在定义语句的时候 表明是一个指针变量，如上面的 int *p_y = &y;
    // 这表明 p_y是一个指针变量
    // 而不在定义语句时，如当用*p_y时(不是定义语句)，表示拿到该指针变量p_y存的地址
    // 所对应变量y的值
    
    char ch1 = 'a';
    char *p_ch1 = &ch1;
    // (void *)表示指向任意类型
    cout<< "指针存放的该char变量的地址为(用void强制转换)： " << (void *)p_ch1 <<"\n"
    << "指针存放的该char变量的地址为(用string强制转换)： " <<(string *)p_ch1 <<"\n"
    << "指针存放的该char变量的地址为： " << p_ch1 <<"\n"
    <<"该char变量的值为:"<< ch1 << "\n"
    <<"或用*指针变量名取char变量的值:" <<*p_ch1 << endl;
    
    
    string str1 = "skrskrskr";
    string *p_str1 = &str1;
    // (void *)表示任意类型
    
    cout << "指针存放的该string变量的地址为： " << p_str1 <<"\n"
    <<"该string变量的值为:"<< str1 << "\n"
    <<"或用*指针变量名取string变量的值:" <<*p_str1 << endl;
    
    double dou1 = 3.14;
    double *p_dou1 = &dou1;
    // (void *)表示任意类型
    
    cout << "指针存放的该double变量的地址为： " << p_dou1 <<"\n"
    <<"该double变量的值为:"<< dou1 << "\n"
    <<"或用*指针变量名取double变量的值:" <<*p_dou1 << endl;
    *p_dou1 = 88.22;
    cout <<"用指针修改变量值："<< dou1 <<"\n"
    <<"修改后的变量的地址(不变)"<< p_dou1<< endl;
    
    
    // 空指针为nullptr，不指向任何变量，可以给野指针赋予初值，这样其地址就是0，就不会乱指
    int *ptr1 = nullptr;
    cout << "空指针所存的地址为："<<ptr1 << endl;
    //
    int *ptr2 = 0;
    cout << "ptr2所存的地址为："<<ptr2 << endl;
    int *ptr3 = NULL; // 等价于 int *ptr3 =0
    cout << "ptr3所存的地址为："<<ptr3 << endl;
    // 上面3个指针所存的地址全是0，这是一种指针初始化的方法，防止乱指
    // 强烈建议 初始化所有指针！！！
    
    // void*指针，可以存放任意对象的地址
    
    double dd1 = 3.14;
    double *p_d1 = &dd1;
    void *p_d2 = &dd1;
    cout << (p_d1==p_d2) << endl;
    
    // void *指针s存在一个内存地址，地址指向的内容是什么类型不能确定
    // void *类型指针一般用来：拿来和别的指针比较，作为函数的输入和输出 或赋值给
    // 另外一个void* 指针
    // 不能用来修改数据 下面一行代码是错的
    // *p_d2 = 666;
    
    
    // 引用 底层还是指针
    
    int int_value = 10;
    int& ref_int_value = int_value;
    ref_int_value = 15;
    cout <<"引用==地址===>" <<&int_value << "\t" << &ref_int_value << endl;
    cout <<"引用==值===>" <<int_value << "\t" << ref_int_value << endl;
    
    // 等价于
    int* ref_value = &int_value;
    *ref_value = 20;
    cout << &int_value << "\t"<< ref_value << endl;
    cout << int_value << "\t" << *ref_value << endl;
    
    
    // 数组和指针
    double score [] = {6,5,4,3,2,1};
    cout << "当前数组为"<< endl;
    for(int i=0;i<6;i++){
        cout << score[i] << "\t";
    }
    cout << endl;
    double * p_score = score;
    // 在这里的* p_score = score 等价于定义了名为p_score的指针，它指向了数组的第一个元素
    // 当指针等于数组名时，实际的意义就是这个指针指向了数组的第一个元素，保存了数组第一个元素的地址
    // 当然也可以直接定义指向数组第一个元素的指针 如下
    double *p_score_0 = &score[0];
    // 注意这里第一个元素前m加了取地址符，由于整个数组的没有完整的地址(如链式存储的数组),
    // 所以如果指针等于数组名，那么就不用加&(默认已经指向数组第一个元素)，如上面的* p_score = score
    // 但score[0]是有明确地址的，所以如果定义指向数组第一个元素的指针时，就必须加上取地址符
    // 即上面的*p_score_0 = &score[0]，这两种方式都可以进行算术运算，也都可以充当索引功能
    // 用来取数组的值
    cout << endl;
    cout <<"数组和指针的size==>\t" <<sizeof(score) << "\t" << sizeof(p_score) << endl;
    // 地址都占 8个字节(有的是4个 不同机器不同)
    // 而double一个占8个字节 所以5个元素共占5*8=40个字节
    // 通过指针可以取数组元素
    cout <<"通过指针取数组的元素==>"
                << p_score[2] <<"\t" << *(p_score +=1)<< "\t"
                << *(p_score++) << "\t" <<*p_score <<"\t"
    << *(p_score_0+=3) <<"\t" << *(p_score_0-=2)<< "\t"<<endl;
    cout << endl;
    *p_score_0 +=3;
    cout << *p_score_0<< endl;
    //首先注意上面代码中的 *(p_score_0+=3)是先进行指针平移，往后移了3个位置，再把相应的值取出
    //注意这里要加括号，如果不加，那么*p_score_0+=3就成了修改当前指针所指元素的值了
    
    
    /* 再注意上面几种取数组的值的方式的区别
     p_score刚开始指向了数组的第一个元素，是一个指针，保存了数组第一个元素的地址
     p_score[2]等价于*(p_score+2)，即此时可以拿到数组第2个元素即score[2],
     但注意，此时的p_score还没有被更新，还是指向了原位置，如果是p_score+=2，那么就会被更新了
     另外，++和+=1是不一样的，++无论加不加括号，都是表达式运算完毕再++，而+=1不是这样
     */
    // 注意下面这个不是指针平移，是通过指针修改指针所指的数组元素的值
    cout << endl;
    for(int i=0;i<6;i++){
        cout <<"这里不是指针平移，而是通过指针修改指针所指的数组元素的值===>" << (*p_score)++<<"\t" <<score[0]<< endl;
    }
    cout << endl;
    // 指针在平移时，每次移动的空间是sizeof(T),T为该指针目前指的元素的字节
    
    
    
    // new 动态分配内存
    // 指针的真正的用武之地：在运行阶段分配未命名的内存以存储值
    int * ptr_int = new int;
    delete ptr_int;// 释放ptr_int所指向的内存 不要释放两次
    // delete与new成对使用
    // 不要说释放已经释放的内存
    // 不能释放声明变量分配的内存
    // 对空指针使用delete是安全的
    // 可以参考这个：http://c.biancheng.net/view/206.html
    
    
    // 用指针实现数据逆序
    int arrs[] = {1,2,3,4,5,6};
    int *p_arrs_s = arrs;
    int *p_arrs_e = p_arrs_s+5;
    for(int i =0;i<6;i++){
        cout <<"数组逆序====>"<< *(p_arrs_e-i) << endl;
    }
    // 或者交换头指针和尾指针所指的数字
    cout << endl;
    int temp;
    int end = 5;
    int start =0;
    while (start<=end) {
        temp = *p_arrs_s;
        *p_arrs_s = *p_arrs_e;
        *p_arrs_e = temp;
        cout<< *(p_arrs_s) <<"\t"<< *(p_arrs_e)<< endl;
        p_arrs_s+=1;
        p_arrs_e-=1;
        start +=1;
        end -=1;
        
    }
    
    for(int i =0;i<6;i++){
        cout<<"数组逆序====>"<<arrs[i]<< endl;
    }
    cout << "二维数组和指针的一些运算>>>>"<< endl;
    // 关于二维数组的运算
    int arr_two[3][5] = { {0, 1, 2, 3,6}, {4, 5, 6, 7,8}, {8, 9, 10, 11,9} };
    int (*p)[5] = arr_two;
    //把数组首地址a放入p中(arr_two的地址就是arr_two[0]的地址)，所以等价于把arr_two[0]的地址放入p
    //此处不能去除括号！否则就不再是指向某个数组的【指针】
    //而是变成一个存放指针的【数组】
    //即*p[5]=*(p[5]),里面就只能存放5个指针

    printf("*p[0] = %d\n",*p[0]);
    
    printf("arr_two=%p\n",arr_two);//a=a[0]
    
    printf("arr_two[0]=%p, p=%p\n",arr_two[0],p);//a[0]=p
    printf("arr_two[1]=%p, p+1=%p\n",arr_two[1],p+1);//a[1]=p+1
    printf("arr_two[2]=%p, p+2=%p\n\n",arr_two[2],p+2);
    
    //p+1的实际地址操作为：p+sizeof(int)*5=p+20，即p+1实际上移动了20个地址位置
    //因为p在定义时就为int，每一行就有5个int，所以p+1实际上移动了20个int大小
    
    printf("sizeof(*(p+1))=%d\n\n", sizeof(*(p+1)));
    //*(p+1)表示的是第一行的数据，即a[0]的所有数据
    
    printf("a[1][1]=%d, *(p+1)[0]=%d\n", arr_two[1][0],*(p+1)[0]);//所以*(p+1)==a[1]
    
    printf("a[1][1]=%d, *(*(p+1)+1)=%d\n\n", arr_two[1][1],*(*(p+1)+1));
    //同理，因为*(p+1)==a[1]，即*(p+1)是一个指针，那就可以通过指针的操作获得里面的数据
    //即：*(*(p+1)+1)=a[1][1]
    //*(p+1)+1外面的一个+1是指针移动了1个int大小
    printf("sizeof(*(*(p+1)+1))=%d\n\n", sizeof(*(*(p+1)+1)));
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}






