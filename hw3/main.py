import random
import sys
import string
import triangle, Rectangle, circle, container
from datetime import datetime

if __name__ == '__main__':
    random.seed(datetime.now())
    cont = container()
    if len(sys.argv) != 5:
        print('Wrong commandline arguments! Can\'t proceed further.')
        exit()
    elif sys.argv[1] == '-f':
        input_file = sys.argv[2]
        output_file_figures = sys.argv[3]
        output_file_perimeter_sum = sys.argv[4]
        fptr = open(input_file)
        cont.input(fptr)
    elif sys.argv[1] == '-n':
        number_of_figures = int(sys.argv[2])
        output_file_figures = sys.argv[3]
        output_file_perimeter_sum = sys.argv[4]
        cont.input_random(number_of_figures)
    else:
        print('Incorrect input. Please enter '
              'your data again according to task guidelines.')
        exit()
    cont.shaker_sort()
    output_fptr_figures = open(output_file_figures)
    output_fptr_perimeter_sum = open(output_file_perimeter_sum)
    cont.output(output_fptr_figures)
    output_fptr_perimeter_sum.write(f"Perimeter sum = {str(cont.perimeter_sum())}")