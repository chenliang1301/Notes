C++ �еĶ�̬�ڴ����
- C++ ͨ��new�ؼ��ֽ��ж�̬�ڴ�����
- ������������

�������룺
Type* pointer = new Type;
//....
delete point;

Type* pointer = new Type[N];
//....
delete[] point;//�ͷ�һƬ�ڴ�ռ�
delete poinr;//�ͷ������׵�ַ�����ڴ�ռ䣬����ڴ�й¶

    p = new int[10];//p��ָ�����һƬ����ռ䣬����40���ֽڣ���

#### new�ؼ�����malloc����

- new�ؼ�����C++��һ����
- malloc��C�⺯��
- new�ǻ������������
- malloc�ǻ����ֽ������
- new����ĳ�����ͱ����ǿ��Գ�ʼ����
- malloc���߱��ɳ�ʼ��

new�ؼ��ֳ�ʼ��
int* pi = new int(1);//����ռ�ɹ����ʼ��Ϊ1

#### C++�����ռ�

- C
    - C�������е�ȫ�ֱ�ʶ������ͬһ��������
    - ��ʶ�����ܷ�����ͻ
- C++ �����ռ�
    - �����ռ佫ȫ��������ֳɲ�ͬ����
    - ��ͬ�����ռ�ı�ʶ������ͬ��
    - �����ռ���໥Ƕ��
    - ȫ��������Ҳ��Ĭ�������ռ�
- C++ �����ռ䶨��
�磺
namespace Name //��
{
    namespace Internal
    {

    }
}

- C++�����ռ��ʹ��
    - ʹ�����������ռ䣺using namespace name;
    -  ʹ�������ռ��еı�����using name::variable;
    - ʹĬ�������ռ������::variable;

```cpp

#include <stdio.h>

namespace First//�����ռ�,��
{
    int i = 0;
}

namespace Second
{
    int i = 1;

    namespace Internal
    {
        struct P
        {
            int x;
            int y;
        };
    }
}

int main()
{
    using namespace First;
    using Second::Internal::P;

    printf("First::i = %d\n", i);//0
    printf("Second::i = %d\n", Second::i);//1

    P p = {2, 3}; //�Ѿ�����

    printf("p.x = %d\n", p.x);//2
    printf("p.y = %d\n", p.y);//3

    return 0;
}

```

- �ܽ�
    - C++��̬�ڴ����ؼ���new
    - C++��̬�ڴ����ɳ�ʼ��
    - C++��̬�ڴ����������͵�
    - C++�����ռ䣬������Ƴ�ͻ

