#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
int main()
{
	FILE *fp1;                               /*����FILE����ָ�����*/ 
	FILE *fp2;
	char password[20]={"1234"};             /*���õ�½����*/ 
	char pass[20],txt[60000],changetxt[60000];
	char point,txtname[20],stxtname[20];
	int N,i;
	printf("������ʹ�����룺\n");          /*��ʾ��������*/ 
	gets(pass) ;                           /*��ȡ�û���������*/ 
	if(strcmp(password,pass))              /*�Ա������Ƿ���ȷ*/ 
	{
		printf("�����������\n");
		exit(0);                          /*�˳�����*/ 
	}
	else
	{
		printf("��ӭʹ�ã�����e���ļ����м���\n����d���ļ����н���\n����0�˳�����\n");/*��ʾʹ�÷���*/ 
		scanf("%c",&point);              /*��ȡ�û�ָ��*/ 
		switch(point)
		{
			case'e':
				printf("��������Ҫ���ܵ��ĵ����ƣ�\n"); 
				scanf("%s",txtname);               /*��ȡ��Ҫ���ܵ��ĵ���*/ 
				if((fp1=fopen(txtname,"r"))==NULL) /*�жϴ��ļ��Ƿ�ʧ��*/ 
				{
					printf("�ļ���ʧ��\n����������˳�����\n");
					getchar();	
					exit(0);                    /*�˳�����*/ 
				}
				fgets(txt,sizeof(txt),fp1);    /*��ȡ�ĵ��ַ�*/ 
				N=sizeof(txt);
				for(i=0;i<N;i++)
				{
				changetxt[i]=txt[i]+i;       /*���ü����ַ�*/ 
				}
				changetxt[i]='\0';            /*�����ַ����������*/ 
				printf("��������Ҫ������ĵ��ĵ�\n");
				scanf("%s",&stxtname);        /* ��ȡ��Ž����ĵ���*/ 
				if((fp2=fopen(stxtname,"w"))==NULL) 
				{
					printf("�ļ�������\n����������˳�����\n");
					getchar();	
					exit(0);
				}
				fputs(changetxt,fp2);        /*��ż����ĵ�*/ 
				fclose(fp1);                /*�ر��ļ�*/ 
				fclose(fp2);
				break;
			case'd':
		    	printf("��������Ҫ���ܵ��ĵ����ƣ�\n");
				scanf("%s",&txtname);
				if((fp1=fopen(txtname,"r"))==NULL) 
				{
					printf("�ļ���ʧ��\n����������˳�����\n");
					getchar();	
					exit(0);
				}
				fgets(txt,sizeof(txt),fp1);
				N=sizeof(txt);
				for(i=0;i<N;i++)
				{
				changetxt[i]=txt[i]-i; 
				}
				changetxt[i]='\0';
				printf("��������Ҫ���ԭ�ĵ��ĵ�\n");
				scanf("%s",&stxtname);
				if((fp2=fopen(stxtname,"w"))==NULL) 
				{
					printf("�ļ�������\n����������˳�����\n");
					getchar();	
					exit(0);
				}
				fputs(changetxt,fp2);
				break;
				fclose(fp1);                /*�ر��ļ�*/ 
				fclose(fp2);
			case '0':                 /*��������*/ 
				break;
			default:
				printf("�������\n"); /*��ʾ�������*/ 
				break;				
		}
	}
	return 0;
 } 

