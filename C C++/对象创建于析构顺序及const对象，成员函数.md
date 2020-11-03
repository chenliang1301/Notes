# �������󴴽�ʱ���캯��˳��

- 1����
- 2��Ա����
- 3����

## ������˳���෴

```cpp

#include <stdio.h>

class Member
{
    const char* ms;
public:
    Member(const char* s)
    {
        printf("Member(const char* s): %s\n", s);

        ms = s;
    }
    ~Member()
    {
        printf("~Member(): %s\n", ms);
    }
};

class Test
{
    Member mA;
    Member mB;
public:
    Test() : mB("mB"), mA("mA")
    {
        printf("Test()\n");
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};

Member gA("gA");

int main()
{
    Test t;

    return 0;
}

```

��ӡ
Member(const char* s): gA
Member(const char* s): mA
Member(const char* s): mB
Test()
~Test()
~Member(): mB
~Member(): mA
~Member(): gA

- ջ�����ȫ�ֶ���Ĵ�����������������ջ��ջ˳��
- �Ѷ��������������deleteʱ

### const��������

- const����Ϊֻ������
- ֻ������ĳ�Ա�������ɸı�
- ����׶β��ɸģ����н׶���Ч
- ֻ������ֻ�ܵ���const��Ա����
-

### const��Ա����

- const��Ա���������޸ĳ�Ա����

```cpp

#include <stdio.h>

class Test
{
    int mi;
public:
    int mj;
    Test(int i);
    Test(const Test& t);
    int getMi();//const��Ա��������
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)//t Ϊtest���ã�tΪֻ������ֻ�ܵ���const��Ա����
{
    mi = t.getMi();
}

int Test::getMi()//const��Ա��������
{
    //mi = 2;//const��Ա���������޸ĳ�Ա����
    return mi;
}

int main()
{
    const Test t(1);
    //t.mj = 3;//error ֻ������ĳ�Ա����ֵ���ɸı䣬����׶β��ɸģ����н׶���Ч
    //printf("t.getMi() = %d\n", t.getMi());//1

    return 0;
}

```

#### ����

- �����ɳ�Ա�����ͳ�Ա��������
- ���������ݺͺ�������
    -  ����λ��ջ���ѡ�ȫ��������
    - ����λ�ڴ����

#### ����

- ÿ���������Լ��Ķ������ԣ���Ա������
- ���ж�������ķ�������Ա������
- ������ֱ�ӷ��ʶ��������
- ���������ز���this������ָ����ǰ����

```cpp

#include <stdio.h>

class Test
{
    int mi;
public:
    int mj;
    Test(int i);
    Test(const Test& t);
    int getMi();//const��Ա��������
    void print();
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)//t Ϊtest���ã�tΪֻ������ֻ�ܵ���const��Ա����
{
    mi = t.mi;//�������캯�������Լ��ĳ�Ա������
}

int Test::getMi()//const��Ա��������
{
    //mi = 2; //const��Ա���������޸ĳ�Ա����
    return mi;
}

void Test::print()//thisָ��ָ��ǰ����ֵΪ�����ַ����Ա��������thisָ��
{
    printf("this = %d\n", this);//this
}

int main()
{
     Test t1(1);
     Test t2(2);
     Test t3(3);
     printf("t1.getMi() = %d\n", t1.getMi());
     printf("&t1 = %d\n", &t1);
     t1.print();//���ϵ�ַ��ͬ
     printf("t2.getMi() = %d\n", t2.getMi());
     printf("&t2 = %d\n", &t2);
     t2.print();//���ϵ�ַ��ͬ
     printf("t3.getMi() = %d\n", t3.getMi());
     printf("&t3 = %d\n", &t3);
     t3.print();//

    //t.mj = 3;//error ֻ������ĳ�Ա����ֵ���ɸı䣬����׶β��ɸģ����н׶���Ч
    //printf("t.getMi() = %d\n", t.getMi());//1

    return 0;
}

```

## С��

- ���������˳���빹�캯��˳���෴
- const�ؼ��������ζ���Ϊֻ������
- ֻ������ֻ�ܵ���const��Ա����
- ���ж�������ĳ�Ա����
- ��Ա��������thisָ�����ڱ�ʾ��ǰ����
