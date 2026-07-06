#pragma once


#include <stdio.h>
#include <assert.h>



void InserSort(int* arr, int n);

void ShellInsert(int* arr, int n);

void SelectInsert(int* arr, int n);

void AdjustDown(int* arr, int parent, int size);
void HeapSort(int* arr, int n);

void BubbleSort(int* arr, int n);