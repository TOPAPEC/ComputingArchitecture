import random
import sys
from Container import Container
from datetime import datetime

if __name__ == '__main__':
    begin_time = datetime.now()
    random.seed(None)
    cont = Container()
    if len(sys.argv) != 5:
        print('Wrong command line arguments! Can\'t proceed further.')
        exit()
    elif sys.argv[1] == '-f':
        input_file = sys.argv[2]
        output_file_figures = sys.argv[3]
        output_file_perimeter_sum = sys.argv[4]
        with open(input_file) as fptr:
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
    with open(output_file_figures, 'w') as output_file:
        cont.output(output_file)
    with open(output_file_perimeter_sum, 'w') as output_file:
        output_file.write(f"Perimeter sum = {str(cont.perimeter_sum())}")

    print(f"Execution time is {datetime.now() - begin_time}")