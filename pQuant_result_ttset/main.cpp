#include"pQuant.h"
string inname = "";
string outname = "";
string logname = "";
int main()
{
	ofstream log(logname);
	if (!log.is_open())
	{
		cout << "日志文件无法打开或建立，程序退出。";
		exit(EXIT_FAILURE);
	}
	ifstream in(inname);
	if (!in.is_open())
	{
		cout << "定量结果无法打开，程序退出。";
		log<< "定量结果无法打开，程序退出。";
		exit(EXIT_FAILURE);
	}
	vector<pquant> veclist;
	string title;
	getline(in, title);
	in >> veclist;
	valarray<double> vallist(0.0,veclist.size());
	for (int i = 0; i < veclist.size(); i++)
	{
		vallist[i] = veclist[i].ratio;
	}
	qtest(veclist, vallist);
	
	ofstream out(outname);
	for (int i = 0; i < veclist.size(); i++)
	{
		if (veclist[i].output_tag)
			out << veclist[i] << endl;
		else
			continue;
	}
}