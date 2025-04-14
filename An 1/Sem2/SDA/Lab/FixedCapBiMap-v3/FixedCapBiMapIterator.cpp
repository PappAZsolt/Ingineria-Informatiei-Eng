#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
using namespace std;


FixedCapBiMapIterator::FixedCapBiMapIterator(const FixedCapBiMap& d) : map(d)
{
	this->currentPositions = 0;
}


void FixedCapBiMapIterator::first() {
	this->currentPositions = 0;
}


void FixedCapBiMapIterator::next() {
	if (this->currentPositions == this->map.mapSize)
		throw exception();
	this->currentPositions++;
}


TElem FixedCapBiMapIterator::getCurrent(){
	return this->map.elements[this->currentPositions];
}


bool FixedCapBiMapIterator::valid() const {
	return this->currentPositions < this->map.mapSize;
}



