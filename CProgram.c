#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[50];
  char address[50];
  int roll;
  int age;
  int s;
} student;

int main()
{
  FILE *fadd;
  FILE *temp;
  student student1;
  int choice;
  int s;
  while(1)
  {
    student1.s ;
    student1.s = (rand() * 67481 + 22051) % 236180;
    
    printf("\n<---------------------Student Database----------------------->\n");
    printf("\t1) ->Add\n\t2) ->List\n\t3) ->Delete\n\t4) ->Update\n\t5) ->Exit DataBase\n");
    printf("------------> ");
    scanf("%d", &choice);
    if (choice == 5)
    {
      printf("Good Bye ");
      return 0;
    }
    switch (choice)
    {
    case 1:
      fadd = fopen("Student.bin", "ab");

      if (fadd == NULL)
      {
        printf("Error: Cannot open file\n");
        break;
      }
      printf("\nSerial No : %d",student1.s);
      printf("\nName : ");
      scanf(" %s", student1.name);
      printf("Address : ");
      scanf(" %s", student1.address);
      printf("Roll No : ");
      scanf(" %d", &student1.roll);
      printf("Age : ");
      scanf(" %d", &student1.age);
     
      fwrite(&student1, sizeof(student), 1,fadd);
     
      printf("\n<-- Successfully Added Data to the Database -->\n");

      fclose(fadd);
      break;

    case 2:
      fadd = fopen("Student.bin", "rb");
      if (fadd == NULL)
      {
        printf("Error: Cannot open file\n");
        break;
      }
      else
      {
        int ch;
        while ((ch = fread(&student1,sizeof(student1),1,fadd)) != 0)
        {
       printf("Serial No : %d\n", student1.s);
       printf("\t1) Name : %s\n", student1.name);
       printf("\t2) Address : %s\n", student1.address);
       printf("\t3) Roll No : %d\n", student1.roll);
       printf("\t4) Age : %d\n\n", student1.age);
        }
        }
      
      fclose(fadd);
      break;

    case 3:
      fadd = fopen("Student.bin", "rb");
      if (fadd == NULL)
      {
        printf("Error: Cannot open file\n");
        break;
      }
      temp = fopen("Temp_file.bin", "wb");
      int c;
      printf("Enter the Serial Number You Want To Delete : ");
      scanf(" %d", &c);
      
      student buff;
      while (fread(&buff, sizeof(student), 1, fadd) == 1)
      {
        
        
        { 
        if (c != buff.s)
        {
          fwrite(&buff, sizeof(student), 1, temp);
        }
      }
      }
     
      fclose(fadd);
      fclose(temp);
      remove("Student.bin");
      rename("Temp_file.bin", "Student.bin");
      break;

      case 4:
      int d;
      fadd = fopen("Student.bin","rb");
      if(fadd == NULL)
      {
        printf("Error : Cannot Open File\n");
        break;
      }
      temp = fopen("Temp_file.bin","wb");
      printf("Enter The Serial Number You Want To Update : ");
      scanf("%d",&d);
      
      while (fread(&buff, sizeof(student), 1, fadd) == 1)
      {
         if (buff.s == d)
        {
          fwrite(&buff, sizeof(student), 1, temp);
    
          printf("\tEnter The New Name : ");
          scanf("%s",student1.name);
          printf("\tEnter The New Address : ");
          scanf("%s",student1.address);
          printf("\tEnter The New Roll Number : ");
          scanf("%d",&student1.roll);
          printf("\tEnter The New Age : ");
          scanf("%d",&student1.age);
          fwrite(&student1, sizeof(student), 1, temp);
          }
          else
        {
          fwrite(&buff, sizeof(student), 1, temp); // Keep original record
        }
        
        fclose(fadd);
        fclose(temp);
        remove("Student.bin");
        rename("Temp_file.bin", "Student.bin");
        
      }
      break;

    default:
    {
      printf("\n<-- Invalid Input -->\n");
    }
    }
    
}
   return 0;
}


