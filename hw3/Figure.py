import random

from typing import Type

from Rectangle import Rectangle


class Figure:
    color_dict = [
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "dark_blue",
        "purple"
    ]

    def __init__(self):
        self.color = None

    @staticmethod
    def generic_init_input(line: str):
        args = line.split()
        type, color = int(args[0]), int(args[1])
        if type == 1:
            figure = Rectangle()
        elif type == 2:
            figure = Triagle()
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
        type, color = random.randint(1, 3), random.randint(0, 7)
        if type == 1:
            figure = Rectangle()
        elif type == 2:
            figure = Triagle()
        elif type == 3:
            figure = Circle()
        figure.input_random()
        figure.color = Figure.color_dict[color]
        return figure

    def input(self, args):
        pass

    def input_random(self):
        pass

    def output(self, fptr):
        pass

    def perimeter(self):
        pass