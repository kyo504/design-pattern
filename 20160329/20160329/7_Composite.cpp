// 7_Composite

// ������ �ڽ��� ũ�Ⱑ ������, ������ �ڽ��� ũ�Ⱑ �����ϴ�.
// ������ ���ϰ� ���� ��� ũ�⸦ ���� �� �ֽ��ϴ�.

#include <iostream>
using namespace std;
#include <vector>

// 1. File�� Folder�� ������ �θ� : Item
// 2. File�� Folder�� ���� : getSize();

class Item
{
	string name;
public:
	Item(string s) : name(s) {};

	virtual ~Item() {};
	virtual int getSize() = 0;
};

class Folder : public Item
{
	vector<Item*> v;

public:
	Folder(string s) : Item(s) {}
	void addItem(Item* p) {
		v.push_back(p);
	}

	virtual int getSize()
	{
		int sum=0;

		for (int i = 0; i < v.size(); ++i) {
			sum += v[i]->getSize();
		}

		return sum;
	}

	// C++������ ������Ʈ ������ ������ ��, 
	// �����ϰ� �ִ� ��� ��ü�� ���� �޸� ������ å���� �ִ�.
	~Folder() {
		for (int i = 0; i < v.size(); ++i)
			delete v[i];
	}
};

class File : public Item
{
public:
	int size;
	File(string s, int n) : Item(s), size(n) {}

	virtual int getSize()
	{
		return size;
	}
};

int main()
{
  // �Ʒ��ڵ尡 ����ǵ��� Folder, File Ŭ������ ����� ������
  Folder* fol1 = new Folder("ROOT");
  Folder* fol2 = new Folder("A");

  File* f1 = new File("a.txt", 10); // �̸�, ũ��
  File* f2 = new File("b.txt", 20);

  // ���輳��
  fol2->addItem(f1);
  fol1->addItem(f2);
  fol1->addItem(fol2);
  cout << f2->getSize() << endl; // 20
  cout << fol2->getSize() << endl; // 10
  cout << fol1->getSize() << endl; // 30

  delete fol1;
  //Composite ����
  // - ��ü�� �ݵ�� ���� �����ؾ� �Ѵ�.
  // 
}