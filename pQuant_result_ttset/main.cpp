#include"pQuant.h"
string inname = "";
string outname = "";
string logname = "";
int main()
{
	ofstream log(logname);
	if (!log.is_open())
	{
		cout << "��־�ļ��޷��򿪻����������˳���";
		exit(EXIT_FAILURE);
	}
	ifstream in(inname);
	if (!in.is_open())
	{
		cout << "��������޷��򿪣������˳���";
		log<< "��������޷��򿪣������˳���";
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