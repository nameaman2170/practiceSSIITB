/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<unistd.h>
int main(){
	execl("/bin/ls", "-Rl", NULL);
}
