import random

from Figure import Figure


class Triangle(Figure):
    def __init__(self):
        super().__init__()
        self.x1, self.y1, self.x2, self.y2, self.x3, self.y3 = 0, 0, 0, 0, 0, 0

    def input(self, args: list[str]):
        self.x1, self.y1, self.x2, self.y2, self.x3, self.y3 = \
            int(args[0]), int(args[1]), int(args[2]), int(args[3]), int(args[4]), int(args[5])

    def get_side1(self):
        return ((self.x1 - self.x2) * (self.x1 - self.x2) + (self.y1 - self.y2) * (self.y1 - self.y2)) ** (1 / 2)

    def get_side2(self):
        return ((self.x1 - self.x3) * (self.x1 - self.x3) + (self.y1 - self.y3) * (self.y1 - self.y3)) ** (1 / 2)

    def get_side3(self):
        return ((self.x3 - self.x2) * (self.x3 - self.x2) + (self.y3 - self.y2) * (self.y3 - self.y2)) ** (1 / 2)

    def check_if_triangle_is_correct(self):
        return (self.get_side1() + self.get_side2() > self.get_side3()) and \
               (self.get_side1() + self.get_side3() > self.get_side2()) and \
               (self.get_side3() + self.get_side2() > self.get_side1())

    def input_random(self):
        self.x1, self.y1 = random.randint(1, 20), random.randint(1, 20)
        self.x2, self.y2 = random.randint(1, 20), random.randint(1, 20)
        while (self.x1, self.y1) == (self.x2, self.y2):
            self.x2, self.y2 = random.randint(1, 20), random.randint(1, 20)
        self.x3, self.y3 = random.randint(1, 20), random.randint(1, 20)
        while not self.check_if_triangle_is_correct():
            self.x3, self.y3 = random.randint(1, 20), random.randint(1, 20)

    def output(self, fptr) -> None:
        fptr.write(f'It is Triangle: x1 = {self.x1}, y1 = {self.y1}, x2 = {self.x2}, y2 = {self.y2}, x3 = {self.x3},'
                   f' y3 = {self.y3}. Perimeter = {self.perimeter()}. Color = {self.color}\n')

    def print(self) -> str:
        return (f'It is Triangle: x1 = {self.x1}, y1 = {self.y1}, x2 = {self.x2}, y2 = {self.y2}, x3 = {self.x3},'
                   f' y3 = {self.y3}. Perimeter = {self.perimeter()}. Color = {self.color}\n')


    def perimeter(self) -> float:
        return float(self.get_side1() + self.get_side2() + self.get_side3())
