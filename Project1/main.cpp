#include <iostream>
#include <cstring>

using namespace std;

/* const static ���� */
class ContryArea
{
public:
	const static int RUSSIA = 17100;
	const static int SOUTH_KOREA = 100;
};

int main()
{
	/* const static ���� */
	cout << "Russia area : " << ContryArea::RUSSIA << endl;
	cout << "Korea area : " << ContryArea::SOUTH_KOREA << endl;

	return 0;
}
