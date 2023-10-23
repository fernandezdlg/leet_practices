CXX = clang++
CXXFLAGS = -std=c++23 -stdlib=libc++ -O2 -Wextra -Wpedantic

EXTRA =
LIBS = -L/opt/homebrew/opt/llvm/lib/c++ -Wl,-rpath,/opt/homebrew/opt/llvm/lib/c++
INCLUDE = -I.
targets = main

all: $(targets)

% : %.cpp
	$(CXX) $< $(CXXFLAGS) $(EXTRA) $(INCLUDE) $(LIBS) -o $@

clean:
	rm -f *.o *~ $(targets) *.txt .tags

.PHONY: all
.PHONY: clean
