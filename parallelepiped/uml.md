# UML Parallelepiped
For [PlantUML](//www.plantuml.com/plantuml/png/XPF1IiD0443l-OezjXZ17cqHccqf7XI4YjSowQvnORfRCvk3YF-kYqh2P9gzxdkPUNF8cYAqiJjXSKGWKa_G0g95UtPdQuhFeb3gMhrYWAYWFg3pLjsfcy5hVPHUoHahsc0Eu1jCxxT308i9KWz9Ib9Nh7GsNudFe_9od5rApQKONCgrfPmwN_ss_j76nWVdRQLdStKCdk9Ae7epHVVEs9upeKgBTRNj1O5NYxoW-GgAPhcas3hV9E_vutov8YLMtcWWktNG10-Ovbx-89axrrByrtjpBExj3p9ZawcxDlWe3vLCUQfqMgQq5rbf_lfxwvgtcB-zzpANSr7msCJCrTmJRyxFUmJdkIB6lNVGsibrauO6ueQqXYflqZ3Ak1qYDvZo4h0xZN0T0YeIVdqEzKQ6ye_VS_6_vxXQPFcWxQjOMs-w4tu3)
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
   + Parallelepiped(float ab_line = 0, float bc_line = 0, float side_line = 0, float bad_angle = 90, float a1ad_angle = 90, float a1ab_angle = 90);

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
