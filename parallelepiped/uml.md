# UML Parallelepiped
For [PlantUML](//www.plantuml.com/plantuml/png/ZPD1Qy8m5CVl_HGvAkkOlMsMWQqY6qmG7BkMroRhmcBYadGmnEy-CntLrvXwVVzV_Y-_mviO2zesQn5L0emXIz0W11DimpUCHjie8kIMl0i5ba1P22uPUIIZasbP-QQ6K-QbWHOWQ-7c3wS1986an8cnO7b5k7GhZbobv3VJjh2gqFkkJx8bYsBvJEv8SZyYkyYfa1jaE1Yctl6PSNok6cF7s2iN-yrYlzOmFVplcDRClkoRitmmT6B6ffuqduRI5QUipH6GkSLvDci1Jvub_K2ELnXBnsDZDPUrurv_DfT_uRwOIPg3OJCEjP8WNE_b1uwSSstiFzwINN35zX7jaWYTQoLje1IHg3MavY_rWAYpr_w9yVh3zhiZxh8v1ZqSRWnR8yw3NTMt02wlaLXzDQ1PS5sGoC5u2RJ6P9AwCjF3Da9W0Y5lIZJhJbmg9OXfJp_jZlEfTtmuTjpJNddg2R8aaFnjtqKJ9ccp5hy0)
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
  - static inline float convert_to_rad_k { M_PI / 180 }


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
