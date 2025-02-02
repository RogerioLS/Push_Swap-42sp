<div align = center>

# 🔃 Push Swap | 42 SP

![Norminette](https://github.com/RogerioLS/Push_Swap-42sp/actions/workflows/norminette.yml/badge.svg)
![Build](https://github.com/RogerioLS/Push_Swap-42sp/actions/workflows/build.yml/badge.svg)
![Tester Roger](https://github.com/RogerioLS/Push_Swap-42sp/actions/workflows/tester_roger-42sp.yml/badge.svg)
![Tester Gui](https://github.com/RogerioLS/Push_Swap-42sp/actions/workflows/tester_gui-42sp.yml/badge.svg)
![Tester Vinicius](https://github.com/RogerioLS/Push_Swap-42sp/actions/workflows/tester_vinicius-42sp.yml/badge.svg)
![Static Badge](https://custom-icon-badges.demolab.com/badge/Push_Swap-42-blue?logo=repo)
![42 São Paulo](https://custom-icon-badges.demolab.com/badge/42-SP-1E2952)
![License](https://custom-icon-badges.demolab.com/github/license/RogerioLS/Push_Swap-42sp?logo=law&color=dark-green)
![Code size in bytes](https://custom-icon-badges.demolab.com/github/languages/code-size/RogerioLS/Push_Swap-42sp?logo=file-code&color=dark-green)
![Top language](https://custom-icon-badges.demolab.com/github/languages/top/RogerioLS/Push_Swap-42sp?color=dark-green)
![Last commit](https://custom-icon-badges.demolab.com/github/last-commit/RogerioLS/Push_Swap-42sp?logo=history&color=dark-green)
![Repo size](https://custom-icon-badges.demolab.com/github/repo-size/RogerioLS/Push_Swap-42sp?logo=database)
![Languages](https://custom-icon-badges.demolab.com/github/languages/count/RogerioLS/Push_Swap-42sp?logo=command-palette&color=red)
![GitHub repo file count (file type)](https://custom-icon-badges.demolab.com/github/directory-file-count/RogerioLS/Push_Swap-42sp%2Fsources?logo=file&label=files%20sources&color=8602b1)
![Discord](https://custom-icon-badges.demolab.com/discord/1114673462859006044?&logo=comments&label=testemunhas%20de%20vim&color=ffbe3a)
![](https://img.shields.io/github/forks/RogerioLS/Push_Swap-42sp)

</div>

---

- Actual Status : finished.
- Result        : Approved with 100 points ✅

---

### 🔷 The Mandatory part:
1. We have at our disposal, two stacks named `a` and `b`.
2. Create a program that takes as parameters, a random set of numbers (negative or positive), without duplicates. Our program has to handle both types of inputs: as a variable number of command line arguments; a string, i.e. "numbers between quotation marks, seperated by a space".
3. Implement an algorithm, that sorts in ascending order, the input of random numbers.
4. Our algorithm will consist of swap, rotate, reverse rotate and push operations. 
5. After taking in an input of numbers, and passing them through our sorting algorithms, our program will output the list of operations (instructions).

---

### 🔷 Operations:

| Operation | Code | Definition |
| --- | --- | --- |
| **Push** | `pa`, `pb` | The topmost number in one stack is pushed to the top of the other stack. |
| **Swap** | `sa`, `sb`, `ss` | The two topmost numbers in a given stack swap places. `ss` swaps elements in both stacks individually at the same time. |
| **Rotate** | `ra`, `rb`, `rr` | All elements in a given stack are shifted one position up, so that the first element becomes the last one, the second becomes the first, and so on. `rr` rotates both stacks at the same time. |
| **Reverse-rotate** | `rra`, `rrb`, `rrr` | All elements in a given stack are shifted one position below, so that the last element becomes the first one, the second but last one becomes the last one, and so on. `rrr` reverse-rotates both stacks at the same time. |

<img align="center" src="https://royalbox.com.br/github/push_swap_moves.png">

---

### 🔷 Using a push_swap visualizer
1. I can't recommend this enough. 
2. It was very useful for me to see what my code was doing during its implementation, and help with a lot of my debugging. 
3. The one I used can be found here https://github.com/o-reo/push_swap_visualizer

Make sure you follow this sequence:
1. git clone the repository inside your main push_swap directory, where your push_swap executable will be. 
2. Install the required packages as stated on the README.md (do `sudo apt update` first to make sure you have the latest information about available packages)
3. Then, to install a package, do e.g. `sudo apt install cmake`
4. cd inside `/push_swap_visualizer` 
5. `mkdir build`
6. cd into `build` then:
	- `cmake ..`
	- `make`
	- Like myself, you might run into some build errors in your terminal. For example, you're missing a OpenGL package. I just chat gpt'd all the error messages and followed the installation commands 😅
7. After a sucessfull build of `cmake ..` and `make`:
	- run `./bin/visualizer` and a window of the program should apear. 
	- change the "push_swap file path" to `../../push_swap`

---

### 🔷 Using the checker provided by 42
1. Download the correct file from the subject page, e.g. for Mac, or Linux, inside the same directory as your executable.
2. Running the checker likely won't work, as it won't have the executable permission. Check by typing in the terminal `ls -l`
3. To give it permission, do `chmod +x <filename>`
4. Test your executable against everything we need our push_swap to do:
	- e.g. the correct outputs for all error types
	- e.g. run `ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG `
	- To see how many instructions, run `ARG="4 10 1 3 2"; ./push_swap $ARG | wc -l`
	- For our program to pass the evaluation, it'll have to return `n` size of instructions for sorting `x` number of values:
		- If x = 3 then n <= 3
		- If x = 5 then n <= 12
		- If x = 100 then n < 1500
		- If x = 500 then n < 11500
		- Note: the lesser instructions our algorithm returns, the more evaluation points we will get.

---

### 🔷 Running this code
First off clone this repo. Then compile the program using `make`, and finally pass in a space-separated unordered list of numbers to the program `push_swap`. It will output all the stack operations that it was able to apply sequentially in order to have your list sorted in ascending order.
```bash
git clone https://github.com/RogerioLS/Push_Swap-42sp
cd Push_Swap-42sp
make
./bin/push_swap 42 -42 1 2 3 0 472834 2347 -66573567
```
Obs.: Numbers can range from -2147483648 to 2147483647. Duplicates are not allowed! Try it on and see what happens :)

---

### What is an algorithm?
- A set of intructions to solve a problem.


### What is the concept of complexity?
- Algorithm analysis: 
	Analyzing the algorithm's step by step instructions to understand their performance.
- Algorithm efficiency:
	Looking at how quickly an algorithm solves a problem, and the resources it uses up, like time and memory.
- Asymptotic Notation: 
	Using mathematical notations like Big O, Omega and Theta to look at the algorithm's running time, as the problem becomes larger.
- Time complexity:
	Using Big O, looking at the best, worst, and average case for an algorithm to complete.
- Space complexity:
	Using Big 0, looking at the amount of memory space an algorithm uses.

---

> [!NOTE]
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.