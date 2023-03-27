import numpy as np
import subprocess

def run_test(size: int):
    args = set()
    minimum = np.iinfo(np.int32).min
    maximum = np.iinfo(np.int32).max
    while len(args) < size:
        args.add(np.random.randint(minimum, maximum))
    inputs = " ".join(str(i) for i in np.random.choice(list(args), size, replace=False))
    output = subprocess.run(["./push_swap", inputs], capture_output=True)
    steps = len(output.stdout.splitlines())
    grade = "OK"
    if (size < 501):
        if (steps >= 5500):
            grade = "KO"
    elif (size < 101):
        if (steps >= 700):
            grade = "KO"
    elif (size < 6):
        if (steps >= 13):
            grade = "KO"
    elif (size < 4 and steps >= 3):
        grade = "KO"
    print(f"Size {size: 3d}, Steps: {steps: 8d}, Grade: {grade}",  end="")
    result = subprocess.run(["./checker_linux", inputs], input= output.stdout, capture_output=True)
    print(f", Sorted: {result.stdout.decode()[:-1]}", end="")
    # result = subprocess.run(["./checker", inputs], input= output.stdout, capture_output=True)
    # print(f", MyChecker: {result.stdout.decode()[:-1]}", end="")
    print()

def main(seed: int, max_range: int, max_repeat: int):
    iteration = 1
    np.random.seed(seed)
    for size in range(1, max_range + 1):
        for _ in range(max_repeat):
            print(f"Iteration: {iteration: 4d}, ", end="")
            run_test(size)
            iteration += 1
    run_test(1000)
    iteration += 1
    run_test(3141)
    iteration += 1
    run_test(10000)

if __name__ == "__main__":
    main(42, 750, 1)
    # main(42, 750, 5)  # Took about 1h30m to run
