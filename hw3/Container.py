from Figure import Figure
from FigureFabric import FigureFabric


class Container:
    def __init__(self):
        self.cont = []

    def input(self, fptr) -> None:
        for line in fptr:
            self.cont.append(FigureFabric.generic_init_input(line))

    def input_random(self, num_figures) -> None:
        for i in range(num_figures):
            self.cont.append(FigureFabric.generic_init_random())
            print(self.cont[-1].print())

    def output(self, fptr) -> None:
        fptr.write(f"Container contains {len(self.cont)} elements.\n")
        for i, figure in enumerate(self.cont):
            fptr.write(f"{i}. ")
            figure.output(fptr)

    def perimeter_sum(self) -> float:
        sum = 0.0
        for figure in self.cont:
            sum += figure.perimeter()
        return sum

    def shaker_sort(self):
        cont = self.cont
        n = len(cont)
        swapped = True
        start = 0
        end = n - 1
        while swapped == True:
            swapped = False
            for i in range(start, end):
                if cont[i].perimeter() > cont[i + 1].perimeter():
                    cont[i], cont[i + 1] = cont[i + 1], cont[i]
                    swapped = True
            if swapped == False:
                break
            swapped = False
            end = end - 1
            for i in range(end - 1, start - 1, -1):
                if cont[i].perimeter() > cont[i + 1].perimeter():
                    cont[i], cont[i + 1] = cont[i + 1], cont[i]
                    swapped = True
            start = start + 1
