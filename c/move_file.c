#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 80
int main(){
// curious if #define things are better?
// I dont know what the difference is yet

		char srcFilePath[] = "/home/johannesr/Desktop/";
		char srcFileName[] = "note.md";

		char destFilePath[] = "/home/johannesr/Documents/.notes/";
		char destFileName[50];
		char defaultFileContent[] = "# edit this file";
		FILE *ptr;
		FILE *destPtr;
		char fileContent[20];

		strcat(srcFilePath, srcFileName);
		ptr = fopen(srcFilePath, "r");
		/*
		printf(srcFilePath);
		printf("\n");
		printf(destFilePath);
		printf("\n");
		*/

		// constructs name in the wanted time format
		// this is easier than in python for some reason?
		// kinda sick

		time_t time_raw_format;
		struct tm *ptr_time;
		time ( &time_raw_format  );
		ptr_time = localtime ( &time_raw_format );
		if (strftime(destFileName,50,"%d-%m-%Y", ptr_time) == 0){
				// fallback name path incase there is an error with the time.
				printf("couldn't prepare formatted string\n");
				strcat(destFilePath, "new-note.md");
		}else {
				strcat(destFileName, ".md");
				//printf("current local time and date: %s\n", destFileName);
				strcat(destFilePath, destFileName);

		}
		if (ptr == NULL){
				printf("File doesnt exists\n");
				fclose(ptr);
				return 1;
		}
		// there is a bug here
		// it doesnt go long enough to cover the defaultFileContent.
		// I dont know how to fix it, but it works fine without this feature.
		//
		fgets(fileContent, 1+strlen(defaultFileContent), ptr);
		//printf("content: %s\n", fileContent);
		int equal = strcmp(fileContent, defaultFileContent);
		if (equal == 0) {
				printf("File has not been changed and is invalid. \n");
				fclose(ptr);
				return 1;
		}else {
				fclose(ptr);
				ptr = fopen(srcFilePath, "r");
				char line[MAX_LINE_LENGTH] = {0};
				if (access(destFilePath, F_OK) == 0){
						printf("file already exists... \n");
						// destPtr = fopen(destFilePath, "a");
						// appends the text
						// i chose to not do this by default.
						return 1;
				}
				else {
						destPtr = fopen(destFilePath, "w+");
						printf("writing content to file: %s\n", destFilePath);
				}
				if (!destPtr) {
						printf("file not found and some error occured\n");
				}
				while (fgets(line, MAX_LINE_LENGTH, ptr)) {
					// printf(line);
					// goes through every line and writes it to the new file
					//
					// uncertain if i should delete or clean the previous note.
					// It is kinda nice having it there as a reminder.
					fprintf(destPtr, line);
				}
				
			fclose(destPtr);
		fclose(ptr);
		return 0;
		}
}
