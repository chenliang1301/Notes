#include <stdio.h>
#include <string.h>

int main()
{
	char fstr[14] = {0};
	//int ret = sprintf(fstr, "fileio_%d_%s", 10, "chen");

	int ret = snprintf(fstr, 14, "fileio_%d_%s", 10, "chen");
	printf("ret:%d, strlen(fstr):%zu\n", ret, strlen(fstr));
	printf("fstr = %s\n", fstr);
	
	FILE* pf = fopen(fstr, "w+");
	if(NULL == pf)
	{
		printf("fopen fail\n");
	}
	char *str = "hello world";
	int len = strlen(str);
	ret = fwrite(str, 1, len, pf);
	printf("ret = %d\n", ret);

	fclose(pf);
	pf = NULL;
	return 0;
}

