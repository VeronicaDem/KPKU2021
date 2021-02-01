from math import sqrt
class Point():
    def __init__(self, x,y,z):
        self.x = x;
        self.y = y;
        self.z = z;
    def dist(self, p):
        return sqrt((p.x - self.x)**2 + (p.y - self.y)**2 + (p.z - self.z)**2)

class Triangular():
    def __init__(self, p1, p2, p3):
        self.p1 = p1;
        self.p2 = p2;
        self.p3 = p3;

    def s(self):
        a = self.p1.dist(self.p2)
        b = self.p2.dist(self.p3)
        c = self.p3.dist(self.p1)

        p = (a + b + c) / 2
        return sqrt(p * (p - a) * (p - b) * (p - c))

x,y,z = input("Введите координаты первой точки").split()
x = float(x)
y = float(y)
z = float(z)
p1 = Point(x,y,z)
x,y,z = input("Введите координаты второй точки").split()
x = float(x)
y = float(y)
z = float(z)
p2 = Point(x, y, z)
x,y,z = input("Введите координаты третьей точки").split()
x = float(x)
y = float(y)
z = float(z)
p3 = Point(x,y,z)

tr = Triangular(p1,p2,p3)
print(tr.s())
