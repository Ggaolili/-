#ifndef HYGL_H_INCLUDED
#define HYGL_H_INCLUDED
typedef struct User
{
 //��š��������Ա��ֻ����롢�ȼ������֡�
 int flag;//�жϵ�¼�û�Ϊ����Ա������ͨ�û�
 int num;//�û����
 char name[25];//����
 char sex[7];//�Ա�
 char phone[14];//�ֻ�����
 int grade;//�û��ȼ�
 char passworld[7];
 int integral;//����
 float moeny;
 struct User *next;
}User,*pUser;
int Num;
//��¼����
void loginInterface();
//��¼�ж�
pUser loginChoice(pUser);
//����Ա����
pUser Administrators(pUser);
//�����Ա��Ϣ������Ա��
void userInterface(pUser);
pUser build(pUser,int);
//���������Ա�����Ϣ
void ergodic(pUser);
//�ڻ�Ա���в���ĳ���˲�������������������Ϣ
void findInterface(pUser);
pUser findByName(pUser,char *);
pUser findByNum(pUser,int);
pUser deleteInterface(pUser);
pUser modifyInterface(pUser);
void view(pUser);
void writeFile(pUser);
pUser readFile(pUser);



#endif // HYGL_H_INCLUDED
