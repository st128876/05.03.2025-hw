#include<iostream>


using namespace std;
class ArrayList
{ 
private:
	int len;
	int* data;
	void init(int len = 10)
	{
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
	void expand();

public:
	ArrayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	ArrayList(ArrayList& list)
	{
		//this->len = list.len;
		//this->data = list.data;
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		free(this->data);
	}

	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}

	void pushBack(int element)
	{
		int* newData = (int*)malloc(sizeof(int) * (this->len + 1));

		for (int i = 0; i < this->len; i++) 
		{
			newData[i] = this->data[i];
		}
		
		this->len = this->len + 1;
		this->data = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 0; i < this->len - 1; i++)
		{
			this->data[i] = newData[i];
		}
		this->data[this->len - 1] = element;
	}

	void pushFront(int element)
	{
		int* newData = (int*)malloc(sizeof(int) * (this->len + 1));

		for (int i = 0; i < this->len; i++)
		{
			newData[i] = this->data[i];
		}

		this->len = this->len + 1;
		this->data = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 1; i < this->len; i++)
		{
			this->data[i] = newData[i];
		}
		this->data[0] = element;
	}

	int popBack()
	{
		int* newData = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 0; i < this->len; i++)
		{
			newData[i] = this->data[i];
		}

		this->len = this->len - 1;
		this->data = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 0; i < this->len; i++)
		{
			this->data[i] = newData[i];
		}
		return newData[this->len + 1];
	}

	int popFront()
	{
		int* newData = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 0; i < this->len; i++)
		{
			newData[i] = this->data[i];
		}

		this->len = this->len - 1;
		this->data = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 0; i < this->len; i++)
		{
			this->data[i] = newData[i + 1];
		}

		return newData[0];
	}

	int extract(int index)
	{
		int* newData = (int*)malloc(sizeof(int) * (this->len - 1));

		for (int i = 0; i < index; i++)
		{
			newData[i] = this->data[i];
		}

		int ans = this->data[index];

		for (int i = index + 1; i < this->len; i++)
		{
			newData[i - 1] = this->data[i];
		}

		this->len = this->len - 1;
		this->data = (int*)malloc(sizeof(int) * (this->len));

		for (int i = 0; i < this->len; i++)
		{
			this->data[i] = newData[i];
		}
		return ans;
	}

	void insert(int index, int element)
	{
		this->data[index] = element;
	}

	void reverse(int start, int end)
	{
		int* between_data = (int*)malloc(sizeof(int) * (end - start));

		int j = start;
		for (int i = end; i >= start; i--)
		{
			between_data[j] = this->data[i];
			j++;
		}

		for (int i = start; i <= end; i++)
		{
			this->data[i] = between_data[i];
		}

	}

	int sum()
	{
		int ans = 0;

		for (int i = 0; i < this->len; i++)
		{
			ans = ans + this->data[i];
		}
		return ans;
	}

	int secondMax();

	int lastMinIndex();

	int shift(int k);

	int countOdd();

	int sumEven();
};

//int max(ArrayList list)
//{
//	int mx = list.get(0);
//	for (int i = 0; i < list.count(); ++i)
//	{
//		mx = (mx > list.get(i) ? mx : list.get(i));
//	}
//	return mx;
//}

int main(int argc, char* argv[])
{
	ArrayList list(6);
	list.randomize();
	list.print();
	list.reverse(1, 1);
	list.print();

	return 0;
}