CXX = g++
CXXFLAGS = -O2 -std=c++17

programa: main.cpp studentas.cpp failai.cpp studentas.h failai.h
	$(CXX) $(CXXFLAGS) main.cpp studentas.cpp failai.cpp -o programa

clean:
	rm -f programa vargsiukai.txt kietiakiai.txt rezultatai.txt
