import time


def count_helium(container_structure):
    start = time.time_ns()
    count = 0
    left_bound = 0
    right_bound = len(container_structure) - 1
    max_left_bound_reached = False
    max_right_bound_reached = False
    while left_bound < right_bound:
        if not max_left_bound_reached:
            index_shift = 1
            temp_count = 0
            while left_bound + index_shift < right_bound and \
                    container_structure[left_bound + index_shift] < container_structure[left_bound]:
                temp_count += container_structure[left_bound] - container_structure[left_bound + index_shift]
                index_shift += 1

            if container_structure[left_bound + index_shift] >= container_structure[left_bound]:
                count += temp_count
                left_bound += index_shift
            else:
                max_left_bound_reached = True

        if not max_right_bound_reached:
            index_shift = 1
            temp_count = 0
            while right_bound - index_shift > left_bound and \
                    container_structure[right_bound - index_shift] < container_structure[right_bound]:
                temp_count += container_structure[right_bound] - container_structure[right_bound - index_shift]
                index_shift += 1
            if container_structure[right_bound - index_shift] >= container_structure[right_bound]:
                count += temp_count
                right_bound -= index_shift
            else:
                max_right_bound_reached = True
    end = time.time_ns()
    print(f"Elapsed time in nanoseconds: {end - start}")
    return count


if __name__ == '__main__':
    assert 6 == count_helium([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
    assert 8 == count_helium([0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2])
    assert 9 == count_helium([4, 2, 0, 3, 2, 5])
    assert 83 == count_helium([6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3])
