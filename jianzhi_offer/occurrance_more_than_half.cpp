#include <iostream>
using namespace std;
bool occurrance_more_than_half( int* array, int length, int& target);
int partition(int* array, int begin, int end);//闭区间
bool occurrance_more_than_half_2( int* array, int length, int& target);
int main(int argc, char** argv){
    int array[] = {1,2,3,3,2,2,2,2};
    int length=sizeof(array)/sizeof(array[0]);
    cout << "length: " << length << endl;
    int target;
    if( occurrance_more_than_half_2( array, length, target ) )
	cout << "success " << target << endl;
    else
	cout << "failure" << target << endl;
    return 0;
}

bool occurrance_more_than_half( int* array, int length, int& target){
    if( array == NULL || length <= 0 )
	return false;

    int i=0,j=length-1, middle=length>>1;
    int pivot;

    pivot=partition(array, i, j);//闭区间
    while( pivot != middle ){
	if( pivot < middle )
	    pivot=partition(array, pivot+1, j );
	else
	    pivot=partition(array, i, pivot-1);
    }
    target=array[pivot];

    i=0;
    int count=0;
    while( i < length ){
	cout << "ee " << array[i] << endl;
	if( array[i] == target ){
	    cout << i << " " << array[i] << endl;
	    ++count;
	}
	++i;
    }
    cout << "count " << count << endl;
    if( count > length>> 1 )
	return true;
    return false;
}
int partition(int* array, int begin, int end){
    int pivot_value=array[begin];
    int i=begin;
    int j=end;
    while( i < j ){
	while( i < j && array[j] >= pivot_value ){
	    --j;
	}
	if( i < j ){
	    array[i]=array[j];
	    ++i;
	}
	while( i < j && array[i] <= pivot_value ){
	    ++i;
	}
	if( i < j ){
	    array[j]=array[i];
	    --j;
	}
    }
    array[i]=pivot_value; //这句代码容易被忘掉
    return i;
}
bool occurrance_more_than_half_2( int* array, int length, int& target){
    if( array == NULL || length <= 0  )
	return false;

    target=array[0];
    int occurrance=1;
    int i;
    for( i=1; i< length; ++i ){
	if( occurrance == 0 ){
	    target=array[i];
	    occurrance=1;
	}else{
	    if( array[i] ==target )
		++occurrance;
	    else
		--occurrance;
	}
    }

    i=0;
    int count=0;
    while( i < length ){
	if( array[i] == target ){
	    ++count;
	}
	++i;
    }
    if( count > length>> 1 )
	return true;
    return false;
}
