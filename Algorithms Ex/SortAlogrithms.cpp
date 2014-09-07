#include <iostream>
#include <ctime>

using namespace std;

inline void swap(int &m, int &n)
{
    int tmp = m;
    m = n;
    n = tmp;
}
void print_array(int *data, size_t size)
{
    for (int i = 0; i < size; i++)
        cout << data[i] << "  ";
    cout << endl;
}
void shell_sort(int *data, size_t size)
{
    for ( int gap = size / 2; gap > 0; gap /= 2 ) {
        for ( int i = gap; i < size; i++ ) {
            int temp = data[i];
            int j = 0;
            for( j = i; j >= gap && data[j - gap] > temp; j -= gap ) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}
void insert_sort(int *data, size_t size)
{
    for( int i = 1; i < size; i++ ) {
        int j = i;
        int temp = data[i];
        while( j > 0 && data[j-1] > temp ) {
            data[j--] = data[j-1];
        }
        data[j] = temp;
    }
}
void selection_sort(int *data, size_t size)
{
    int i(0), j(size - 1);
    while ( i < j ) {
        int m(i), n(j), max(data[i]), min(data[i]);
        for ( int k = i+1; k <= j; k++ ) {
            if ( data[k] > max ) {
                n = k;
                max = data[k];
            } else if ( data[k] < min) {
                m = k;
                min = data[k];
            }
        }
        data[m] = data[i];  data[i++] = min;
        data[n] = data[j];  data[j--] = max;
    }
}
int quick_sort_recursive(int *data, size_t size)
{
	int pivot(size-1), i(0), j(size-1), mid(0);
	if ( size < 2 )
		return -1;
	for( ; i < j; i++, j-- ) {
		if ( data[i] > data[pivot] && data[j] < data[pivot] ) {
			swap( data[i], data[j] );
		} else if ( data[i] > data[pivot] ) {
			--i;
		} else if ( data[j] < data[pivot] )  {
			++j;
		}
	}
	mid = i>j?i:j;
	swap( data[pivot], data[mid] );
	quick_sort_recursive( data, mid );
	quick_sort_recursive( data + mid, size-mid );
	return 0;
}

int main()
{
    int data[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
    clock_t start,stop;
    start = clock();
    //shell_sort(data,16);
    //insert_sort(data,16);
    //selection_sort(data, 16);
    quick_sort_recursive(data, 16);
    stop = clock();
    cout << "Time consumed: " << ( stop - start ) << "ms" << endl;
    print_array(data, 16);
    return 0;
}
