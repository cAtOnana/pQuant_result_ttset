#include"pQuant.h"
#include<algorithm>
string inname = "97H_2.spectra.list";
string outname = "97H_2.spectraflit.list";
string logname = "97H_2.log";
bool sortbybigger(pquant& a, pquant& b) { return a.ratio < b.ratio; }
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
	sort( veclist.begin(), veclist.end(),sortbybigger);
	valarray<double> vallist(0.0,veclist.size());
	for (int i = 0; i < veclist.size(); i++)
	{
		vallist[i] = veclist[i].ratio;
	}
	log10(vallist);
	qtest(veclist, vallist);
	ofstream out(outname);
	out << title << endl;
	for (int i = 0; i < veclist.size(); i++)
	{
		if (veclist[i].output_tag)
			out << veclist[i] << endl;
		else
			cout << veclist[i] << endl;
	}
	cout << "aaa";
	char z;
	cin >> z;
	return 0;
}