#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"HYGL.h"

void loginInterface()
{
    int Choice;
	pUser head = NULL;
	head = readFile(head);
	ergodic(head);
	while(1)
	{
		printf("\n\n\n");
		printf("\t\t\t+---------------------------+\n");
		printf("\t\t\t+                           +\n");
		printf("\t\t\t+           1.登录          +\n");
		printf("\t\t\t+                           +\n");
		printf("\t\t\t+        2.管理员注册       +\n");
		printf("\t\t\t+                           +\n");
		printf("\t\t\t+         3.关闭系统        +\n");
		printf("\t\t\t+                           +\n");
		printf("\t\t\t+---------------------------+\n");
		fflush(stdin);
		scanf("%d",&Choice);
		switch (Choice)
		{
		case 1:
			loginChoice(head);
			break;
		case 2:
			head = build(head,1);
			break;
		case 3:
			if (head != NULL)
			{
				writeFile(head);
			}
			exit(0);
		default:
			printf("\t\t您的输入有误");
			break;
		}
	}
}

pUser loginChoice(pUser head)
{
	int i;
	int inputNum;
	char iputPassworld[7];
	pUser p = NULL;
	printf("\t\t请输入管理员或会员编号：");
	fflush(stdin);
	scanf("%d",&inputNum);
	if ((p = findByNum(head,inputNum)) == NULL)
	{
		printf("\t\t该编号不存在,");
		///system("pause");
		return 0;
	}
	printf("\t\t请输入管理员或会员密码：");
	for (i = 0; i < 3; i++)
	{
		scanf("%s",iputPassworld);
		if(strcmp(iputPassworld,p ->passworld) == 0)
		{
			if (p ->flag == 1)
			{
				head = Administrators(p);
			}
			else
			{
				userInterface(p);
			}
			break;
		}
		else
		{
			printf("\t\t密码错误，重新输入\n");
		}
	}
	return head;
}

pUser Administrators(pUser head)
{
	char Choice;
	while (1)
	{
		printf("\t\t");
		printf("\t\t\t\t当前为管理员模式\n");
		printf("\n\n\n");
		printf("\t\t\t+------------------------------+\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          1.注册用户          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          2.查找用户          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          3.遍历全部          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          4.修改用户          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          5.删除用户          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          6.退出登录          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+------------------------------+\n");
		fflush(stdin);
		scanf("%c",&Choice);
		switch (Choice)
		{
		case '1':
			head = build(head,0);
			break;
		case '2':
			findInterface(head);
			break;
		case '3':
			ergodic(head);
			break;
		case '4':
			modifyInterface(head);
			break;
		case '5':
			deleteInterface(head);
			break;
		case '6':
			return head;
		default:
			printf("\t\t输入有误，请重试\n");
			break;
		}
	}
}

void findInterface(pUser head)
{
	char Choice;
	int Number,l;
	char Name[25];
	pUser pNode;
	printf("\t\t请选择查找方式\n");
	while (1)
	{
		printf("\t\t\t+------------------------------+\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+        1.按编号查找          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+        2.按姓名查找          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+------------------------------+\n");
		fflush(stdin);
		scanf("%c",&Choice);
		switch (Choice)
		{
		case '1':
			printf("\t\t\t请输入查找的编号:");
			fflush(stdin);
			scanf("%d",&Number);
			pNode = findByNum(head,Number);
			break;
		case '2':
			printf("\t\t\t请输入查找的姓名：");
			fflush(stdin);
			scanf("%s",Name);
			pNode = findByName(head,Name);
			break;
		default:
			printf("\t\t\t选择有误，重新选择");
			break;
		}
		if (pNode == NULL || pNode ->flag == 1)
		{
			printf("\t\t\t查找结果为空\n");
		}
		else
		{
			printf("|  编号  |	姓名 |	性别  |	 电话  |   积分  |  等级  |\n");
			view(pNode);
		}
		printf("\t\t\t若继续查询请按1，否则请按任意键退出\n");
		getchar();
		if (getchar() != '1')
		{
			break;
		}
	}
}

pUser build(User *head,int Flag)
{
	pUser p = NULL;
	pUser q = NULL;
	char Sex;
	while (1)
	{
		p = (pUser)malloc(sizeof(User));
		p ->flag = Flag;
		printf("\t\t\t请输入姓名：");
		fflush(stdin);
		scanf("%s",p->name);
		while (1)
		{
			printf("\t\t\t请输入性别(男：m，女：w):");
			getchar();
			Sex = getchar();
			if (Sex == 'm'||Sex == 'w')
			{
				Sex == 'm'?strcpy(p ->sex,"男"):strcpy(p ->sex,"女");
				break;
			}
			else
			{
				printf("\t\t\t输入不合法，重新输入\n");
			}
		}
		printf("\t\t\t请输入手机号码：");
		fflush(stdin);
		scanf("%s",p ->phone);
		while (1)
		{
			printf("\t\t\t请输入六位密码:");
			scanf("%s",p ->passworld);
			if (strlen(p ->passworld) == 6)
			{
				break;
			}
		}

		p ->num = ++Num;
		p ->grade = 0;
		p ->integral = 0;
		p ->moeny = 0;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q = head;
			while (q ->next != NULL)
			{
				q = q ->next;
			}
			q ->next = p;
		}
		p ->next = NULL;
		printf("|   编号   |	姓名  |	 性别  |  电话  |   积分  |  等级  |\n");
		view(p);
		printf("\t\t\t若您需要继续注册请按1，退出请按任意键\n");
		getchar();
		if (getchar() != '1')
		{
			return head;
		}
	}
}

void ergodic(pUser head)
{
	pUser p = head;
	while (p != NULL)
	{
		if (p ->flag != 1)
		{
			printf("|   编号   |	姓名  |	 性别  |  电话  |   积分  |  等级  |\n");
			view(p);
		}
		p = p ->next;
	}
}

pUser findByName(pUser head,char Name[12])
{
	pUser p = head;
	while (p != NULL)
	{
		if (strcmp(p ->name,Name) == 0 && p ->flag != 1)
		{
			return p;
		}
		p = p ->next;
	}
	return NULL;
}

pUser findByNum(pUser head,int number)
{
	pUser p = head;
	while (p != NULL)
	{
		if (number == p ->num)
		{
			return p;
		}
		p = p ->next;
	}
	return NULL;
}

pUser modifyInterface(pUser head)
{
	int Number;
	pUser pNode = NULL;
	char Choice;
	printf("\t\t\t请输入用户编号进行修改功能：");
	fflush(stdin);
	scanf("%d",&Number);
	if ((pNode = findByNum(head,Number)) != NULL && pNode ->flag != 1)
	{
		while (1)
		{
			printf("\t\t\t+------------------------------+\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           1.修改姓名         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           2.修改密码         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           3.修改手机         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           4.修改性别         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           5.退出修改         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+------------------------------+\n");
			fflush(stdin);
			scanf("%c",&Choice);
			switch (Choice)
			{
			case '1':
				printf("\t\t\t请输入新的用户姓名：");
				scanf("%s",pNode ->name);
				break;
			case '2':
				printf("\t\t\t\t请输入新的用户密码：");
				scanf("%s",pNode ->passworld);
				break;
			case '3':
				printf("\t\t\t请输入新的手机号码：");
				scanf("%s",pNode ->phone);
				break;
			case '4':
				printf("\t\t\t请输入修改后的用户性别：");
				scanf("%s",pNode ->sex);
				break;
			case '5':
				return head;
			default:
				break;
			}
			system("cls");
		}
	}
	else
	{
		printf("\t\t\t未发现该用户信息，无法修改\n");
	}
	return head;
}

pUser deleteInterface(pUser head)
{
	int Number;
	pUser pNode = NULL;
	pUser qNode = NULL;
	printf("\t\t\t请输入您要删除用户的编号:");
	fflush(stdin);
	scanf("%d",&Number);
	pNode = findByNum(head,Number);
	if (pNode == NULL)
	{
		printf("\t\t\t未发现该用户，无法删除\n");
		return head;
	}
	if (head == pNode)
	{
		head = pNode ->next;
	}
	else
	{
		qNode = head;
		while (qNode ->next != pNode)
		{
			qNode = qNode ->next;
		}
		qNode ->next = pNode ->next;
	}
	free(pNode);
	return head;
}
void userInterface(pUser pNode)
{
	char Choice;
	float Moeny;
	pNode ->integral += 1;
	while (1)
	{
		printf("\t\t\t+-------------------------------+\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         1.查看个人信息        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         2.个人每日签到        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         3.添加消费记录        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         4.退出账号登录        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+-------------------------------+\n");
		fflush(stdin);
		scanf("%c",&Choice);
		switch (Choice)
		{
		case '1':
			printf("|   编号   |	姓名  |	 性别  |  电话  |   积分  |  等级  |\n");
			view(pNode);
			break;
		case '2':
			pNode ->integral += 1;
			printf("\t\t签到成功，积分加一\n");
			break;
		case '3':
			printf("\t\t请输入您的消费金额,将会为您转变为积分：");
			scanf("%f",&Moeny);
			pNode ->moeny +=Moeny;
			Moeny = pNode ->moeny;
			pNode ->integral += Moeny/10;
			break;
		case '4':
			return;
		default:
			printf("操作有误，请重试\n");
			break;
		}
	}
}
void view(pUser p)
{
	p ->grade = p ->integral/10;
	printf("|%10d|%10s|%6s|%13s|%6d|%10d|\n",p ->num,p->name,p->sex,p->phone,p->integral,p->grade);
}

void writeFile(pUser head)
{
	pUser pNode = head;
	FILE *fp;
	if ((fp = fopen("number.txt","wb")) == NULL);
	while (pNode != NULL)
	{
		fprintf(fp,"%d %d %s %s %s %d %s %d %.2f\n",pNode ->flag,pNode ->num,pNode ->name,pNode ->sex,pNode ->phone,pNode->grade,pNode->passworld,pNode->integral,pNode->moeny);
		pNode = pNode ->next;
	}
	fclose(fp);
}

pUser readFile(pUser head)
{
	FILE *fp;
	pUser pNode = NULL;
	pUser qNode = NULL;
	if ((fp = fopen("number.txt","r")) == NULL)
	{
		return NULL;
	}
	else
	{
		while (1)
		{
			pNode = (pUser)malloc(sizeof(User));
			fscanf(fp,"%d %d %s %s %s %d %s %d %f\n",&pNode ->flag,&pNode ->num,pNode ->name,pNode ->sex,pNode ->phone,&pNode->grade,pNode->passworld,&pNode->integral,&pNode->moeny);
			if (head == NULL)
			{
				head = pNode;
			}
			else
			{
				qNode = head;
				while (qNode ->next != NULL)
				{
					qNode = qNode ->next;
				}
				qNode ->next = pNode;
			}
			pNode ->next = NULL;
			Num++;
			if (feof(fp))
			{
				break;
			}
		}
		fclose(fp);
	}
	return head;
}
