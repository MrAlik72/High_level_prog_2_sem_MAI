#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
	char name[255];
	uint8_t age, gender;

} data;

long int filesize( FILE *file) 
{ 
long int size_of_file; 
fseek(file, 0, SEEK_END);  
size_of_file = ftell(file); 
fseek(file, 0, SEEK_SET); 
return(size_of_file); 
}

void show(int j, int counts, data *st)
{
	printf("Surname        Age   Gedner\n");
	for(j=0;j<counts;j++)
	{
		char gen[6];
		if (st[j].gender == 1) strcpy(gen, " Man ");
		if (st[j].gender == 0) strcpy(gen, "Woman");
		printf("%-14s %-5hhu %s\n",st[j].name, st[j].age, gen);
	}
	printf("\n");
}

int main()
{
	system("clear");
	int i, j, g;
	while(1)
	{
		printf("1) Add students\n2) Remove student\n3) Show all students\n4) Sort\n0) Exit\n");
		scanf("%d", &i);
		if(i == 0) break;
		data student;

		if(i == 1)
		{	
			while(1)
			{

				FILE* file = fopen("base.csv", "a+");
				printf("Write second name, age and gender(1 for Man, 0 for Woman) of student\n");
				scanf("%s%hhu%hhu", student.name, &student.age, &student.gender);
				fwrite(&student, sizeof(student), 1, file);
				fclose(file);

				printf("1) Continue 0)Back\n");
				scanf("%d", &i);
				if (i == 0) break;
			}
		}

		if(i == 2)
		{
			char delete[255];
			printf("What student do u want delete\n");
			scanf("%s", delete);
			FILE* file = fopen("base.csv", "a+");
			int counts = filesize(file)/sizeof(student);
			data *st = (data*)malloc(counts*sizeof(student));
			fread(st, sizeof(student), counts, file);
			for (j = 0; j < counts; j++)
			{
				if (strncmp(st[j].name, delete, strlen(delete)) == 0)
					break;

			}	

			for (; j < counts-1; j++) 
			{	
				st[j] = st[j+1];
			}

			fclose(file);
			file = fopen("base.csv", "w+");
			fwrite(st, sizeof(student), counts-1, file);
			fclose(file);
			free(st);
		}

		if(i == 3)
		{	
			FILE* file = fopen("base.csv", "a+");
			int counts = filesize(file)/sizeof(student);
			data *st = (data*)malloc(counts*sizeof(student));
			fread(st, sizeof(student), counts, file);
			fclose(file);
			char gen[6];
			show(j, counts,st);
			free(st);
		}

		if (i == 4)
		{
			printf("1) Alphabetically\n2) Ascending ages\n3) Descending ages\n4) By gender\n0) Exit\n");
			scanf("%d",&i);
			FILE* file = fopen("base.csv", "r");
			int counts = filesize(file)/sizeof(student);
			data *st = (data*)malloc(counts*sizeof(student));
			fread(st, sizeof(student), counts, file);
			fclose(file);
			data Sort;

			if (i == 1)
			{
				for (j = counts - 1; j > 0; j --)
					for (g = 0; g < j; g ++)
						if (strncmp(st[g].name, st[g + 1].name, 1) > 0)
						{
							Sort = st[g];
							st[g] = st[g + 1];
							st[g + 1] = Sort;
						}
						
				char gen[6];
				show(j, counts,st);
				free(st);
			}  
			
			if (i == 2)
			{
				for (j = counts - 1; j > 0; j --)
					for (g = 0; g < j; g ++)
						if (st[g].age > st[g+1].age)
						{
							Sort = st[g];
							st[g] = st[g + 1];
							st[g + 1] = Sort;
						}
						
				char gen[6];
				show(j, counts,st);
				free(st);

			}

			if (i == 3)
			{
				for (j = counts - 1; j > 0; j --)
					for (g = 0; g < j; g ++)
						if (st[g].age < st[g+1].age)
						{
							Sort = st[g];
							st[g] = st[g + 1];
							st[g + 1] = Sort;
						}
						
				char gen[6];
				show(j, counts,st);
				free(st);

			}

			if(i == 4)
			{
				for (j = counts - 1; j > 0; j --)
					for (g = 0; g < j; g ++)
						if (st[g].gender < st[g+1].gender)
						{
							Sort = st[g];
							st[g] = st[g + 1];
							st[g + 1] = Sort;
						}
						
				char gen[6];
				show(j, counts,st);
				free(st);
			}
		}
	}	
}