#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queue.h"
#include "doctest.h"

TEST_CASE("Tests") {

	Queue queue;

	queue.enqueue(1);
	queue.enqueue(4);
	queue.dequeue();
	CHECK((queue.first)->data == 4);
	queue.dequeue();
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	CHECK((queue.first)->data == 3);
	CHECK((queue.last)->data == 5);
	queue.dequeue();
	CHECK((queue.first)->data == 4);
	CHECK((queue.last)->data == 5);
}