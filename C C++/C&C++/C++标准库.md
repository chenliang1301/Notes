# ��׼��Ĵ�ӡ

```cpp

#include <stdio.h>

const char endl = '\n';

class Console
{
public:
    Console& operator << (int i)//
    {
        printf("%d\n", i);
        return *this;//���ص�ǰ����
    }

    Console& operator << (char c)//
    {
        printf("%c", c);
        return *this;//���ص�ǰ����
    }

    Console& operator << (const char* s)//
    {
        printf("%s", s);
        return *this;//���ص�ǰ����
    }

    Console& operator << (double d)//
    {
        printf("%f", d);
        return *this;//���ص�ǰ����
    }

};

Console cout;

int main()
{

    cout << 1 << endl;

    cout << "chen" << endl;
    //==>cout.operator << (1);//1�����������

    double a = 0.1;
    double b = 0.2;

    cout << a + b << endl;

    return 0;
}

```

- C++��׼�������ͺ�������ɵļ���
- C++��׼���ж������Ͷ���λ��std�����շ�����
- C++��׼��ͷ�ļ�����.h
- C++��׼�⺭��C��Ĺ���

```cpp

#include <cstdio>//C��

#include <cstring>

#include <cstdlib>

#include <cmath>

using namespace std;

int main()
{
    printf("hello world\n");

    char * p = (char *)malloc(18);
    strcpy(p, "che");

    double a = 3;
    double b = 4;
    double c = sqrt(a*a + b*b);

    printf("c = %f\n", c);

    free(p);

    return 0;
}

```

## C++ �������

```cpp

#include <iostream>//C��

#include <cmath>

using namespace std;

int main()
{
    cout << "hello" << endl;

    double a = 3;
    double b = 4;

    cout << "input a:";
    cin >> a;//�������뵽a

    cout << "input b:";
    cin >> b;//�������뵽a

    double c = sqrt(a*a + b*b);

    cout << "c = " << c << endl;

    return 0;
}

```

## С��

- C++��׼�������ͺ�������ɵļ���
- C++��׼����������㷨�����ݽṹ��ʵ��
- C++��׼�⺭��C�⹦��
- C++��׼��λ��std�����ռ�
