/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/

#include<unistd.h>
int main(){
	char *str[] = {"/bin/ls", "-Rl", NULL};
        execv(str[0], str);
}

