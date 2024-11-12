#include <iostream>
using namespace std;

class CPU
{
	string model;
	double Ghz;
public:
	CPU() = default;
	CPU(const char* mod, double g)
	{
		model.append(mod);
		Ghz = g;
	}
	void Print()
	{
		cout << "CPU: " << model << " " << Ghz << "Ghz" << endl;
	}
};

class RAM
{
	string model;
	double memory;
public:
	RAM() = default;
	RAM(const char* mod, double m)
	{
		model.append(mod);
		memory = m;
	}
	void Print()
	{
		cout << "RAM: " << model << " " << memory << "Gb" << endl;
	}
};

class SSD
{
	string model;
	double val;
public:
	SSD() = default;
	SSD(const char* mod, double v)
	{
		model.append(mod);
		val = v;
	}
	void Print()
	{
		cout << "SSD: " << model << " " << val << endl;
	}
};

class GPU
{
	string model;
public:
	GPU() = default;
	GPU(const char* mod)
	{
		model = mod;
	}
	void Print()
	{
		cout << "GPU: " << model << endl;
	}
};

class Mouse
{
	string model;
	string type;
public:
	Mouse() = default;
	Mouse(const char* mod, const char* t)
	{
		model = mod;
		type = t;
	}
	void Print()
	{
		cout << "Mouse: " << model << ", " << type;
	}
};

class Laptop
{
	CPU cpu;
	RAM ram;
	SSD ssd;
	GPU gpu;
	Mouse* mouse;
public:
	Laptop() = default;
	Laptop(const char* cpuM, double g, const char* ramM, double mem, const char* ssdM, double v, const char* gpuM, Mouse* m) :cpu(cpuM, g), ram(ramM, mem), ssd(ssdM, v)
	{
		gpu = gpuM;
		mouse = m;
	}
	void Print()
	{
		cpu.Print();
		ram.Print();
		ssd.Print();
		gpu.Print();
		mouse->Print();
		cout << endl << endl;
	}
};

int main()
{
	Mouse myMouse("Samsung", "wireless");
	Laptop* myLaptop = new Laptop("Intel", 4.5, "DDR4", 16, "Samsung", 512, "NVIDIA", &myMouse);
	myLaptop->Print();
	delete myLaptop;
	myMouse.Print();
}
