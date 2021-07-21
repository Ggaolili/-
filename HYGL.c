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
		printf("\t\t\t+           1.��¼          +\n");
		printf("\t\t\t+                           +\n");
		printf("\t\t\t+        2.����Աע��       +\n");
		printf("\t\t\t+                           +\n");
		printf("\t\t\t+         3.�ر�ϵͳ        +\n");
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
			printf("\t\t������������");
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
	printf("\t\t���������Ա���Ա��ţ�");
	fflush(stdin);
	scanf("%d",&inputNum);
	if ((p = findByNum(head,inputNum)) == NULL)
	{
		printf("\t\t�ñ�Ų�����,");
		///system("pause");
		return 0;
	}
	printf("\t\t���������Ա���Ա���룺");
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
			printf("\t\t���������������\n");
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
		printf("\t\t\t\t��ǰΪ����Աģʽ\n");
		printf("\n\n\n");
		printf("\t\t\t+------------------------------+\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          1.ע���û�          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          2.�����û�          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          3.����ȫ��          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          4.�޸��û�          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          5.ɾ���û�          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+          6.�˳���¼          +\n");
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
			printf("\t\t��������������\n");
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
	printf("\t\t��ѡ����ҷ�ʽ\n");
	while (1)
	{
		printf("\t\t\t+------------------------------+\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+        1.����Ų���          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+        2.����������          +\n");
		printf("\t\t\t+                              +\n");
		printf("\t\t\t+------------------------------+\n");
		fflush(stdin);
		scanf("%c",&Choice);
		switch (Choice)
		{
		case '1':
			printf("\t\t\t��������ҵı��:");
			fflush(stdin);
			scanf("%d",&Number);
			pNode = findByNum(head,Number);
			break;
		case '2':
			printf("\t\t\t��������ҵ�������");
			fflush(stdin);
			scanf("%s",Name);
			pNode = findByName(head,Name);
			break;
		default:
			printf("\t\t\tѡ����������ѡ��");
			break;
		}
		if (pNode == NULL || pNode ->flag == 1)
		{
			printf("\t\t\t���ҽ��Ϊ��\n");
		}
		else
		{
			printf("|  ���  |	���� |	�Ա�  |	 �绰  |   ����  |  �ȼ�  |\n");
			view(pNode);
		}
		printf("\t\t\t��������ѯ�밴1�������밴������˳�\n");
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
		printf("\t\t\t������������");
		fflush(stdin);
		scanf("%s",p->name);
		while (1)
		{
			printf("\t\t\t�������Ա�(�У�m��Ů��w):");
			getchar();
			Sex = getchar();
			if (Sex == 'm'||Sex == 'w')
			{
				Sex == 'm'?strcpy(p ->sex,"��"):strcpy(p ->sex,"Ů");
				break;
			}
			else
			{
				printf("\t\t\t���벻�Ϸ�����������\n");
			}
		}
		printf("\t\t\t�������ֻ����룺");
		fflush(stdin);
		scanf("%s",p ->phone);
		while (1)
		{
			printf("\t\t\t��������λ����:");
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
		printf("|   ���   |	����  |	 �Ա�  |  �绰  |   ����  |  �ȼ�  |\n");
		view(p);
		printf("\t\t\t������Ҫ����ע���밴1���˳��밴�����\n");
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
			printf("|   ���   |	����  |	 �Ա�  |  �绰  |   ����  |  �ȼ�  |\n");
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
	printf("\t\t\t�������û���Ž����޸Ĺ��ܣ�");
	fflush(stdin);
	scanf("%d",&Number);
	if ((pNode = findByNum(head,Number)) != NULL && pNode ->flag != 1)
	{
		while (1)
		{
			printf("\t\t\t+------------------------------+\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           1.�޸�����         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           2.�޸�����         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           3.�޸��ֻ�         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           4.�޸��Ա�         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+           5.�˳��޸�         +\n");
			printf("\t\t\t+                              +\n");
			printf("\t\t\t+------------------------------+\n");
			fflush(stdin);
			scanf("%c",&Choice);
			switch (Choice)
			{
			case '1':
				printf("\t\t\t�������µ��û�������");
				scanf("%s",pNode ->name);
				break;
			case '2':
				printf("\t\t\t\t�������µ��û����룺");
				scanf("%s",pNode ->passworld);
				break;
			case '3':
				printf("\t\t\t�������µ��ֻ����룺");
				scanf("%s",pNode ->phone);
				break;
			case '4':
				printf("\t\t\t�������޸ĺ���û��Ա�");
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
		printf("\t\t\tδ���ָ��û���Ϣ���޷��޸�\n");
	}
	return head;
}

pUser deleteInterface(pUser head)
{
	int Number;
	pUser pNode = NULL;
	pUser qNode = NULL;
	printf("\t\t\t��������Ҫɾ���û��ı��:");
	fflush(stdin);
	scanf("%d",&Number);
	pNode = findByNum(head,Number);
	if (pNode == NULL)
	{
		printf("\t\t\tδ���ָ��û����޷�ɾ��\n");
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
		printf("\t\t\t+         1.�鿴������Ϣ        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         2.����ÿ��ǩ��        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         3.������Ѽ�¼        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+         4.�˳��˺ŵ�¼        +\n");
		printf("\t\t\t+                               +\n");
		printf("\t\t\t+-------------------------------+\n");
		fflush(stdin);
		scanf("%c",&Choice);
		switch (Choice)
		{
		case '1':
			printf("|   ���   |	����  |	 �Ա�  |  �绰  |   ����  |  �ȼ�  |\n");
			view(pNode);
			break;
		case '2':
			pNode ->integral += 1;
			printf("\t\tǩ���ɹ������ּ�һ\n");
			break;
		case '3':
			printf("\t\t�������������ѽ��,����Ϊ��ת��Ϊ���֣�");
			scanf("%f",&Moeny);
			pNode ->moeny +=Moeny;
			Moeny = pNode ->moeny;
			pNode ->integral += Moeny/10;
			break;
		case '4':
			return;
		default:
			printf("��������������\n");
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
