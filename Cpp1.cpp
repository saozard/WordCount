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

int CC(char file[]){		//�ַ���ͳ�ƺ��� 
	FILE *pf=NULL;
	int i=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ�ܣ���ǰĿ¼�޸��ļ�\n");
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

int WC(char file[]){		//����ͳ�ƺ��� 
	FILE *pf=NULL;
	int i=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ�ܣ���ǰĿ¼�޸��ļ�\n");
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

int LC(char file[]){		//����ͳ�ƺ��� 
	FILE *pf=NULL;
	int i=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ�ܣ���ǰĿ¼�޸��ļ�\n");
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


int main(){//������ 
	int i,j;
	char input[200],File[200];
	printf("���������£�\n");
	printf("	wc.exe -c file.c     //�����ļ� file.c ���ַ���\n");
	printf("	wc.exe -w file.c    //�����ļ� file.c �Ĵʵ���Ŀ\n");
	printf("	wc.exe -l file.c      //�����ļ� file.c ������\n");
	while(1){
		printf("�����룺");
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
							printf("�ļ����ַ���Ϊ��%d\n",cc);
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
							printf("�ļ��Ĵ���Ϊ��%d\n",wc);
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
							printf("�ļ�������Ϊ��%d\n",lc);
							continue;
						}
					}	
				}
			}
		}
		printf("	�����������������\n");
	}
    system("pause");
	return 0;
}