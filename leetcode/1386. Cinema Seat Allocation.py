from typing import List


class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        def book_seat(booked_seats) -> int:
            new_booking = set()
            for i in [2, 4, 6]:
                if (i - 2) not in new_booking:
                    for s in range(i, i + 4):
                        if s in booked_seats:
                            break
                    else:
                        new_booking.add(i)
            return len(new_booking)

        reservedSeats.sort()
        booked_seats = set()

        ans = 0
        empty_rows = n
        for i, (r, c) in enumerate(reservedSeats):
            if i > 0 and reservedSeats[i - 1][0] != r:
                ans += book_seat(booked_seats)
                empty_rows -= 1
                booked_seats.clear()
            booked_seats.add(c)

        if len(booked_seats) > 0:
            ans += book_seat(booked_seats)
            empty_rows -= 1
        ans += 2 * empty_rows
        return ans


