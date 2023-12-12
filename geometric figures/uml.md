# Geometric figures
For [PlantUML](//www.plantuml.com/plantuml/png/fP91IiD068NtSugVhDhQW5iRXNg3OWzGfiaO2fC4PoOh5TID6vTk1OzGf85AiMVuSoE7SSfqXXgKRlDUtl--nuobeaBL1ISffrB2zAQcWi4j0OZXcbTKWLnaB254VpcnSiy9S06d_SI8rfupDTL2hmzfLKgL-98DE2nEc5WKJ37XT6EOLnK7QNFTRNttdjZULonLjCnvK9tfc6osH-2CUq73q6wvOBG3jkS25cF_3NRGIJlu2wxB3_hvx1CgAEUCLxcWXSTlG6Tpcbbwtzgzm33Cq9EScKtSXCONrF8tkjI-mmCSlO_D3bh-3EEUGuIlk6sViMaVy0lN-1d1-LqSw-_lkCKLhjidR73JlaIxjpy2VCDb-uWRBQoqwGENvjU6UFFz9zhrwKWVipAh2_uD)
```
@startuml
class Square {
  - float side;


  + Square(float side = 0);

  + float getSide() const;
  + float getSquare() const;
  + float getPerimeter() const;

  + bool setSide(float side);
}

class Rectangle {
  - float second_side;


  + Rectangle(float side, float second_side = 0) : Square(side);

  + float getSecondSide() const;
  + float *getSquare() const;
  + float *getPerimeter() const;

  + bool setSecondSide(float second_side);
}

class Parallelogram {
  - float angle_bad;


  + Parallelogram(float side, float second_side, float angle_bad = 90) : Rectangle(side, second_side);

  + float getAngle() const;
  + float **getSquare() const;
  + float *getPerimeter() const;

  + bool setAngle(float angle_bad);
}

Rectangle "Дочерний" <|-- "Родитель" Square : Наследование
Parallelogram "Дочерний" <|-- "Родитель" Rectangle : Наследование
@enduml
```
