#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void DataInitialization();
void DataEntry();
void DataReading(string fileName);
void Print();
bool DataCleaning();
void DataChange();
void Copy();
int AmountOfData();
void DeleteData();
void AddData();
void SaveData(string fileName);