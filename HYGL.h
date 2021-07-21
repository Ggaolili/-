#ifndef HYGL_H_INCLUDED
#define HYGL_H_INCLUDED
typedef struct User
{
 //编号、姓名、性别、手机号码、等级、积分。
 int flag;//判断登录用户为管理员还是普通用户
 int num;//用户编号
 char name[25];//姓名
 char sex[7];//性别
 char phone[14];//手机号码
 int grade;//用户等级
 char passworld[7];
 int integral;//积分
 float moeny;
 struct User *next;
}User,*pUser;
int Num;
//登录界面
void loginInterface();
//登录判断
pUser loginChoice(pUser);
//管理员界面
pUser Administrators(pUser);
//输入会员信息建立会员表
void userInterface(pUser);
pUser build(pUser,int);
//输出整个会员表的信息
void ergodic(pUser);
//在会员表中查找某个人并输出他（她）的相关信息
void findInterface(pUser);
pUser findByName(pUser,char *);
pUser findByNum(pUser,int);
pUser deleteInterface(pUser);
pUser modifyInterface(pUser);
void view(pUser);
void writeFile(pUser);
pUser readFile(pUser);



#endif // HYGL_H_INCLUDED
