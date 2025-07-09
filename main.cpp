#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <filesystem>


using std::cout;
using std::cin;
using std::endl;

void init();            //��������
void new_stu();         //���ѧ����Ϣ
void show();            //�г�����ѧ����Ϣ
void find();            //����ѧ����Ϣ
void del();          //ɾ��ѧ����Ϣ

std::vector<std::string> lines;

std::ofstream fout;
std::ifstream fin;

int main()
{
	system("color F2");
	init();
	fin.open("student.txt");
	std::string line;
	while (getline(fin, line)) 
	{
        lines.push_back(line);
    }
	fin.close();
	while (1)
	{
		cout << "��������Ҫִ�еĲ���: ";
		int num;
		cin >> num;
		switch (num)
		{
		case 0:
			exit(0);
			break;
		case 1: 
			new_stu();
			break;
		case 2: 
			show();
			break;
		case 3:
			find();
			break;
		case 4:
			del();
			break;
		default: break;
		}
	}
	return 0;
}

void init()
{
	cout << "***********************************************************\n";
	cout << "***********************************************************\n";
	cout << "*                  ��ӭʹ��ѧ����Ϣ����ϵͳ!              *\n";   
	cout << "*             ����һ����������õ�ѧ����Ϣ����ϵͳ!       *\n";
	cout << "*               By GeorgeYao13 on Github                  *\n";
	cout << "***********************************************************\n";
	cout << "***********************************************************\n";
	cout << "��Ϣ����ϵͳ�ѳɹ�����!\n";
	cout << "�������Ӧ�ı����ִ�в�ͬ�Ĳ���!\n";
	cout << "(0) �˳�ϵͳ\n";
	cout << "(1) ���ѧ����Ϣ\n";
	cout << "(2) �г�����ѧ����Ϣ\n";
	cout << "(3) ����ѧ����Ϣ\n";
	cout << "(4) ɾ��ѧ����Ϣ\n";
}

void new_stu()
{
	std::string name;   //ѧ������
	cout << "������ѧ������: ";
	cin >> name;
	int grade;          //ѧ���꼶
	cout << "�������꼶: ";
	cin >> grade;
	int cla;            //ѧ���༶
	cout << "������༶: ";
	cin >> cla;
	int sch_num;        //ѧ��ѧ��
	cout << "������ѧ��: ";
	cin >> sch_num;
	double scores;      //ѧ������
	cout << "���������: ";
	cin >> scores;
	fout.open("student.txt", std::ios::app);
	std::string id = std::to_string(grade) + std::to_string(cla) + std::to_string(sch_num);
	fout << id << "          " << name << "         " << grade << "          " << cla << "           " << sch_num << "           " << scores << endl;
	fout.close();
}

void show()
{
	cout << "id             ����         �꼶         �༶         ѧ��         ����" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	fin.open("student.txt");
	std::string line;
    while (getline(fin, line)) 
	{
        cout << line << endl;
    }
    fin.close();
}

void find()
{
	std::string keyword;
	cout << "������ؼ���/��������: ";
	cin >> keyword;
	cout << "����         �꼶         �༶         ѧ��         ����" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find(keyword) != std::string::npos) {
            cout << lines[i] << endl;
        }
    }
}

void del()
{
	cout << "������Ҫɾ����ѧ��id: ";
	std::string del_id;
	cin >> del_id;
	fin.open("student.txt");
	fout.open("temp.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::istringstream iss(line);
		std::string firstword;
		if (iss >> firstword)
		{
			if(firstword == del_id)
				continue;
		}
		fout << line << endl;
	}
	fout.close();
	fin.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");
}