#include "PackageGeneration.h"
#include <iostream>
#include "Package.h"
#include "BaseStation.h"

using namespace std;

PackageGeneration::PackageGeneration(int time, BaseStation* base)
{
	time_ = time;
	base_ = base;
}

void PackageGeneration::Execute() 
{
	Package* package = new Package();
	base_->AddPackage(package);
}
void PackageGeneration::Print()
{
	cerr << "Zaplanowanie wygenerowania pakietu " << time_ << endl;
}
