from cs50 import get_int

# main function
def main():
    # initialize height in 0 to emulates the do while
    height = 0

    # keep asking a valid height value to the customer until type something valid between 1 and 8
    while height < 1 or height > 8:
        height = get_int('Height: ')

    # calling the printing line method per each line in the pyramid
    for i in range(height):
        print_line(height, i)

# print line function
def print_line(height, line_number):
    # increase line_number in 1 because it start in 0
    line_number += 1
    spaces = height - line_number

    # left side
    left = ' ' * spaces + '#' * line_number
    # rigth side
    rigth = '#' * line_number

    print(left + '  ' + rigth)

main()
