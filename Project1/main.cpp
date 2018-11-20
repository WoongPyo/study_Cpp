#include <iostream>
#include <cstring>

using namespace std;
/* ���� ó���� ���� ��Ӱ��迡���� �������ӿ� ���� ���ǻ��� */
class AAA
{
public:
	void ShowYou()
	{
		cout << "AAA exception" << endl;
	}
};

class BBB : public AAA
{
public:
	void ShowYou()
	{
		cout << "BBB exception" << endl;
	}
};

class CCC : public BBB
{
public:
	void ShowYou()
	{
		cout << "BBB exception" << endl;
	}
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}


int main(void)
{
	/* ���� ó���� ���� ��Ӱ��迡���� �������ӿ� ���� ���ǻ��� */
	
	try
	{
		ExceptionGenerator(3); //CCC
		ExceptionGenerator(2); //BBB
		ExceptionGenerator(1); //AAA
	}
	catch (AAA &expn)
	{
		cout << "catch(AAA &expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB &expn)
	{
		cout << "catch(BBB &expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC &expn)
	{
		cout << "catch(CCC &expn)" << endl;
		expn.ShowYou();
	}

	return 0;
}
