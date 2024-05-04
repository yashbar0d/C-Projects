#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
int rollNumber;
char name[36];
char gender;
};
void printLine(char g,int size)
{
int i;
for(i=1;i<=size;i++)printf("%c",g);
printf("\n");
}
void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayListOfStudents();
int main()
{
int ch;
while(1)
{
printf("1. Add student\n");
printf("2. Edit student\n");
printf("3. Delete student\n");
printf("4. Search student\n");
printf("5. Display list of students\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addStudent();
else if(ch==2) editStudent();
else if(ch==3) deleteStudent();
else if(ch==4) searchStudent();
else if(ch==5) displayListOfStudents();
else if(ch==6) break;
else printf("Invalid choice\n");
}
return 0;
}
void addStudent()
{
FILE *f;
struct Student t,g;
int rollNumber;
char name[37];
char gender;
char m;
printf("Student (Add Module)\n");
printf("Enter roll number: ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("student.data","rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==t.rollNumber)
{
printf("That roll number has been alloted to %s\n",t.name);
fclose(f);
return;
}
}
fclose(f);
}
printf("Enter name: ");
fgets(name,37,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter gender(M/F): ");
gender=getchar();
fflush(stdin);
if(gender!='M' && gender!='m' && gender!='F' && gender!='f')
{
printf("Invalid gender\n");
return;
}
printf("Save(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not added\n");
return;
}
g.rollNumber=rollNumber;
strcpy(g.name,name);
g.gender=gender;
f=fopen("student.data","ab");
fwrite(&g,sizeof(struct Student),1,f);
fclose(f);
printf("Student added,press enter to continue...........");
getchar();
fflush(stdin);
}
void editStudent()
{
FILE *f1,*f2;
int found;
struct Student g,t;
int rollNumber;
char name[37];
char gender;
char m;
printf("Student (Edit Module)\n");
printf("Enter roll number of the student to edit: ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
f1=fopen("student.data","rb");
if(f1==NULL)
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollNumber==t.rollNumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name: %s\n",t.name);
if(t.gender=='m' || t.gender=='M')
{
printf("Gender: Male\n");
}
else
{
printf("Gender: Female\n");
}
printf("Edit(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student not updated\n");
return;
}
printf("Enter name: ");
fgets(name,37,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter gender(M/F): ");
gender=getchar();
fflush(stdin);
if(gender!='m' && gender!='M' && gender!='F' && gender!='F')
{
printf("Invalid gender\n");
return;
}
printf("Update(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not updated\n");
return;
}
g.rollNumber=rollNumber;
strcpy(g.name,name);
g.gender=gender;
f1=fopen("student.data","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollNumber!=t.rollNumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
else
{
fwrite(&g,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("student.data","wb");
f2=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Student),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
printf("student updated,press enter to continue...........");
getchar();
fflush(stdin);
}
void deleteStudent()
{
FILE *f1,*f2;
int found;
struct Student t;
int rollNumber;
char m;
printf("Student (Delete Module)\n");
printf("Enter roll number of the student to delete: ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
f1=fopen("student.data","rb");
if(f1==NULL)
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollNumber==t.rollNumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name: %s\n",t.name);
if(t.gender=='m' || t.gender=='M')
{
printf("Gender: Male\n");
}
else
{
printf("Gender: Female\n");
}
printf("Delete(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not deleted\n");
return;
}
f1=fopen("student.data","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollNumber!=t.rollNumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("student.data","wb");
f2=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Student),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);               
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
printf("Student deleted,press enter to continue..........");
getchar();
fflush(stdin);
}
void searchStudent()
{
FILE *f;
struct Student t;
int rollNumber;
int found;
printf("Student (Search Module)\n");
printf("Enter roll number: ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("student.data","rb");
if(f==NULL)
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==t.rollNumber)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name: %s\n",t.name);
if(t.gender=='M' || t.gender=='m')
{
printf("Gender: Male\n");
}
else
{
printf("Gender: Female\n");
}
printf("Press enter to continue.........");
getchar();
fflush(stdin);
}
void displayListOfStudents()
{
FILE *f;
int newPage,pageSize;
int Sno;
struct Student t;
f=fopen("student.data","rb");
if(f==NULL)
{
printf("Student(List Module)\n");
printLine('-',70);
printf("%10s %-12s %-35s %s\n","S.No.","Roll number","Name","Gender");
printLine('-',70);
printf("Press enter to continue..........");
getchar();
fflush(stdin);
return;
}
newPage=1;
pageSize=5;
Sno=0;
while(1)
{
if(newPage==1)
{
printf("Student(List Module)\n");
printLine('-',70);
printf("%10s %-12s %-35s     %s\n","S.No.","Roll number","Name","Gender");
printLine('-',70);
newPage=0;
}
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
Sno++;
if(t.gender=='M' || t.gender=='m')
{
printf("%7d  %9d      %-40s%-6s\n",Sno,t.rollNumber,t.name,"Male");
}
else
{
printf("%7d  %9d      %-40s%-6s\n",Sno,t.rollNumber,t.name,"Female");
}
if(Sno%pageSize==0)
{
printLine('-',70);
printf("Press enter to continue..........");
getchar();
fflush(stdin);
newPage=1;
}
}
if(Sno==0)
{
printf("     No students added\n");
printLine('-',70);
printf("press enter to continue.........");
getchar();
fflush(stdin);
}
if(Sno%pageSize!=0)
{
printLine('-',70);
printf("Press enter to continue...........");
getchar();
fflush(stdin);
}
fclose(f);
}