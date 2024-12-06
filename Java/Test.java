
class Test {

    private static int partition(int arr[], int begin, int end) {
        int pivot = arr[end];
        int i = (begin - 1);

        for (int j = begin; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;

                int swapTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = swapTemp;
            }
        }

        int swapTemp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = swapTemp;

        return i + 1;
    }

    private static void quickSort(int arr[], int begin, int end) {
        if (begin < end) {
            int partitionIndex = partition(arr, begin, end);

            quickSort(arr, begin, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, end);
        }
    }

    private static long test() {
        int totalItems = 10000000;

        int arr[] = new int[totalItems];
        for (int i = 0; i < totalItems; i++) {
            arr[i] = (int) (Math.random() * totalItems);
        }

        long startTime = System.currentTimeMillis();
        quickSort(arr, 0, totalItems - 1);
        long duration = System.currentTimeMillis() - startTime;

        System.out.println(duration + " ms");
        return duration;
    }

    public static void main(String[] args) {
        System.out.println("====== Java ======");

        long totalDuration = 0;
        int runs = 10;
        for (int i = 0; i < runs; i++) {
            long duration = test();
            totalDuration += duration;
        }
        System.out.println("Total duration: " + totalDuration + " ms");
        System.out.println("Average duration: " + (totalDuration / runs) + " ms");
    }
};
