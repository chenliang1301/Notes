#include <stdio.h>
#include <string.h>


int main()
{
	char path[14] = {0};
	int ret = sprintf(path, "fileio_%d_%s", 10, "chen");
	
	printf("ret:%d, strlen(fstr):%zu, path:%s\n", ret, strlen(path), path);
	
	FILE* pf = fopen(path, "w+");
	if(NULL == pf)
	{
		printf("fopen fail\n");
	}
	char *str = "hello world";
	
	ret = fwrite(str, 1, strlen(str), pf);
	printf("ret = %d\n", ret);

	fclose(pf);
	pf = NULL;
	return 0;
}

