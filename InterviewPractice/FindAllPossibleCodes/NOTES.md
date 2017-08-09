Let there be an encoding system, where a=1, b=2, c=3,....z=26.
Given a numerical string, find all possible codes that string can generate.
Give a count as well as print the strings.

---

Analysis:

An roman letter can map to either one or two digits.
We can use a recursive approach:
- Parse 1 letter, then recursively parse the rest of the string.
- Parse 2 letter, then recursively parse the rest of the string.

