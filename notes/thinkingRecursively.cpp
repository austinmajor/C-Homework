#include <chrono>
#include <iostream>
#include <random>
#include <vector>

/*
    Perform binary search
    -- know size of array
    -- calculate mid-point
    -- is mid-point what i'm looking for
    -- if yes, return location
    -- if no, is what we're looking for bigger or smaller than the mid-point value
    -- if smaller, search through elements 0 - (mid -1)
    -- if larger, search through elements (mid + 1) - (size -1)
    -- calculate mid-point...


 */
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer()
	    : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void rbinarySearch(const std::vector<int>& a, int key, int first, int last, bool& found, int& loc);
void ibinarySearch(const std::vector<int>& a, int key, int first, int last, bool& found, int& loc);
void basicSearch(const std::vector<int>& a, int size, int key, bool& found, int& loc);

int main()
{
    std::random_device rando;
    std::mt19937 engine(rando());
    std::vector<int> myArr(10000);
    int location, fill = 20000;
    bool found;

    for (int i = 0; i < 10000; i++) {
        myArr[i] = fill;
        fill++;
    }

    // for (int i = 0; i < 10000; i++)
    //     std::cout << myArr[i] << " ";
    // std::cout << std::endl;

    Timer timer;
    rbinarySearch(myArr, 29555, 0, 9999, found, location);
    double time = timer.elapsed();
    std::cout << "Found 25555 at index " << location << " in " << time << " seconds.\n";

    timer.reset();
    ibinarySearch(myArr, 29555, 0, 9999, found, location);
    time = timer.elapsed();
    std::cout << "Found 25555 at index " << location << " in " << time << " seconds.\n";

    timer.reset();
    basicSearch(myArr, 29555, 10000, found, location);
    time = timer.elapsed();
    std::cout << "Found 25555 at index " << location << " in " << time << " seconds.\n";

}

void rbinarySearch(const std::vector<int>& a, int key, int first, int last, bool& found, int& loc)
{
    int mid;

    if (first > last) {
        found = false;
    } else {
        mid = (first + last) / 2;

        if (key == a[mid]) {
            found = true;
            loc = mid;
        } else if (key < a[mid]) {
            rbinarySearch(a, key, first, mid - 1, found, loc);
        } else if (key > a[mid]) {
            rbinarySearch(a, key, mid + 1, last, found, loc);
        }
    }
}

void ibinarySearch(const std::vector<int>& a, int key, int first, int last, bool& found, int& loc)
{
    int low = first;
    int high = last;
    int mid;
    found = false;

    while ( (low <= high) && !(found) ) {
        mid = (low + high) / 2;
        if (key == a[mid]) {
            found = true;
            loc = mid;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        }
    }
}

void basicSearch(const std::vector<int>& a, int size, int key, bool& found, int& loc)
{
    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            found = true;
            loc = i;
            return;
        }
    }
    found = false;
}
