// C++11_14_Learn.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
/**/
// git-hub user2

#include <iostream>
#include <string>
#include <vector>

// ������ �++
// 1. RAII
// ����:
//   ������� ��������
//   Basic Exception Sefety

// 1. Smart Pointers
// ����:
//   ������������ ��������� �������� ���������
//   �������� �������������� �����������

// ��������� �������� �������� �� �����. ������� 1
class EventHandler {
public:
	virtual ~EventHandler()
	{}
};

class MouseEventHandler1 : public EventHandler {
public:
	MouseEventHandler1()
	{}

protected:
	~MouseEventHandler1()
	{}
};

void useMouseEventHandler1() {
	//MouseEventHandler meh; // We can't do it
	EventHandler* pMeh = new MouseEventHandler1(); // We can do it
	delete pMeh; // Polymorphic delete call
}

// ��������� �������� �������� �� �����. ������� 2
class MouseEventHandler {
public:
	static MouseEventHandler* instance() {
		return new MouseEventHandler();
	}

	void destroy() {
		delete this;
	}

protected:
	MouseEventHandler()
	{}

	~MouseEventHandler()
	{}
};

// ��������� �������� ������� � ����
class ScopedLock {
private:
	static void* operator new(size_t size);
	static void* operator new(size_t, void* mem); // Placement new
};

void useScopedLock() {
	ScopedLock sl;                                // We can do it
	//ScopedLock* pSl1 = new ScopedLock();          // We can't do it
	void* pSl2Buf = ::operator new(sizeof(ScopedLock));
	//ScopedLock* pSl2 = new(pSl2Buf) ScopedLock(); // We can't do it
}

// Copy-On-Write
// Interface Class
// Member Detector
// Named Constructor
// Scope Guard
// Runtime Static Initialization Order Idioms
// ����� ��� ������ C++: https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms








class A {
public:
	A() {
		std::cout << "A::A()\n";
	}

	~A() {
		std::cout << "A::~A()\n";
	}

//private:
};

class Person {
public:
	Person() = default;

	Person(const std::string& name)
		: Person(name, "emptyFamily")
	{}

	Person(const std::string& name, const std::string& family) :
		name_(name)
		, family_(family)
	{}

	Person(const Person&) = delete;
	const Person& operator= (const Person&) = delete;

	std::string Name() const {
		return name_;
	}

private:
	std::string name_;
	std::string family_;
};
/**/
int _tmain(int argc, _TCHAR* argv[]) {
	/**/
	// Function
	
	// Tuples
	
	// Math
	
	// Type Traits - ��������� ������ � compile time �������� �� ���, ��������, ����� � ��������� ������
	
	// RegExp

	// SmartPointers - unique_ptr, shared_ptr, weak_ptr
	//auto pPerson = std::make_shared<Person>();
	
	// std::enabled_shared_from_this - ��������������� �� ���� ����� �������� shared_ptr �� ������� ������, ��� ���� �� ����� �������� �������� �������

	// PRNG - ��������� ���������� ��������� �����

	// HashTables - unordered map

	// unique_ptr - ������ auto_ptr
	//std::unique_ptr<A> pA = std::make_unique;

	// Thread

	// auto � decltype
	std::vector<double> vd;
	vd.emplace_back(3.14);
	vd.emplace_back(1.8);
	vd.emplace_back(5.9);
	auto itv1 = vd.cbegin();
	decltype(itv1) itv2;
	//for(decltype(vd.cbegin()) itv : vd) {
	//	std::cout << *
	//}

	for(const auto& rv : vd) {
		std::cout << rv << ' ';
	}
	std::cout << '\n';

	// Lambda Functions
	// ���������� �� ������� ���������� �� ���������� �������:
	// [] - ������� �������� �� �������������
	// [x] - ������������� ���������� x �� ��������
	// [&x] - ������������� ���������� x �� ������
	// [=] - ������������� ��� ���������� ���������� �� ��������
	// [&] - ������������� ��� ���������� ���������� �� ������
	// [=, &x] - ������������� ��� ���������� ���������� �� ��������, � ���������� x �� ������
	// [&, y] - ������������� ��� ���������� ���������� �� ������, � ���������� y �� ��������
	// [x, &y, &z] - ������������� ���������� x �� ��������, � ���������� y � z �� ������
	auto fPersonsLessByName = [] (const Person& p1 , const Person& p2) -> bool {
		return p1.Name() < p2.Name();
	};

	std::vector<Person> vp;
	//std::qsort(vp.cbegin(), vp.cend(), fPersonsLessByName);

	// override � final

	// delete � default

	// Variadic Template

	// Threads � TLS

	// UTF8

	// RAII ???

	// lock_guard
	//std::mutex m;
	//std::lock_guard<std::mutex> lk(m);
/**/
	return 0;
}

