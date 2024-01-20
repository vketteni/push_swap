import sys, os, random

RANDOM_SIZE = 30

def print_stacks(stack_a, stack_b, show_pointers=False):
    if (stack_a):
        max_length = max(len(str(element[0])) for element in stack_a)
    print()
    print("\tstack_1\t\tstack_2")
    for i in range(max(len(stack_a), len(stack_b))):
        print("\t", end="")
        if (show_pointers):
            print(f"({stack_a[i][1] if i < len(stack_a) else '0 '}) <-", end="")
        if i < len(stack_a):
            print(f"{f'{stack_a[i][3]}[ {stack_a[i][0]} ]'.ljust(max_length + 6)}", end="")
            
            f"{stack_a[i][3]}[ {stack_a[i][0]} ]"
        else:
            print("[   ]", end="")  # Pad for shorter stack
        if (show_pointers):
            print(f"-> ({stack_a[i][2] if i < len(stack_a) else '0 '})", end="")
        print("\t\t", end="")

        if (show_pointers):
            print(f"\t({stack_b[i][1] if i < len(stack_b) else '0 '}) <-", end="")
        if i < len(stack_b):
            print(f"{stack_b[i][3]}[ {stack_b[i][0]} ]", end="")
        else:
            print("[   ]", end="")
        if (show_pointers):
            print(f"-> ({stack_b[i][2] if i < len(stack_b) else '0 '})", end="")
        print()
    print()

# print stack element values on a line
def print_line(stack):
    for element in stack:
        print(element[0], end=" ")
    print()

def sa(stack):
    if len(stack) > 1:
        stack[0], stack[1] = stack[1], stack[0]

def sb(stack):
    sa(stack)

def ss(stack_a, stack_b):
    sa(stack_a)
    sb(stack_b)

def pa(stack_a, stack_b):
    if stack_b:
        stack_a.insert(0, stack_b.pop(0))

def pb(stack_a, stack_b):
    pa(stack_b, stack_a)

def ra(stack):
    if stack:
        stack.append(stack.pop(0))

def rb(stack):
    ra(stack)

def rr(stack_a, stack_b):
    ra(stack_a)
    rb(stack_b)

def rra(stack):
    stack.insert(0, stack.pop())

def rrb(stack):
    rra(stack)

def rrr(stack_a, stack_b):
    rra(stack_a)
    rrb(stack_b)
def init_stack(stack, numbers):
    for i, element in enumerate(numbers):
        previous_pointer = "0 " if i == 0 else f"p{i-1}"  # Use symbolic pointers
        next_pointer = "0 " if i == len(numbers) - 1 else f"p{i+1}"
        own_pointer = f"p{i}"
        stack.append((element, previous_pointer, next_pointer, own_pointer))
    return (stack)
# Get numbers as command-line arguments
numbers = [(int(arg)) for arg in sys.argv[1:]]
# Initialize stacks
stack_a = []
init_stack(stack_a, numbers)

stack_b = []       # Stack B starts empty

print_stacks(stack_a, stack_b)  # Print initial stacks

total_instructions = ""
stack_a_copy = stack_a.copy()  # Copy stack to check if it's sorted
stack_b_copy = stack_b.copy()
while True:
    instruction = input("Enter instruction (or 'q' to quit): ")
    if instruction == 'q':
        break
    instructions = instruction.split()
    for instruction in instructions:
        # Execute instruction
        if instruction == "sa":
            sa(stack_a)
        elif instruction == "sb":
            sb(stack_b)
        elif instruction == "ss":
            ss(stack_a, stack_b)
        elif instruction == "pa":
            pa(stack_a, stack_b)
        elif instruction == "pb":
            pb(stack_a, stack_b)
        elif instruction == "ra":
            ra(stack_a)
        elif instruction == "rb":
            rb(stack_b)
        elif instruction == "rr":
            rr(stack_a, stack_b)
        elif instruction == "rra":
            rra(stack_a)
        elif instruction == "rrb":
            rrb(stack_b)
        elif instruction == "rrr":
            rrr(stack_a, stack_b)
        elif instruction == "re":
            stack_a = stack_a_copy.copy()
            stack_b = stack_b_copy.copy()
            total_instructions = ""
        elif instruction == "cl":
            os.system("clear")
        elif instruction == "random":
            stack_a, stack_b = [], []
            stack_a = init_stack(stack_a, random.sample(range(0, RANDOM_SIZE), RANDOM_SIZE))
            stack_a_copy = stack_a.copy()
            stack_b_copy = stack_b.copy()
        elif instruction == "print":
            print_line(stack_a)
        else:
            print("Invalid instruction")
        if (instruction != "re" and instruction != "cl"):
            total_instructions += instruction + " "

    print(f"[{total_instructions}] : {len(total_instructions.split())}")

    print_stacks(stack_a, stack_b)  # Print updated stacks
