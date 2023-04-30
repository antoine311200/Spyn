#include <gtest/gtest.h>

#include "../src/utils/Wrapper.h"

class SimpleClass {
public:
	SimpleClass(int prop = 42) : prop(prop) {}
	~SimpleClass() {}
	SimpleClass* clone() const { return new SimpleClass(*this); }
	int get() { return prop; }
	void set(int newProp) { prop = newProp; }

private:
	int prop;
};


// Demonstrate wrapper assertions.
TEST(WrapperTest, WrapperAssertions) {

	// Create a SimpleClass object
	SimpleClass simple;
	const SimpleClass simpleConst;

	// Create a Wrapper object with the SimpleClass as a template
	Wrapper<SimpleClass> simpleWrapped(&simple);
	Wrapper<SimpleClass> simpleWrappedClone(simple);
	Wrapper<SimpleClass> simpleWrappedConst(simpleConst);
	Wrapper<SimpleClass> simpleWrappedDupplicate;

	simpleWrappedDupplicate = simpleWrapped;

	simpleWrapped->set(1);
	simpleWrappedClone->set(2);
	simpleWrappedDupplicate->set(3);

	EXPECT_EQ(&(*simpleWrapped), &simple);
	EXPECT_NE(&(*simpleWrappedClone), &simple);
	EXPECT_NE(&simpleWrappedDupplicate, &simpleWrapped);
	EXPECT_NE(&(*simpleWrappedConst), &simpleConst);

	EXPECT_EQ(simpleWrapped->get(), simple.get());
	EXPECT_NE(simpleWrappedDupplicate->get(), simpleWrapped->get()); // 3 != 1
};