// C++11_14_Learn.cpp: определ€ет точку входа дл€ консольного приложени€.

#include "stdafx.h"
/**/
// git-hub user2

#include <iostream>
#include <string>
#include <vector>

// »диомы —++
// 1. RAII
// ÷ель:
//   ќчистка ресурсов
//   Basic Exception Sefety

// 1. Smart Pointers
// ÷ель:
//   —ымитировать поведеине обычного указател€
//   ƒобавить дополнительные возможности

// «апретить создание объектов на стеке. ¬ариант 1
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

// «апретить создание объектов на стеке. ¬ариант 2
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

// «апретить создание объекта в куче
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
//  нига про »диомы C++: https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms








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
	
	// Type Traits - позвол€ет узнать в compile time €вл€етс€ ли тип, например, типом с плавающей точкой
	
	// RegExp

	// SmartPointers - unique_ptr, shared_ptr, weak_ptr
	//auto pPerson = std::make_shared<Person>();
	
	// std::enabled_shared_from_this - унаследовавшись от него можно получить shared_ptr на текущий объект, при этом не будет двойного удалени€ объекта

	// PRNG - добавлены генераторы случайных чисел

	// HashTables - unordered map

	// unique_ptr - замена auto_ptr
	//std::unique_ptr<A> pA = std::make_unique;

	// Thread

	// auto и decltype
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
	// —оглашени€ по захвату переменных из окружающей области:
	// [] - никакие значени€ не захватываютс€
	// [x] - захватываетс€ переменна€ x по значению
	// [&x] - захватываетс€ переменна€ x по ссылке
	// [=] - захватываютс€ все окружающие переменные по значению
	// [&] - захватываютс€ все окружающие переменные по ссылке
	// [=, &x] - захватываютс€ все окружающие переменные по значению, а переменна€ x по ссылке
	// [&, y] - захватываютс€ все окружающие переменные по ссылке, а переменна€ y по значению
	// [x, &y, &z] - захватываетс€ переменна€ x по значению, а переменные y и z по ссылке
	auto fPersonsLessByName = [] (const Person& p1 , const Person& p2) -> bool {
		return p1.Name() < p2.Name();
	};

	std::vector<Person> vp;
	//std::qsort(vp.cbegin(), vp.cend(), fPersonsLessByName);

	// override и final

	// delete и default

	// Variadic Template

	// Threads и TLS

	// UTF8

	// RAII ???

	// lock_guard
	//std::mutex m;
	//std::lock_guard<std::mutex> lk(m);
/**/
	return 0;
}

