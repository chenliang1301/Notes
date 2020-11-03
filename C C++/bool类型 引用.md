���ۣ�
bool���ͣ�ռ��һ���ֽ�
true�����㣬����Ϊ1
false���㣬����Ϊ0

```cpp

#include <stdio.h>

int main(int argc, char *argv[])
{
    bool b = false;
    int a = b;

    printf("sizeof(b) = %d\n", sizeof(b));//1
    printf("b = %d, a = %d\n", b, a);//0,0

    b = 3;
    a = b;

    printf("b = %d, a = %d\n", b, a);//1,1

    b = -5;
    a = b;

    printf("b = %d, a = %d\n", b, a);//1,1

    a = 10;
    b = a;

    printf("a = %d, b = %d\n", a, b);//10,1

    a = 0;
    b = a;

    printf("a = %d, b = %d\n", a, b);//0,0

    return 0;
}

```

���ܽ᣺bool���εı����Ὣֵ��Ϊ1��0.

��Ŀ�����
C�в��ܵ���ֵ
C++����Ŀ��������ܷ��ض�Ϊ����ʱ���ɵ���ֵ�����ص��Ǳ���������
C++����Ŀ��������ܷ����г���ʱ�����ɵ���ֵ�����ص���ֵ������

```cpp

#include <stdio.h>

int main(int argc, char *argv[])
{

    int a = 1l;
    int b = 22;

    (a < b ? a : b ) = 3; //��a��b�����ã���
    (a < b ? a : 1 ) = 3; //��
    printf("a = %d\tb = s%d\n", a, b); //3,255

}

```

����
����Ѷ�������ı���
������Type& b = a;
�磺int a = 2;
 int& b = a;
 b = 5;//a==5

```cpp

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 4;
    int& b = a;
    float& b = a;/* ����ǿ���ͣ���������һ�� */
    int& b;/* ��δ���� */
    int& b = 1;/* �� */

    b = 5;

    printf("a = %d\n", a);//4
    printf("b = %d\n", b);//5
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);//��a��ַ��ͬ

    return 0;
}

```

 ���ܽ᣺
 1boolֵֻ��Ϊtrue��1����false��0��
 2��Ŀ����������ܵķ���ֵ��Ϊ����ʱ���ر��������ã�����Ϊ��ֵ�������ؿ���Ϊ������ֵ����ֵΪֵ��������ֵ
 3C++�����ÿ���Ϊ�����ı���
