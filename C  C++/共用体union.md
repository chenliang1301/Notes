## �����÷�ͬ�ṹ��

```c
/* 1.s,iͬһ���ڴ�
   2.s_tr1.i������int���ͽ����ڴ�ռ�
   3.s_tr1.s������short���ͽ����ڴ�ռ�
 */
union STR1 {
	short s;			//8		
	int i;				//4		
};						//12	

int main()
{
	union STR1 s_tr1;
	printf("sizeof(s_tr1) = %d\n", sizeof(s_tr1));	// 4

	s_tr1.i = 4;
	printf("s_tr1.s = %d\n", s_tr1.s);		//4
	printf("s_tr1.i = %d\n", s_tr1.i);		//4
	printf("&s_tr1.s = %d\n", &s_tr1.s);	//
	printf("&s_tr1.i = %d\n", &s_tr1.i);	//������ַ��ȣ�ָ��ͬһ���ڴ�
	return 0;
}
```
### ��ͬ��
- union����һ���ڴ浥Ԫ�����ڴ��ж��ֲ�ͬ�Ľ�����ʽ���ṹ���Ա�˴˶������������һ��
- �������ڴ���룬ֻ��һ���ڴ�ռ䡣
- �ڴ�ȡ����Ԫ��ռ������ڴ�Ĵ�С
