#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
		char filePath[] = "/home/johannesr/Desktop/";
		char fileName[] = "note.md";
		char defaultFileContent[] = "# edit this file";
		FILE *ptr;
		strcat(filePath, fileName);
		if (access(filePath, F_OK) == 0) {
				printf("File already exists\n");
				return 1;
		}else {
				
		ptr = fopen(filePath,"w+");
		fprintf(ptr, defaultFileContent);
		fclose(ptr);
		}
		return 0;
}
