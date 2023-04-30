#include <gtest/gtest.h>

#include "../src/utils/Wrapper.h"

class SimpleClass {
public:
	SimpleClass(int prop = 42) : prop(prop) {}
	~SimpleClass() {}
	SimpleClass* clone() const { return new SimpleClass(*this); }
	int get() { return prop; }

private:
	int prop;
};

// Demonstrate some basic assertions.
TEST(WrapperTest, WrapperAssertions) {

	// Create a SimpleClass object
	SimpleClass simple;
	SimpleClass* simple_ptr = &simple;
	
	// Create a Wrapper object with the SimpleClass as a template
	Wrapper<SimpleClass> simpleWrapped;

	// Equalize the SimpleClass with the Wrapper
	simpleWrapped = simple;

	// Test equalities
	EXPECT_EQ(simple, simpleWrapped);
	EXPECT_EQ(&simple, &simpleWrapped);
	EXPECT_EQ(simple.get(), simpleWrapped->get());
	EXPECT_EQ(simple_ptr->get(), simpleWrapped->get());

}