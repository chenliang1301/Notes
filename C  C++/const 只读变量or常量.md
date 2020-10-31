- const�������б��׼
	- ֻ��**������**��ʼ���� const�����Ż������ű�
	- ʹ������**����**��ʼ���� const������Ȼ��ֻ������
	- voliate const���εĳ��������������ű�����ֻ������
	> ����������ֱ��ȷ����ʼֵ��const��ʶ��������Ϊֻ����������

- const�����������ʼ����������
	- ��ͬ����ʼ��������Ϊֻ������
	- ��ͬ������һ���µ�ֻ������ 
	

```cpp
#include <stdio.h>

int main()
{
    const int x = 1;	//xΪ������ͬʱ����ռ䣬һ�㲻ʹ�ã�����ͨ��ָ�������ʹ��
    const int& rx = x;  //rxΪֻ��������ֵ1�����ܳ����ڸ�ֵ���ŵ����
     
    int& nrx = const_cast<int&>(rx);  //const_cast����ֻ�����������ԣ�nrxΪȥ��ֻ�����Եı�������rx��ͬһ���ڴ�ռ�
    
    nrx = 5;
    
    printf("x = %d\n", x);//1
    printf("rx = %d\n", rx);//1
    printf("nrx = %d\n", nrx);//5
    printf("&x = %p\n", &x);//
    printf("&rx = %p\n", &rx);
    printf("&nrx = %p\n", &nrx);//���ߵ�ַ��ͬ
    
    volatile const int y = 2; //volatile ��䣬ֻ������������ռ�
    int* p = const_cast<int*>(&y);//ȥ���ռ�ĵ�ֻ�����ԣ���ȡ����Ϊp
    
    *p = 6;
    
    printf("y = %d\n", y);//6
	printf("&y = %p\n", &y);//y�ĵ�ַ
    printf("p = %p\n", p);//y�ĵ�ַ
    
    const int z = y;//ֻ������
    
    p = const_cast<int*>(&z);//ȥ��ֻ������
    
    *p = 7;
    
    printf("z = %d\n", z);//7
    printf("p = %p\n", p);//z�ĵ�ַ
    
    char c = 'c';
    char& rc = c;
    const int& trc = c;//���Ͳ�ͬ�������µ�ֻ������*********
    
    rc = 'a';
    
    printf("c = %c\n", c);//a
    printf("rc = %c\n", rc);//a
    printf("trc = %c\n", trc);//c
    
    return 0;
}

```
#### ������ָ��Ĺ�ϵ
> ���� ������ָ�볣��
- ָ���Ǹ�����
	- ֵΪ�ڴ��ַ������Ҫ��ʼ�����ɱ��治ͬ��ֵ
	- ͨ��ָ��ɷ����ڴ��ֵַ  
	- ָ�뱻const���γ�Ϊ������ֻ������
- ����ֻ�Ǳ�����������
	- �����õĲ�������ֵ��ȡ��ַ�����ᴫ�ݵ���Ӧ�ı�����
	- const���Σ�ʹ��������ֻ������
	- ���ñ����ʼ����֮���޷������������� 	

- C++�Ƕȣ������Ǳ�����������
- C++���������������ڲ�ʹ��ָ�볣����ʵ�֡����á�

```cpp
#include <stdio.h>

int a = 1;

struct SV
{
    int& x;
    int& y;
    int& z;
};

int main()
{
    int b = 2;
	int a = 1;
    int* pc = new int(3);
    SV sv = {a, b, *pc};
    //int& array[] = {a, b, *pc}; // &array[1] - &array[0] = ?  Expected ==> 4,��Ա��ַ֮���ڴ�Ϊ4
	//C++��֧����������
    
    printf("&sv.x = %p\n", &sv.x);//a��ַ
	printf("&a = %p\n", &a);//a��ַ
    printf("&sv.y = %p\n", &sv.y);//b��ַ
	printf("&b = %p\n", &b);//b��ַ
    printf("&sv.z = %p\n", &sv.z);//*pc��ַ
	printf("&8pc = %p\n", &(*pc));//b��ַ    
    delete pc;
    
    return 0;
}

```


## С��
- ָ���Ǳ����������Ǳ���
- const���ò����µ�ֻ������
- �������ڲ�ʹ��ָ�볣��ʵ������
- ����������ȷ����ʼֵ��const��ʶ����Ϊֻ������
