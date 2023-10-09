from typing import List

def get_accumulated_days() -> List[int]:
    days_in_months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    accumulated_days = [0]
    counter = 0

    for day in days_in_months:
        counter += day
        accumulated_days.append(counter)

    return accumulated_days


ACCUMULATED_DAYS = get_accumulated_days()


def get_day_in_year(month: int, day: int) -> int:
    return ACCUMULATED_DAYS[month - 1] + day


n = int(input())

for t in range(n):
    start_month, start_day, initial_bacteria, end_month, end_day = (
        int(x) for x in input().split()
    )

    days = get_day_in_year(end_month, end_day) - get_day_in_year(start_month, start_day)

    ans = initial_bacteria * 2**days

    print(ans)
