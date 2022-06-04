# note reminder

A personal system to automate my personal dev-notes.

I have built the same program in C, and Python.

The C program has a few bugs but it works pretty much as intended.

## what it does

There are two parts to the program. One which creates a template file for me to help me remember.
It will be located on my Desktop, so I'll see it every time I am on my computer.

It will not create a new file if there is already one file there with the same name.

The other program will move the file from the Desktop and place it in my notes folder. It will also format the filename in a time format so that I know which day it represents.

### python vs c

Python has cool oneliner that does this from the **shutil** libary.
```python
            shutil.move(src, target + file_name)
```

In C it's a bit more complicated... Atleast from my limited information.
This is my first program in C so it is very possible there are better ways to do this.
```c

				ptr = fopen(srcFilePath, "r");
				char line[MAX_LINE_LENGTH] = {0};
				if (access(destFilePath, F_OK) == 0){
						return 1;
				}
				else {
						destPtr = fopen(destFilePath, "w+");
				}
				if (!destPtr) {
						printf("file not found and some error occured");
						fclose(destPtr);
						return 1;
				}
				while (fgets(line, MAX_LINE_LENGTH, ptr)) {
					fprintf(destPtr, line);
				}

```
I open the source file and read from it, then write it into the new file at the same time.
Essentially copying it line by line.


