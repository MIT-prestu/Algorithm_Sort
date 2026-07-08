#pragma once


#include <stdio.h>
#include <assert.h>



void InserSort(int* arr, int n);

void ShellInsert(int* arr, int n);

void SelectInsert(int* arr, int n);

void AdjustDown(int* arr, int parent, int size);
void HeapSort(int* arr, int n);

void BubbleSort(int* arr, int n);

int GetMidNum(int* arr, int left, int right);
//Hoare
int PartSort1(int* arr, int left, int right);
//Pit-Digging Method
int PartSort2(int* arr, int left, int right);
//Front-Rear Pointers
int PartSort3(int* arr, int left, int right);

void QuickSort(int* arr, int left, int right);
