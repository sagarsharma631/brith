# Sudoku Solver
Brute force approach (backtracking) having exponential runtime is mostly used to create a Sudoku solver. Although this approach is easiest to implement but it suffers due to its runtime.
Most of the Sudoku do not need to be solved using backtracking. They can be solved by using some techniques which a normal person uses while solving a Sudoku. I have implemented these approaches before 
utilizing backtracking.
My intention is to compare runtime between following 2 approaches: 
- **Bactracking** 
- **Optimizations, then utilizing backtracking**

**NOTE** : Henceforth, approaches will be called as optimizations
# Optimizations Implemented 
### Naked Single Optimization
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| 2  | 2  | 2  | 2  | 2  | 2  | 2  | 2  | 2  |
| 3  | 3  | 3  | 3  | 3  | 3  | 3  | 3  | 3  |
| 4  | 4  | 4  | 4  | 4  | 4  | 4  | 4  | 4  |
| 5  | 5  | 5  | 5  | 5  | 5  | 5  | 5  | 5  |
| 6  | 6  | 6  | 6  | 6  | 6  | 6  | 6  | 6  |
| 7  | 7  | 7  | 7  | 7  | 7  | 7  | 7  | 7  |
| 8  | 8  | 8  | 8  | 8  | 8  | 8  | 8  | 8  |
| 9  | 9  | 9  | 9  | 9  | 9  | 9  | 9  | 9  |
### Locked Candidate Optimization
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| 2  | 2  | 2  | 2  | 2  | 2  | 2  | 2  | 2  |
| 3  | 3  | 3  | 3  | 3  | 3  | 3  | 3  | 3  |
| 4  | 4  | 4  | 4  | 4  | 4  | 4  | 4  | 4  |
| 5  | 5  | 5  | 5  | 5  | 5  | 5  | 5  | 5  |
| 6  | 6  | 6  | 6  | 6  | 6  | 6  | 6  | 6  |
| 7  | 7  | 7  | 7  | 7  | 7  | 7  | 7  | 7  |
| 8  | 8  | 8  | 8  | 8  | 8  | 8  | 8  | 8  |
| 9  | 9  | 9  | 9  | 9  | 9  | 9  | 9  | 9  |

# Code

# References
