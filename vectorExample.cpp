
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void printLength(const vector<int>& array) {
	cout << "in printLength: " << array.size() << endl;
}
void print(const vector<int>& array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
class Student {
private:
public:
	string name;
	int age;
	Student() :name(""), age(0) {};
	Student(const string& _name, int _age) : name(_name), age(_age) {}
	string getName() const { return name; }
	int getAge() const { return age; }
};
int main()
{
	std::cout << "Hello World!\n";
	vector<int> array{ 3,5,6,7,3 };
	cout << "in main: " << array.size() << endl;
	printLength(array);
	array.push_back(4);
	print(array);
	array.assign(10, 2);//tạo array mới (2,2,2)
	print(array);
	array.pop_back();
	print(array);
	array.insert(array.begin() + 1, 3);//(2,2)->(2,3,2)
	print(array);
	array.erase(array.begin());
	print(array);
	//(3 2 2 2 2 2 2 2 2)->(3 2 2 2 2 2)
	array.erase(array.begin() + 2, array.begin() + 5); print(array);
	array.emplace(array.begin() + 1, 4); print(array);


	Student s1("tuan1", 21);
	vector<Student> ds;
	ds.emplace(ds.begin(),"tuan", 20); //them vao ds k tạo pt mới
	ds.insert(ds.begin(), s1); //them vao ds phải tạo pt mới
	auto printvt = [](const vector<Student>& ds) {
		for (const Student& p : ds) {
			cout << p.name << " " << p.age << endl;
		}
	};
	printvt(ds);

	ds.emplace_back("tuan2", 22); cout << "emplace_back: \n"; printvt(ds);

	vector<Student> ds2;
	ds2.emplace_back("tuan3", 23);
	ds2.emplace_back("tuan4", 24);
	ds2.emplace_back("tuan5", 25);
	cout << "ds2: \n";
	printvt(ds2);
	ds2.swap(ds);
	cout << "ds2 swap: \n"; printvt(ds2);
	cout << "ds swap: \n"; printvt(ds);
	ds2.clear();
	cout << "ds2 clear: \n"; printvt(ds2);

	cout << "rbegin:\n"; //duyet nguoc
	for (auto i = ds.rbegin(); i < ds.rend();i++) {
		cout << (*i).getName() << " " << (*i).getAge() << endl;
	}

	cout << "begin:\n"; //duyet xuoi
	for (auto i = ds.begin(); i < ds.end(); i++) {
		cout << (*i).getName() << " " << (*i).getAge() << endl;
	}
	
	cout << "cbegin:\n"; //k cho phep thay doi gia tri cua pt, muon su dung cbegin phai co tu khoa const truoc ham get trong class getName() const {}
	for (auto i = ds.cbegin(); i < ds.cend(); i++) {
		cout << (*i).getName() << " " << (*i).getAge() << endl;
		//cout << (*i).name;
	}

	
	//duyet vector
	cout <<"ds.at(0).getName(): " << ds.at(0).getName() << endl;

	cout << "ds.front().getName(): " << ds.front().getName() << endl;
	cout << "ds.back().getName(): " << ds.back().getName() << endl;


	//kich thuoc //phan biet vùng chứa và vùng nhớ
	cout << " ds.size(): " << ds.size() << endl;
	cout << "ds.max_size(): " << ds.max_size() << endl; //kich thuoc toi da cua vung nho
	ds.resize(4);
	cout << " ds.resize(4): " << ds.size() << endl;
	cout << "ds: \n";
	printvt(ds);
	cout << " ds.size(): " << ds.size() << endl;
	ds.resize(2);
	cout << " ds.resize(2): " << ds.size() << endl;
	cout << "ds: \n";
	printvt(ds);

	cout << "ds.empty(): " << ds.empty() << endl; //0: co pt
	cout << "ds2.empty(): " << ds2.empty() << endl; //1: rong

	//thay doi vung nho chua du lieu, co the lam mat du lieu
	ds.resize(4);
	printvt(ds);
	cout << "ds.capacity(): " << ds.capacity() << endl;
	Student s2("tuan", 22);
	ds.push_back(s2);
	printvt(ds);
	cout << "ds.capacity(): " << ds.capacity() << endl;
	cout << " ds.size(): " << ds.size() << endl; //size chỉ tính vùng có dữ liệu
	ds.shrink_to_fit();
	cout << "ds.capacity(): " << ds.capacity() << endl;

	//reserve thay doi vung nho duoc cap phat nhung k lam mat pt
	ds.reserve(4); //k lam mat pt
	cout << "ds.reserve(4): \n";
	printvt(ds);
	cout << "ds.capacity(): " << ds.capacity() << endl;

	ds.reserve(10);
	cout << "ds.reserve(10): \n";
	printvt(ds);
	cout <<"ds.capacity(): " << ds.capacity() << endl;
	ds.shrink_to_fit();
	cout << "ds.capacity(): " << ds.capacity() << endl;

	vector<bool> arr{ true, false, true, true, true };
	cout << " arr.size(): " << arr.size() << endl;
	
	vector<int> vtint{ 1,0,5,6,6,2,7,7,7,8,9,1 };
	cout << "vtint.size(): " << vtint.size() << endl;
	for (auto i = vtint.begin(); i < vtint.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	auto fint = [](const vector<int>& vt) { //con tro thi phai dung them const
		for (const auto& v : vt) {
			cout << v << " ";
		}
		cout << endl;
		for (auto v = vt.begin(); v < vt.end();v++) {
			cout << *v << " ";
		}
		cout << endl;
	};
	cout << "fint\n";
	fint(vtint);
	sort(vtint.begin(), vtint.end());
	fint(vtint);

	printvt(ds);
	auto ar = [](Student& a, Student& b) {
		return a.getAge() < b.getAge();
	};
	//sort(ds.begin(), ds.end(),ar);
	sort(ds.begin(), ds.end(), [](Student& a, Student& b) {
		return a.getAge() < b.getAge();
		});
	cout << "sort(ds.begin(), ds.end(),ar): \n";
	printvt(ds);

}
