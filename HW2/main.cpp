using namespace std;
#include <ctime>;
#include <iostream>;

int linearSearch( int* arr, int N, int value ){
    for ( int i = 0; i < N; i++)
        if ( arr[i] == value )
            return i;
    return -1;
}

int binarySearch( int* arr, int N, int value ){
    int low = 0, high = N - 1;
    while ( low <= high ) {
        int mid = (low + high) / 2;
        if ( arr[ mid ] < value )
            low = mid + 1;
        else if ( arr[ mid ] > value )
            high = mid - 1;
        else
            return mid;
        }
    return -1;
}

int main(){
    unsigned long int keyFound = -1;
    unsigned long size = 100000000;
    unsigned long loopSize = 1000000;
    int* arr = new int[size];

    //creating the array
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }

    double duration;
    clock_t startTime = clock();

    for (int x = 0; x < loopSize; x++)
    {
        //keyFound = linearSearch(arr, size, -1); //for array not having the key
        keyFound = binarySearch(arr, size, 0.01*size); // array has the key at 1% mark
    }

    if (keyFound != -1)
        cout << "Key Found!" << endl;
    else
        cout << "Key Not Found!" << endl;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete [] arr;

return 0;
}
