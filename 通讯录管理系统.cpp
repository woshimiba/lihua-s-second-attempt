#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//设计联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
	};


//设计通讯录结构体
struct Addressbooks {
	//联系人数组
	struct Person personArray[MAX];
	//联系人个数
	int m_Size;

};
//添加联系人
void addPerson(Addressbooks* abs) 
{
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！";
		return;
	}
	else {

		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		cout << "性别:" << endl;
		cout << " 1--男\n 2--女\n";

		//性别
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
				}
			 cout << "输入有误，请重新输入\n";
		}

		//年龄
		cout << "年龄:";
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "电话:";
		string phone="";

		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "住址:";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功 " << endl;
		system("pause");//按任意键继续
		system("cls");//清屏操作
	}
}


void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0)
		cout << "当前记录为空" << endl;
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名:" << abs->personArray[i].m_Name <<"\t";
			cout << "性别:" <<( abs->personArray[i].m_Sex==1?"男":"女") << "\t";
			cout << "年龄:" << abs->personArray[i].m_Age << "\t";
			cout << "电话:" << abs->personArray[i].m_Phone <<"\t";
			cout << "住址:" << abs->personArray[i].m_Addr <<"\n";

		}
	}
	system("pause");
	system("cls");//清屏

}//检测联系人是否存在  
int isExist(Addressbooks * abs,string name ){
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}
//  3 .删除指定联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人 ：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功 " << endl;
	}
	else {
	cout << "查无此人 \n";
}
	system("pause");
	system("cls");
}
// 4.查找指定联系人信息
void findPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人 :" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名:" << abs->personArray[ret].m_Name << "\t";
		cout << "性别:" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs->personArray[ret].m_Age << "\t";
		cout << "电话:" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址:" << abs->personArray[ret].m_Addr << "\n";
	}
	else { cout << "查无此人" << endl; }
	system("pause");
	system("cls");//清屏
}
//5.修改指定联系人信息
void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人 :" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "性别:" << endl;
		cout << "1--男\n2--女\n";

		//性别
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入\n";
		}

		//年龄
		cout << "年龄:";
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "电话:";
		string phone = "";

		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "住址:";
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	}
	else { cout << "查无此人" << endl; }
	system("pause");
	system("cls");//清屏
}
//清空联系人
void claenPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "联系人已清空" << endl;
	system("pause");
	system("cls");//清屏
}

void ShowMenu(void);

int main(){
	Addressbooks abs;
	//初始化人员个数
	abs.m_Size = 0;
	int select = 0;

	while (true) {

		ShowMenu();

		cin >> select;
		switch (select) {
		case 1:	
			addPerson(&abs) ;//添加
			break; 
		case 2:showPerson(&abs);//显示
			break;
		case 3://删除
		/*{cout << "请输入删除联系人的姓名 :  " << endl;
		string name;
		cin >> name;
		if (isExist(&abs, name) == -1)
			cout << "查无此人" << endl;
		else
void deletePerson(Addressbooks* abs) {
			cout << "找到此人" << endl; }*/
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);//查找
			break;
		case 5:
			modifyPerson(&abs);//修改
			break;
		case 6://清空
			claenPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用\n"; 
			system("pause"); return 0;
			break;
		default:
			break;
		}
	}
return 0;
}
void ShowMenu(void) {
	cout <<endl<<"	1.添加联系人\n"<<"	2.显示联系人\n"<<"	3.删除联系人\n"
		 <<"	4.查找联系人\n"<<"	5.修改联系人\n"<<"	6.清空联系人\n"<<"	0.退出通讯录\n\n";
	cout << "请输入您要进行的操作（数字）：";
}
