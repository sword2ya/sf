CXX=g++
CXXFLAGS=-g -pthread
INC=-I ../include -I ../head


BASE_DIR=..
SRC_DIR=$(BASE_DIR)/src
OBJECT_DIR=./obj

TEST_TARGET=MainTest
TEST_LIB=../lib/gtest.a
TEST_SRC_DIR=$(BASE_DIR)/srctest $(SRC_DIR)
TEST_SRC_PATHS=$(foreach x, $(TEST_SRC_DIR), $(wildcard $(x)/*.cpp))
TEST_OBJECTS=$(subst .cpp,.o,$(subst $(BASE_DIR),$(OBJECT_DIR),$(TEST_SRC_PATHS)))
TEST_OBJECT_DIR=$(subst $(BASE_DIR),$(OBJECT_DIR),$(TEST_SRC_DIR))
TEST_DEPS=$(TEST_OBJECTS:.o=.cpp.d)

MAIN_TARGET=Main
MAIN_SRC_DIR=$(BASE_DIR)/srcmain $(SRC_DIR)
MAIN_SRC_PATHS=$(foreach x, $(MAIN_SRC_DIR), $(wildcard $(x)/*.cpp))
MAIN_OBJECTS=$(subst .cpp,.o,$(subst $(BASE_DIR),$(OBJECT_DIR),$(MAIN_SRC_PATHS)))
MAIN_OBJECT_DIR=$(subst $(BASE_DIR),$(OBJECT_DIR),$(MAIN_SRC_DIR))
MAIN_DEPS=$(MAIN_OBJECTS:.o=.cpp.d) 

$(TEST_TARGET):$(TEST_OBJECTS) $(TEST_LIB)
	$(CXX) -o $@ $(TEST_OBJECTS) $(TEST_LIB) $(CXXFLAGS)

$(MAIN_TARGET):$(MAIN_OBJECTS) 
	$(CXX) -o $@ $(MAIN_OBJECTS) $(CXXFLAGS)

sinclude $(TEST_DEPS)
sinclude $(MAIN_DEPS)

$(OBJECT_DIR)/%.o:$(BASE_DIR)/%.cpp $(OBJECT_DIR)/%.cpp.d
	$(CXX) -o $@ -c $< $(INC) $(CXXFLAGS)

$(TEST_DEPS) $(MAIN_DEPS):$(OBJECT_DIR)/%.cpp.d:$(BASE_DIR)/%.cpp
	@set -e;\
	rm -f $@;\
	$(CXX) $< -MM $(INC) | sed 's,.*\.o\s*:,$(subst .cpp.d,.o,$@):,g' > $@;

.PHONY:test
test:$(TEST_TARGET)

.PHONY:testobj
testobj:$(TEST_OBJECTS)

.PHONY:main 
main:$(MAIN_TARGET)

clean:
	-rm $(TEST_DEPS) $(TEST_OBJECTS) $(TEST_TARGET) \
	$(MAIN_TARGET) $(MAIN_OBJECTS) $(MAIN_DEPS)

init:
	mkdir -p $(TEST_OBJECT_DIR)
	mkdir -p $(MAIN_OBJECT_DIR)

print:
	@echo "MAIN_SRC_DIR" $(MAIN_SRC_DIR)
	@echo "MAIN_SRC_PATHS" $(MAIN_SRC_PATHS)
	@echo "MAIN_OBJECTS" $(MAIN_OBJECTS)
	@echo "MAIN_OBJECT_DIR" $(MAIN_OBJECT_DIR)
	@echo "MAIN_DEPS" $(MAIN_DEPS)
	@echo "TEST_OBJECTS" $(TEST_OBJECTS)

	@echo "TEST_OBJECTS:.o=.cpp.d" $(TEST_OBJECTS:.o=.cpp.d)




