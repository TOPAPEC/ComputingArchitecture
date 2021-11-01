import random

from Figure import Figure


class Rectangle(Figure):
    def __init__(self):
        super().__init__()
        self.x_upper_left, self.y_upper_left, self.x_lower_right, self.y_lower_right = 0, 0, 0, 0

    def input(self, args: list[str]):
        self.x_upper_left, self.y_upper_left, self.x_lower_right, self.y_lower_right = \
            int(args[0]), int(args[1]), int(args[2]), int(args[3])

    def input_random(self):
        self.x_upper_left, self.y_upper_left = random.randint(21, 40), random.randint(21, 40)
        self.x_lower_right, self.y_lower_right = random.randint(0, 20), random.randint(0, 20)
        while self.x_lower_right >= self.x_upper_left or self.y_lower_right >= self.y_upper_left:
            self.x_lower_right, self.y_lower_right = random.randint(0, 20), random.randint(0, 20)

    def output(self, fptr) -> None:
        fptr.write(f'It is Rectangle: x_upper_left = {self.x_upper_left}, y_upper_left = {self.y_upper_left}, '
                   f'x_lower_right = {self.x_lower_right}, y_lower_right = {self.y_lower_right}. '
                   f'Perimeter = {self.perimeter()}. Color = {self.color}\n')

    def perimeter(self) -> float:
        return 2 * (abs(self.x_upper_left - self.x_lower_right) + abs(self.y_upper_left - self.y_lower_right))
