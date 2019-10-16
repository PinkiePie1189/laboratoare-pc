#include <stdio.h>
#include <string.h>

int main() {
	int val = 5; //0x00000005
	char buf[10];
	snprintf(buf, 10, "%hhx", val);
	//printf("%s", buf);
	
	if (!strcmp(buf, "5")) {
		printf("Little-endian\n");
	} else {
		printf("Big-endian\n");
	}

	return 0;
}
