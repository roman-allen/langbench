import random
import time

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

def test():
    total_items = 10000000
    arr = [random.randint(0, total_items - 1) for _ in range(total_items)]

    start_time = time.time()
    quickSort(arr, 0, total_items - 1)
    end_time = time.time()

    duration = (end_time - start_time) * 1000
    print(f"{duration:.2f} ms")
    return duration

def main():
    print("====== Python ======")

    total_duration = 0
    runs = 10
    for _ in range(runs):
        duration = test()
        total_duration += duration

    print(f"Total duration: {total_duration:.2f} ms")
    print(f"Average duration: {total_duration / runs:.2f} ms")

if __name__ == "__main__":
    main()