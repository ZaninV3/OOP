# UML Parallelepiped
For [PlantUML](//www.plantuml.com/plantuml/dpng/bPH1ImCn48Nl-ojoR745UxH5w6vByQ0WLBoMsMPS0zEaxcGF8lvt3IYLD1sIwxxlxNilXrcoXy6F1whs1Cpg2GOWGiAZEQAkFgjAgMirMZQzHQrUoO5NqEt8M5HtwYObTtjHPgDHzeFUWUqf0BT90cOvIFSV2KFKLRHlCbqaFv_DhC-drQavTN92dQvTfwjE5xzTeqKz-WTZiMadKxLtblr2mjfL5hOr6a_W9R89vTfcVI8bi9aLa6sSpbxFv-m7O_l0FNySCmg66OtLBJ2k3VJE0eM036UmRCp0_iztiWYEBVumEh88APl1MI_792sbEU4TocA2GquHtkmUJV_c2ruiDeZZvOY4eImZB2-927nPmYCOMxHu-px2W7bDyj0ME4R51jnO7NxFkQQHA4OliI-EniCPrpb7YbEtBHBRbI26pka_fwzNB3SpKOykrLUrHAl70tq3)
```
@startuml
class Parallelepiped
{

  - unsigned float ab_line = 0
  - unsigned float bc_line = 0
  - unsigned float side_line = 0
  - unsigned float bad_angle = 90
  - unsigned float a1ad_angle = 90
  - unsigned float a1ab_angle = 90


   + Parallelepiped();
   + Parallelepiped(float ab_line = 0, float bc_line = 0, float side_line = 0, float bad_angle = 90, float a1ad_angle = 90, float a1ab_angle = 90);

   + unsigned float getLineAB() const;
   + unsigned float getLineBC() const;
   + unsigned float getLineSide() const;

   + unsigned float getAngleBAD() const;
   + unsigned float getAngleA1AD() const;
   + unsigned float getAngleA1AB() const;

   + std::string getType() const;

   + unsigned float getSideAndBaseDiagonalAngle() const;

   + unsigned float getBaseFirstDiagonal() const;
   + unsigned float getBaseSecondDiagonal() const;

   + unsigned float getFrontFirstDiagonal() const;
   + unsigned float getFrontSecondDiagonal() const;

   + unsigned float getSideFirstDiagonal() const;
   + unsigned float getSideSecondDiagonal() const;

   + unsigned float getBaseFirstHeight() const;
   + unsigned float getBaseSecondHeight() const;

   + unsigned float getFrontFirstHeight() const;
   + unsigned float getFrontSecondHeight() const;

   + unsigned float getSideFirstHeight() const;
   + unsigned float getSideSecondHeight() const;

   + unsigned float getMainHeight() const;

   + unsigned float getFrontSquare() const;
   + unsigned float getSideSquare() const;
   + unsigned float getBaseSquare() const;
   + unsigned float getFrontsAndSidesSquare() const;
   + unsigned float getFullSquare() const;

   + unsigned float getVolume() const;

   + bool setLineAB() const;
   + bool setLineBC() const;
   + bool setLineSide() const;

   + bool setAngleBAD() const;
   + bool setAngleA1AD() const;
   + bool setAngleA1AB() const;
}
@enduml
```
