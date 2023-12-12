# Geometric figures
For [PlantUML](//www.plantuml.com/plantuml/png/ZP51he9038RtFKMNm7iaxj648nWvW1cX4fA1YTEoKk_k12Qf0J5k-pL_-xKbY_4ozXPgQvYnket64zu1CSUhTKQGkuOAW53vYpXHW0VSfSKCvsfBKWMGf5YxWQLOe3dWCpoIxteIyigdXejp5ZdcwkmmzmbnxnFLOeRMBbQd4DEStmoqSIsnXV_NQMlbYMs9Pr_Dir_KDN-vJBo3Nc3_oFFuAIXfQC9tNm00)
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


  + Rectangle(float side = 0);
  + Rectangle(float side, float second_side);

  + float getSecondSide() const;
  + float *getSquare() const;
  + float *getPerimeter() const;

  + bool setSecondSide(float second_side);
}

Rectangle <|-- Square
@enduml
```
