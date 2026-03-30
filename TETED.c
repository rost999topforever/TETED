#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void){
char com[2500];
char text[99999];
char name[999];
int sys=0;
int num;
printf("TETED by rost999topforever\n");
while (1) {
printf("t(%d)}>>",time(NULL));
fgets(com,sizeof(com),stdin);
com[strcspn(com,"\n")]=0;
if((strcmp(com,"write")==0||strcmp(com,"add")==0)&&sys!=-1){
printf("name}>>");
fgets(name,sizeof(name),stdin);
name[strcspn(name,"\n")]=0;
FILE *f=fopen(name,"a+");
if(f!=NULL){
printf("text}>>");
fgets(text,sizeof(text),stdin);
text[strcspn(text,"\n")]=0;
fprintf(f,"%s",text);
fclose(f);
}
}
else if((strcmp(com,"rewrite")==0)&&sys!=-1){
printf("name}>>");
fgets(name,sizeof(name),stdin);
name[strcspn(name,"\n")]=0;
FILE *f=fopen(name,"w+");
if(f!=NULL){
printf("text}>>");
fgets(text,sizeof(text),stdin);
text[strcspn(text,"\n")]=0;
fprintf(f,"%s",text);
fclose(f);
}
}
else if((strcmp(com,"read")==0||strcmp(com,"cat")==0)&&sys!=-1){
printf("name}>>");
fgets(name,sizeof(name),stdin);
name[strcspn(name,"\n")]=0;
FILE *f=fopen(name,"r");
if(f!=NULL){
while (fgets(text,sizeof(text),f)){
printf("%s\n",text);
}
fclose(f);
}
}
else if(((strcmp(com,"exit")==0)||(strcmp(com,"q")==0)||strcmp(com,"esc")==0)&&sys!=-1){
exit(0);
}
else if((strcmp(com,"delete_text")==0||strcmp(com,"no_text")==0||strcmp(com,"clear")==0)&&sys!=-1){
printf("name}>>");
fgets(name,sizeof(name),stdin);
name[strcspn(name,"\n")]=0;
FILE *f=fopen(name,"w+");
if(f!=NULL){
fclose(f);
}
}
else if((strcmp(com,"_rm")==0||strcmp(com,"remove")==0)&&sys!=-1){
if (sys>=1){
printf("name}>>");
fgets(name,sizeof(name),stdin);
name[strcspn(name,"\n")]=0;
remove(name);
}
}
else if(strcmp(com,"sys_on")==0){
sys=1;
}
else if(strcmp(com,"sys_off")==0){
sys=0;
}
else if(strcmp(com,"no_shell_sys")==0||strcmp(com,"sys_mode")==0){
sys=2;
}
else if(strcmp(com,"sys_shell")==0||strcmp(com,"sys_sh")==0){
sys=-1;
}
else {
if(sys==1||sys==-1){
system(com);
}
else {
printf("ERR !!\n");
}
}
}
}