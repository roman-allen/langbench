#include <iostream>
#include <ctime>
#include <cstdlib>

class Test
{
public:
    static int partition(int *arr, int begin, int end)
    {
        int pivot = arr[end];
        int i = begin - 1;

        for (int j = begin; j < end; ++j)
        {
            if (arr[j] <= pivot)
            {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[end]);
        return i + 1;
    }

    static void quickSort(int *arr, int begin, int end)
    {
        if (begin < end)
        {
            int partitionIndex = partition(arr, begin, end);

            quickSort(arr, begin, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, end);
        }
    }

    static long test()
    {
        int totalItems = 10000000;
        int *arr = new int[totalItems];

        std::srand(std::time(nullptr));

        for (int i = 0; i < totalItems; ++i)
        {
            arr[i] = std::rand() % totalItems;
        }

        clock_t start = clock();
        quickSort(arr, 0, totalItems - 1);
        clock_t end = clock();

        double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
        std::cout << duration << " ms\n";
        return duration;
    }

    static void main()
    {
        std::cout << "====== C++ ======\n";

        long totalDuration = 0;
        int runs = 10;

        for (int i = 0; i < runs; ++i)
        {
            long duration = test();
            totalDuration += duration;
        }

        std::cout << "Total duration: " << totalDuration << " ms\n";
        std::cout << "Average duration: " << (totalDuration / runs) << " ms\n";
    }
};

int main()
{
    Test::main();
    return 0;
}