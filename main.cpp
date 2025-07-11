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

void init();            //启动画面
void new_stu();         //添加学生信息
void show();            //列出所有学生信息
void find();            //查找学生信息
void del();          //删除学生信息

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
		cout << "请输入你要执行的操作: ";
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
	cout << "*                  欢迎使用学生信息管理系统!              *\n";   
	cout << "*             这是一款免费且易用的学生信息管理系统!       *\n";
	cout << "*               By GeorgeYao13 on Github                  *\n";
	cout << "***********************************************************\n";
	cout << "***********************************************************\n";
	cout << "信息管理系统已成功启动!\n";
	cout << "请输入对应的编号以执行不同的操作!\n";
	cout << "(0) 退出系统\n";
	cout << "(1) 添加学生信息\n";
	cout << "(2) 列出所有学生信息\n";
	cout << "(3) 查找学生信息\n";
	cout << "(4) 删除学生信息\n";
}

void new_stu()
{
	std::string name;   //学生姓名
	cout << "请输入学生姓名: ";
	cin >> name;
	int grade;          //学生年级
	cout << "请输入年级: ";
	cin >> grade;
	int cla;            //学生班级
	cout << "请输入班级: ";
	cin >> cla;
	int sch_num;        //学生学号
	cout << "请输入学号: ";
	cin >> sch_num;
	double scores;      //学生分数
	cout << "请输入分数: ";
	cin >> scores;
	fout.open("student.txt", std::ios::app);
	std::string id = std::to_string(grade) + std::to_string(cla) + std::to_string(sch_num);
	fout << id << "          " << name << "         " << grade << "          " << cla << "           " << sch_num << "           " << scores << endl;
	fout.close();
}

void show()
{
	cout << "id             姓名         年级         班级         学号         分数" << endl;
	cout << "---------------------------------------------------------------------" << endl;
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
	cout << "请输入关键字/词以搜索: ";
	cin >> keyword;
	cout << "id             姓名         年级         班级         学号         分数" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find(keyword) != std::string::npos) {
            cout << lines[i] << endl;
        }
    }
}

void del()
{
	cout << "请输入要删除的学生id: ";
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
