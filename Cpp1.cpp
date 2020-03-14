#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int EON(char input[]){
	if(input[0]=='w'&&input[1]=='c'&&input[2]=='.'&&input[3]=='e'&&input[4]=='x'&&input[5]=='e')
		return 1;
	else
		return 0;
}

int CC(char file[]){		//字符数统计函数 
	FILE *pf=NULL;
	int i=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败，当前目录无该文件\n");
		return -1;
	}
    char lastchar;
	while((lastchar = fgetc(pf))!=EOF){
        lastchar = fgetc(pf);
		i++;
	}
    fclose(pf);
    return i;
}

int WC(char file[]){		//词数统计函数 
	FILE *pf=NULL;
	int i=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败，当前目录无该文件\n");
		return -1;
	}
    char lastchar;
    lastchar = fgetc(pf);
    while(lastchar!=EOF){
        if(lastchar>='a'&&lastchar<='z'||lastchar>='A'&&lastchar<='Z'||lastchar>='0'&&lastchar<='9'){
        	while(lastchar>='a'&&lastchar<='z'||lastchar>='A'&&lastchar<='Z'||lastchar>='0'&&lastchar<='9'||lastchar=='_'){
        		lastchar=fgetc(pf);
			}
			i++;
			lastchar=fgetc(pf);
		}
		lastchar=fgetc(pf);
	}
	fclose(pf);
    return i;
}

int LC(char file[]){		//行数统计函数 
	FILE *pf=NULL;
	int i=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败，当前目录无该文件\n");
		return -1;
	}
    char lastchar;
    lastchar = fgetc(pf);
    while(lastchar!=EOF){
		if(lastchar=='\n'){
		    i++;
		    lastchar = fgetc(pf);
		}
		else{
		    lastchar = fgetc(pf);
		}
	}
	fclose(pf);
    return i+1;
}


int main(){//主函数 
	int i,j;
	char input[200],File[200];
	printf("程序功能如下：\n");
	printf("	wc.exe -c file.c     //返回文件 file.c 的字符数\n");
	printf("	wc.exe -w file.c    //返回文件 file.c 的词的数目\n");
	printf("	wc.exe -l file.c      //返回文件 file.c 的行数\n");
	while(1){
		printf("请输入：");
		gets(input);
		if(EON(input)==1){
			if(input[6]==' '){
				if(input[7]=='-'){
					if(input[8]=='c'){
						if(input[9]==' '){
							for(i=10,j=0;input[i]!='\0';i++,j++)
								File[j]=input[i];
							for(j;j<200;j++)
								File[j]='\0';
							int cc=0;
							cc=CC(File);
							if(cc==-1)
								continue;
							printf("文件的字符数为：%d\n",cc);
							continue;
						}
					}
					if(input[8]=='w'){
						if(input[9]==' '){
							for(i=10,j=0;input[i]!=NULL;i++,j++)
								File[j]=input[i];
							for(j;j<200;j++)
								File[j]='\0';
							int wc=0;
							wc=WC(File);
							if(wc==-1)
								continue;
							printf("文件的词数为：%d\n",wc);
							continue;
						}
					}	
					if(input[8]=='l'){
						if(input[9]==' '){
							for(i=10,j=0;input[i]!=NULL;i++,j++)
								File[j]=input[i];
							for(j;j<200;j++)
								File[j]='\0';
							int lc=0;
							lc=LC(File);
							if(lc==-1)
								continue;
							printf("文件的行数为：%d\n",lc);
							continue;
						}
					}	
				}
			}
		}
		printf("	输入错误，请重新输入\n");
	}
    system("pause");
	return 0;
}