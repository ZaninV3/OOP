# UML Parallelepiped
For [PlantUML](//www.plantuml.com/plantuml/png/ZPEnJiCm48RtF8N7LWI9ZZH2gjsgOW09gOYrkjGcMBhQ9NO6X7Xti0fAUhaahFT__k-xmQiGeOxD4RC3GWZY2Mf0D6XEzcHqzfbbGboBL_GG1PHxjCw8Et7JcPO7RXgiDYmDUW-kmZI_xGQm64dARfAKn1KndSqBTdnXdbygvzGrPoLptZ3dzUR5sUythKnyiCv8DPkBWtSX5aogrcFfpchJvWIGQR6IcnPWShcO1XHT4Q9UBaEihQiIz_nn6hP8Yj9f1S5iB5JU0QRUuGU9tDewn3-y9VlWpln4kayIT5jx5_bIZcHR-TFuKWOadPFNtnjRlSNfsoatU3a1EOuqJbnDE0RxLzyZMCSYLEwzWTgChXib50IEe6k2T3gLXGcsGQG4GLuyDiTUN7gF8hHVl-YFrPgEEv-TzhI_l602kHXEpjk_ifLnkZdYDm00)
```
@startuml
class Parallelepiped
{

  - float ab_line = 0
  - float bc_line = 0
  - float side_line = 0
  - float bad_angle = 90
  - float a1ad_angle = 90
  - float a1ab_angle = 90


   + Parallelepiped();
   + Parallelepiped(float ab_line, float bc_line, float side_line, float bad_angle = 90, float a1ad_angle = 90, float a1ab_angle = 90);

   + float getLineAB() const;
   + float getLineBC() const;
   + float getLineSide() const;

   + float getAngleBAD() const;
   + float getAngleA1AD() const;
   + float getAngleA1AB() const;

   + std::string getType() const;

   + float getSideAndBaseDiagonalAngle() const;

   + float getBaseFirstDiagonal() const;
   + float getBaseSecondDiagonal() const;

   + float getFrontFirstDiagonal() const;
   + float getFrontSecondDiagonal() const;

   + float getSideFirstDiagonal() const;
   + float getSideSecondDiagonal() const;

   + float getBaseFirstHeight() const;
   + float getBaseSecondHeight() const;

   + float getFrontFirstHeight() const;
   + float getFrontSecondHeight() const;

   + float getSideFirstHeight() const;
   + float getSideSecondHeight() const;

   + float getMainHeight() const;

   + float getFrontSquare() const;
   + float getSideSquare() const;
   + float getBaseSquare() const;
   + float getFrontsAndSidesSquare() const;
   + float getFullSquare() const;

   + float getVolume() const;

   + bool setLineAB();
   + bool setLineBC();
   + bool setLineSide();

   + bool setAngleBAD();
   + bool setAngleA1AD();
   + bool setAngleA1AB();
}
@enduml
```
