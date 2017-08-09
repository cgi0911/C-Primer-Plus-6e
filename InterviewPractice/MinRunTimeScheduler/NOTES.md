Given a task sequence tasks such as ABBABBC, and an integer k, which is the cool down time between two same tasks.
Assume the execution for each individual task is 1 unit.

For example, if k = 3, then tasks BB takes a total of 5 unit time to finish, because B takes 1 unit of time to execute,
then wait for 3 unit, and execute the second B again for another unit of time. So 1 + 3 + 1 = 5.

Given a task sequence and the cool down time, return the total execution time.

Follow up: Given a task sequence and the cool down time, rearrange the task sequence such that the execution time is minimal.

---

