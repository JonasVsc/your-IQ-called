// P.S. This file will be refactored.



#include<iostream>
using namespace std;

class DiagonalMatrix
{
public:
	DiagonalMatrix(int sz)
		:	size_{sz}
	{
		A_ = new int[size_] {};

		for(int i = 0; i < size_; i++)
		{
			A_[i] = 1;
		}
	}

	void display()
	{
		for(int i = 0; i < size_; i++)
		{
			for(int j = 0; j < size_; j++)
			{
				if(i == j)
					cout << A_[i] << ' ';
				else
					cout << '0' << ' ';
			}
			cout << '\n';
		}
	}

	void set(int m, int n, int v)
	{
		if(m > size_ - 1)
			throw runtime_error("invalid range access");

		if(m != n)
			throw runtime_error("invalid insert element location");
		else
			A_[m] = v;
	}

	int get(int m, int n)
	{
		if(m > size_ - 1)
			throw runtime_error("invalid range access");

		if(m != n)
			throw runtime_error("invalid insert element location");
		else
			return A_[m];
	}


private:
	int *A_;
	int size_;

};


int main()
{
	DiagonalMatrix my_matrix(5);
	my_matrix.display();
	return 0;
}