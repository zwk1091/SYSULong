/*
  分组小程序
  每个院有多各组
  讲这些组分为1对1的形式，有同院回避原则
  将数据以：
  XX院  #数量
  XX院  #数量
  ....
  的形式存放在data.txt文件，运行程序即可
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	fstream in;
	in.open("data.txt");
	vector<string> teamName;
	vector<int> teamNum;
	int totalCapusNum=0;
	int totalTeamNum=0;
	//cin >> totalCapusNum;

	//for (int i = 0; i < totalCapusNum; i++)
	int tNum;
	string tName;
	while(in >> tName >> tNum){
		teamName.push_back(tName);
		teamNum.push_back(tNum);
		totalTeamNum += tNum;
		totalCapusNum++;
	}
	if (totalTeamNum % 2 == 1) {
		totalCapusNum++;
		totalTeamNum++;
		teamName.push_back("‘轮空’");
		teamNum.push_back(1);
	}
	int needToPair = totalTeamNum;
	while (needToPair>0) {
		int pair1=0,pair2=0;
		while (pair1 == pair2||teamNum[pair1]==0||teamNum[pair2]==0) {
			pair1 = rand() % totalCapusNum;
			pair2 = rand() % totalCapusNum;
		}
		
		cout << teamName[pair1]<<teamNum[pair1]<<"队" << " vs "<< teamName[pair2]<<teamNum[pair2] <<"队"<< endl;
		cout << "----------------------------" << endl;
		teamNum[pair1]--;
		teamNum[pair2]--;
		needToPair -= 2;
	}
	
	system("pause");
	return 0;
}