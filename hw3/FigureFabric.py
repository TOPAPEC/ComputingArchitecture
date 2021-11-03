import random

from Circle import Circle
from Rectangle import Rectangle
from Triangle import Triangle
from Figure import Figure


class FigureFabric:
    @staticmethod
    def generic_init_input(line: str):
        args = line.split()
        type, color = int(args[0]), int(args[1])
        if type == 1:
            figure = Rectangle()
        elif type == 2:
            figure = Triangle()
        elif type == 3:
            figure = Circle()
        else:
            print("Type number error, unable to create a figure")
            return None
        figure.input(args[2:])
        figure.color = Figure.color_dict[color]
        return figure

    @staticmethod
    def generic_init_random():
        type, color = random.randint(1, 3), random.randint(0, 6)
        if type == 1:
            figure = Rectangle()
        elif type == 2:
            figure = Triangle()
        elif type == 3:
            figure = Circle()
        figure.input_random()
        figure.color = Figure.color_dict[color]
        return figure
