#include <iostream>
#include <math.h>
using namespace std;

long double fact(int N)
{
    if(N < 0) 
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, x;
	cout << "¬ведите n: " << endl;
	cin >> n;
	cout << "¬ведите x: " << endl;
	cin >> x;
	float res;
	int k = 1;

	for (k = 1; k != n; k++)
	{
		res = (1 + sin(k * x) / fact(k));
		res *= res;

	}
	cout << "–езультат равен " << res << endl;

	system("pause");
	return 0;
}