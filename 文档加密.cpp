#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
int main()
{
	FILE *fp1;                               /*定义FILE类型指针变量*/ 
	FILE *fp2;
	char password[20]={"1234"};             /*设置登陆密码*/ 
	char pass[20],txt[60000],changetxt[60000];
	char point,txtname[20],stxtname[20];
	int N,i;
	printf("请输入使用密码：\n");          /*提示输入密码*/ 
	gets(pass) ;                           /*获取用户输入密码*/ 
	if(strcmp(password,pass))              /*对比密码是否正确*/ 
	{
		printf("密码输入错误！\n");
		exit(0);                          /*退出程序*/ 
	}
	else
	{
		printf("欢迎使用！输入e对文件进行加密\n输入d对文件进行解密\n输入0退出程序\n");/*提示使用方法*/ 
		scanf("%c",&point);              /*获取用户指令*/ 
		switch(point)
		{
			case'e':
				printf("请输入想要加密的文档名称：\n"); 
				scanf("%s",txtname);               /*获取需要加密的文档名*/ 
				if((fp1=fopen(txtname,"r"))==NULL) /*判断打开文件是否失败*/ 
				{
					printf("文件打开失败\n输入任意键退出程序\n");
					getchar();	
					exit(0);                    /*退出程序*/ 
				}
				fgets(txt,sizeof(txt),fp1);    /*获取文档字符*/ 
				N=sizeof(txt);
				for(i=0;i<N;i++)
				{
				changetxt[i]=txt[i]+i;       /*设置加密字符*/ 
				}
				changetxt[i]='\0';            /*设置字符串结束标记*/ 
				printf("请输入想要存放密文的文档\n");
				scanf("%s",&stxtname);        /* 获取存放解密文档名*/ 
				if((fp2=fopen(stxtname,"w"))==NULL) 
				{
					printf("文件不存在\n输入任意键退出程序\n");
					getchar();	
					exit(0);
				}
				fputs(changetxt,fp2);        /*存放加密文档*/ 
				fclose(fp1);                /*关闭文件*/ 
				fclose(fp2);
				break;
			case'd':
		    	printf("请输入想要解密的文档名称：\n");
				scanf("%s",&txtname);
				if((fp1=fopen(txtname,"r"))==NULL) 
				{
					printf("文件打开失败\n输入任意键退出程序\n");
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
				printf("请输入想要存放原文的文档\n");
				scanf("%s",&stxtname);
				if((fp2=fopen(stxtname,"w"))==NULL) 
				{
					printf("文件不存在\n输入任意键退出程序\n");
					getchar();	
					exit(0);
				}
				fputs(changetxt,fp2);
				break;
				fclose(fp1);                /*关闭文件*/ 
				fclose(fp2);
			case '0':                 /*结束程序*/ 
				break;
			default:
				printf("输入错误\n"); /*提示输入错误*/ 
				break;				
		}
	}
	return 0;
 } 

