using System;

class Test
{
    private static int Partition(int[] arr, int begin, int end)
    {
        int pivot = arr[end];
        int i = begin - 1;

        for (int j = begin; j < end; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                (arr[i], arr[j]) = (arr[j], arr[i]);
            }
        }

        (arr[i + 1], arr[end]) = (arr[end], arr[i + 1]);
        return i + 1;
    }

    private static void QuickSort(int[] arr, int begin, int end)
    {
        if (begin < end)
        {
            int partitionIndex = Partition(arr, begin, end);

            QuickSort(arr, begin, partitionIndex - 1);
            QuickSort(arr, partitionIndex + 1, end);
        }
    }

    private static long RunTest()
    {
        int totalItems = 10000000;
        int[] arr = new int[totalItems];
        Random random = new Random();

        for (int i = 0; i < totalItems; i++)
        {
            arr[i] = random.Next(totalItems);
        }

        long startTime = Environment.TickCount64;
        QuickSort(arr, 0, totalItems - 1);
        long duration = Environment.TickCount64 - startTime;

        Console.WriteLine(duration + " ms");
        return duration;
    }

    public static void Main()
    {
        Console.WriteLine("====== C# ======");

        long totalDuration = 0;
        int runs = 10;
        for (int i = 0; i < runs; i++)
        {
            long duration = RunTest();
            totalDuration += duration;
        }
        Console.WriteLine("Total duration: " + totalDuration + " ms");
        Console.WriteLine("Average duration: " + (totalDuration / runs) + " ms");
    }
}