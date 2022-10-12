#pragma once
#include <iostream>
#include <vector>

using namespace std;

int max_position(vector<int>, int, int, int&);
void arrange_positive_negative(vector<int>&);
void merge_sort(vector<int>&);
int find_vector_range(vector<int>);
void reverse_counting_sort(int, vector<int>);
void max_heapify(vector<int>&, int, int);
void build_max_heap(vector<int>&);
int heap_extract_max(vector<int>&);
int search_heap(vector<int>&,int,int);
void delete_heap(vector<int>&);
void heap_judgement(vector<int>&);
int heap_judgement(vector<int>&,int,int);