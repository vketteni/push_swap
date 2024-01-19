from collections import Counter
import sys

def count_elements(input_string):
    # Use Counter to count occurrences of each element
    element_counts = Counter(input_string)

    # Sort elements by their count
    element_counts = dict(sorted(element_counts.items(), key=lambda item: item[1], reverse=True))


    # total amount of elements
    total_elements = sum(element_counts.values())
    # Print the count for each element on a new line
    for element, count in element_counts.items():

        print(f"[{element.capitalize()}: {count}]", end=" ")
    # print total amount of elements
    print(f": {total_elements}", end="")
    print()

# Example usage
if __name__ == "__main__":
    input_string = sys.argv[1:]
    #print(input_string)
    count_elements(input_string)
