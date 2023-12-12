# Geometric figures
For [PlantUML](//www.plantuml.com/plantuml/png/fP91IWCn68NtESLFLssT0RSw2lK6nHwWf3DnA6Gcc6HMAgWRDoxT2XwXI0SgnPxXdniPOoGcr59nc_VoyhutCrAQIjrKdEISAWMJouPA1bS488KBBgW6DIzOHeWvEN1otmjm2eU3p8hENZ8zCK9_0BcebSv2oGLi5yTCpYkccVIwDSo4uA1Shd_Rl7j3NEzpbcjQbpogpd9H5zCV1DuOGIJn5SS6nz_Gxic8nzf_0nxk91xkW-ppWtun_vXAoZdZefIq2ZQmiDCPBTm2eNM_5P8uonmUsMtyd9_U9AeNRdLcVTk6-FTEBZjg-JMG_pLw-8IRxW7RxXRVSOLlFJYvJbDp_e8RNEAgkySMrzrZptrp0uZFkEZkS6s4fJ6zui9URKcu-1-YVPyTwIDM5qt5Fm00)
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


  + Rectangle(float side = 0, float second_side = 0) : Square(side);

  + float getSecondSide() const;
  + float *getSquare() const;
  + float *getPerimeter() const;

  + bool setSecondSide(float second_side);
}

class Parallelogram {
  - float angle_bad;


  + Parallelogram(float side = 0, float second_side = 0, float angle_bad = 90) : Rectangle(side, second_side);

  + float getAngle() const;
  + float **getSquare() const;
  + float *getPerimeter() const;

  + bool setAngle(float angle_bad);
}

Rectangle "Дочерний" <|-- "Родитель" Square : Наследование
Parallelogram "Дочерний" <|-- "Родитель" Rectangle : Наследование
@enduml
```
