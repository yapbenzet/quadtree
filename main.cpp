#include "include/point.hpp"
#include "include/node.hpp"
#include "include/region.hpp"
#include "include/quad_tree.hpp"
#include <iostream>
#include <random>
#include <chrono>

int main()
{
	const int bucket_size = 5;
	const long point_count = 1e6;

	Point<long double> center(0,0);
	Region<long double> region(512,center);
	quad_tree<long double> quadtree(region,bucket_size);

	std::mt19937_64 machine;
	std::uniform_real_distribution<long double> distrubition(-512, 512);

	std::cout << "Allocating Space...\n";
	std::vector<Point<long double>> points(point_count);
	std::cout << "Space allocated...\nGenerating random data...\n";
	for (auto& i : points)
	{
		i = Point<long double>(distrubition(machine), distrubition(machine));
	}
	std::cout << "Random data generated\nInserting...\n";
	using namespace std::chrono;

	auto begin = high_resolution_clock::now();

	for (auto& i : points)
	{
		quadtree.insert(i);
	}
	auto end = high_resolution_clock::now();
	std::cout << "Inserted\n";
	duration<long double> duration = end - begin;

	std::cout << "Duration:"<< duration.count() << std::endl;
	std::cin.get();
	std::cout << quadtree;

	std::cin.get();
	return 0;
    
}
