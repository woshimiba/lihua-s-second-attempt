#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
	};


//���ͨѶ¼�ṹ��
struct Addressbooks {
	//��ϵ������
	struct Person personArray[MAX];
	//��ϵ�˸���
	int m_Size;

};
//�����ϵ��
void addPerson(Addressbooks* abs) 
{
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�";
		return;
	}
	else {

		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		cout << "�Ա�:" << endl;
		cout << " 1--��\n 2--Ů\n";

		//�Ա�
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
				}
			 cout << "������������������\n";
		}

		//����
		cout << "����:";
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "�绰:";
		string phone="";

		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "סַ:";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ� " << endl;
		system("pause");//�����������
		system("cls");//��������
	}
}


void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "����:" << abs->personArray[i].m_Name <<"\t";
			cout << "�Ա�:" <<( abs->personArray[i].m_Sex==1?"��":"Ů") << "\t";
			cout << "����:" << abs->personArray[i].m_Age << "\t";
			cout << "�绰:" << abs->personArray[i].m_Phone <<"\t";
			cout << "סַ:" << abs->personArray[i].m_Addr <<"\n";

		}
	}
	system("pause");
	system("cls");//����

}//�����ϵ���Ƿ����  
int isExist(Addressbooks * abs,string name ){
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}
//  3 .ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ�� ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ� " << endl;
	}
	else {
	cout << "���޴��� \n";
}
	system("pause");
	system("cls");
}
// 4.����ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ�� :" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "����:" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�:" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����:" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰:" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ:" << abs->personArray[ret].m_Addr << "\n";
	}
	else { cout << "���޴���" << endl; }
	system("pause");
	system("cls");//����
}
//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�� :" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�Ա�:" << endl;
		cout << "1--��\n2--Ů\n";

		//�Ա�
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������\n";
		}

		//����
		cout << "����:";
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "�绰:";
		string phone = "";

		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "סַ:";
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	}
	else { cout << "���޴���" << endl; }
	system("pause");
	system("cls");//����
}
//�����ϵ��
void claenPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "��ϵ�������" << endl;
	system("pause");
	system("cls");//����
}

void ShowMenu(void);

int main(){
	Addressbooks abs;
	//��ʼ����Ա����
	abs.m_Size = 0;
	int select = 0;

	while (true) {

		ShowMenu();

		cin >> select;
		switch (select) {
		case 1:	
			addPerson(&abs) ;//���
			break; 
		case 2:showPerson(&abs);//��ʾ
			break;
		case 3://ɾ��
		/*{cout << "������ɾ����ϵ�˵����� :  " << endl;
		string name;
		cin >> name;
		if (isExist(&abs, name) == -1)
			cout << "���޴���" << endl;
		else
void deletePerson(Addressbooks* abs) {
			cout << "�ҵ�����" << endl; }*/
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);//����
			break;
		case 5:
			modifyPerson(&abs);//�޸�
			break;
		case 6://���
			claenPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��\n"; 
			system("pause"); return 0;
			break;
		default:
			break;
		}
	}
return 0;
}
void ShowMenu(void) {
	cout <<endl<<"	1.�����ϵ��\n"<<"	2.��ʾ��ϵ��\n"<<"	3.ɾ����ϵ��\n"
		 <<"	4.������ϵ��\n"<<"	5.�޸���ϵ��\n"<<"	6.�����ϵ��\n"<<"	0.�˳�ͨѶ¼\n\n";
	cout << "��������Ҫ���еĲ��������֣���";
}
