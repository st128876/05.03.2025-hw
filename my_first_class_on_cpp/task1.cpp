#include<iostream>


using namespace std;
class ArrayList
{ 
private:
	int len;
	int* data;
	int* sorted_data;
	void init(int len = 10)
	{
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
		this->sorted_data = (int*)malloc(sizeof(int) * len);
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
		free(this->sorted_data);
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

	int secondMax() 
	{
		this->update_sorted_list();
		return this->sorted_data[this->len - 2];
	}


	int lastMinIndex()
	{
		this->update_sorted_list();
		for (int i = 0; i < this->len; i++) 
		{
			if (this->data[i] = this->sorted_data[0])
			{
				return i;
			}
		}
	}

	void shift(int k)
	{
		int* newData = (int*)malloc(sizeof(int) * (this->len));
		for (int i = 0; i < this->len; i++)
		{
			newData[i] = this->data[i];
		}


		for (int i = 0; i < this->len; i++)
		{
			this->data[(i + k) % this->len] = newData[i];
		}

	}


	int countOdd()
	{
		int ans = 0;
		for (int i = 0; i < this->len; i++)
		{
			if (this->data[i] % 2 == 1)
			{
				ans = ans + 1;
			}
		}
		cout << ans << endl;
		return ans;
	}

	int sumEven()
	{
		int ans = 0;
		for (int i = 0; i < this->len; i++)
		{
			if (this->data[i] % 2 == 0)
			{
				ans = ans + this->data[i];
			}
		}
		return ans;
	}


	void update_sorted_list()
	{
		this->sorted_data = (int*)malloc(sizeof(int) * this->len);
		for (int i = 0; i < this->len; i++)
		{
			this->sorted_data[i] = this->data[i];
		}
		this->quicksort(0, this->len - 1);
	}

	void quicksort(int left, int right)
	{
		if (left > right) {return;}
		int opr = this->sorted_data[(left + right) / 2];
		int i = left;
		int j = right;
		while (i <= j)
		{
			while (this->sorted_data[i] < opr) i++;
			while (this->sorted_data[j] > opr) j--;
			if (i <= j) 
			{
				int tmp = this->sorted_data[i];
				this->sorted_data[i] = this->sorted_data[j];
				this->sorted_data[j] = tmp;
				i++;
				j--;
			}
		}
		this->quicksort(left, j);
		this->quicksort(i, right);
	}
};


int main(int argc, char* argv[])
{
	int n = 5;
	ArrayList list(n);

	list.randomize();
	list.print();
	list.shift(3);
	list.print();

	return 0;
}