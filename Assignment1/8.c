/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
int main(){
	FILE* file = fopen("input_file.txt", "r");
	if(file == NULL){
		printf("file can not be opened: ");
		return 1;
	}	
	char line[1024];
	while(1){
		char* str = fgets(line, 1024, file);
		if(str == NULL){
			printf("this is end of file : ");
			break;
		}
		printf("%s", str);
	}
	return 0;
}
