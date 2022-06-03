
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
		char srcFilePath[] = "/home/johannesr/Desktop/";
		char srcFileName[] = "note.md";
		char defaultFileContent[] = "# edit this file";
		FILE *ptr;
		char fileContent[50];
		strcat(srcFilePath, srcFileName);
		ptr = fopen(srcFilePath, "r");
		if (ptr == NULL){
				printf("File doesnt exists\n");
				fclose(ptr);
				return 1;
		}
		
		fgets(fileContent, strlen(defaultFileContent)+1,ptr);
		printf("content: %s\n", fileContent);
		int equal = strcmp(fileContent, defaultFileContent);
		if (equal == 0) {
				printf("File has not been changed and is invalid. \n");
				fclose(ptr);
				return 1;
		}else {
		fclose(ptr);
		return 0;
		}
}
