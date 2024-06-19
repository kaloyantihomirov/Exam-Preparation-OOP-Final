#include <iostream>

#include <fstream>

#include "SoundFromFile.hpp"
#include "Mix.hpp"
#include "PeriodicSound.hpp"
#include "Sequence.hpp"
#include "Playlist.hpp"

void createBinaryFile()
{
	//float [-1; 1]

	//0.2 0.3 0.4 0.5 0.5 0.7

	std::ofstream out("exampleSound3.dat", std::ios::binary);
	float arr[] = { 0.6f };
	size_t size = sizeof(arr) / sizeof(arr[0]); //6

	out.write((const char*)&arr, sizeof(arr[0]) * size);

	out.close();
}

int main()
{
	//createBinaryFile();

	//SoundFromFile<float, int> sff1("exampleSound1.dat");
	//SoundFromFile<float, int> sff2("exampleSound2.dat");
	//SoundFromFile<float, int> sff3("exampleSound3.dat");

	//sff1.printForDebug();
	//sff2.printForDebug();
	//sff3.printForDebug();

	//std::cout << "------------------------" << std::endl;

	//DigitalSound<float, int>* arr[] = { &sff1, &sff2, &sff3 };

	//Mix<float, int> mix(arr, 3);
	////mix.printForDebug();

	//std::cout << "------------------------" << std::endl;

	//float arrForPeriodicSound[] = { 0.6f, 0.4f, 0.1f, 0.9f };
	//size_t size = sizeof(arrForPeriodicSound) / sizeof(arrForPeriodicSound[0]);

	//PeriodicSound<float, int> ps(arrForPeriodicSound, size, 4);
	////ps.printForDebug();

	//std::cout << "final sequence sound test: " << std::endl;

	//Sequence<float, int> seq(arr, 3);
	//seq.printForDebug();

	//std::cout << "saving seq to file " << std::endl;
	//seq.save("seqFile.bin");
	//std::cout << "creating soundfromfile from the created file..." << std::endl;
	//SoundFromFile<float, int> sffSeq("seqFile.bin");
	//std::cout << "printing the created sound..." << std::endl;
	//sffSeq.printForDebug();

	Playlist pp("ppInfo.txt");

	return 0;
}