#pragma once//2151641 王佳垚 mayaaowu@gmail.com 19821126070

using namespace std;

struct Rectangle
{
private:
	//初始化为0，否则后面使用未初始化数据*10
	int width = 0;
	int length = 0;
	//重载>>以实现Rectangle输入,长宽可多位数
	friend istream& operator>>(istream& is, Rectangle& rhs)
	{
		string initial;
		is >> initial;
		const int poi_0 = initial.find(',');
		for (int poi_1 = 0; poi_1 < poi_0; ++poi_1)
		{
			if (initial.at(poi_1) < '0' || initial.at(poi_1) > '9')
				//设置cin为fail状态
				is.setstate(ios_base::failbit);
			else
				rhs.length = rhs.length * 10 + (initial.at(poi_1) - '0');
		}
		for (unsigned int poi_2 = poi_0 + 1; poi_2 < initial.length(); ++poi_2)
		{
			if (initial.at(poi_2) < '0' || initial.at(poi_2) > '9')
				//设置cin为fail状态
				is.setstate(ios_base::failbit);
			else
				rhs.width = rhs.width * 10 + (initial.at(poi_2) - '0');
		}
		return is;
	}
	//重载<<以实现Rectangle格式化输出
	friend ostream& operator<<(ostream& os, Rectangle& rhs)
	{
		os << "(" << rhs.length << "," << rhs.width << ")";
		return os;
	}
};

template<typename T>
struct Stack
{
private:
	//SIZE在这改
	const static int SIZE = 5;
	T elem[SIZE];
	int head = 0;
public:
	void push(const T elem0)
	{
		if (!isFull())
			elem[head++] = elem0;
	}
	T pop()
	{
		if (!isEmpty())
			return elem[--head];
		return elem[head];
	}
	bool isEmpty() { return head == 0 ? true : false; }const
	bool isFull() { return head == SIZE ? true : false; }const
	void print()const
	{
		cout << "[";
		for (int poi = 0; poi < head; ++poi)
			cout << elem[poi] << ",";
		cout << "]" << endl;
	}
};
