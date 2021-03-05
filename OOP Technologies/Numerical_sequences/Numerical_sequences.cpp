#include "Numerical_sequences.h"

int main() {
	const int N = 3;
	Container* container = new Container;
	for (int i = 0; i < N; i++) {
		if (i % 3 == 2) {
			container->Push(*(new Arithmetic(1, 0.1)));
		}
		else if (i % 3 == 1) {
			container->Push(*(new Geometric(2, 0.1)));
		}
		else 
			container->Push(*(new Fibonacci(3, 0.1)));
	}
	container->Show(5);
	container->FindMaxValue(6);

	Fibonacci* arith1 = new Fibonacci;
	container->Push(*arith1);
	container->Show(5);
	container->FindMaxValue(6);

	arith1->setValue(1, 0.1);
	container->Show(5);
	container->FindMaxValue(6);

	Fibonacci* arith2 = new Fibonacci;
	*arith2 = *arith1;
	arith2->Show(5);
	std::cout << arith2->Calculate(3) << "\n\n";

	arith1->~Fibonacci();

	arith2->Show(5);
	std::cout << arith2->Calculate(3) << "\n\n";

	Container* container1 = new Container;
	Container* container2 = container;
	Container* container3(container1);

	container1->Show(3);
	container2->Show(3);
	container3->Show(3);

	Container* container4 = new Container(std::move(*container2));
	Container* container5 = new Container;
	*container5 = std::move(*container2);

	container1->Show(3);
	container4->Show(3);
	container5->Show(3);
	std::cout << "\n\n___________________________________\n\n";

	Container* container6 = new Container;
	*container6 = *container4;// = new Container(*container4);

	container4->Show(3);
	container6->Show(3);
	std::cout << (*container4 == *container6);
	std::cout << "\n\n";
	std::cout << (*container4 != *container6);
	std::cout << "\n\n";

	std::cout << "\n\n___________________________________\n\n";
	container4->Pop();
	container4->Show(3);
	container4->Pop();
	container4->Show(3);
	container4->Pop();
	container4->Show(3);
	container4->Pop();
	container4->Show(3);
	container4->Pop();
	container4->Show(3);
	container4->Pop();
	container4->Show(3);
	container4->Pop();
	container4->Show(3);
	std::cout << "\n\n___________________________________\n\n";

	container1->~Container();
	container2->~Container();
	container3->~Container();
	container4->~Container();
	container5->~Container();

	container4->Pop();
	container4->Show(3);
	container6->Show(3);

	return 0;
}