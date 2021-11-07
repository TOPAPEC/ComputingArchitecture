import math
import random

from Figure import Figure


class Circle(Figure):
    def __init__(self):
        super().__init__()
        self.x_center, self.y_center, self.radius = 0, 0, 0

    def input(self, args: list[str]):
        self.x_center, self.y_center, self.radius = \
            int(args[0]), int(args[1]), int(args[2])

    def input_random(self):
        self.x_center, self.y_center, self.radius = \
            random.randint(0, 20), random.randint(0, 20), random.randint(0, 20)

    def output(self, fptr) -> None:
        fptr.write(f'It is Circle: x_center = {self.x_center}, y_center = {self.y_center}, radius = {self.radius}. '
                   f'Perimeter = {self.perimeter()}. Color = {self.color}\n')

    def print(self) -> str:
        return (f'It is Circle: x_center = {self.x_center}, y_center = {self.y_center}, radius = {self.radius}. '
         f'Perimeter = {self.perimeter()}. Color = {self.color}\n')

    def perimeter(self) -> float:
        return 2.0 * math.pi * self.radius;
