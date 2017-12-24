#include<stdio.h>

int main(int argc, int *argv[])
{
	char *source_file, *destination_file;
	char ch;

	FILE *fp_src, *fp_des;

	if(argc < 3)
	{
		puts("\n Atleast two arguments are required to copy from one file to another\n");
		return;
	}

	source_file = argv[1];
	destination_file = argv[2];

	fp_src = fopen(source_file, "r");

	if(fp_src == NULL)
	{
		puts("\n Error reading source file \n");
		return;
	}

	fp_des = fopen(destination_file, "a");

	if( fp_des == NULL )
	{
		puts("\n Error reading destination file\n");
		return;
	}

	while(1)
	{
		ch = fgetc(fp_src);
	
		if( ch == EOF )
			break;
		fputc(ch, fp_des);
	}
	fclose(fp_src);
	fclose(fp_des);

	puts("\n File has been copied succesfully\n");
