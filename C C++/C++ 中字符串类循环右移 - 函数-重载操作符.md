```cpp

#include <iostream>

#include <string>//��׼C++

using namespace std;

/* //�Ѿ�ʵ��
void swap(int& a, int& b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void string_sort(string a[], int len)//�ַ�������
{
    for(int i=0; i<len; i++)
        int MinIndex = i;
        for(int j=i+1; j<len; j++)
        {
            MinIndex = (a[i] < a[j] ? i : j)
            swap(a[i], a[MinIndex]);
        }
}
*/

void string_sort(string a[], int len)//�ַ�������
{
    for(int i=0; i<len; i++)
        for(int j=i; j<len; j++)
            if(a[i] > a[j])//�ַ�����ıȽ�
                swap(a[i], a[j]);//С����a��0������
}

string string_add(string a[], int len)//�ַ�������
{
    string ret = "";

    for(int i=0; i<len; i++)
    {
        ret += a[i] + ";";//����������
    }

    return ret;
}

int main()
{
    string sa[7] =
    {
        "Hello World",
        "D.T.Software",
        "C#",
        "Java",
        "C++",
        "Python",
        "TypeScript"
    };

    int len = sizeof(sa) / sizeof(sa[0]);

    string_sort(sa, len);

    for(int i = 0; i < len; i++)
    {
        cout << sa[i] << endl;
    }

    cout << endl;

    cout << string_add(sa, len) << endl;

    return 0;
}

```

##  �ַ��������ֵ��໥ת��

- <sstream>������string�Ľ���
- istringstream
- ostringstream

```cpp

#include <iostream>

#include <sstream>

#include <string>

#include <iostream>

#include <string>

using namespace std;

#define TO_NUMBER(s, n) (istringstream(s) >> (n))

#define TO_STRING(n) (((ostringstream&)(ostringstream() << n)).str())

int main()
{
    double n = 0;

    if(TO_NUMBER("234.23", n))
    {
        cout << n << endl;
    }

    cout << TO_STRING(666.777) << endl;
    cout << s << endl;

    return 0;
}

```

```cpp

#include <iostream>

#include <string>

using namespace std;

string operator >> (const string& s, unsigned int n)
{
    string ret = "";

    //abcdef ==> 3 efg abcd
    //abc.def ==> 3 efg abcd

    unsigned int pos = 0;

    // abc ==> 1 cab
    // abc ==> 4 cab

    n = n % s.length();
    pos = s.length() - n;

    ret = s.substr(pos);//��ȡpos֮�����е��ַ���
    ret += s.substr(0, pos);//��ȡ0����pos�������ַ���

    // abcdefg ==> 8   abcdefg ==> 1



    return ret;


}

int main()
{
    string s = "abcdefg";
    cout << (s>>8) << endl;

    return 0;
}

```

## С��

- C++û��ԭ���ַ���
- ��׼��sting��

## ��ҵ
- �ַ�����ת
