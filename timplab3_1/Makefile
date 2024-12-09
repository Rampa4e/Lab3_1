# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Исходные файлы и объекты
SOURCES = test.cpp modAlphaChiper.cpp
EXECUTABLE = test_program

# Основное правило сборки
all: $(EXECUTABLE)

# Правило сборки исполняемого файла
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) -I$(UNITTEST_PATH) -L$(UNITTEST_PATH) -o $(EXECUTABLE) $(SOURCES) -lUnitTest++

# Очистка скомпилированных файлов
clean:
	rm -f $(EXECUTABLE) *.o
