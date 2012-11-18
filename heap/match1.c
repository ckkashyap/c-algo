#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match_(char *str, char *pat) {
	if(pat==NULL)return 0;
	if(*pat==0)return 1;

	if(str==NULL)return 0;
	if(*str==0)return 0;

	if(*str == *pat)return match_(str+1, pat+1);
	else return 0;
}

int match(char *str, char *pat) {
	int l,i,j;
	l=strlen(str);
	for(i=0;i<l;i++) {
		if(match_(str+i,pat)) {
			printf("%s\n",str);
			for(j=0;j<i;j++) {
				printf(" ");
			}
			printf("^\n");
			return 1;
		}
	}
	printf("NO MATCH\n");
	return 0;
}

int main(int argc, char *argv[]) {
	match(argv[1], argv[2]);
	return 0;
}
