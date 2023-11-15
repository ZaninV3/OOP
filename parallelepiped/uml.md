# UML Parallelepiped
For [PlantUML](//www.plantuml.com/plantuml/png/ZPF1IWCn48Rl-nGvjhY2FTeYD6af7XI4YjSosyGrC4tgJlOWuhjhKEjsEjtrEl-NVxuvP4u9cjJkiDWY4Aa7Q03HeTlxlRF5Ur4eTQcUCK9IK6tG1wTkr5LdMcsbANdhH1hi1aADUNxT3M3IarJT92kf2sOw6i_4yP5vUQnSSjTIb2nbmrBM6y--_NxIsgKx7vmsex7Qna1f9gHcqPUklNL_EGDqNcpqyW18kPuC0uQle6IdKqgD3tNc7j_svosoeWxM0BcbXpe6mDnx_a4cLxwXz8iVI05Skw_8df8CNJKn9BbK8kLMyJIvL007EzdrjyxNBsduTix9byk5dEjlv5SpJi3-rNSFFd14b7jjeN5zw_e90yG9QGtfO7CP3R0j8YSOyXIntPt4LOoeIFZwF3IBdZ0Roitol-UndWpc7RUFOkw2RNVu2G00)
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

   + bool setLineAB() const;
   + bool setLineBC() const;
   + bool setLineSide() const;

   + bool setAngleBAD() const;
   + bool setAngleA1AD() const;
   + bool setAngleA1AB() const;
}
@enduml
```
